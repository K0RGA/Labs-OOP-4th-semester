#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new CoordPlaneScene(QRectF(-525,-300,1050,600), QPointF(50,50));
    display = new CoordPlaneView(scene);
    ui->gridLayout->addWidget(display);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createButton_clicked()
{
    NewVectorDialog* wind = new NewVectorDialog(this);
    wind->show();
    if(wind->exec() == QDialog::Accepted)
    {
        GraphicsVector* res = new GraphicsVector(wind->getLine());
        scene->addItem(res);
        QString temp = QString(QString::number(res->line().dx()) + ":" + QString::number(res->line().dy()));
    }

}

void MainWindow::on_plusButton_clicked()
{
    GraphicsVector* res = new GraphicsVector;
    GraphicsVector buff;
    QList<QGraphicsItem *> toCalculate = scene->selectedItems();
    for (int i = 0; i < toCalculate.size(); i++)
    {
        buff = *static_cast<GraphicsVector *>(toCalculate[i]);
        *res = *res + buff;
        QString temp = QString(QString::number(res->line().dx()) + ":" + QString::number(res->line().dy()));
    }
    scene->addItem(res);
    update();
}

void MainWindow::on_minusButton_clicked()
{
    GraphicsVector* res = new GraphicsVector;
    QList<QGraphicsItem *> toCalculate = scene->selectedItems();
    if(toCalculate.size() == 2)
    {
        if(static_cast<GraphicsVector *>(toCalculate[0])->seletion_number() > static_cast<GraphicsVector *>(toCalculate[1])->seletion_number())
        {
            *res = *static_cast<GraphicsVector *>(toCalculate[0]) - *static_cast<GraphicsVector *>(toCalculate[1]);
            scene->addItem(res);
            QString temp = QString(QString::number(res->line().dx()) + ":" + QString::number(res->line().dy()));
        }
        else
        {
            *res = *static_cast<GraphicsVector *>(toCalculate[1]) - *static_cast<GraphicsVector *>(toCalculate[0]);
            scene->addItem(res);
            QString temp = QString(QString::number(res->line().dx()) + ":" + QString::number(res->line().dy()));
        }
    }
    else
    {
        qDebug() << "U choosed more or less than 2 vectors" << endl;
    }
}


void MainWindow::on_multButton_clicked()
{
    QList<QGraphicsItem *> toCalculate = scene->selectedItems();
    bool ok;
    double d = QInputDialog::getDouble(this, tr("Vector Multiplying"),
                                       tr("Coefficient:"), 0, -100, 100, 2, &ok);
    qreal d_c = qreal(d);
    if (ok)
    {
        for (int i = 0; i < toCalculate.size(); i++)
        {
            *static_cast<GraphicsVector *>(toCalculate[i]) = *static_cast<GraphicsVector*>(toCalculate[i])*d_c;
        }
    }
}

void MainWindow::on_deleteButton_clicked()
{
    QList<QGraphicsItem *> toRemove = scene->selectedItems();
    for (int i = 0; i < toRemove.size(); i++)
    {
        delete toRemove[i];
    }
    toRemove.clear();
}
