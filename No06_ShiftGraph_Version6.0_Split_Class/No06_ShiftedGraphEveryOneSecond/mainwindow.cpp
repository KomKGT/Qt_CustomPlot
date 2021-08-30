#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <QtSerialPort/QSerialPortInfo>
#include "myserialport.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MySerialPort();
    MySerialPort *function = new MySerialPort();
    function->setserial();

    /*****************************Plot Graph Section******************************/
    init();
    ui->plot->addGraph();
    counter = 1;
    clicked = 1;
    ui->plot->xAxis->setRange(0,counter);


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(shifted()));
    timer->start(1000);

    qv_x.append(0);
    qv_y.append(1.0);

    ui->plot->graph(0)->setData(qv_x,qv_y);
    ui->plot->xAxis->setLabel("Time (second)");
    ui->plot->yAxis->setLabel("Temperature (F)");
    QSharedPointer<QCPAxisTickerFixed> fixedLatitudeTicker(new QCPAxisTickerFixed);
    fixedLatitudeTicker->setTickStep(1);
    fixedLatitudeTicker->setScaleStrategy(QCPAxisTickerFixed::ssNone);
    ui->plot->xAxis->setTicker(fixedLatitudeTicker);
    ui->plot->xAxis->setTicks(true);
    ui->plot->replot();
    /**************************End of Plot Graph Section******************************/

    /**************************Serial Port Section**************************/
    /*stm32_is_available = false;
    stm32_port_name = "";
    stm32 = new QSerialPort;
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
            if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
            {
                if(serialPortInfo.vendorIdentifier() == stm32_nucleo_vendor_id)
                {
                    if(serialPortInfo.productIdentifier() == stm32_nucleo_product_id)
                    {
                        stm32_port_name = serialPortInfo.portName();
                        stm32_is_available = true;
                        qDebug() << serialPortInfo.portName();
                    }
                }
             }
     }

    if(stm32_is_available)
    {
        stm32->setPortName(stm32_port_name);
        stm32->open(QSerialPort::WriteOnly);
        stm32->setBaudRate(QSerialPort::Baud19200);
        stm32->setDataBits(QSerialPort::Data8);
        stm32->setParity(QSerialPort::NoParity);
        stm32->setStopBits(QSerialPort::OneStop);
        stm32->setFlowControl(QSerialPort::NoFlowControl);
        //QObject::connect(stm32,SIGNAL(readyRead()),this,SLOT(readSerial()));
    }
    else
    {
        QMessageBox::warning(this,"Port error","Couldn't find stm32");
    }*/

}

MainWindow::~MainWindow()
{
    /*if(stm32->isOpen())
    {
        stm32->close();
    }*/
    delete ui;
}

void MainWindow::shifted()
{
    if(clicked%2 == 0)
    {
        timer->start(time);
        if((counter <= 99) && (counter + time/1000 <= 99) )
        {
            //timer->start(time);
            counter = counter + time/1000;

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
        else if((counter > 99) || (counter + time/1000 >99))
        {
            //timer->start(time);
            counter = counter + time/1000;
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
        timer->stop();
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

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QSettings settings("MySoft","MyApp");
    settings.setValue("settings",ui->comboBox->currentIndex());
    qDebug() << index;
    reciever(index);

}

//void MainWindow::readSerial()
//{
    //qDebug() << "Yes it work";
//}

void MainWindow::init()
{
    ui->comboBox->clear();

    ui->comboBox->addItem(QString::number(1)+ " sec");
    for(int i = 5;i<16;i = i+5)
    {
        ui->comboBox->addItem(QString::number(i) + " sec");
    }

}

void MainWindow::reciever(int index)
{
    time = 1000;
    if(index == 0)
    {
        time = 1000;
    }
    else if(index == 1)
    {
        time = 5000;
    }
    else if(index == 2)
    {
        time = 10000;
    }
    else if(index == 3)
    {
        time = 15000;
    }

}




