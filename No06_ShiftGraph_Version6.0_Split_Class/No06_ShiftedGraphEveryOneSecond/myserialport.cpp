#include "myserialport.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
MySerialPort::MySerialPort()
{
    /**************************Serial Port Section**************************/
    stm32_is_available = false;
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
        qDebug() << "Error";
        QMessageBox::warning(NULL,"Port error","Couldn't find stm32"); // ใช้ Null แทน this https://stackoverflow.com/questions/15503000/how-to-call-qmessagebox-static-api-outside-of-a-qwidget-sub-class
    }

}

void MySerialPort::setserial()
{
    /**************************Serial Port Section**************************/
    stm32_is_available = false;
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
        qDebug() << "Error555";
    }

}
