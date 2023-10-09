/********************************************************************************
** Form generated from reading UI file 'selectlevel.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTLEVEL_H
#define UI_SELECTLEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_selectLevel
{
public:
    QGridLayout *gridLayout;
    QPushButton *selectBtn;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *hard;
    QRadioButton *medium;
    QRadioButton *easy;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QDialog *selectLevel)
    {
        if (selectLevel->objectName().isEmpty())
            selectLevel->setObjectName("selectLevel");
        selectLevel->setWindowModality(Qt::NonModal);
        selectLevel->resize(464, 133);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectLevel->sizePolicy().hasHeightForWidth());
        selectLevel->setSizePolicy(sizePolicy);
        selectLevel->setMaximumSize(QSize(464, 133));
        selectLevel->setLayoutDirection(Qt::LeftToRight);
        selectLevel->setAutoFillBackground(false);
        selectLevel->setStyleSheet(QString::fromUtf8("\n"
"	background-color: rgb(192, 191, 188);\n"
""));
        selectLevel->setSizeGripEnabled(false);
        selectLevel->setModal(false);
        gridLayout = new QGridLayout(selectLevel);
        gridLayout->setObjectName("gridLayout");
        selectBtn = new QPushButton(selectLevel);
        selectBtn->setObjectName("selectBtn");
        selectBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        gridLayout->addWidget(selectBtn, 2, 4, 1, 1);

        label = new QLabel(selectLevel);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Chilanka")});
        font.setPointSize(30);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label, 0, 0, 1, 5);

        label_2 = new QLabel(selectLevel);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        hard = new QRadioButton(selectLevel);
        hard->setObjectName("hard");
        hard->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(hard, 1, 3, 1, 1);

        medium = new QRadioButton(selectLevel);
        medium->setObjectName("medium");
        medium->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(medium, 1, 2, 1, 1);

        easy = new QRadioButton(selectLevel);
        easy->setObjectName("easy");
        easy->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        easy->setChecked(true);

        gridLayout->addWidget(easy, 1, 1, 1, 1);

        pushButton = new QPushButton(selectLevel);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        gridLayout->addWidget(pushButton, 2, 3, 1, 1);

        label_3 = new QLabel(selectLevel);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 4, 1, 1);


        retranslateUi(selectLevel);
        QObject::connect(pushButton, &QPushButton::clicked, selectLevel, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(selectLevel);
    } // setupUi

    void retranslateUi(QDialog *selectLevel)
    {
        selectLevel->setWindowTitle(QCoreApplication::translate("selectLevel", "Select Difficulty Level", nullptr));
        selectBtn->setText(QCoreApplication::translate("selectLevel", "Select", nullptr));
        label->setText(QCoreApplication::translate("selectLevel", "Select Difficulty Level", nullptr));
        label_2->setText(QCoreApplication::translate("selectLevel", "Difficulty Level :: ", nullptr));
        hard->setText(QCoreApplication::translate("selectLevel", "Hard", nullptr));
        medium->setText(QCoreApplication::translate("selectLevel", "Medium", nullptr));
        easy->setText(QCoreApplication::translate("selectLevel", "Easy", nullptr));
        pushButton->setText(QCoreApplication::translate("selectLevel", "Cancel", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class selectLevel: public Ui_selectLevel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTLEVEL_H
