#ifndef ACERCADELPROGRAMA_H
#define ACERCADELPROGRAMA_H

#include <QDialog>

namespace Ui {
class AcercaDelPrograma;
}

class AcercaDelPrograma : public QDialog
{
    Q_OBJECT

public:
    explicit AcercaDelPrograma(QWidget *parent = nullptr);
    ~AcercaDelPrograma();

private:
    Ui::AcercaDelPrograma *ui;
};

#endif // ACERCADELPROGRAMA_H
