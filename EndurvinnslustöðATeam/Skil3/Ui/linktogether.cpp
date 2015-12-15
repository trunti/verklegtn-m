#include "linktogether.h"
#include "ui_linktogether.h"

LinkTogether::LinkTogether(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LinkTogether)
{
    ui->setupUi(this);
    displayAllScientists();
    displayAllComputers();
    DisplayRelation();
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

void LinkTogether::DisplayRelation()
{
    ui->table_relation->clearContents();
    vector<Links> links = linkService.Relation();

    ui->table_relation->setRowCount(links.size());

    for(unsigned int i = 0; i < links.size();i++){
        QString sname = QString::fromStdString(links[i].sciname);
        QString cname = QString::fromStdString(links[i].compname);

        ui->table_relation->setItem(i, 0, new QTableWidgetItem(sname));
        ui->table_relation->setItem(i, 1, new QTableWidgetItem(cname));
    }

}

/*void LinkTogether::on_button_link_clicked()
{
    int selectedSciIndex = ui->list_scient->currentIndex();
    int selectedCompIndex = ui->list_comp->currentIndex();
    Scientist selectedSci = currentlyDisplayedScientist.at(selectedSciIndex);

    if(success)
    {
        int answer = QMessageBox::question(this, "Confirm", "Are you sure");
        if(answer == QMessageBox::No)
            return;
        displayAllScientists();
        ui->Button_remove_sci->setEnabled(false);

    }
    else
    {
        QMessageBox::warning(this, "Error", "Remove faild!");
    }
}*/
