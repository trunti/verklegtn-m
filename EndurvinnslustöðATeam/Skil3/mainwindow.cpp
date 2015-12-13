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
        Scientist currentScientist = scientist.at(row);

        QString name = QString::fromStdString(currentScientist.getName());
        QString gender = QString::fromStdString(currentScientist.getGender());
        QString byear = QString::number(currentScientist.getByear());
        QString dyear = QString::number(currentScientist.getDyear());

        ui->table_scientists->setItem(row, 0, new QTableWidgetItem(name));
        ui->table_scientists->setItem(row, 1, new QTableWidgetItem(gender));
        ui->table_scientists->setItem(row, 2, new QTableWidgetItem(byear));
        ui->table_scientists->setItem(row, 3, new QTableWidgetItem(dyear));
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
    ui->table_computer->clearContents();
    ui->table_computer->setRowCount(computer.size());

    for(unsigned int row = 0;row < computer.size();row++)
    {
        Computer currentComputer = computer.at(row);

        QString name = QString::fromStdString(currentComputer.getName());
        QString year = QString::number(currentComputer.getYear());
        QString type = QString::fromStdString(currentComputer.getType());
        QString wasbuilt = QString::number(currentComputer.getWasbuilt());

        ui->table_computer->setItem(row, 0, new QTableWidgetItem(name));
        ui->table_computer->setItem(row, 1, new QTableWidgetItem(year));
        ui->table_computer->setItem(row, 2, new QTableWidgetItem(type));
        ui->table_computer->setItem(row, 3, new QTableWidgetItem(wasbuilt));
    }
    currentlyDisplayedComputer = computer;
}
