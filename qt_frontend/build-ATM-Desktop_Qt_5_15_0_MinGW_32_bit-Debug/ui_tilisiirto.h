/********************************************************************************
** Form generated from reading UI file 'tilisiirto.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILISIIRTO_H
#define UI_TILISIIRTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tilisiirto
{
public:
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_8;
    QPushButton *pushButton_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLineEdit *lineEdit_5;

    void setupUi(QDialog *tilisiirto)
    {
        if (tilisiirto->objectName().isEmpty())
            tilisiirto->setObjectName(QString::fromUtf8("tilisiirto"));
        tilisiirto->resize(800, 600);
        label_2 = new QLabel(tilisiirto);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 30, 191, 91));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        pushButton = new QPushButton(tilisiirto);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 490, 101, 22));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(tilisiirto);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 490, 131, 21));
        pushButton_2->setFont(font1);
        label = new QLabel(tilisiirto);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 140, 81, 21));
        label->setFont(font1);
        label_8 = new QLabel(tilisiirto);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(230, 400, 101, 16));
        pushButton_3 = new QPushButton(tilisiirto);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 320, 80, 22));
        widget = new QWidget(tilisiirto);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 240, 411, 58));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 0, 3, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 1, 3, 1, 1);

        widget1 = new QWidget(tilisiirto);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(190, 320, 205, 27));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        lineEdit_5 = new QLineEdit(widget1);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout_2->addWidget(lineEdit_5, 0, 1, 1, 1);


        retranslateUi(tilisiirto);

        QMetaObject::connectSlotsByName(tilisiirto);
    } // setupUi

    void retranslateUi(QDialog *tilisiirto)
    {
        tilisiirto->setWindowTitle(QCoreApplication::translate("tilisiirto", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("tilisiirto", "Automaatti", nullptr));
        pushButton->setText(QCoreApplication::translate("tilisiirto", "Edellinen", nullptr));
        pushButton_2->setText(QCoreApplication::translate("tilisiirto", "Kirjaudu ulos", nullptr));
        label->setText(QCoreApplication::translate("tilisiirto", "Tilisiirto", nullptr));
        label_8->setText(QCoreApplication::translate("tilisiirto", "Maksu l\303\244htenyt", nullptr));
        pushButton_3->setText(QCoreApplication::translate("tilisiirto", "L\303\244het\303\244", nullptr));
        label_3->setText(QCoreApplication::translate("tilisiirto", "Saajan tilinumero", nullptr));
        label_5->setText(QCoreApplication::translate("tilisiirto", "Viite", nullptr));
        label_4->setText(QCoreApplication::translate("tilisiirto", "Summa", nullptr));
        label_6->setText(QCoreApplication::translate("tilisiirto", "Viesti", nullptr));
        lineEdit_4->setText(QString());
        label_7->setText(QCoreApplication::translate("tilisiirto", "Maksup\303\244iv\303\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tilisiirto: public Ui_tilisiirto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILISIIRTO_H
