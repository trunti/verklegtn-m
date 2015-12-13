#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Button_Scientist_clicked()
{
    ScientistsDisplay scientdisplay;
    scientdisplay.exec();
}

void MainWindow::on_Buttin_Computer_clicked()
{
    ComputerDisplay compdisplay;
    compdisplay.exec();
}
