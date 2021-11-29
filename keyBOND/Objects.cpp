#include "Objects.h"
#include "dialog.h"

#include <QGridLayout>
#include <ctime>

QString str_from_file = "Я надеюсь, что мы не будем выглядеть очень плохо на синкапе";

Objects::Objects(QWidget *parent) : QWidget(parent) {
    /*QFile in = QString("1.txt");
    if (!in.open(QIODevice::ReadOnly)) {
        std::cout << "File didn't opened" << std::endl;
    }*/
    label = new QLabel(str_from_file, this);
    line = new QLineEdit("", this);
    copy = new QLabel("", this);
    error = new QLabel("", this);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(label, 1, 1);
    grid->addWidget(line, 2, 1);
    grid->addWidget(copy, 3, 1);
    grid->addWidget(error, 4, 1);

    setLayout(grid);

    connect(line, &QLineEdit::textEdited, this, &Objects::OnLine);
}


int last_length = 0;
int mistakes = 0;
bool first_char = true;
int begin;
int end;

enum {CORRECT, ERROR, FINISH} state = CORRECT;

void Objects::OnLine() {
    QString input = line->text();

    if (first_char) {
        begin = clock();
        first_char = false;
    }

    if (state == CORRECT) {
        if (input.length() > last_length) {
            if (input.length() < str_from_file.length()) {
                if (input[input.length() - 1] == str_from_file[input.length() - 1]) {
                    state = CORRECT;
                    copy->setText(copy->text() + input[input.length() - 1]);
                    error->setText("");
                } else {
                    mistakes = 1;
                    state = ERROR;
                    QString error_message = "Введён неверный символ на позиции %1";
                    error->setText(error_message.arg(input.length()));
                }
            } else if (input.length() == str_from_file.length()) {
                if (input[input.length() - 1] == str_from_file[input.length() - 1]) {
                    state = FINISH;
                    copy->setText(copy->text() + input[input.length() - 1]);
                    end = clock();
                    float time = ((float)(end - begin) / CLOCKS_PER_SEC);
                    float speed = (str_from_file.length() / time) * 60;
                    QString level_up = "Уровень пройден\nВремя: %1 секунд\nСкорость: %2 символов в минуту";
                    error->setText(level_up.arg(time).arg(speed));
                } else {
                    mistakes = 1;
                    state = ERROR;
                    QString error_message = "Введён неверный символ на позиции %1";
                    error->setText(error_message.arg(input.length()));
                }
            }
        } else {
            state = CORRECT;
            QString copy_text = copy->text();
            copy_text.remove(input.length(), 1);
            copy->setText(copy_text);
        }
    } else if (state == ERROR) {
        if (mistakes == 1) {
            if (input.length() > last_length) {
                ++mistakes;
            } else {
                mistakes = 0;
                state = CORRECT;
                error->setText("");
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
        } else {
            state = CORRECT;
            QString copy_text = copy->text();
            copy_text.remove(input.length(), 1);
            copy->setText(copy_text);
            error->setText("");
        }
    }

    last_length = input.length(); // Подумать, куда лучше поставить





    /*

    QString input = line->text();

    std::cout << "line_length = " << line_length << std::endl;
    std::cout << "input.length() = " << input.length() << std::endl;
    std::cout << "copy_length = " << copy_length << std::endl;

    if (input.length() <= line_length) {
        if (done && line_length == copy_length){
            done = false;
        }
        if (mistakes > 0) {
            --mistakes;
            std::cout << "--mistakes" << std::endl;
        }
        if (line_length > 0) {
            --line_length;
        }
        std::cout << "---Deleted charachter---" << std::endl;

        if (copy_length > line_length) {
            if (copy_length == 1) {
                copy->setText("");
            } else {
                QString new_copy = copy->text();
                new_copy.remove(copy_length - 1, 1);
                copy->setText(new_copy);
            }
            --copy_length;
        }
        std::cout << "line_length = " << line_length << std::endl;  // debug
        std::cout << "copy_length = " << copy_length << std::endl;  // debug
    } else if (!done) {
        if (mistakes > 0) {
            ++mistakes;
            ++line_length;
        } else {
            if (input[line_length] == str_from_file[line_length]) {
                error->setText("");
                copy->setText(copy->text() + input[line_length]);
                ++line_length;
                ++copy_length;
            } else {
                ++mistakes;
                ++line_length;
                QString error_message = "Введён неверный символ на позиции %1";
                error->setText(error_message.arg(line_length));
            }
        }
    }
    std::cout << "mistakes = " << mistakes << std::endl;  // debug



    if (mistakes == 0 && line_length == str_from_file.length()){
        error->setText("Уровень пройден");
        done = true;
    }*/



}
