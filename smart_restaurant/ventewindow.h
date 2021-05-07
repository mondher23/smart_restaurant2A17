#ifndef VENTEWINDOW_H
#define VENTEWINDOW_H

#include <QDialog>
#include "avis.h"
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <vente.h>
//#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QTime>
#include <QDateTime>
namespace Ui {
class ventewindow;
}

class ventewindow : public QDialog
{
    Q_OBJECT

public:
    explicit ventewindow(QWidget *parent = nullptr);
    ~ventewindow();

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

    void myfunction();


    void on_excel_clicked();

    void on_btn_ajout_notes_clicked();

    void on_btn_notes_clicked();

private:
    Ui::ventewindow *ui;
    Avis A;
    vente V;
     QTimer *timer;
};

#endif // VENTEWINDOW_H
