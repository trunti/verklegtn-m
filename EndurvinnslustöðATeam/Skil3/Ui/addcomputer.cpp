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
