#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "avis.h"
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <vente.h>
#include "smtp.h"
#include <QtWidgets/QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *gestion = nullptr);
    ~MainWindow();

private slots:
    void on_btn_ajout_clicked();

    void on_btn_supp_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_btn_ajout_2_clicked();

    void on_btn_supp_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_add_clicked();

    void on_remove_clicked();

    void on_multy_clicked();

    void on_div_clicked();

    void sendMail();

    void mailSent(QString);

    void on_senbtn_clicked();

private:
    Ui::MainWindow *ui;
    Avis A;
    vente V;
};
#endif // MAINWINDOW_H
