#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    int counter;      //ตัวนับเพิ่มแกน X (เป็นเหมือน global variable)
    int clicked;        //ตัวนับครั้งที่ click ปุ่ม Start,Pause X (เป็นเหมือน global variable)
    int time;           //เปลี่ยนเวลาที่ใช้ Timer inturrupt X (เป็นเหมือน global variable)
    QVector<double> qv_x,qv_y;
    void init();            //ใช้ Load data ComboBox
    void reciever(int);     //ฟังชันรับค่าจาก ตัวเลือกที่เราเลือกจาก ComboBox

    QTimer *timer;          //ใช้ timer แบบนี้เนื่องจากจะได้เป็นเหมือน global variable


};
#endif // MAINWINDOW_H
