#ifndef INPUTBTNWIDGET_H
#define INPUTBTNWIDGET_H

#include <QWidget>
#include <QPaintEvent>


#define UP 1
#define DOWN 2


class InputBtnWidget: public QWidget
{
    Q_OBJECT

public:
    InputBtnWidget(QWidget *parent=nullptr);

    void createAtPosition(int pos, QRect rect);

private slots:
    void clickedBtn();

private:
    int height;
    int width;
    int widPosition;

    QString btnStyle;


    void initializeStyle();
    void paintEvent(QPaintEvent *event);
    void printButtons();


};

#endif // INPUTBTNWIDGET_H
