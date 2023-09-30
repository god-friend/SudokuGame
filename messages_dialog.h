#ifndef MESSAGES_DIALOG_H
#define MESSAGES_DIALOG_H

#include <QDialog>

namespace Ui {
class messages_dialog;
}

class messages_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit messages_dialog(QWidget *parent = nullptr);
    ~messages_dialog();

    void singleBtnMessage(QString title, QString message);


private:
    Ui::messages_dialog *ui;
    void setTitle(QString title);
    void setMessage(QString message);
};

#endif // MESSAGES_DIALOG_H
