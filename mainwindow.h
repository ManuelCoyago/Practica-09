#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

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
    void on_plainTextEdit_textChanged();
    void actualizarConteoCaracteres();
    void on_actionAbrir_Archivo_triggered();
    void on_actionGuardar_Archivo_triggered();
    void on_actionNuevo_Archivo_triggered();
    void on_actionSalir_del_programa_triggered();

    void on_actionAcerca_del_programa_triggered();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
