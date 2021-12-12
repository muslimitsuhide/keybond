#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

QString str_from_file = "Привет, мир! Я КиБонд!";
int cur_level = 1;
enum {FIRST_CHAR, LAST_CHAR} process_status = FIRST_CHAR;

void setNextLevel() {
    QString level_name = "C:\keybond\keyBOND\%1.txt";
    QFile in = level_name.arg(++cur_level);
    if (!in.open(QIODevice::ReadOnly)) {
        std::cout << "File didn't opened!" << std::endl;
    } else {
        process_status = FIRST_CHAR;
        str_from_file = in.readLine();
    }
}

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setNextLevel();

    ui->label->setText(str_from_file);
    ui->line->setText("");
    ui->line->setStyleSheet("font: 20pt; color: rgb(0, 255, 0);");
    ui->error->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}




int last_length = 0;
int mistakes = 0;
bool first_char = true;
int begin;
int end;


enum {CORRECT, ERROR, FINISH} state = CORRECT;



void MainWindow::on_line_textEdited(const QString &arg1) {
    QString input = arg1;

    if (process_status == FIRST_CHAR) {
        begin = clock();
        process_status = LAST_CHAR;
    }

    if (state == CORRECT) {
        if (input.length() > last_length) {
            if (input.length() < str_from_file.length()) {
                if (input[input.length() - 1] == str_from_file[input.length() - 1]) {
                    state = CORRECT;
                    ui->error->setText("");
                    ui->line->setStyleSheet("font: 20pt; color: rgb(0, 255, 0);");
                } else {
                    mistakes = 1;
                    state = ERROR;
                    QString error_message = "Введён неверный символ на позиции %1";
                    ui->error->setText(error_message.arg(input.length()));
                    ui->line->setStyleSheet("font: 20pt; color: rgb(255, 0, 0);");
                }
            } else if (input.length() == str_from_file.length()) {
                if (input[input.length() - 1] == str_from_file[input.length() - 1]) {
                    state = FINISH;
                    end = clock();
                    float time = ((float)(end - begin) / CLOCKS_PER_SEC);
                    float speed = (str_from_file.length() / time) * 60;
                    QString level_up = "Уровень пройден\nВремя: %1 секунд\nСкорость: %2 символов в минуту";
                    //ui->error->setText(level_up.arg(time).arg(speed));
                    ui->line->setStyleSheet("font: 20pt; color: rgb(0, 255, 0);");
                    QMessageBox::information(this, "Ура!", level_up.arg(time).arg(speed), QMessageBox::Ok);
                    setNextLevel();
                } else {
                    mistakes = 1;
                    state = ERROR;
                    QString error_message = "Введён неверный символ на позиции %1";
                    ui->error->setText(error_message.arg(input.length()));
                    ui->line->setStyleSheet("font: 20pt; color: rgb(255, 0, 0);");
                }
            }
        } else {
            state = CORRECT;
            ui->line->setStyleSheet("font: 20pt; color: rgb(0, 255, 0);;");
        }
    } else if (state == ERROR) {
        if (mistakes == 1) {
            if (input.length() > last_length) {
                ++mistakes;
            } else {
                mistakes = 0;
                state = CORRECT;
                ui->error->setText("");
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
            ui->error->setText("");
            ui->line->setStyleSheet("font: 20pt; color: rgb(0, 255, 0);");
        }
    }

    last_length = input.length();
}
