#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //displayAllScientists();
    displayAllComputers();
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

void MainWindow::displayAllComputers()
{
    vector<Computer> computer = computerService.getAllComputers("Name", true);
    displayComputers(computer);
}

void MainWindow::displayComputers(vector<Computer> computer)
{
    ui->list_scient->clear();

    for(unsigned int i = 0;i < computer.size();i++)
    {
        Computer currentComputer = computer[i];

        ui->list_scient->addItem(QString::fromStdString(currentComputer.getName()));
    }
}
