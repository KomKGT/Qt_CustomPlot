#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Period = 1;
    Amplitude = 1;

    QVector<double> x(501),y(501);
    for(int i =0;i<501;i++)
    {
        x[i] = i/50.0 - 5;
        y[i] = 2*sin(2*3.1415*2*x[i]);
    }
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x,y);
    ui->plot->xAxis->setRange(-4,4);
    ui->plot->yAxis->setRange(-99,99);
    ui->plot->replot();
    ui->dial->setNotchTarget(10.0);
    //ui->dial->

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dial_valueChanged(int value) //Change Amplitude
{
    Amplitude = value;
    QVector<double> x(501),y(501);
    for(int i =0;i<501;i++)
    {
        x[i] = i/50.0 - 5;
        y[i] = Amplitude*sin(Period*x[i]);
    }
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x,y);
    ui->plot->replot();
}

void MainWindow::on_dial_2_valueChanged(int value) //Change Period
{
    Period = value;
    QVector<double> x(501),y(501);
    for(int i =0;i<501;i++)
    {
        x[i] = i/50.0 - 5;
        y[i] = Amplitude*sin(Period*x[i]);
    }
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x,y);
    ui->plot->replot();
}


