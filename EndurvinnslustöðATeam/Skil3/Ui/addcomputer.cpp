#include "addcomputer.h"
#include "ui_addcomputer.h"
#include <QMessageBox>
addcomputer::addcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcomputer)
{
    ui->setupUi(this);
}

addcomputer::~addcomputer()
{
    delete ui;
}

void addcomputer::on_pushButton_clicked()
{
    QString name = ui->input_name->text();
    QString year = ui->input_year->text();
    QString type = ui->input_type->text();
    QString wasbuilt = ui->input_wasbuilt->text();

    ui->error_name->setText("");
    ui->error_year->setText("");
    ui->error_type->setText("");
    ui->error_built->setText("");



    if(name.isEmpty())
    {
        ui->error_name->setText("<span style='color:red'>Name cannot be empty</span>");
        return;
    }
    if(year.isEmpty())
    {
        ui->error_year->setText("<span style='color:red'>Year cannot be empty</span>");
        return;
    }
    if(type.isEmpty())
    {
        ui->error_type->setText("<span style='color:red'>Type cannot be empty</span>");
        return;
    }
    if(wasbuilt.isEmpty())
    {
        ui->error_built->setText("<span style='color:red'>Built cannt be empty</span>");
        return;
    }

    if(year < "1600" || year > "2015")
    {
        QMessageBox::warning(this, "Error", "Year is wrong");
        return;
    }

    if((type != "Transitor") && (type != "transitor") && (type != "Electronic") && (type != "electronic") && (type != "Electronic - mechanical") && (type != "electronic - mechanical") && (type != "mechanical") && (type != "Mechanical") && (type != "Other") && (type != "other"))
    {
        QMessageBox::warning(this, "Error", "This is not a type of computer");
        return;
    }

    if((wasbuilt != "yes") && (wasbuilt != "Yes") && (wasbuilt != "no") && (wasbuilt != "No"))
    {
        QMessageBox::warning(this, "Error", "Answer yes or no");
        return;
    }

    if((wasbuilt == "yes") || (wasbuilt == "Yes"))
    {
        wasbuilt = "1";
    }
    else
    {
        wasbuilt = "0";
    }

    int answer = QMessageBox::question(this, "Confirm", "Are you sure");
    if(answer == QMessageBox::No)
    {
        return;
    }

    bool success = computerService.addComputer(Computer(name.toStdString(), year.toInt(), type.toStdString(), wasbuilt.toInt()));

    if(success)
    {
        ui->input_name->setText("");
        ui->input_year->setText("");
        ui->input_type->setText("");
        ui->input_wasbuilt->setText("");

    }
    else
    {
        ui->input_name->setText("");
        ui->input_year->setText("");
        ui->input_type->setText("");
        ui->input_wasbuilt->setText("");
    }
    this->done(0);
}

void addcomputer::on_Button_back_clicked()
{
    close();
}

void addcomputer::on_Button_exit_clicked()
{
    exit(1);
}
