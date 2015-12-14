#include "linktogether.h"
#include "ui_linktogether.h"

LinkTogether::LinkTogether(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LinkTogether)
{
    ui->setupUi(this);
}

LinkTogether::~LinkTogether()
{
    delete ui;
}
