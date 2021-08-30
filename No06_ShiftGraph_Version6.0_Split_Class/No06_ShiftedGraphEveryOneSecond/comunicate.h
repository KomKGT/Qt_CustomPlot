#ifndef COMUNICATE_H
#define COMUNICATE_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>

class Comunicate
{
public:
    Comunicate();


    QSerialPort *stm32;

    static const quint16 stm32_nucleo_vendor_id = 1155; //stm32
    static const quint16 stm32_nucleo_product_id = 14155;//stm32

    QString stm32_port_name;
    bool stm32_is_available;
};

#endif // COMUNICATE_H
