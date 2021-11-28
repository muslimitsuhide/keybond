#include "hellowindow.h"
#include "ui_hellowindow.h"
#include "mainwindow.h"


HelloWindow::HelloWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelloWindow)
{
    ui->setupUi(this);
}

HelloWindow::~HelloWindow()
{
    delete ui;
}

void HelloWindow::on_pushButton_clicked()
{
    window.show();
}

