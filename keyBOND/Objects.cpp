#include "line.h"
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

QString str_from_file = "qwerty";
int i = 0;
int cur_length = 0;

void Objects::OnLine() {
    QString input = line->text();
    std::cout << input.size() << std::endl;  // Debug

    if (cur_length > input.length()) {
        std::cout << "Deleted charachter" << std::endl;  // Debug
        if (i > 0) {
            --i;
        }
    }
    else if (input[i] == str_from_file[i]) {
        ++cur_length;
        error->setText("");
        copy->setText(copy->text() + input[i]);
        ++i;
    } else {
        ++cur_length;
        QString error_message = "Введён неверный символ на позиции %1";
        error->setText(error_message.arg(i + 1));
        ++i;
    }





    /*
    if (input[input.size() - 1] == str[i]){
        str_copy += str[i];
        copy->setText(str_copy);
        ++i;
    } else {
        input.replace(1, input.size() - 1, "");
        line->text() = input;
        copy->setText(input);
    }*/
}
