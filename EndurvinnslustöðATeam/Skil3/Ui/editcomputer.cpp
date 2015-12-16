#include "editcomputer.h"
#include "ui_editcomputer.h"
#include <QMessageBox>

EditComputer::EditComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditComputer)
{
    ui->setupUi(this);
}

EditComputer::~EditComputer()
{
    delete ui;
}

void EditComputer::CompToEdit(int chosen,string order,bool ASC)
{
    Edit = compservice.getAllComputers(order,ASC);

    ui->table_computer->clearContents();
    ui->table_computer->setRowCount(1);

    QString notbuilt = "Not built!";
    QString built = "Yes!";
    Computer currentComputer = Edit.at(chosen);

    QString name = QString::fromStdString(currentComputer.getName());
    QString year = QString::number(currentComputer.getYear());
    QString type = QString::fromStdString(currentComputer.getType());
    QString wasbuilt = QString::number(currentComputer.getWasbuilt());

    ui->table_computer->setItem(0, 1, new QTableWidgetItem(year));
    ui->table_computer->setItem(0, 0, new QTableWidgetItem(name));
    ui->table_computer->setItem(0, 2, new QTableWidgetItem(type));
    if(wasbuilt == "0")
    {
        ui->table_computer->setItem(0, 3, new QTableWidgetItem(notbuilt));
    }
    else
    {
        ui->table_computer->setItem(0, 3, new QTableWidgetItem(built));
    }
}

void EditComputer::on_Button_edit_clicked()
{
    QString str;
    QTableWidgetItem* itm = ui->table_computer->item( 0, 0 );
    str = itm->text();
    string Compname = str.toStdString();

    int ID;

    for (unsigned int i = 0; i < Edit.size(); i++)
    {
        Computer currentComputer = Edit.at(i);
        if(Compname == currentComputer.getName()){
            ID = currentComputer.getID();
        }
    }

    QString name = ui->input_name->text();
    QString year = ui->input_year->text();
    QString type = ui->input_type->text();
    QString wasbuilt = ui->input_wasbuilt->text();

    if(wasbuilt != "yes" && wasbuilt != "Yes" && wasbuilt != "no" && wasbuilt != "No" && !wasbuilt.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Built is wrong");
        return;
    }

    if(type != "Transitor" && type != "transitor" && type != "Electronic" && type != "electronic" && type != "Electronic - mechanical" && type != "electronic - mechanical" && type != "mechanical" && type != "Mechanical" && type != "Other" && type != "other" && !type.isEmpty())
    {
        QMessageBox::warning(this, "Error", "This is not a type of computer");
        return;
    }

    if(year > "2015" && year < "1600" && !year.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Year is wrong");
        return;
    }

    int answer = QMessageBox::question(this, "Confirm", "Are you sure");
    if(answer == QMessageBox::No)
    {
        return;
    }
    else
    {
        if(!name.isEmpty())
        compservice.UpdateComputer("name",name.toStdString(),ID);
        if(!year.isEmpty())
        compservice.UpdateComputer("year",year.toStdString(),ID);
        if(!type.isEmpty())
        compservice.UpdateComputer("type",type.toStdString(),ID);
        if(!wasbuilt.isEmpty())
        compservice.UpdateComputer("build",wasbuilt.toStdString(),ID);
    }
    ui->Button_edit->setEnabled(false);
    this->done(0);
}

void EditComputer::on_Button_back_clicked()
{
    close();
}

void EditComputer::on_Button_exit_clicked()
{
    exit(1);
}
