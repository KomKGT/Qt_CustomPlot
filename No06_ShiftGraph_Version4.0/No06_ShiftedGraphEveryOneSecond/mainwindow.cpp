#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plot->addGraph();
    counter = 1;
    clicked = 1;
    ui->plot->xAxis->setRange(0,counter);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(shifted()));
    timer->start(1000);

    qv_x.append(counter);
    qv_y.append(1.0);

    ui->plot->graph(0)->setData(qv_x,qv_y);

    QSharedPointer<QCPAxisTickerFixed> fixedLatitudeTicker(new QCPAxisTickerFixed);
    fixedLatitudeTicker->setTickStep(1);
    fixedLatitudeTicker->setScaleStrategy(QCPAxisTickerFixed::ssNone);
    ui->plot->xAxis->setTicker(fixedLatitudeTicker);
    ui->plot->xAxis->setTicks(true);
    ui->plot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::shifted()
{
    if(clicked%2 == 0)
    {
        if(counter <= 99)
        {
            counter = counter + 1;

            ui->plot->xAxis->setRange(0,counter);
            //ui->plot->xAxis->ticker()->setTickCount(10);
            //qDebug() << ui->plot->xAxis->ticker();
            QSharedPointer<QCPAxisTickerFixed> fixedLatitudeTicker(new QCPAxisTickerFixed);
            fixedLatitudeTicker->setTickStep(1);
            fixedLatitudeTicker->setScaleStrategy(QCPAxisTickerFixed::ssNone);
            ui->plot->xAxis->setTicker(fixedLatitudeTicker);
            ui->plot->xAxis->setTicks(true);

            qv_x.append(counter);
            qv_y.append(3);
            ui->plot->graph(0)->setData(qv_x,qv_y);
            ui->plot->replot();

            ui->plot->graph(0)->rescaleAxes(true);
            qDebug() << "Check" << counter;
        }
        else if(counter > 99)
        {
            counter = counter + 1;
            ui->plot->xAxis->setRange(0,counter);
            //ui->plot->xAxis->ticker()->setTickCount(10);
            //qDebug() << ui->plot->xAxis->ticker();
            QSharedPointer<QCPAxisTickerFixed> fixedLatitudeTicker(new QCPAxisTickerFixed);
            fixedLatitudeTicker->setTickStep(10);
            fixedLatitudeTicker->setScaleStrategy(QCPAxisTickerFixed::ssNone);
            ui->plot->xAxis->setTicker(fixedLatitudeTicker);
            ui->plot->xAxis->setTicks(true);

            qv_x.append(counter);
            qv_y.append(5);
            ui->plot->graph(0)->setData(qv_x,qv_y);

            ui->plot->replot();
        }

    }
    else if(clicked%2 == 1)
    {
        ui->plot->xAxis->setRange(0,counter);
        //ui->plot->xAxis->ticker()->setTickCount(10);
        //qDebug() << ui->plot->xAxis->ticker();

        ui->plot->replot();

        ui->plot->graph(0)->rescaleAxes(true);
        qDebug() << "Stop" << counter;
    }
}


void MainWindow::on_btnStart_clicked()
{
    clicked = clicked + 1;
    if(clicked%2==0)
    {
        ui->btnStart->setText("Pause");
    }
    else if(clicked%2 == 1)
    {
        ui->btnStart->setText("Start");
    }
    shifted();
    qDebug() << "Pass" << clicked;
}
