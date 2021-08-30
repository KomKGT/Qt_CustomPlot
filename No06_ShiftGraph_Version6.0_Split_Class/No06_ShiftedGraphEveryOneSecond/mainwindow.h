#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void shifted();
    //void on_pushButton_clicked();

    void on_btnStart_clicked();

    void on_comboBox_currentIndexChanged(int index);

    //void readSerial();

private:
    Ui::MainWindow *ui;
    /*Plot Graph Section*/
    int counter;
    int clicked;
    int time;
    QVector<double> qv_x,qv_y;
    void init();
    void reciever(int);

    QTimer *timer;
    /*------------------*/

    /*Serial Port Section*/
    //QSerialPort *stm32;

    //static const quint16 stm32_nucleo_vendor_id = 1155; //stm32
    //static const quint16 stm32_nucleo_product_id = 14155;//stm32

    //QString stm32_port_name;
    //bool stm32_is_available;
    /*------------------*/
};
#endif // MAINWINDOW_H
