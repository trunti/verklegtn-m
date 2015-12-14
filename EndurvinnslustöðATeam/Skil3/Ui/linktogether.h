#ifndef LINKTOGETHER_H
#define LINKTOGETHER_H

#include <QDialog>
#include "Services/computerservice.h"
#include "Services/scientistservice.h"
#include <vector>
#include <string>

namespace Ui {
class LinkTogether;
}

class LinkTogether : public QDialog
{
    Q_OBJECT

public:
    explicit LinkTogether(QWidget *parent = 0);
    ~LinkTogether();

private:
    void displayAllScientists();
    void displayAllComputers();
    void DisplayScientName(vector<Scientist> scientName);
    void DisplayCompName(vector<Computer> compName);
    vector<Scientist> scientName;
    vector<Computer> compName;
    Ui::LinkTogether *ui;

    Scientistservice scientistService;
    Computerservice computerService;
};

#endif // LINKTOGETHER_H
