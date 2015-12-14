#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H

#include <QDialog>

namespace Ui {
class addcomputer;
}

class addcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit addcomputer(QWidget *parent = 0);
    ~addcomputer();

private:
    Ui::addcomputer *ui;
};

#endif // ADDCOMPUTER_H
