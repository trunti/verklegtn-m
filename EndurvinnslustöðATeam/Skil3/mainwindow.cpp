#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllScientists();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()
{
    vector<Scientist> scientist = scientistService.getAllScientists("pName", true);
    displayScientists(scientist);
}

void MainWindow::displayScientists(vector<Scientist> scientist)
{
    ui->list_scient->clear();

    for(unsigned int i = 0; i < scientist.size(); i++)
    {
        Scientist currentScientist = scientist[i];

        ui->list_scient->addItem(QString::fromStdString(currentScientist.getName()));
    }

}
