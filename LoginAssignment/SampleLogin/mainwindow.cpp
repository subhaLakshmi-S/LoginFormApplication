#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDebug>
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


void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

  if(username == "subha" && password == "sure"){
      QMessageBox::information(this, "Login","Username and password is correct");
      //hide();
      secDialog = new Dialog(this);
      secDialog->show();
      qDebug()<<"You have logged in";
  }
  else{
     QMessageBox::warning(this, "Login","Username and password is incorrect");
      qDebug()<<"Your login is failed";
  }
}
