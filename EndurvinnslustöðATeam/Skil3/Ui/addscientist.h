#ifndef ADDSCIENTIST_H
#define ADDSCIENTIST_H

#include <QDialog>
#include "Services/scientistservice.h"
#include <vector>
#include <string>

namespace Ui {
class addscientist;
}

class addscientist : public QDialog
{
    Q_OBJECT

public:
    explicit addscientist(QDialog *parent = 0);
    ~addscientist();

private slots:
    void on_pushButton_add_clicked();

private:
    Scientistservice scientistService;
    Ui::addscientist *ui;
};

#endif // ADDSCIENTIST_H
