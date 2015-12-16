#include "addscientist.h"
#include "ui_addscientist.h"
#include <QMessageBox>

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

    ui->error_name->setText("");
    ui->error_gender->setText("");
    ui->error_yearB->setText("");
    ui->error_yearD->setText("");

    if(name.isEmpty())
    {
        ui->error_name->setText("<span style='color:red'>Name cannot be empty</span>");
        return;
    }
    if(gender.isEmpty())
    {
        ui->error_gender->setText("<span style='color:red'>Gender cannot be empty</span>");
        return;
    }
    if(yearBorn.isEmpty())
    {
        ui->error_yearB->setText("<span style='color:red'>Birth year cannot be empty</span>");
        return;
    }

    if((gender != "Male") && (gender != "male") && (gender != "Female") && (gender != "female"))
    {
        QMessageBox::warning(this, "Error", "Gender is wrong");
        return;
    }

    if(yearDeath > "2015")
    {
        QMessageBox::warning(this, "Error", "Year of death is wrong");
        return;
    }

    if(yearBorn < "1500" || yearBorn >"2000")
    {
        QMessageBox::warning(this,"Error", "Birth year is wrong");
        return;
    }

    if((yearDeath < yearBorn) && !yearDeath.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Death year or birth year are wrong");
        return;
    }

    int answer = QMessageBox::question(this, "Confirm", "Are you sure");
    if(answer == QMessageBox::No)
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
        ui->input_name->setText("");
        ui->input_gender->setText("");
        ui->input_birth_year->setText("");
        ui->input_death_year->setText("");
    }
    this->done(0);
}
