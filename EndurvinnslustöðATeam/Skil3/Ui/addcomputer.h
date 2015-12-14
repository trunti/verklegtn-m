#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H

#include <QDialog>
#include "Services/computerservice.h"

namespace Ui {
class addcomputer;
}

class addcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit addcomputer(QWidget *parent = 0);
    ~addcomputer();

private slots:
    void on_pushButton_clicked();

private:
    Computerservice computerService;
    Ui::addcomputer *ui;
};

#endif // ADDCOMPUTER_H
