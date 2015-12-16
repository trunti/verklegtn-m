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
    void SetWhoToEdit(int Chosen);

private slots:
    void on_Button_Update_clicked();

private:
    void Edit();
    vector<Scientist> EditScient;
    Scientistservice scientistservice;
    Ui::EditScientist *ui;
};

#endif // EDITSCIENTIST_H
