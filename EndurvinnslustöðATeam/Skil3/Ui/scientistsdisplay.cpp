#include "scientistsdisplay.h"
#include "ui_scientistsdisplay.h"

ScientistsDisplay::ScientistsDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScientistsDisplay)
{
    ui->setupUi(this);

    ui->dropdown_order_by->addItem("Name");
    ui->dropdown_order_by->addItem("Gender");
    ui->dropdown_order_by->addItem("Birth Year");
    ui->dropdown_order_by->addItem("Death Year");

    ui->dropdown_order_by_ascending->addItem("Ascending");
    ui->dropdown_order_by_ascending->addItem("Descending");

    displayAllScientists();
}

ScientistsDisplay::~ScientistsDisplay()
{
    delete ui;
}

void ScientistsDisplay::displayAllScientists()
{
    vector<Scientist> scientist = scientistService.getAllScientists(GetOrderBy(), orderByAscending());
    displayScientists(scientist);
}

void ScientistsDisplay::displayScientists(vector<Scientist> scientist)
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

bool ScientistsDisplay::orderByAscending()
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

void ScientistsDisplay::on_dropdown_order_by_currentIndexChanged(int index)
{
    on_Search_window_textChanged("");
}

string ScientistsDisplay::GetOrderBy()
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

void ScientistsDisplay::on_Search_window_textChanged(const QString &arg1)
{
    string Input = ui->Search_window->text().toStdString();

    vector<Scientist> scientist = scientistService.searchScientists(Input, GetOrderBy(), orderByAscending());
    displayScientists(scientist);
}

void ScientistsDisplay::on_dropdown_order_by_ascending_activated(const QString &arg1)
{
    on_Search_window_textChanged("");
}
