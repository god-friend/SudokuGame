/********************************************************************************
** Form generated from reading UI file 'showscores.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWSCORES_H
#define UI_SHOWSCORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showScores
{
public:
    QGridLayout *gridLayout;
    QLabel *bestMediumTime;
    QLabel *bestEasyTime;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *bestHardTime;
    QScrollArea *easyScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *easyWid;
    QScrollArea *mediumScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *mediumWid;
    QScrollArea *hardScrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *hardWid;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QPushButton *backBtn;
    QLabel *label_6;
    QLabel *label;

    void setupUi(QWidget *showScores)
    {
        if (showScores->objectName().isEmpty())
            showScores->setObjectName("showScores");
        showScores->resize(647, 350);
        gridLayout = new QGridLayout(showScores);
        gridLayout->setObjectName("gridLayout");
        bestMediumTime = new QLabel(showScores);
        bestMediumTime->setObjectName("bestMediumTime");
        bestMediumTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(bestMediumTime, 2, 3, 1, 1);

        bestEasyTime = new QLabel(showScores);
        bestEasyTime->setObjectName("bestEasyTime");
        bestEasyTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(bestEasyTime, 2, 1, 1, 1);

        label_9 = new QLabel(showScores);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label_9, 2, 4, 1, 1);

        label_8 = new QLabel(showScores);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label_8, 2, 2, 1, 1);

        label_7 = new QLabel(showScores);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        label_3 = new QLabel(showScores);
        label_3->setObjectName("label_3");
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        label_4 = new QLabel(showScores);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label_4, 1, 4, 1, 1);

        label_2 = new QLabel(showScores);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        bestHardTime = new QLabel(showScores);
        bestHardTime->setObjectName("bestHardTime");
        bestHardTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(bestHardTime, 2, 5, 1, 1);

        easyScrollArea = new QScrollArea(showScores);
        easyScrollArea->setObjectName("easyScrollArea");
        easyScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 204, 222));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        easyWid = new QWidget(scrollAreaWidgetContents);
        easyWid->setObjectName("easyWid");

        verticalLayout->addWidget(easyWid);

        easyScrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(easyScrollArea, 3, 0, 1, 2);

        mediumScrollArea = new QScrollArea(showScores);
        mediumScrollArea->setObjectName("mediumScrollArea");
        mediumScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 203, 222));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        mediumWid = new QWidget(scrollAreaWidgetContents_2);
        mediumWid->setObjectName("mediumWid");

        verticalLayout_2->addWidget(mediumWid);

        mediumScrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(mediumScrollArea, 3, 2, 1, 2);

        hardScrollArea = new QScrollArea(showScores);
        hardScrollArea->setObjectName("hardScrollArea");
        hardScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 204, 222));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        hardWid = new QWidget(scrollAreaWidgetContents_3);
        hardWid->setObjectName("hardWid");

        verticalLayout_3->addWidget(hardWid);

        hardScrollArea->setWidget(scrollAreaWidgetContents_3);

        gridLayout->addWidget(hardScrollArea, 3, 4, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_5 = new QLabel(showScores);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        backBtn = new QPushButton(showScores);
        backBtn->setObjectName("backBtn");
        backBtn->setMaximumSize(QSize(73, 22));
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

        label_6 = new QLabel(showScores);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 2);

        label = new QLabel(showScores);
        label->setObjectName("label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Chilanka")});
        font1.setPointSize(26);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 2, 1, 2);


        retranslateUi(showScores);

        QMetaObject::connectSlotsByName(showScores);
    } // setupUi

    void retranslateUi(QWidget *showScores)
    {
        showScores->setWindowTitle(QCoreApplication::translate("showScores", "Form", nullptr));
        bestMediumTime->setText(QString());
        bestEasyTime->setText(QString());
        label_9->setText(QCoreApplication::translate("showScores", "Best Time :: ", nullptr));
        label_8->setText(QCoreApplication::translate("showScores", "Best Time :: ", nullptr));
        label_7->setText(QCoreApplication::translate("showScores", "Best Time :: ", nullptr));
        label_3->setText(QCoreApplication::translate("showScores", "Medium", nullptr));
        label_4->setText(QCoreApplication::translate("showScores", "Hard", nullptr));
        label_2->setText(QCoreApplication::translate("showScores", "Easy", nullptr));
        bestHardTime->setText(QString());
        label_5->setText(QString());
        backBtn->setText(QCoreApplication::translate("showScores", "Back", nullptr));
        label_6->setText(QString());
        label->setText(QCoreApplication::translate("showScores", "Scores", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showScores: public Ui_showScores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWSCORES_H
