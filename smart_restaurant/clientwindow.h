#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include "client.h"
#include "carte.h"
//#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QTime>
#include <QDateTime>


namespace Ui {
class clientwindow;
}

class clientwindow : public QDialog
{
    Q_OBJECT

public:
    explicit clientwindow(QWidget *parent = nullptr);
    ~clientwindow();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_tri_clicked();

    void on_pb_tri_2_clicked();

    void on_tab_client_activated(const QModelIndex &index);

    void on_tab_carte_activated(const QModelIndex &index);

    void on_pb_modifier_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_modifier_2_clicked();

    void on_pb_rechercher_2_clicked();
    void myfunction();
    /*void sendMail();
    void mailSent(QString);

    void on_envoyer_clicked();*/

    void on_excel_clicked();

    void on_btn_ajout_notes_clicked();

    void on_btn_notes_clicked();

private:
    Ui::clientwindow *ui;
    Client C;
    Carte Cr;
    QTimer *timer;
};

#endif // CLIENTWINDOW_H
