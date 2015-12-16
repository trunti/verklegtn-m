#include "editscientist.h"
#include "ui_editscientist.h"
#include <QMessageBox>

EditScientist::EditScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditScientist)
{
    ui->setupUi(this);
    ui->input_name->setText("");
    ui->input_gender->setText("");
    ui->input_birth_year->setText("");
    ui->input_death_year->setText("");
}
EditScientist::~EditScientist()
{
    delete ui;
}

void EditScientist::SetWhoToEdit(int Chosen)
{
    QString alive = "Alive!";
    ui->table_scientists->clearContents();
    bool yes = true;
    EditScient = scientistservice.getAllScientists("pname", yes);

    ui->table_scientists->setRowCount(1);
    int row = 0;
    Scientist currentScientist = EditScient.at(Chosen);

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



void EditScientist::on_Button_Update_clicked()
{
    QString str;
    QTableWidgetItem* itm = ui->table_scientists->item( 0, 0 );
    str = itm->text();
    string Sciname = str.toStdString();
    int ID;
    bool yes = true;

    EditScient = scientistservice.getAllScientists("pname", yes);
    for (unsigned int i = 0; i < EditScient.size(); i++)
    {
        Scientist currentScientist = EditScient.at(i);
        if(Sciname == currentScientist.getName()){
            ID = currentScientist.getID();
        }
    }
    QString name = ui->input_name->text();
    QString gender = ui->input_gender->text();
    QString yearBorn = ui->input_birth_year->text();
    QString yearDeath = ui->input_death_year->text();

    scientistservice.UpdateScientist("pname",name.toStdString(),ID);
    scientistservice.UpdateScientist("gender",gender.toStdString(),ID);
    scientistservice.UpdateScientist("born",yearBorn.toStdString(),ID);
    scientistservice.UpdateScientist("died",yearDeath.toStdString(),ID);

    int answer = QMessageBox::question(this, "Confirm", "Are you sure");
    if(answer == QMessageBox::No)
    {
        return;
    }
    this->done(0);

}
