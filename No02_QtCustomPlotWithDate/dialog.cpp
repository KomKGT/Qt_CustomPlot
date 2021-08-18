#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QString>
#include <QFile>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    int size = 3;
        QVector<double> x(size),y(size);

        for(int i = 0; i<size ; i++)
        {
            //x[i] = i;
            y[i] = i;
        }
        QDateTime time1,time2,time3;

        //time1 = QDateTime::currentDateTime();
        time1 = QDateTime::fromString("01/01/2014","MM/dd/yyyy");
        time2 = QDateTime::fromString("01/02/2014","MM/dd/yyyy");
        time3 = QDateTime::fromString("01/03/2014","MM/dd/yyyy");
        x[0] = time1.toTime_t();
        x[1] = time2.toTime_t();
        x[2] = time3.toTime_t();

        ui->plot->legend->setVisible(true);
        ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);

        ui->plot->setInteraction(QCP::iRangeDrag,true);
        ui->plot->setInteraction(QCP::iRangeZoom,true);
        ui->plot->addGraph();
        ui->plot->graph(0)->setData(x,y);
        ui->plot->graph(0)->setName("ควย");

        ui->plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
        ui->plot->xAxis->setLabel("Day");
        ui->plot->xAxis->setDateTimeFormat("MM/dd/yyyy");

        ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
        ui->plot->xAxis->setRange(x.first()-24,x.last()+24);
        ui->plot->yAxis->setRange(0,2);

        ui->plot->xAxis->pixelToCoord(pos().x());
        ui->plot->xAxis->pixelToCoord(pos().y());
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnSave_clicked()
{
    QString fileName("D:/Qt_CustomPlot/customplot.png");
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << file.errorString();
    }
    else
    {
        ui->plot->savePng(fileName);
    }

}
