#ifndef SHOWSCORES_H
#define SHOWSCORES_H

#include <QWidget>
#include <vector>
#include "gameData.h"


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
    QWidget *centralWid;

    void getAndPrintScores();
    std::vector<GameData<QString>> readFile(QString filename);
    void showFileContents(QString widgetName, std::vector<GameData<QString>> data);
};

#endif // SHOWSCORES_H
