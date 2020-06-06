/********************************************************************************
** Form generated from reading UI file 'card.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARD_H
#define UI_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Card
{
public:
    QAction *buy_smth;
    QAction *returnbuy;
    QAction *is_working;
    QAction *balance;
    QAction *work_end;
    QWidget *centralwidget;
    QLabel *numlab;
    QLabel *valid;
    QLabel *name;
    QLabel *CHNM;
    QPushButton *PIN;
    QPushButton *balance_info;
    QPushButton *base_balance;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Card)
    {
        if (Card->objectName().isEmpty())
            Card->setObjectName(QStringLiteral("Card"));
        Card->resize(652, 394);
        buy_smth = new QAction(Card);
        buy_smth->setObjectName(QStringLiteral("buy_smth"));
        returnbuy = new QAction(Card);
        returnbuy->setObjectName(QStringLiteral("returnbuy"));
        is_working = new QAction(Card);
        is_working->setObjectName(QStringLiteral("is_working"));
        balance = new QAction(Card);
        balance->setObjectName(QStringLiteral("balance"));
        work_end = new QAction(Card);
        work_end->setObjectName(QStringLiteral("work_end"));
        centralwidget = new QWidget(Card);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        numlab = new QLabel(centralwidget);
        numlab->setObjectName(QStringLiteral("numlab"));
        numlab->setGeometry(QRect(12, 220, 291, 50));
        numlab->setStyleSheet(QLatin1String("font: 75 24pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);\n"
""));
        numlab->setFrameShape(QFrame::NoFrame);
        valid = new QLabel(centralwidget);
        valid->setObjectName(QStringLiteral("valid"));
        valid->setGeometry(QRect(330, 230, 291, 41));
        valid->setStyleSheet(QLatin1String("font: 75 16pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);"));
        name = new QLabel(centralwidget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(230, 280, 291, 50));
        name->setStyleSheet(QLatin1String("font: 75 24pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);"));
        name->setFrameShape(QFrame::NoFrame);
        CHNM = new QLabel(centralwidget);
        CHNM->setObjectName(QStringLiteral("CHNM"));
        CHNM->setGeometry(QRect(10, 290, 221, 41));
        CHNM->setStyleSheet(QLatin1String("font: 75 16pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);"));
        PIN = new QPushButton(centralwidget);
        PIN->setObjectName(QStringLiteral("PIN"));
        PIN->setGeometry(QRect(470, 20, 75, 23));
        balance_info = new QPushButton(centralwidget);
        balance_info->setObjectName(QStringLiteral("balance_info"));
        balance_info->setGeometry(QRect(560, 20, 75, 23));
        base_balance = new QPushButton(centralwidget);
        base_balance->setObjectName(QStringLiteral("base_balance"));
        base_balance->setGeometry(QRect(560, 140, 75, 23));
        Card->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Card);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 652, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        Card->setMenuBar(menubar);
        statusbar = new QStatusBar(Card);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Card->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(buy_smth);
        menu->addAction(returnbuy);
        menu->addAction(is_working);
        menu->addAction(balance);
        menu->addAction(work_end);

        retranslateUi(Card);

        QMetaObject::connectSlotsByName(Card);
    } // setupUi

    void retranslateUi(QMainWindow *Card)
    {
        Card->setWindowTitle(QApplication::translate("Card", "Card", 0));
        buy_smth->setText(QApplication::translate("Card", "\320\241\320\276\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \320\277\320\276\320\272\321\203\320\277\320\272\321\203", 0));
        returnbuy->setText(QApplication::translate("Card", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214 \321\202\320\276\320\262\320\260\321\200", 0));
        is_working->setText(QApplication::translate("Card", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \321\200\320\260\320\261\320\276\321\202\321\203 \320\272\320\260\321\200\321\202\321\213", 0));
        balance->setText(QApplication::translate("Card", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\261\320\260\320\273\320\260\320\275\321\201 \320\272\320\260\321\200\321\202\321\213", 0));
        work_end->setText(QApplication::translate("Card", "\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214 \321\200\320\260\320\261\320\276\321\202\321\203 \321\201 \320\272\320\260\321\200\321\202\320\276\320\271", 0));
        numlab->setText(QApplication::translate("Card", "0460 5453 6070 8391", 0));
        valid->setText(QApplication::translate("Card", "Valid:", 0));
        name->setText(QApplication::translate("Card", "Vasya Pupkin", 0));
        CHNM->setText(QApplication::translate("Card", "Cardholder name:", 0));
        PIN->setText(QString());
        balance_info->setText(QString());
        base_balance->setText(QString());
        menu->setTitle(QApplication::translate("Card", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class Card: public Ui_Card {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARD_H
