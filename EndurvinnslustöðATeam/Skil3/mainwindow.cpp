#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->dropdown_order_by->addItem("Name");
    ui->dropdown_order_by->addItem("Gender");
    ui->dropdown_order_by->addItem("Birth Year");
    ui->dropdown_order_by->addItem("Death Year");

    ui->dropdown_order_by_ascending->addItem("Ascending");
    ui->dropdown_order_by_ascending->addItem("Descending");

    displayAllScientists();
    displayAllComputers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()
{
    vector<Scientist> scientist = scientistService.getAllScientists(GetOrderBy(), orderByAscending());
    displayScientists(scientist);
}

void MainWindow::displayScientists(vector<Scientist> scientist)
{
    QString alive = "Alive!";
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
        if(dyear == "2016")
        {
            ui->table_scientists->setItem(row, 3, new QTableWidgetItem(alive));
        }
        else
        {
            ui->table_scientists->setItem(row, 3, new QTableWidgetItem(dyear));
        }
    }

    currentlyDisplayedScientist = scientist;
}

void MainWindow::displayAllComputers()
{
    vector<Computer> computer = computerService.getAllComputers(GetOrderBy(), orderByAscending());
    displayComputers(computer);
}

void MainWindow::displayComputers(vector<Computer> computer)
{
    ui->table_computer->clearContents();
    ui->table_computer->setRowCount(computer.size());

    for(unsigned int row = 0;row < computer.size();row++)
    {
        QString notbuilt = "Not built!";
        QString built = "Yes!";
        Computer currentComputer = computer.at(row);

        QString name = QString::fromStdString(currentComputer.getName());
        QString year = QString::number(currentComputer.getYear());
        QString type = QString::fromStdString(currentComputer.getType());
        QString wasbuilt = QString::number(currentComputer.getWasbuilt());

        ui->table_computer->setItem(row, 0, new QTableWidgetItem(name));
        ui->table_computer->setItem(row, 2, new QTableWidgetItem(type));
        if(year == "0" && wasbuilt == "0")
        {
            ui->table_computer->setItem(row, 1, new QTableWidgetItem(notbuilt));
            ui->table_computer->setItem(row, 3, new QTableWidgetItem(notbuilt));
        }
        else
        {
            ui->table_computer->setItem(row, 1, new QTableWidgetItem(year));
            ui->table_computer->setItem(row, 3, new QTableWidgetItem(built));
        }
    }
    currentlyDisplayedComputer = computer;
}

bool MainWindow::orderByAscending()
{
    string AscText = ui->dropdown_order_by_ascending->currentText().toStdString();

    if(AscText == "Ascending")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MainWindow::on_dropdown_order_by_currentIndexChanged(int index)
{
    on_Search_window_textChanged("");
}

string MainWindow::GetOrderBy()
{
    string CurrentOrderWanted = ui->dropdown_order_by->currentText().toStdString();

    if(CurrentOrderWanted == "Name")
    {
        return "pName";
    }
    else if(CurrentOrderWanted == "Gender")
    {
        return "Gender";
    }
    else if(CurrentOrderWanted == "Birth Year")
    {
        return "Born";
    }
    else if(CurrentOrderWanted == "Death Year")
    {
        return "Died";
    }
    return "pName";
}

void MainWindow::on_Search_window_textChanged(const QString &arg1)
{
    string Input = ui->Search_window->text().toStdString();

    vector<Scientist> scientist = scientistService.searchScientists(Input, GetOrderBy(), orderByAscending());
    displayScientists(scientist);
}

void MainWindow::on_dropdown_order_by_ascending_activated(const QString &arg1)
{
    on_Search_window_textChanged("");
}
