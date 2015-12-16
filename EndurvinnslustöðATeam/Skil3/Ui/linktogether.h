#ifndef LINKTOGETHER_H
#define LINKTOGETHER_H

#include <QDialog>
#include "Services/computerservice.h"
#include "Services/scientistservice.h"
#include "Services/linkservice.h"
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

private slots:

    void on_button_link_clicked();
    void on_table_relation_clicked(const QModelIndex &index);
    void on_button_remove_link_clicked();
    void on_Button_back_clicked();
    void on_Button_exit_clicked();

private:
    void displayAllScientists();
    void displayAllComputers();
    void DisplayScientName(vector<Scientist> scientName);   // Aðeins displayað nöfninn
    void DisplayCompName(vector<Computer> compName);
    void DisplayRelation();                                 // Náð í allar tengingarnar og displayað aðeins nöfnin tengd
    vector<Scientist> scientName;
    vector<Computer> compName;
    Ui::LinkTogether *ui;
    Scientistservice scientistService;
    linkservice linkService;
    Computerservice computerService;
};

#endif // LINKTOGETHER_H
