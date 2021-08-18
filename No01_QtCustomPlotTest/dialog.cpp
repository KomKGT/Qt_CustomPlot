#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    int size = 10;
    QVector<double> x(size),y(size);

    for(int i = 0; i<size ; i++)
    {
        x[i] = i;
        y[i] = i;
    }

    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x,y);
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->xAxis->setRange(0,10);
    ui->plot->yAxis->setRange(0,10);
    ui->plot->replot();
}

Dialog::~Dialog()
{
    delete ui;
}

