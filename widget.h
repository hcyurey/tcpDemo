#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void slot_newConnect();
    void slot_readMessage();
    void slot_displayError(QAbstractSocket::SocketError);
    void slot_sendBtn();
    void slot_connected();
    void slot_disconnected();
    void slot_scanLine(QString sn);

private:
    void parseData(QString data);
    void tcpSend(QString msg);

private:
    Ui::Widget *ui;

    QTcpSocket *tcpSocket;
    QString message;        // 接收的字符串
    quint16 blockSize;      // 文件大小信息
    bool connectedState;
    QString m_snCode;
    QString sendFlag;       // 传给资讯的标志位信息，1表示通知要传值了，2表示真正传值的信息
};

#endif // WIDGET_H
