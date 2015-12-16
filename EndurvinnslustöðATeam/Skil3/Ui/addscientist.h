#ifndef ADDSCIENTIST_H
#define ADDSCIENTIST_H

#include <QDialog>
#include "Services/scientistservice.h"

namespace Ui {
class addscientist;
}

class addscientist : public QDialog
{
    Q_OBJECT

public:
    explicit addscientist(QDialog *parent = 0);
    ~addscientist();

private slots:
    void on_pushButton_add_clicked();//þegar ýtt er á add fer villumelding afstað og addar ef allt er löglegt

    void on_Button_back_clicked();

    void on_Button_exit_clicked();

private:
    Scientistservice scientistService;
    Ui::addscientist *ui;
};

#endif // ADDSCIENTIST_H
