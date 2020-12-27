#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "proj_classes.h"
#include "student.h"

extern DB<Student> myStudentDB;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
     myStudentDB.add();
}

void MainWindow::on_delButton_clicked()
{
    myStudentDB.del();
}

void MainWindow::on_displayButton_clicked()
{
    ui->textBrowser->clear();
    myStudentDB.display();

}
