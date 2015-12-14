#ifndef LINKTOGETHER_H
#define LINKTOGETHER_H

#include <QDialog>

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
    Ui::LinkTogether *ui;
};

#endif // LINKTOGETHER_H
