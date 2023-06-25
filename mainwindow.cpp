#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"
#include "QFile"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_plainTextEdit_textChanged()
{
    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::actualizarConteoCaracteres);

}
void MainWindow::actualizarConteoCaracteres()
{
    QString texto = ui->plainTextEdit->toPlainText();
    int conteo = texto.length();
    ui->statusbar->showMessage("Conteo de caracteres: " + QString::number(conteo));
}

void MainWindow::on_actionAbrir_Archivo_triggered()
{
    // Mostrar el diálogo para seleccionar un archivo
    QString fileName = QFileDialog::getOpenFileName(this, "Abrir archivo", QString(), "Archivos de texto (*.txt)");

    // Verificar si se seleccionó un archivo
    if (!fileName.isEmpty()) {
        // Abrir el archivo utilizando QFile
        QFile file(fileName);

        // Verificar si se pudo abrir el archivo
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Leer el contenido del archivo
            QString contenido = QTextStream(&file).readAll();

            // Cerrar el archivo
            file.close();

            // Mostrar el contenido en el QPlainTextEdit
            ui->plainTextEdit->setPlainText(contenido);
        } else {
            // Mostrar un mensaje de error si no se pudo abrir el archivo
            QMessageBox::warning(this, "Error", "No se pudo abrir el archivo.");
        }
    }
}
void MainWindow::on_actionGuardar_Archivo_triggered()
{
    // Mostrar el diálogo para seleccionar la ubicación y el nombre del archivo a guardar
    QString fileName = QFileDialog::getSaveFileName(this, "Guardar archivo", QString(), "Archivos de texto (*.txt)");

    // Verificar si se seleccionó un archivo válido
    if (!fileName.isEmpty()) {
        // Abrir el archivo utilizando QFile en modo de escritura
        QFile file(fileName);

        // Verificar si se pudo abrir el archivo
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            // Obtener el contenido del QPlainTextEdit
            QString contenido = ui->plainTextEdit->toPlainText();

            // Escribir el contenido en el archivo
            QTextStream stream(&file);
            stream << contenido;

            // Cerrar el archivo
            file.close();
        } else {
            // Mostrar un mensaje de error si no se pudo abrir el archivo
            QMessageBox::warning(this, "Error", "No se pudo guardar el archivo.");
        }
    }
}


void MainWindow::on_actionNuevo_Archivo_triggered()
{
    // Limpiar el contenido del QPlainTextEdit
    ui->plainTextEdit->clear();
}



void MainWindow::on_actionSalir_del_programa_triggered()
{
    this->close();
}

