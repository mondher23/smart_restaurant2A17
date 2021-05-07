#ifndef PLATSWINDOW_H
#define PLATSWINDOW_H

#include <QDialog>
#include "plats.h"
#include "specialites.h"
#include "ingredients.h"
//#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QTime>
#include <QDateTime>
namespace Ui {
class platswindow;
}

class platswindow : public QDialog
{
    Q_OBJECT

public:
    explicit platswindow(QWidget *parent = nullptr);
    ~platswindow();

private slots:
    void on_pb_ajoutersp_clicked();

    //void on_tab_sp_activated(const QModelIndex &index);

    void on_pb_rechercher_sp_clicked();

    void on_pb_trier_sp_clicked();

    void on_pb_modifier_sp_clicked();

    void on_pb_supprimer_sp_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_rechercher_p_clicked();

    void on_pb_trierplat_clicked();

    void on_pb_modifier_p_clicked();

    void on_pb_supprimer_p_clicked();

    void on_tab_plat_activated(const QModelIndex &index);

    //void on_tablestat_activated(const QModelIndex &index);



    void on_pb_ajouterig_clicked();

    void on_tab_ig_activated(const QModelIndex &index);

    void on_pb_rechercher_ig_clicked();

    void on_pb_trier_ig_clicked();

    void on_pb_modifier_ig_clicked();

    void on_pb_supprimer_ig_clicked();
    void myfunction();

   /* void sendMail();

    void mailSent(QString);*/

    void on_excel_clicked();

    void on_btn_ajout_notes_clicked();

    void on_btn_notes_clicked();

private:
    Ui::platswindow *ui;
    Plats P;
    Specialites S;
    Ingredients I;
    QTimer *timer;
};

#endif // PLATSWINDOW_H
