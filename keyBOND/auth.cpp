#include "auth.h"
#include "ui_auth.h"
#include "mainwindow.h"
#include <QMessageBox>

auth::auth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::auth)
{
    ui->setupUi(this);
}

auth::~auth()
{
    delete ui;
}

void auth::on_pushButton_clicked()
{
    QString name = ui->LogLine->text();
    QString password = ui->PassLine->QLineEdit::text();

    if (name == "Test" && password == "test") {
        QMessageBox::information(this, "", "Авторизация пройдена успешно.");
        hide();
        window = new MainWindow(this);
        window->show();
    } else {
        QMessageBox::warning(this, "", "Введен неверный логин или пароль, попробуйте еще раз.");
        window = new MainWindow(this);
        window->close();
    }
}


void auth::on_guest_clicked()
{
    window = new MainWindow(this);
    window->show();
    QMessageBox::information(this, "", "Внимание! В гостевом режиме статистика скорости вестись не будет.");
    hide();
}


