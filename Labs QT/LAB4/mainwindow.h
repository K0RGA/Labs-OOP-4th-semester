#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "coordplanescene.h"
#include "coordplaneview.h"
#include "graphicsvector.h"
#include "reversedtext.h"
#include <QObject>
#include <QInputDialog>
#include "newvectordialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_createButton_clicked();

    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_multButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
    CoordPlaneScene* scene;
    CoordPlaneView* display;
};
#endif // MAINWINDOW_H
