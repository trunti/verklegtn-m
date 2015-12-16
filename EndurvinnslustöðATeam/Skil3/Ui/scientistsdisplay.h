#ifndef SCIENTISTSDISPLAY_H
#define SCIENTISTSDISPLAY_H

#include <QDialog>
#include "addscientist.h"
#include "Services/scientistservice.h"
#include "editscientist.h"
#include <vector>
#include <string>

using namespace std;


namespace Ui {
class ScientistsDisplay;
}

class ScientistsDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit ScientistsDisplay(QWidget *parent = 0);
    ~ScientistsDisplay();
private slots:
    void on_dropdown_order_by_currentIndexChanged(int index);

    void on_dropdown_order_by_ascending_activated(const QString &arg1);
    void on_Search_window_textChanged(const QString &arg1);

    void on_pushButton_add_scientist_clicked();

    void on_table_scientists_clicked(const QModelIndex &index);

    void on_Button_remove_sci_clicked();

    void on_Button_edit_clicked();

private:
    string GetOrderBy();
    void displayAllScientists();
    void displayScientists(vector<Scientist> scientist);
    bool orderByAscending();

    Scientistservice scientistService;

    Ui::ScientistsDisplay *ui;

    vector<Scientist> currentlyDisplayedScientist;
};

#endif // SCIENTISTSDISPLAY_H
