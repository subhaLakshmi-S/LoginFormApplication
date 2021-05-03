#include "widget.h"
#include "ui_widget.h"
#include<QColorDialog>
#include<QDebug>
#include<QColor>
#include<QPalette>
#include<QFont>
#include<QFontDialog>
#include<QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    QPalette palette=ui->label->palette();
    QColor color=palette.color(QPalette::WindowText);
    QColor chosencolor=QColorDialog::getColor(color,this,"choose text color");
    if(chosencolor.isValid())
    {
        palette.setColor(QPalette::WindowText,chosencolor);
        ui->label->setPalette(palette);
        qDebug()<<"Chosen a valid color";
    }
    else{
        qDebug()<<"Chosen a invalid color";
    }
}

void Widget::on_pushButton_clicked()
{

    QPalette palette=ui->label->palette();
    QColor color=palette.color(QPalette::Window);
    QColor chosencolor=QColorDialog::getColor(color,this,"choose background color");
    if(chosencolor.isValid())
    {
        palette.setColor(QPalette::Window,chosencolor);
        ui->label->setPalette(palette);
        qDebug()<<"Chosen a valid color";
    }
    else{
        qDebug()<<"Chosen a invalid color";
    }
}

void Widget::on_pushButton_3_clicked()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,QFont("Times New Roman",10),this);
    if(ok)
    {
        ui->label->setFont(font);
    }
    else{
        QMessageBox::information(this,"Message","User didnt chose font");
    }
}
