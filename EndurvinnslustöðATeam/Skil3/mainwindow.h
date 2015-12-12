#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Services/scientistservice.h"
#include "Services/computerservice.h"
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

private:
    void displayAllScientists();
    void displayScientists(vector<Scientist> scientist);
    void displayAllComputers();
    void displayComputers(vector<Computer> computer);

    Scientistservice scientistService;
    Computerservice computerService;

    Ui::MainWindow *ui;

    vector<Scientist> currentlyDisplayedScientist;
};

#endif // MAINWINDOW_H
