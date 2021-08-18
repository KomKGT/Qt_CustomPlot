#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qtimer.h>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plot->setInteraction(QCP::iRangeDrag,true);
    ui->plot->setInteraction(QCP::iRangeZoom,true);

    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCross);

    QDateTime time = QDateTime::currentDateTime();

    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
    dateTimeTicker->setDateTimeFormat("hh:mm \r\n dd/MM/yyyy");
    ui->plot->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(QDate(2021,8,14)),QCPAxisTickerDateTime::dateTimeToKey(QDate(2021,8,16)));
    ui->plot->xAxis->setTicker(dateTimeTicker);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_btnAdd_clicked()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPoint(uint x, double y) //STEP 2
{
        QDateTime time = QDateTime::currentDateTime();
        //ui->plot->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(QDateTime::currentDateTime()),QCPAxisTickerDateTime::dateTimeToKey(QDate(2021,8,17)));
        ui->plot->xAxis->setRange(x-2*3600,QCPAxisTickerDateTime::dateTimeToKey(QDate(2021,8,19)));
        ui->plot->replot();
        ui->plot->update();
        qv_x.append(x);
        qv_y.append(1.0);
        qDebug() << "Check";

}
void MainWindow::cleardata()
{
    qDebug() << qv_y[0];
    qv_x.clear();
    qv_y.clear();
}

void MainWindow::plot() //STEP 3
{
    ui->plot->graph(0)->setData(qv_x,qv_y);

    ui->plot->replot();
    ui->plot->update();
}

void MainWindow::on_btnAdd_clicked()
{
    QDateTime time = QDateTime::currentDateTime();
    addPoint(time.toTime_t(),ui->bx_y->value());  //STEP 2
    plot();  //STEP 3

}

void MainWindow::on_btnClear_clicked()
{

    cleardata();
    plot();
}
