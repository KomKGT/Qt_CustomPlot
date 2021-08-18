#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVector<double> x(1601),y(1601);
    for (int i=0; i<1601; ++i)
    {
      x[i] = i/100.0 - 8; // x goes from -1 to 1
      y[i] = (x[i]-3)*(x[i]-3); // let's plot a quadratic function
    }
    ui->plot->addGraph();
    ui->plot->setInteraction(QCP::iRangeDrag,true);
    ui->plot->setInteraction(QCP::iRangeZoom,true);
    ui->plot->graph(0)->setData(x,y);
    ui->plot->xAxis->setRange(-100,100);
    ui->plot->yAxis->setRange(-100,100);
    ui->plot->replot();

}

MainWindow::~MainWindow()
{
    delete ui;
}

