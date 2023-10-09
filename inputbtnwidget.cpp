#include "maingame.h"
#include <QPainter>
#include <QPen>
#include <QGridLayout>

InputBtnWidget::InputBtnWidget(QWidget *parent): QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    height = 120;
    width = 120;
    widPosition = -1;
    initializeStyle();
}

void InputBtnWidget::initializeStyle(){
    btnStyle = "QPushButton{"
               "color: rgb(0,0,0);"
               "background-color: rgb(255,255,255);"
               "border-radius: 10px;"
               "border-width: 2px;"
               "border-style: solid;"
               "border-color: rgb(0,0,0);"
               "}"
               "QPushButton:hover{"
               "background-color: rgb(154, 184, 235);"
               "}"
               "QPushButton:pressed{"
               "background-color: rgb(201, 125, 245);"
               "}";
}

void InputBtnWidget::printButtons(){
    QSize btnSize = QSize(30, 30);
    QGridLayout *grid = new QGridLayout(this);
    QPushButton *buttons[9];
    int n = 1;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            buttons[i] = new QPushButton();
            buttons[i]->setText(QString::number(n));
            buttons[i]->setStyleSheet("color: rgb(0,0,0);");
            buttons[i]->setStyleSheet(btnStyle);
            buttons[i]->setFixedSize(btnSize);
            connect(buttons[i], SIGNAL(clicked(bool)), this, SLOT(clickedBtn()));
            n++;

            grid->addWidget(buttons[i], i, j);
        }
    }


    if(widPosition == UP){
        grid->setContentsMargins(10,10,10,15);
    }else if(widPosition == DOWN){
        grid->setContentsMargins(10,15,10,10);
    }

    this->setLayout(grid);
}

void InputBtnWidget::clickedBtn(){
    QPushButton *btn = qobject_cast<QPushButton*> (sender());
    mainGame *parent = qobject_cast<mainGame*>(this->parentWidget());

    parent->changeBtnValue(btn->text().toInt());

    this->close();
}

void InputBtnWidget::createAtPosition(int pos, QRect rect){

    QRect widRect = rect;
    QPoint centerPoint = rect.center();
    int xCenter = centerPoint.x() - (width / 2);

    if(pos == UP){
        widPosition = UP;

        widRect.setX(xCenter);
        widRect.setY(rect.y() - height);
    }else if(pos == DOWN){
        widPosition = DOWN;

        widRect.setX(xCenter);
        widRect.setY(rect.height() + rect.y());
    }

    widRect.setHeight(height);
    widRect.setWidth(width);

    this->setGeometry(widRect);

    printButtons();
}

void InputBtnWidget::paintEvent(QPaintEvent *event){
    if(widPosition == -1){
        qDebug() << "Please provide position and rect with .createAtPosition() method";
        this->close();
        return;
    }

    QRect widRect = this->geometry();
    QPainter painter(this);
    QPen pen;

    pen.setWidth(5);
    pen.setColor(Qt::black);

    painter.setPen(pen);

    int startX = 1;
    int startY = 1;
    int rectHeight = 1;
    int rectWidth = 1;
    int center = 0;

    if(widPosition == UP){
        startX = 2;
        startY = 2;
        center = widRect.width() / 2;
        rectHeight = widRect.height() - 10;
        rectWidth = widRect.width() - 4;



        painter.drawLine(center-4, rectHeight+3, center, rectHeight+7);
        painter.drawLine(center+4, rectHeight+3, center, rectHeight+7);

    }else if(widPosition == DOWN){

        startX = 2;
        startY = 8;
        center = widRect.width() / 2;
        rectHeight = widRect.height() - 10;
        rectWidth = widRect.width() - 4;


        painter.drawLine(center, 3, center-4, 7);
        painter.drawLine(center, 3, center+4, 7);

    }

    QRect rect;
    rect.setX(startX);
    rect.setY(startY);
    rect.setWidth(rectWidth);
    rect.setHeight(rectHeight);

    painter.drawRect(rect);
    painter.fillRect(rect, QGradient::MountainRock);

    event->accept();
}
