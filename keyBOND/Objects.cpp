#include "Objects.h"
#include "dialog.h"

#include <QGridLayout>


Objects::Objects(QWidget *parent) : QWidget(parent) {
    QFile in = QString("1.txt");
    if (!in.open(QIODevice::ReadOnly)) {
        std::cout << "File didn't opened" << std::endl;
    }
    label = new QLabel(in.readLine(), this);
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

QTextStream out(stdout);
QString str_from_file = "qwerty";
int line_length = 0;
int copy_length = 0;
int mistakes = 0;
bool done = false;

void Objects::OnLine() {
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
    }



}
