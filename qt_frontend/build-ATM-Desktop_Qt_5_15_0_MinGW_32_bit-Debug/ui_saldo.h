/********************************************************************************
** Form generated from reading UI file 'saldo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALDO_H
#define UI_SALDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_saldo
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;

    void setupUi(QDialog *saldo)
    {
        if (saldo->objectName().isEmpty())
            saldo->setObjectName(QString::fromUtf8("saldo"));
        saldo->resize(800, 600);
        label = new QLabel(saldo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 190, 47, 14));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(saldo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 80, 191, 91));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_3 = new QLabel(saldo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 230, 47, 14));
        pushButton = new QPushButton(saldo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 370, 80, 22));
        pushButton_2 = new QPushButton(saldo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 370, 80, 22));
        label_4 = new QLabel(saldo);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(240, 260, 261, 101));
        label_4->setFrameShape(QFrame::Box);

        retranslateUi(saldo);

        QMetaObject::connectSlotsByName(saldo);
    } // setupUi

    void retranslateUi(QDialog *saldo)
    {
        saldo->setWindowTitle(QCoreApplication::translate("saldo", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("saldo", "Saldo", nullptr));
        label_2->setText(QCoreApplication::translate("saldo", "Automaatti", nullptr));
        label_3->setText(QCoreApplication::translate("saldo", "saldo \342\202\254", nullptr));
        pushButton->setText(QCoreApplication::translate("saldo", "Edellinen", nullptr));
        pushButton_2->setText(QCoreApplication::translate("saldo", "Kirjaudu ulos", nullptr));
        label_4->setText(QCoreApplication::translate("saldo", "5 tilitapahtumaa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saldo: public Ui_saldo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALDO_H
