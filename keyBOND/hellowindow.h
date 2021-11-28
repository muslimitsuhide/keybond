#ifndef HELLOWINDOW_H
#define HELLOWINDOW_H

#include <QWidget>
#include <mainwindow.h>

namespace Ui {
class HelloWindow;
}

class HelloWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HelloWindow(QWidget *parent = nullptr);
    ~HelloWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HelloWindow *ui;
    MainWindow window;
};

#endif // HELLOWINDOW_H
