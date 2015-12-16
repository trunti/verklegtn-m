#ifndef RANDOM_H
#define RANDOM_H

#include <QDialog>
#include "Services/scientistservice.h"
#include "Services/computerservice.h"
#include <vector>
#include <string>

namespace Ui {
class Random;
}

class Random : public QDialog
{
    Q_OBJECT

public:
    explicit Random(QWidget *parent = 0);
    ~Random();

private slots:
    void on_Button_get_random_scient_clicked();
    void on_Button_get_random_comp_clicked();
    void on_Button_back_clicked();
    void on_Button_exit_clicked();

private:
    void displayAllScientists();                            // Nær í alla scientista og setur inn í næsta fall sem setur inn í töflu
    void displayScientists(vector<Scientist> scientist);
    void displayAllComputers();                             // Sama of fyrir ofan nema með tölvur
    void displayComputers(vector<Computer> computer);
    Computerservice computerService;
    vector<Computer> currentlyDisplayedComputer;
    Scientistservice scientistService;
    vector<Scientist> currentlyDisplayedScientist;
    Ui::Random *ui;
};

#endif // RANDOM_H
