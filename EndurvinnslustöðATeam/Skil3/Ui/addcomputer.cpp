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

    if(name.isEmpty() || year.isEmpty() || type.isEmpty() || wasbuilt.isEmpty())
    {
        return;
    }
    bool success = computerService.addComputer(Computer(name.toStdString(), year.toInt(), type.toStdString(), wasbuilt.toInt));

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
