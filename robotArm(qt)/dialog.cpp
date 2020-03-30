#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>

dialog::dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dialog)

{
    ui->setupUi(this);

    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;

    ui->com->addItem("");
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
        {
            ui->com->addItem(serialPortInfo.portName());
        }
}

dialog::~dialog()
{
    if(arduino->isOpen()){
        arduino->close();
    }
    delete ui;
}

void dialog::on_alttabla_slider_valueChanged(int value)
{
    ui-> alttabla_text_value ->setText(QString("<span style=\" font-size:8pt; font-weight:250; color: red;\">%1</span>").arg(value));
    dialog::updateRGB(QString("a%1").arg(value));
    qDebug() << m_readData;
}

void dialog::on_omuz_slider_valueChanged(int value)
{
    ui-> omuz_text_value ->setText(QString("<span style=\" font-size:8pt; font-weight:250; color: red;\">%1</span>").arg(value));
    dialog::updateRGB(QString("b%1").arg(value));
}

void dialog::on_dirsek_slider_valueChanged(int value)
{
    ui-> dirsek_text_value ->setText(QString("<span style=\" font-size:8pt; font-weight:250; color: red;\">%1</span>").arg(value));
    dialog::updateRGB(QString("c%1").arg(value));
}

void dialog::on_bilek_slider_valueChanged(int value)
{
    ui-> bilek_text_value ->setText(QString("<span style=\" font-size:8pt; font-weight:250; color: red;\">%1</span>").arg(value));
    dialog::updateRGB(QString("d%1").arg(value));
}

void dialog::on_parmak_slider_valueChanged(int value)
{
    ui-> parmak_text_value ->setText(QString("<span style=\" font-size:8pt; font-weight:250; color: red;\">%1</span>").arg(value));
    dialog::updateRGB(QString("e%1").arg(value));
}
void dialog::on_com_currentIndexChanged(const QString &arg1)
{
    arduino -> close();
    arduino_port_name=arg1;
}


void dialog::updateRGB(QString command)
{
    if(arduino->isWritable()){
        arduino->write(command.toStdString().c_str());
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}


void dialog::on_connectCheckBox_clicked(bool checked)
{
    connectCheck = checked;
    if(connectCheck == true){
    arduino->setPortName(arduino_port_name);
    arduino->open(QSerialPort::ReadWrite);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);
    }
    else arduino->close();
}
