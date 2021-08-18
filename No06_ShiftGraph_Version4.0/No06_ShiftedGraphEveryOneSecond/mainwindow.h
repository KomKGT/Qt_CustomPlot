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

private:
    Ui::MainWindow *ui;
    int counter;
    int clicked;
    QVector<double> qv_x,qv_y;
    //QVector<int> tick;
};
#endif // MAINWINDOW_H
