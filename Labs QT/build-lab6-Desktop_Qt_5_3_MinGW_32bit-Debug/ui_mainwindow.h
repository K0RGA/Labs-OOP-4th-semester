/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *cards;
    QPushButton *newcard;
    QPushButton *delcard;
    QListWidget *history;
    QLabel *label;
    QPushButton *clear_history;
    QPushButton *startform2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(599, 536);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        cards = new QTableWidget(centralwidget);
        if (cards->columnCount() < 5)
            cards->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        cards->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        cards->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        cards->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        cards->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        cards->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        cards->setObjectName(QStringLiteral("cards"));
        cards->setGeometry(QRect(10, 10, 580, 191));
        cards->setShowGrid(true);
        cards->horizontalHeader()->setDefaultSectionSize(115);
        newcard = new QPushButton(centralwidget);
        newcard->setObjectName(QStringLiteral("newcard"));
        newcard->setGeometry(QRect(10, 360, 401, 51));
        delcard = new QPushButton(centralwidget);
        delcard->setObjectName(QStringLiteral("delcard"));
        delcard->setGeometry(QRect(10, 420, 401, 51));
        history = new QListWidget(centralwidget);
        history->setObjectName(QStringLiteral("history"));
        history->setGeometry(QRect(10, 240, 581, 111));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 210, 101, 16));
        clear_history = new QPushButton(centralwidget);
        clear_history->setObjectName(QStringLiteral("clear_history"));
        clear_history->setGeometry(QRect(510, 210, 75, 23));
        startform2 = new QPushButton(centralwidget);
        startform2->setObjectName(QStringLiteral("startform2"));
        startform2->setGeometry(QRect(440, 360, 151, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 599, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        QTableWidgetItem *___qtablewidgetitem = cards->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\272\320\260\321\200\321\202\321\213", 0));
        QTableWidgetItem *___qtablewidgetitem1 = cards->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\221\320\260\320\273\320\260\320\275\321\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = cards->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206/\320\263\320\276\320\264", 0));
        QTableWidgetItem *___qtablewidgetitem3 = cards->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "PIN", 0));
        QTableWidgetItem *___qtablewidgetitem4 = cards->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\222\320\273\320\260\320\264\320\265\320\273\320\265\321\206", 0));
        newcard->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\272\320\260\321\200\321\202\321\203", 0));
        delcard->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\203\321\216", 0));
        label->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\271:", 0));
        clear_history->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0));
        startform2->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\200\320\260\320\261\320\276\321\202\321\203\n"
"\321\201 \320\272\320\260\321\200\321\202\320\276\320\271", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
