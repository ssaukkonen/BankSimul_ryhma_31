/********************************************************************************
** Form generated from reading UI file 'nosto.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOSTO_H
#define UI_NOSTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nosto
{
public:
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_3;
    QPushButton *pushButton_9;
    QWidget *widget;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;

    void setupUi(QDialog *nosto)
    {
        if (nosto->objectName().isEmpty())
            nosto->setObjectName(QString::fromUtf8("nosto"));
        nosto->resize(800, 600);
        label_2 = new QLabel(nosto);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 90, 191, 91));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        pushButton_2 = new QPushButton(nosto);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 460, 151, 51));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_2->setFont(font1);
        label = new QLabel(nosto);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 200, 111, 16));
        label->setFont(font1);
        pushButton = new QPushButton(nosto);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 450, 101, 41));
        pushButton->setFont(font1);
        label_3 = new QLabel(nosto);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 370, 111, 16));
        pushButton_9 = new QPushButton(nosto);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(310, 400, 141, 31));
        pushButton_9->setFont(font1);
        widget = new QWidget(nosto);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(270, 240, 170, 106));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font1);

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font1);

        horizontalLayout->addWidget(pushButton_4);


        formLayout->setLayout(0, QFormLayout::SpanningRole, horizontalLayout);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, pushButton_5);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font1);

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButton_6);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, pushButton_7);

        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setFont(font1);

        formLayout->setWidget(2, QFormLayout::FieldRole, pushButton_8);


        retranslateUi(nosto);

        QMetaObject::connectSlotsByName(nosto);
    } // setupUi

    void retranslateUi(QDialog *nosto)
    {
        nosto->setWindowTitle(QCoreApplication::translate("nosto", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("nosto", "Automaatti", nullptr));
        pushButton_2->setText(QCoreApplication::translate("nosto", "Kirjaudu ulos", nullptr));
        label->setText(QCoreApplication::translate("nosto", "Nosta rahaa", nullptr));
        pushButton->setText(QCoreApplication::translate("nosto", "Edellinen", nullptr));
        label_3->setText(QCoreApplication::translate("nosto", "Tapahtuma OK", nullptr));
        pushButton_9->setText(QCoreApplication::translate("nosto", "N\303\244yt\303\244 saldo", nullptr));
        pushButton_3->setText(QCoreApplication::translate("nosto", "20 \342\202\254", nullptr));
        pushButton_4->setText(QCoreApplication::translate("nosto", "40 \342\202\254", nullptr));
        pushButton_5->setText(QCoreApplication::translate("nosto", "60 \342\202\254", nullptr));
        pushButton_6->setText(QCoreApplication::translate("nosto", "100 \342\202\254", nullptr));
        pushButton_7->setText(QCoreApplication::translate("nosto", "200 \342\202\254", nullptr));
        pushButton_8->setText(QCoreApplication::translate("nosto", "500 \342\202\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nosto: public Ui_nosto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOSTO_H
