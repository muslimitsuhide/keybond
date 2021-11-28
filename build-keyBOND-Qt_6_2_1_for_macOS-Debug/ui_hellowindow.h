/********************************************************************************
** Form generated from reading UI file 'hellowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOWINDOW_H
#define UI_HELLOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelloWindow
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *HelloWindow)
    {
        if (HelloWindow->objectName().isEmpty())
            HelloWindow->setObjectName(QString::fromUtf8("HelloWindow"));
        HelloWindow->resize(400, 300);
        pushButton = new QPushButton(HelloWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 150, 151, 51));

        retranslateUi(HelloWindow);

        QMetaObject::connectSlotsByName(HelloWindow);
    } // setupUi

    void retranslateUi(QWidget *HelloWindow)
    {
        HelloWindow->setWindowTitle(QCoreApplication::translate("HelloWindow", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("HelloWindow", "Tap to start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelloWindow: public Ui_HelloWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOWINDOW_H
