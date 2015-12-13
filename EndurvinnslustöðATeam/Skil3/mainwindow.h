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

private slots:
    void on_dropdown_order_by_currentIndexChanged(int index);

    void on_Search_window_textChanged(const QString &arg1);

    void on_dropdown_order_by_ascending_activated(const QString &arg1);

private:
    string GetOrderBy();
    void displayAllScientists();
    void displayScientists(vector<Scientist> scientist);
    void displayAllComputers();
    void displayComputers(vector<Computer> computer);
    bool orderByAscending();

    Scientistservice scientistService;
    Computerservice computerService;

    Ui::MainWindow *ui;

    vector<Scientist> currentlyDisplayedScientist;
    vector<Computer> currentlyDisplayedComputer;
};

#endif // MAINWINDOW_H
