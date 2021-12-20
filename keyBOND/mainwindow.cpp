#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

QString str_from_file = "Hello, world";
int cur_level = 0;
enum {FIRST_CHAR, NOT_FIRST_CHAR} process_status = FIRST_CHAR;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setNextLevel();

    ui->label->setText(str_from_file);
    ui->line->setText("");
    ui->line->setStyleSheet("font: 20pt; color: rgb(0, 255, 0);");
}

MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::setNextLevel() {
    process_status = FIRST_CHAR;
    QString level_name = "%1.txt";
    QFile in(level_name.arg(++cur_level));
    if (!in.open(QIODevice::ReadOnly)) {
        //std::cout << "File didn't opened!" << std::endl;
    } else {
        str_from_file = in.readLine();
        //std::cout << str_from_file.toStdString() << std::endl;
        ui->label->setText(str_from_file);
    }
}




int last_length = 0;
int mistakes = 0;
int begin;
int end;
time_t begin_time = 0;


enum {CORRECT, ERROR, FINISH} state = CORRECT;


void MainWindow::on_line_textEdited(const QString &arg1) {
    QString input = arg1;

    if (process_status == FIRST_CHAR) {
        begin = clock();
        process_status = NOT_FIRST_CHAR;
    }

    if (state == CORRECT) {
        if (input.length() > last_length) {
            if (input.length() < str_from_file.length()) {
                if (input[input.length() - 1] == str_from_file[input.length() - 1]) {
                    state = CORRECT;
                    ui->line->setStyleSheet("font: 20pt; color: rgb(0, 255, 0);");
                } else {
                    mistakes = 1;
                    state = ERROR;
                    ui->line->setStyleSheet("font: 20pt; color: rgb(255, 0, 0);");
                }
            } else if (input.length() == str_from_file.length()) {
                if (input[input.length() - 1] == str_from_file[input.length() - 1]) {
                    state = FINISH;
                    end = clock();
                    float time = ((float)(end - begin) / CLOCKS_PER_SEC);
                    float speed = (str_from_file.length() / time) * 60;
                    QString level_up = "Уровень пройден\nВремя: %1 секунд\nСкорость: %2 символов в минуту";
                    ui->line->setStyleSheet("font: 20pt; color: rgb(0, 255, 0);");
                    QMessageBox::information(this, "Ура!", level_up.arg(time).arg(speed), QMessageBox::Ok);
                    setNextLevel();
                    ui->line->setText("");
                    ui->line->setStyleSheet("font: 20pt; color: rgb(255, 0, 0);");
                } else {
                    mistakes = 1;
                    state = ERROR;
                    ui->line->setStyleSheet("font: 20pt; color: rgb(255, 0, 0);");
                }
            }
        } else {
            state = CORRECT;
            ui->line->setStyleSheet("font: 20pt; color: rgb(0, 255, 0);");
        }
    } else if (state == ERROR) {
        if (mistakes == 1) {
            if (input.length() > last_length) {
                ++mistakes;
            } else {
                mistakes = 0;
                state = CORRECT;
                ui->line->setStyleSheet("font: 20pt; color: rgb(0, 255, 0);");
            }
        } else {
            if (input.length() > last_length) {
                ++mistakes;
            } else {
                --mistakes;
            }
        }
    } else if (state == FINISH) {
        if (input.length() >= str_from_file.length()) {
            state = FINISH;
            ui->line->setStyleSheet("font: 20pt; color: rgb(0, 255, 0);");
        } else {
            state = CORRECT;
            ui->line->setStyleSheet("font: 20pt; color: rgb(0, 255, 0);");
        }
    }

    last_length = input.length();
}
