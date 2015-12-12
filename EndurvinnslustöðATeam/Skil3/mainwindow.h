#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Services/scientistservice.h"
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

    Scientistservice scientistService;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
