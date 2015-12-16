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
    void on_pushButton_clicked();           // Þegar ýtt er á takkann fer villumelding af stað svo er addað ef allt er í góðu.
    void on_Button_back_clicked();
    void on_Button_exit_clicked();

private:
    Computerservice computerService;
    Ui::addcomputer *ui;
};

#endif // ADDCOMPUTER_H
