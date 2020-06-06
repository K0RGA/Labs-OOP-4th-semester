#ifndef NEWVECTORDIALOG_H
#define NEWVECTORDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QString>

class NewVectorDialog : public QDialog
{
    Q_OBJECT
public:
    NewVectorDialog(QWidget* parent = nullptr);
    QLineF getLine();
private:
    QDoubleSpinBox* x1;
    QDoubleSpinBox* y1;
    QDoubleSpinBox* x2;
    QDoubleSpinBox* y2;

};

#endif // NEWVECTORDIALOG_H
