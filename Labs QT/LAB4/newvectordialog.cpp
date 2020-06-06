#include "newvectordialog.h"
#include <iostream>

NewVectorDialog::NewVectorDialog(QWidget* parent)
    : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    this->setWindowTitle ("Vector creation");
    this->setModal(true);
    this->resize(200,90);
    x1 = new QDoubleSpinBox;
    y1 = new QDoubleSpinBox;
    x2 = new QDoubleSpinBox;
    y2 = new QDoubleSpinBox;
    x1->setRange(-525,525);
    x2->setRange(-525,525);
    y1->setRange(-300,300);
    y2->setRange(-300,300);
    QLabel* startcoords = new QLabel("Start coords");
    QLabel* endcoords = new QLabel("End coords");
    QPushButton* ok = new QPushButton("&Ok");
    QPushButton* cancel = new QPushButton("&Cancel");

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(startcoords, 0, 0);
    layout->addWidget(endcoords, 1, 0);
    layout->addWidget(x1, 0, 1);
    layout->addWidget(y1, 0, 2);
    layout->addWidget(x2, 1, 1);
    layout->addWidget(y2, 1, 2);
    layout->addWidget(cancel, 3, 2);
    layout->addWidget(ok, 3, 1);
    setLayout(layout);

    //connect(coordColorChooser, SIGNAL(clicked()), parent, SLOT(chooseCoordColor()));
    connect(ok, SIGNAL(clicked()), SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), SLOT(reject()));
}

QLineF NewVectorDialog::getLine()
{
    return QLineF(x1->value(), y1->value(), x2->value(), y2->value());
}
