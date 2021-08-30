#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H
#include <QtSerialPort/QSerialPort>

class MySerialPort
{
public:
    MySerialPort();
    void setserial();
private:
    /*Serial Port Section*/
    QSerialPort *stm32;

    static const quint16 stm32_nucleo_vendor_id = 1155; //stm32
    static const quint16 stm32_nucleo_product_id = 14155;//stm32

    QString stm32_port_name;
    bool stm32_is_available;
    /*------------------*/
};

#endif // MYSERIALPORT_H
