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

void MainWindow::on_pushButton_clicked()
{
    ui->output->setText("Hellooo........!!! I will display Your Database records");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->output->setText("Record deleted...again press Display to see ur records");

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->output->setText("Added a record into database..Click Display to see all the records..!!");

}
