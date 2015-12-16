#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect (timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}
void MainWindow::showTime ()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString ("hh : mm : ss");
    ui->Digital_clock->setText(time_text);
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
void MainWindow::on_Button_Random_clicked()
{
    Random random;
    random.exec();
}
void MainWindow::on_Button_link_clicked()
{
    LinkTogether linkT;
    linkT.exec();
}
void MainWindow::on_pushButton_clicked()
{
    close();
}
