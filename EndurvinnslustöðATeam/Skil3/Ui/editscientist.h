#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include <QDialog>
#include "Services/scientistservice.h"
#include <vector>
#include <iostream>

using namespace std;

namespace Ui {
class EditScientist;
}

class EditScientist : public QDialog
{
    Q_OBJECT

public:
    explicit EditScientist(QWidget *parent = 0);
    ~EditScientist();
    void SetWhoToEdit(int Chosen,string order,bool ASC);//sett hvern á að edita inn í töflu

private slots:
    void on_Button_Update_clicked();//þegar er ýtt á takkan er farið í það að finna ID á scientistinum og breyta því sem notenda vill í gagnagrunni

    void on_Button_back_clicked();

    void on_Button_exit_clicked();

private:
    vector<Scientist> EditScient;
    Scientistservice scientistservice;
    Ui::EditScientist *ui;
};

#endif // EDITSCIENTIST_H
