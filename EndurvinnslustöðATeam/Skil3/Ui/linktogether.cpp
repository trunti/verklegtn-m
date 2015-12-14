#include "linktogether.h"
#include "ui_linktogether.h"

LinkTogether::LinkTogether(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LinkTogether)
{
    ui->setupUi(this);
    displayAllScientists();
    displayAllComputers();
}

LinkTogether::~LinkTogether()
{
    delete ui;
}
void LinkTogether::displayAllScientists()
{
    scientName = scientistService.getAllScientists("pName", true);
    DisplayScientName(scientName);
}
void LinkTogether::DisplayScientName(vector<Scientist> scientName)
{
    ui->list_scient->clear();

    for(unsigned int i = 0;i < scientName.size();i++)
    {
        Scientist currentScient = scientName[i];

        ui->list_scient->addItem(QString::fromStdString(currentScient.getName()));

    }
}
void LinkTogether::displayAllComputers()
{
    compName = computerService.getAllComputers("Name", true);
    DisplayCompName(compName);
}
void LinkTogether::DisplayCompName(vector<Computer> compName)
{
    ui->list_comp->clear();

    for(unsigned int i = 0;i < compName.size();i++)
    {
        Computer currentComp = compName[i];

        ui->list_comp->addItem(QString::fromStdString(currentComp.getName()));
    }
}
