#include "messages_dialog.h"
#include "ui_messages_dialog.h"


// Public Members

messages_dialog::messages_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::messages_dialog)
{
    ui->setupUi(this);

}

messages_dialog::~messages_dialog()
{
    delete ui;
}

void messages_dialog::singleBtnMessage(QString title, QString message){
    ui->cancelBtn->setVisible(false);
    connect(ui->okBtn, SIGNAL(clicked(bool)), this, SLOT(close()));

    setTitle(title);
    setMessage(message);


}


// Private Members

void messages_dialog::setMessage(QString message){
    ui->col10Label->setText(message);
    ui->col10Label->setStyleSheet("color: rgb(0,0,0);");
}

void messages_dialog::setTitle(QString title){
    ui->msgTitle->setText(title);
    ui->msgTitle->setStyleSheet("color: rgb(0,0,0);");
}
