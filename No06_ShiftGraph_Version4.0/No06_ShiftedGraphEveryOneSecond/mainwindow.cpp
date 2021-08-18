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

    QTimer *timer = new QTimer(this);                                                           // \
    connect(timer,SIGNAL(timeout()),this,SLOT(shifted()));                                      //  > เรียก Fn shifted ทุกๆ 1 วินาที เพื่อเพิ่ม range แกน x ทีละ 1 
    timer->start(1000);                                                                         // /

    qv_x.append(counter);                                                                       // เก็บค่า counter ใน qv_x เพื่อไป plot ทดสอบ
    qv_y.append(1.0);                                                                           // เก็บค่า 1.0 ใน qv_y เพื่อไป plot ทดสอบ

    ui->plot->graph(0)->setData(qv_x,qv_y);                                                     // Plot คู่อันดับ x,y

    QSharedPointer<QCPAxisTickerFixed> fixedLatitudeTicker(new QCPAxisTickerFixed);             // \
    fixedLatitudeTicker->setTickStep(1);                                                        //   > เริ่มต้นให้ step การ plot โชว์ทีละ 1 ไปเรื่อยๆ(1 , 2 , 3 , ...)
    fixedLatitudeTicker->setScaleStrategy(QCPAxisTickerFixed::ssNone);                          //  |
    ui->plot->xAxis->setTicker(fixedLatitudeTicker);                                            //  | 
    ui->plot->xAxis->setTicks(true);                                                            //  |
    ui->plot->replot();                                                                         // /
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::shifted()
{
    if(clicked%2 == 0)                                                                          // ถ้า Clicked ครั้งแรกให้กราฟเริ่มทำงาน(Start)
    {                                                                                                                                      
        if(counter <= 99)                                                                       // ถ้า range จุดปลายมมีค่า <= 99 (เพื่อset ตัวเลขไม่ให้ทับกัน)
        {
            counter = counter + 1;                                                              

            ui->plot->xAxis->setRange(0,counter);

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
        else if(counter > 99)                                                                   // ถ้า range จุดปลายมมีค่า > 99 (เพื่อset ตัวเลขไม่ให้ทับกัน)
        {
            counter = counter + 1;
            ui->plot->xAxis->setRange(0,counter);
 
            QSharedPointer<QCPAxisTickerFixed> fixedLatitudeTicker(new QCPAxisTickerFixed);     // \
            fixedLatitudeTicker->setTickStep(10);                                               //  >  โชว์ทีละ 10 ไปเรื่อยๆ(10 , 20 , 30 , ...)
            fixedLatitudeTicker->setScaleStrategy(QCPAxisTickerFixed::ssNone);                  //  |
            ui->plot->xAxis->setTicker(fixedLatitudeTicker);                                    //  |
            ui->plot->xAxis->setTicks(true);                                                    // /

            qv_x.append(counter);
            qv_y.append(5);
            ui->plot->graph(0)->setData(qv_x,qv_y);

            ui->plot->replot();
        }

    }
    else if(clicked%2 == 1)                                                                     // ถ้า Clicked ครั้งที่ 2 ให้กราฟเริ่มหยุด(Pause)
    {
        ui->plot->xAxis->setRange(0,counter);  
        

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
