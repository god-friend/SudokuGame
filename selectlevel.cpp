#include "selectlevel.h"
#include "ui_selectlevel.h"
#include "sudoku.h"

selectLevel::selectLevel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectLevel)
{
    ui->setupUi(this);
    markLevel();
    connect(ui->selectBtn, SIGNAL(clicked(bool)), this, SLOT(selectBtnClicked()));
}

selectLevel::~selectLevel()
{
    delete ui;
}

void selectLevel::markLevel(){
    Sudoku *p = (Sudoku *)parent();
    int l = p->getLevel();
    switch(l){
    case 1:
        ui->easy->setChecked(true);
        break;
    case 2:
        ui->medium->setChecked(true);
        break;
    case 3:
        ui->hard->setChecked(true);
        break;
    default:
        qDebug() << "An Error Occured";
        return;
    }
}

void selectLevel::selectBtnClicked()
{
    Sudoku *p = (Sudoku *)parent();
    if(ui->easy->isChecked()){
        p->setVal(1);
    }
    if(ui->medium->isChecked()){
        p->setVal(2);
    }
    if(ui->hard->isChecked()){
        p->setVal(3);
    }
    this->close();
}
