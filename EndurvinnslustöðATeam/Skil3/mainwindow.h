#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Services/scientistservice.h"
#include "Services/computerservice.h"
#include "Ui/scientistsdisplay.h"
#include "Ui/computerdisplay.h"
#include "Ui/random.h"
#include "Ui/linktogether.h"
#include <vector>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_Button_Scientist_clicked();

    void on_Buttin_Computer_clicked();

    void on_Button_Random_clicked();

    void on_Button_link_clicked();

private:
    string GetOrderBy();
    void displayAllScientists();
    void displayScientists(vector<Scientist> scientist);
    void displayAllComputers();
    void displayComputers(vector<Computer> computer);
    bool orderByAscending();


    Ui::MainWindow *ui;

    vector<Scientist> currentlyDisplayedScientist;
    vector<Computer> currentlyDisplayedComputer;
};

#endif // MAINWINDOW_H
