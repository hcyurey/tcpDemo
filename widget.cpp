#include "widget.h"
#include "ui_widget.h"
#include <iostream>
using namespace std;
extern QTextCodec *Codec;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);
    connectedState = false;
    sendFlag = "1";
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
//    QTextCodec *tc = QTextCodec::codecForCStrings();
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(slot_readMessage()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slot_displayError(QAbstractSocket::SocketError)));
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(slot_connected()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(slot_disconnected()));

    connect(ui->connectBtn, SIGNAL(clicked()), this, SLOT(slot_newConnect()));
    connect(ui->sendBtn, SIGNAL(clicked()), this, SLOT(slot_sendBtn()));
    connect(ui->scanLine, SIGNAL(textChanged(QString)), this, SLOT(slot_scanLine(QString)));

}

Widget::~Widget()
{
    tcpSocket->disconnectFromHost();

    delete ui;
}

void Widget::slot_newConnect()
{
    if(connectedState)
    {
        qDebug() << tr("Disconnect...");
        tcpSocket->disconnectFromHost();
        ui->connectBtn->setText("连接");
    }
    else
    {
        qDebug() << tr("Connect to %0...").arg(ui->hostLine->text());
        blockSize = 0;
        tcpSocket->abort();     // 取消已有连接
        tcpSocket->connectToHost(ui->hostLine->text(), ui->portLine->text().toInt());
    }
}

void Widget::slot_readMessage()
{
//    qDebug() << "slot_readMessage()";
#if 0
    QDataStream in(tcpSocket);
    in.setVersion((QDataStream::Qt_5_4));       // 设置数据流版本，要与服务器端相同
    if(blockSize == 0)      // 如果刚开始接收数据
    {
        qDebug() << "bytesAvailable =" << tcpSocket->bytesAvailable();
        if(tcpSocket->bytesAvailable() < (int)sizeof(quint16))  // 如果数据有两字节，则保持到blockSize，否则继续接收
            return;
        in >> blockSize;
        qDebug() << "blockSize =" << blockSize;
    }
    if(tcpSocket->bytesAvailable() < blockSize)     // 如果没有得到全部数据，则返回继续接收
        return;
    in >> message;
#else
    while(tcpSocket->bytesAvailable() > 0)
    {
        QByteArray readByte = this->tcpSocket->readAll();
        message = Codec->toUnicode(readByte);
        qDebug() << "receive =" << message;
    }
#endif
    ui->receiveLine->setText(message);
    parseData(message);
}

void Widget::slot_displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString();
    ui->connectLab->setText(tcpSocket->errorString());
}

void Widget::slot_sendBtn()
{
    QByteArray data(ui->sendLine->text().toLatin1());
    qDebug() << "send =" << data;
    tcpSocket->write(data);
}

void Widget::tcpSend(QString msg)
{
    qDebug() << "send =" << msg;
    tcpSocket->write(qPrintable(msg));
}

void Widget::slot_connected()
{
    connectedState = true;
    qDebug() << tr("连接%0成功！").arg(ui->hostLine->text());
    ui->connectLab->setText("连接成功！");
    ui->connectLab->setStyleSheet("color:blue");
    ui->connectBtn->setText("断开");

}

void Widget::slot_disconnected()
{
    qDebug() << tr("断开连接成功！");
    connectedState = false;
    ui->connectLab->setStyleSheet("color:red");
    ui->connectLab->setText("未连接");
}

void Widget::slot_scanLine(QString sn)
{
#if 0
    QRegExp rx111("\\bRESULT=([\\w]+)\\b");
    rx.setCaseSensitivity(Qt::CaseInsensitive);
    if(sn.indexOf(rx111) >= 0)
    {
        ui->scanLab->setText(tr("RESULT=%0").arg(rx111.cap(1)));
    }
#else
    if(sn.length() != 20)
        return;

    ui->scanLine->clear();
    QRegExp rx("^cmic[0-9a-z]{16}$");
    if(rx.exactMatch(sn))
    {
        ui->scanLab->setText(tr("扫码成功，sn：%0").arg(sn));
        sendFlag = "1";
        m_snCode = sn;
        tcpSend(QString("FLAG=%0;EMP=F3648905;ERROR=N/A;SN=%1;").arg(sendFlag).arg(m_snCode));
    }
    else
    {
        ui->scanLab->setText(tr("格式不正确！"));
    }
#endif
}

void Widget::parseData(QString data)
{
    QRegExp rx("\\bRESULT=(\\w+)\\b");      // 分析返回数据RESULT字段结果
    rx.setCaseSensitivity(Qt::CaseInsensitive);
    if(data.indexOf(rx) < 0)
        return;

    QString res = rx.cap(1);        // RESULT字段结果
    if(res.toUpper() == "OK")
    {
        if(sendFlag == "1")
        {
            sendFlag = "2";

            /** 执行 flag=2 的保存数据 */
            QString wifi_mac = "20:12:34:56:78:9c";     // wifi mac
            QString gwCode = "rla7t6";                  // 随机码
#if 1
            QString account = m_snCode;
#else
            QString account = "cmic057750294d409cd7";   // 读取的账号
//            for(int index = 5; index > 0; index--)      // 去除冒号保存
//            {
//                wifi_mac.remove(3*(index)-1, 1);
//            }
            if(m_snCode != account)     // 扫码sn号必须与设备读取的账号一致
            {
                ui->scanLab->setText(tr("扫码sn号与读取账号不符，请检查后重试！"));
                return;
            }
#endif
            tcpSend(QString("FLAG=%0;EMP=F3648905;ERROR=N/A;SN=%1;WIFI_MAC=%2;GWCODE=%3;ID=%4;")
                            .arg(sendFlag).arg(m_snCode)
                            .arg(wifi_mac)
                            .arg(gwCode)
                            .arg(account) );
        }
        else if(sendFlag == "2")
        {
            sendFlag = "1";

            QRegExp rx_msg("\\bMESSAGE=(.+)\\b");
            rx_msg.setCaseSensitivity(Qt::CaseInsensitive);
            data.indexOf(rx_msg);
//            qDebug() << "rx_msg.cap(1)" << rx_msg.cap(1);
            ui->scanLab->setText(tr("保存数据成功！%0").arg(rx_msg.cap(1)));
        }
    }
    else if(res.toUpper() == "NG")
    {
        sendFlag = "1";

        QRegExp rx_msg("\\bMESSAGE=(.+)\\b");
        data.indexOf(rx_msg);
        ui->scanLab->setText(tr("保存数据失败！%0").arg(rx_msg.cap(1)));
    }
}
