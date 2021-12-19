/********************************************************************************
** Form generated from reading UI file 'auth.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH_H
#define UI_AUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_auth
{
public:
    QGroupBox *groupBox;
    QLineEdit *LogLine;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *PassLine;
    QPushButton *guest;
    QLabel *label_3;

    void setupUi(QWidget *auth)
    {
        if (auth->objectName().isEmpty())
            auth->setObjectName(QString::fromUtf8("auth"));
        auth->resize(662, 385);
        auth->setStyleSheet(QString::fromUtf8("background-color:rgb(105, 109, 122)"));
        groupBox = new QGroupBox(auth);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(170, 100, 351, 161));
        groupBox->setStyleSheet(QString::fromUtf8("background-color:rgb(97, 98, 110)"));
        LogLine = new QLineEdit(groupBox);
        LogLine->setObjectName(QString::fromUtf8("LogLine"));
        LogLine->setEnabled(true);
        LogLine->setGeometry(QRect(120, 40, 201, 21));
        LogLine->setStyleSheet(QString::fromUtf8("background-color:rgb(64, 65, 65)"));
        LogLine->setFrame(false);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(30, 40, 51, 21));
        label->setStyleSheet(QString::fromUtf8("color:white\n"
""));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 110, 141, 32));
        pushButton->setMouseTracking(false);
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(211, 214, 236);\n"
"color:black\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 60, 21));
        label_2->setStyleSheet(QString::fromUtf8("color:white"));
        PassLine = new QLineEdit(groupBox);
        PassLine->setObjectName(QString::fromUtf8("PassLine"));
        PassLine->setEnabled(true);
        PassLine->setGeometry(QRect(120, 70, 201, 21));
        PassLine->setStyleSheet(QString::fromUtf8("background-color:rgb(64, 65, 65)"));
        PassLine->setFrame(false);
        PassLine->setEchoMode(QLineEdit::Password);
        guest = new QPushButton(groupBox);
        guest->setObjectName(QString::fromUtf8("guest"));
        guest->setGeometry(QRect(160, 110, 181, 32));
        guest->setStyleSheet(QString::fromUtf8("background-color:rgb(211, 214, 236);\n"
"color:black\n"
""));
        label_3 = new QLabel(auth);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 80, 91, 15));

        retranslateUi(auth);

        QMetaObject::connectSlotsByName(auth);
    } // setupUi

    void retranslateUi(QWidget *auth)
    {
        auth->setWindowTitle(QCoreApplication::translate("auth", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("auth", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        pushButton->setText(QCoreApplication::translate("auth", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("auth", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        guest->setText(QCoreApplication::translate("auth", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214 \320\272\320\260\320\272 \320\263\320\276\321\201\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("auth", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class auth: public Ui_auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_H
