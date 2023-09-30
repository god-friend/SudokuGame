#ifndef SHOWSCORES_H
#define SHOWSCORES_H

#include <QWidget>
#include "maingame.h"
#include <vector>

namespace Ui {
class showScores;
}

class showScores : public QWidget
{
    Q_OBJECT

public:
    explicit showScores(QWidget *parent = nullptr);
    ~showScores();

private slots:
    void goBack();

private:
    Ui::showScores *ui;
    Sudoku *p;
    QWidget *centralWid;

    void getAndPrintScores();
    std::vector<GameData> readFile(QString filename);
    void showFileContents(QString widgetName, std::vector<GameData> data);
};

#endif // SHOWSCORES_H
