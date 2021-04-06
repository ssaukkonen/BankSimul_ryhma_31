/********************************************************************************
** Form generated from reading UI file 'valikko.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALIKKO_H
#define UI_VALIKKO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Valikko
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;

    void setupUi(QDialog *Valikko)
    {
        if (Valikko->objectName().isEmpty())
            Valikko->setObjectName(QString::fromUtf8("Valikko"));
        Valikko->resize(800, 600);
        widget = new QWidget(Valikko);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(280, 180, 191, 224));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_3->setFont(font1);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font1);

        verticalLayout->addWidget(pushButton_4);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font1);

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font1);

        verticalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font1);

        gridLayout->addWidget(pushButton_5, 1, 0, 1, 1);


        retranslateUi(Valikko);

        QMetaObject::connectSlotsByName(Valikko);
    } // setupUi

    void retranslateUi(QDialog *Valikko)
    {
        Valikko->setWindowTitle(QCoreApplication::translate("Valikko", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Valikko", "Automaatti", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Valikko", "Nosta rahaa", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Valikko", "Tilisiirto", nullptr));
        pushButton->setText(QCoreApplication::translate("Valikko", "N\303\244yt\303\244 saldo", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Valikko", "Selaa tilitapahtumia", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Valikko", "Kirjaudu ulos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Valikko: public Ui_Valikko {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALIKKO_H
