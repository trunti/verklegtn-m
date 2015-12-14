#include "random.h"
#include "ui_random.h"

Random::Random(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Random)
{
    ui->setupUi(this);
}

Random::~Random()
{
    delete ui;
}

void Random::on_Button_get_random_scient_clicked()
{
    vector<Scientist> scient = scientistService.RandomScientist();
    displayScientists(scient);
}

void Random::on_Button_get_random_comp_clicked()
{
    vector<Computer> comp = computerService.RandomComputer();
    displayComputers(comp);
}
void Random::displayScientists(vector<Scientist> scientist)
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
void Random::displayComputers(vector<Computer> computer)
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
