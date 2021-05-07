#ifndef ACHATWINDOW_H
#define ACHATWINDOW_H

#include <QDialog>
#include "fournisseur.h"
#include "achat.h"
#include "connection.h"
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QTimer>
namespace Ui {
class achatwindow;
}

class achatwindow : public QDialog
{
    Q_OBJECT

public:
    explicit achatwindow(QWidget *parent = nullptr);
    ~achatwindow();

private slots:
void myfunction();

void on_pb_ajouter_2_clicked();

void on_pb_trier_2_clicked();

void on_pb_rechercher_2_clicked();

void on_tab_fournisseur_2_activated(const QModelIndex &index);

void on_pb_modifier_3_clicked();

void on_pb_supprimer_2_clicked();

void on_pushButton_2_clicked();

void on_add_2_clicked();

void on_remove_2_clicked();

void on_multy_2_clicked();

void on_div_2_clicked();

void on_pb_ajouter1_2_clicked();

void on_tab_achat_2_activated(const QModelIndex &index);

void on_pb_modifer1_2_clicked();

void on_pb_supprimer1_2_clicked();

void on_pb_tri1_2_clicked();

void on_pb_rechercher1_2_clicked();

void on_excel_clicked();





void on_btn_notes_clicked();

void on_btn_ajout_notes_clicked();

private:
    Ui::achatwindow *ui;
    Fournisseur F;
    Achat A;
    QTimer *timer;
};

#endif // ACHATWINDOW_H
