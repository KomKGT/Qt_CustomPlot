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

    void addPoint(double x,double y);
    void cleardata();
    void plot();

    //double x0 = 999;
    //double y0 = 999;

private slots:
    void on_btnAdd_clicked();

    void on_btnClear_clicked();

private:
    Ui::MainWindow *ui;
    QVector<double> qv_x,qv_y;
};
#endif // MAINWINDOW_H
