#include "linktogether.h"
#include "ui_linktogether.h"
#include <QMessageBox>
#include <iostream>
#include <sstream>

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
    ui->table_scient->clearContents();
    ui->table_scient->setRowCount(scientName.size());

    for(unsigned int i = 0;i < scientName.size();i++)
    {
        Scientist currentScient = scientName[i];
        QString name = QString::fromStdString(currentScient.getName());

        ui->table_scient->setItem(i,0,new QTableWidgetItem(name));

    }
}
void LinkTogether::displayAllComputers()
{
    compName = computerService.getAllComputers("Name", true);
    DisplayCompName(compName);
}
void LinkTogether::DisplayCompName(vector<Computer> compName)
{
    ui->table_comp->clearContents();
    ui->table_comp->setRowCount(compName.size());

    for(unsigned int i = 0;i < compName.size();i++)
    {
        Computer currentComp = compName[i];
        QString name = QString::fromStdString(currentComp.getName());

        ui->table_comp->setItem(i,0,new QTableWidgetItem(name));
    }
}

void LinkTogether::DisplayRelation()
{
    ui->table_relation->clearContents();
    vector<Links> links = linkService.Relation();

    ui->table_relation->setRowCount(links.size());

    for(unsigned int i = 0; i < links.size();i++)
    {
        QString sname = QString::fromStdString(links[i].sciname);
        QString cname = QString::fromStdString(links[i].compname);

        ui->table_relation->setItem(i, 0, new QTableWidgetItem(sname));
        ui->table_relation->setItem(i, 1, new QTableWidgetItem(cname));
    }

}
void LinkTogether::on_button_link_clicked()
{
    int selectedSciIndex = ui->table_scient->currentIndex().row();
    int selectedCompIndex = ui->table_comp->currentIndex().row();

    if(selectedCompIndex < 0 || selectedCompIndex > compName.size() || selectedSciIndex < 0 || selectedSciIndex > scientName.size())
    {
        QMessageBox::warning(this, "Oops!!", "Choose from both tables!");
        return;
    }
    Scientist scient = scientName[selectedSciIndex];
    int SciID = scient.getID();
    Computer comp = compName[selectedCompIndex];
    int CompID = comp.getID();

    ostringstream ss,aa;
    ss << SciID;
    string SID = ss.str();

    aa << CompID;
    string CID = aa.str();

    bool success = linkService.addLink(SID,CID);

    if(success)
    {
        int answer = QMessageBox::question(this, "Confirm", "Are you sure");
        if(answer == QMessageBox::No)
            return;
        DisplayRelation();

    }
    else
    {
        QMessageBox::warning(this, "Error", "Adding a link failed!");
    }
}

void LinkTogether::on_table_relation_clicked(const QModelIndex &index)
{
    ui->button_remove_link->setEnabled(true);
}

void LinkTogether::on_button_remove_link_clicked()
{
    int selectedId = ui->table_relation->currentIndex().row();
    selectedId = selectedId + 1;

    ostringstream ss;

    ss << selectedId;
    string RowId = ss.str();

    bool success = linkService.removeLink(RowId);

    if(success)
    {
        int answer = QMessageBox::question(this, "Confirm", "Are you sure");
        if(answer == QMessageBox::No)
            return;
        DisplayRelation();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Remove failed!");
    }
}
