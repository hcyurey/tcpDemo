/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *hostLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *portLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *connectLab;
    QSpacerItem *horizontalSpacer;
    QPushButton *connectBtn;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *sendLine;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *receiveLine;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *sendBtn;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *scanLine;
    QHBoxLayout *horizontalLayout_8;
    QLabel *scanLab;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(311, 300);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        hostLine = new QLineEdit(Widget);
        hostLine->setObjectName(QStringLiteral("hostLine"));

        horizontalLayout->addWidget(hostLine);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        portLine = new QLineEdit(Widget);
        portLine->setObjectName(QStringLiteral("portLine"));

        horizontalLayout_2->addWidget(portLine);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        connectLab = new QLabel(Widget);
        connectLab->setObjectName(QStringLiteral("connectLab"));

        horizontalLayout_3->addWidget(connectLab);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        connectBtn = new QPushButton(Widget);
        connectBtn->setObjectName(QStringLiteral("connectBtn"));

        horizontalLayout_3->addWidget(connectBtn);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        sendLine = new QLineEdit(Widget);
        sendLine->setObjectName(QStringLiteral("sendLine"));

        horizontalLayout_4->addWidget(sendLine);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        receiveLine = new QLineEdit(Widget);
        receiveLine->setObjectName(QStringLiteral("receiveLine"));

        horizontalLayout_5->addWidget(receiveLine);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        sendBtn = new QPushButton(Widget);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));

        horizontalLayout_6->addWidget(sendBtn);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        scanLine = new QLineEdit(Widget);
        scanLine->setObjectName(QStringLiteral("scanLine"));

        horizontalLayout_7->addWidget(scanLine);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        scanLab = new QLabel(Widget);
        scanLab->setObjectName(QStringLiteral("scanLab"));
        scanLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(scanLab);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "ip:", 0));
        hostLine->setText(QApplication::translate("Widget", "10.100.5.98", 0));
        label_2->setText(QApplication::translate("Widget", "port:", 0));
        portLine->setText(QApplication::translate("Widget", "60123", 0));
        connectLab->setText(QApplication::translate("Widget", "\346\234\252\350\277\236\346\216\245", 0));
        connectBtn->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", 0));
        label_3->setText(QApplication::translate("Widget", "send:", 0));
        label_4->setText(QApplication::translate("Widget", "receive:", 0));
        sendBtn->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", 0));
        label_5->setText(QApplication::translate("Widget", "\346\211\253\347\240\201:", 0));
        scanLab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
