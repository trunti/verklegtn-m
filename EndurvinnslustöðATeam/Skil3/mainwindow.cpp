#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dropdown_order_by->addItem("Name");
    ui->dropdown_order_by->addItem("Build year");
    ui->dropdown_order_by->addItem("Type");
    ui->dropdown_order_by->addItem("Built");

    ui->dropdown_order_by_ascending->addItem("Ascending");
    ui->dropdown_order_by_ascending->addItem("Descending");

    displayAllComputers();
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_Button_Scientist_clicked()
{
    ScientistsDisplay scientdisplay;
    scientdisplay.exec();
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
        return "Name";
    }
    else if(CurrentOrderWanted == "Build year")
    {
        return "Year";
    }
    else if(CurrentOrderWanted == "Type")
    {
        return "Type";
    }
    else if(CurrentOrderWanted == "Built")
    {
        return "Build";
    }
    return "Name";
}
void MainWindow::on_Search_window_textChanged(const QString &arg1)
{
    string Input = ui->Search_window->text().toStdString();

    vector<Computer> comp = computerService.searchComputers(Input, GetOrderBy(), orderByAscending());
    displayComputers(comp);
}
void MainWindow::on_dropdown_order_by_ascending_activated(const QString &arg1)
{
    on_Search_window_textChanged("");
}
