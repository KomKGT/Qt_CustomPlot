#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plot->setInteraction(QCP::iRangeDrag,true);
    ui->plot->setInteraction(QCP::iRangeZoom,true);

    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCross);
    //ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    //ui->plot->graph(0)->setPen(QPen(Qt::red));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPoint(double x, double y) //STEP 2
{

        qv_x.append(x);
        qv_y.append(y);

}

void MainWindow::cleardata()
{
    qv_x.clear();
    qv_y.clear();
}

void MainWindow::plot() //STEP 3
{
    ui->plot->graph(0)->setData(qv_x,qv_y);

    ui->plot->replot();
    ui->plot->update();
}


void MainWindow::on_btnAdd_clicked() //STEP 1
{
    addPoint(ui->bx_x->value(),ui->bx_y->value());  //STEP 2
    plot();  //STEP 3

}

void MainWindow::on_btnClear_clicked()
{
    cleardata();
    plot();
}
