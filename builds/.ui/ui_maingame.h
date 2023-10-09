/********************************************************************************
** Form generated from reading UI file 'maingame.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGAME_H
#define UI_MAINGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainGame
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
    QPushButton *newGameBtn;
    QHBoxLayout *horLay;
    QGridLayout *gridLayout_2;
    QPushButton *backBtn;
    QLCDNumber *timeSpent;

    void setupUi(QWidget *mainGame)
    {
        if (mainGame->objectName().isEmpty())
            mainGame->setObjectName("mainGame");
        mainGame->resize(710, 352);
        gridLayout = new QGridLayout(mainGame);
        gridLayout->setObjectName("gridLayout");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        newGameBtn = new QPushButton(mainGame);
        newGameBtn->setObjectName("newGameBtn");
        newGameBtn->setMinimumSize(QSize(100, 25));
        newGameBtn->setMaximumSize(QSize(100, 25));
        newGameBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(153, 193, 241);\n"
"	border-radius: 10px;\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(26, 95, 180);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(220, 138, 221);\n"
"}"));

        gridLayout_3->addWidget(newGameBtn, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 0, 2, 1, 1);

        horLay = new QHBoxLayout();
        horLay->setObjectName("horLay");

        gridLayout->addLayout(horLay, 1, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        backBtn = new QPushButton(mainGame);
        backBtn->setObjectName("backBtn");
        backBtn->setMinimumSize(QSize(70, 25));
        backBtn->setMaximumSize(QSize(70, 25));
        backBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(153, 193, 241);\n"
"	border-radius: 10px;\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(26, 95, 180);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(220, 138, 221);\n"
"}"));

        gridLayout_2->addWidget(backBtn, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        timeSpent = new QLCDNumber(mainGame);
        timeSpent->setObjectName("timeSpent");
        timeSpent->setMaximumSize(QSize(16777215, 16777215));
        timeSpent->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        timeSpent->setSmallDecimalPoint(false);
        timeSpent->setDigitCount(1);
        timeSpent->setProperty("value", QVariant(0.000000000000000));

        gridLayout->addWidget(timeSpent, 0, 1, 1, 1);


        retranslateUi(mainGame);

        QMetaObject::connectSlotsByName(mainGame);
    } // setupUi

    void retranslateUi(QWidget *mainGame)
    {
        mainGame->setWindowTitle(QCoreApplication::translate("mainGame", "Form", nullptr));
        newGameBtn->setText(QCoreApplication::translate("mainGame", "New Game", nullptr));
        backBtn->setText(QCoreApplication::translate("mainGame", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainGame: public Ui_mainGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAME_H
