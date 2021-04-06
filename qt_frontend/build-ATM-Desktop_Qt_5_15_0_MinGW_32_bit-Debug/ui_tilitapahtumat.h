/********************************************************************************
** Form generated from reading UI file 'tilitapahtumat.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILITAPAHTUMAT_H
#define UI_TILITAPAHTUMAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_tilitapahtumat
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *tilitapahtumat)
    {
        if (tilitapahtumat->objectName().isEmpty())
            tilitapahtumat->setObjectName(QString::fromUtf8("tilitapahtumat"));
        tilitapahtumat->resize(800, 600);
        label = new QLabel(tilitapahtumat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 40, 201, 111));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        pushButton = new QPushButton(tilitapahtumat);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 490, 111, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        label_2 = new QLabel(tilitapahtumat);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 170, 201, 41));
        label_2->setFont(font1);
        pushButton_2 = new QPushButton(tilitapahtumat);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 490, 131, 31));
        pushButton_2->setFont(font1);
        label_3 = new QLabel(tilitapahtumat);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 220, 311, 141));
        label_3->setFrameShape(QFrame::Box);
        pushButton_3 = new QPushButton(tilitapahtumat);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(350, 370, 131, 31));
        pushButton_3->setFont(font1);
        pushButton_4 = new QPushButton(tilitapahtumat);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);
        pushButton_4->setGeometry(QRect(180, 370, 121, 31));
        pushButton_4->setFont(font1);
        pushButton_5 = new QPushButton(tilitapahtumat);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(240, 420, 161, 41));
        pushButton_5->setFont(font1);

        retranslateUi(tilitapahtumat);

        QMetaObject::connectSlotsByName(tilitapahtumat);
    } // setupUi

    void retranslateUi(QDialog *tilitapahtumat)
    {
        tilitapahtumat->setWindowTitle(QCoreApplication::translate("tilitapahtumat", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("tilitapahtumat", "Automaatti", nullptr));
        pushButton->setText(QCoreApplication::translate("tilitapahtumat", "Edellinen", nullptr));
        label_2->setText(QCoreApplication::translate("tilitapahtumat", "Tilitapahtumat", nullptr));
        pushButton_2->setText(QCoreApplication::translate("tilitapahtumat", "Kirjaudu ulos", nullptr));
        label_3->setText(QCoreApplication::translate("tilitapahtumat", "10 tilitapahtumaa", nullptr));
        pushButton_3->setText(QCoreApplication::translate("tilitapahtumat", "Seuraavat 10", nullptr));
        pushButton_4->setText(QCoreApplication::translate("tilitapahtumat", "Edelliset 10", nullptr));
        pushButton_5->setText(QCoreApplication::translate("tilitapahtumat", "Tulevat maksut", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tilitapahtumat: public Ui_tilitapahtumat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILITAPAHTUMAT_H
