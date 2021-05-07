#ifndef PERSONNELWINDOW_H
#define PERSONNELWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include "personnels.h"
#include "fonction.h"
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QtWidgets>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QTime>
#include <QDateTime>
namespace Ui {
class personnelwindow;
}

class personnelwindow : public QDialog
{
    Q_OBJECT

public:
    explicit personnelwindow(QWidget *parent = nullptr);
    ~personnelwindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_tri_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supp_clicked();

    void on_pb_rechercher_clicked();

    void on_tab_personnels_activated(const QModelIndex &index);

    void on_pb1_ajouter_clicked();

    void on_pb1_supprimer_clicked();

    void on_pb1_modifier_clicked();

    void on_pb1_rechercher_clicked();

    void on_pb1_trier_clicked();

    void on_tab_fonctions_activated(const QModelIndex &index);

    void on_pushButton_clicked();
    void myfunction();

    void on_excel_clicked();

    void on_btn_ajout_notes_clicked();

    void on_btn_notes_clicked();

private:
    Ui::personnelwindow *ui;
    Personnels P;
    Fonction F;
    QTimer *timer;
};

#endif // PERSONNELWINDOW_H
