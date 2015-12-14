#include "addcomputer.h"
#include "ui_addcomputer.h"

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

    }
}
