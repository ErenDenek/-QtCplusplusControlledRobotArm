#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include <QSerialPort>

namespace Ui {
class dialog;
}

class dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = nullptr);
    ~dialog();

private slots:

    void updateRGB(QString);

    void on_alttabla_slider_valueChanged(int value);

    void on_omuz_slider_valueChanged(int value);

    void on_dirsek_slider_valueChanged(int value);

    void on_bilek_slider_valueChanged(int value);

    void on_parmak_slider_valueChanged(int value);

    void on_com_currentIndexChanged(const QString &arg1);

    void on_connectCheckBox_clicked(bool checked);

private:
    Ui::dialog *ui;

    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 6790;
    static const quint16 arduino_uno_product_id = 29987;
    QString arduino_port_name;
    bool arduino_is_available;

    QByteArray m_readData;
    bool connectCheck = false;
};

#endif // DIALOG_H
