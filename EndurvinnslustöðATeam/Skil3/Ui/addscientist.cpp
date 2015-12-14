#include "addscientist.h"
#include "ui_addscientist.h"

addscientist::addscientist(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::addscientist)
{
    ui->setupUi(this);
}

addscientist::~addscientist()
{
    delete ui;
}

void addscientist::on_pushButton_add_clicked()
{
    QString name = ui->input_name->text();
    QString gender = ui->input_gender->text();
    QString yearBorn = ui->input_birth_year->text();
    QString yearDeath = ui->input_death_year->text();

    if(name.isEmpty() || gender.isEmpty() || yearBorn.isEmpty() || yearDeath.isEmpty())
    {
        return;
    }
    bool success = scientistService.addScientist(Scientist(name.toStdString(), gender.toStdString(), yearBorn.toInt(), yearDeath.toInt()));

    if(success)
    {
        ui->input_name->setText("");
        ui->input_gender->setText("");
        ui->input_birth_year->setText("");
        ui->input_death_year->setText("");
    }
    else
    {

    }

}
