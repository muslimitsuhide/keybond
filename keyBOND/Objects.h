#pragma once

#include <iostream>

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QFile>

class Objects : public QWidget {
    Q_OBJECT // этот макрос должен включаться в классы, которые объявляют свои собственные сигналы и слоты

public:
    Objects(QWidget *parent = 0);

private slots:
    void OnLine();

private:
    QLabel* label;
    QLineEdit* line;
    QLabel* copy;
    QLabel* error;

};
