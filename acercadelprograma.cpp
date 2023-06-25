#include "acercadelprograma.h"
#include "ui_acercadelprograma.h"

AcercaDelPrograma::AcercaDelPrograma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AcercaDelPrograma)
{
    ui->setupUi(this);
}

AcercaDelPrograma::~AcercaDelPrograma()
{
    delete ui;
}
