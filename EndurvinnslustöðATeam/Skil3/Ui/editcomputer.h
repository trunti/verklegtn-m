#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>
#include "Services/computerservice.h"
#include <vector>
#include <iostream>

namespace Ui {
class EditComputer;
}

class EditComputer : public QDialog
{
    Q_OBJECT

public:
    explicit EditComputer(QWidget *parent = 0);
    ~EditComputer();
    void CompToEdit(int chosen, string order, bool ASC);    // Finna hvaða tölvu á að edita.

private slots:
    void on_Button_edit_clicked();                          // Fundið tölvu ID og breytt þeirri tölvu í gagnagrunni.
    void on_Button_back_clicked();
    void on_Button_exit_clicked();

private:
    vector<Computer> Edit;
    Computerservice compservice;
    Ui::EditComputer *ui;
};

#endif // EDITCOMPUTER_H
