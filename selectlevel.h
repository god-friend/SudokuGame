#ifndef SELECTLEVEL_H
#define SELECTLEVEL_H

#include <QDialog>

namespace Ui {
class selectLevel;
}

class selectLevel : public QDialog
{
    Q_OBJECT

public:
    explicit selectLevel(QWidget *parent = nullptr);
    ~selectLevel();

private slots:
    void selectBtnClicked();

private:
    Ui::selectLevel *ui;
    void markLevel();
};

#endif // SELECTLEVEL_H
