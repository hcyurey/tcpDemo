#include "widget.h"
#include <QApplication>
#include <QTextCodec>

//QTextCodec *Codec = QTextCodec::codecForName("GBK");
QTextCodec *Codec = QTextCodec::codecForName("Big5");

int main(int argc, char *argv[])
{
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("System"));

    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
