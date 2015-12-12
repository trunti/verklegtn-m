#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllScientists();
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
    ui->table_scientists->clearContents();

    ui->table_scientists->setRowCount(scientist.size());

    for (unsigned int row = 0; row < scientist.size(); row++)
    {
        Scientist currentScientist = scientist[row];

        QString name = QString::fromStdString(currentScientist.getName());
        QString gender = QString::fromStdString(currentScientist.getGender());

        ui->table_scientists->setItem(row, 0, new QTableWidgetItem(name));
        ui->table_scientists->setItem(row, 1, new QTableWidgetItem(gender));
        ui->table_scientists->setItem(row, 2, new QTableWidgetItem(currentScientist.getByear()));
        ui->table_scientists->setItem(row, 3, new QTableWidgetItem(currentScientist.getDyear()));
    }

    currentlyDisplayedScientist = scientist;
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
        ui->list_scient->addItem(QString::number(currentComputer.getYear()));
    }
}
