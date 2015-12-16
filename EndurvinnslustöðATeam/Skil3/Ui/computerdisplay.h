#ifndef COMPUTERDISPLAY_H
#define COMPUTERDISPLAY_H

#include <QDialog>
#include "Services/computerservice.h"
#include "addcomputer.h"
#include "editcomputer.h"
#include <vector>
#include <string>

using namespace std;

namespace Ui {
class ComputerDisplay;
}

class ComputerDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerDisplay(QWidget *parent = 0);
    ~ComputerDisplay();
private slots:
    void on_dropdown_order_by_currentIndexChanged(int index);

    void on_Search_window_textChanged(const QString &arg1);

    void on_dropdown_order_by_ascending_activated(const QString &arg1);

    void on_table_computer_clicked(const QModelIndex &index);

    void on_Button_remove_comp_clicked();

    void on_pushButton_add_computer_clicked();

    void on_Button_edit_clicked();

private:
    string GetOrderBy();
    void displayAllComputers();
    void displayComputers(vector<Computer> computer);
    bool orderByAscending();

    Computerservice computerService;

    vector<Computer> currentlyDisplayedComputer;

    Ui::ComputerDisplay *ui;
};

#endif // COMPUTERDISPLAY_H
