#include "computerdisplay.h"
#include "ui_computerdisplay.h"
#include <QMessageBox>
ComputerDisplay::ComputerDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerDisplay)
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

ComputerDisplay::~ComputerDisplay()
{
    delete ui;
}
void ComputerDisplay::displayAllComputers()
{
    vector<Computer> computer = computerService.getAllComputers(GetOrderBy(), orderByAscending());
    displayComputers(computer);
}

void ComputerDisplay::displayComputers(vector<Computer> computer)
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
bool ComputerDisplay::orderByAscending()
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

void ComputerDisplay::on_dropdown_order_by_currentIndexChanged(int index)
{
    on_Search_window_textChanged("");
}

string ComputerDisplay::GetOrderBy()
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
void ComputerDisplay::on_Search_window_textChanged(const QString &arg1)
{
    string Input = ui->Search_window->text().toStdString();

    vector<Computer> comp = computerService.searchComputers(Input, GetOrderBy(), orderByAscending());
    displayComputers(comp);
}
void ComputerDisplay::on_dropdown_order_by_ascending_activated(const QString &arg1)
{
    on_Search_window_textChanged("");
}

void ComputerDisplay::on_table_computer_clicked(const QModelIndex &index)
{
    ui->Button_remove_comp->setEnabled(true);
}

void ComputerDisplay::on_Button_remove_comp_clicked()
{
    int selectedComputerIndex = ui->table_computer->currentIndex().row();
    Computer selectedComputer = currentlyDisplayedComputer.at(selectedComputerIndex);
    bool success = computerService.removeComputer(selectedComputer);
    if(success)
    {
        displayAllComputers();
        ui->Button_remove_comp->setEnabled(false);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Remove faild!");
    }
}
