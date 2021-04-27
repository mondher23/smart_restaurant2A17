
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QMainWindow>
#include "plats.h"
#include "specialites.h"
#include "ingredients.h"

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
    void on_pb_ajouter_clicked();

    void on_pb_ajoutersp_clicked();

    void on_pb_trierplat_clicked();

    void on_pb_supprimer_p_clicked();

    void on_pb_supprimer_sp_clicked();

    void on_pb_trier_sp_clicked();

    void on_pb_rechercher_sp_clicked();

    void on_pb_modifier_sp_clicked();

    void on_pb_rechercher_p_clicked();

    void on_pb_modifier_p_clicked();

    void on_tab_plat_activated(const QModelIndex &index);

    void on_pb_ajouterig_clicked();

    void on_pb_modifier_ig_clicked();

    void on_pb_supprimer_ig_clicked();

    void on_pb_trier_ig_clicked();

    void on_pb_rechercher_ig_clicked();

    void on_tab_ig_activated(const QModelIndex &index);

    void sendMail();

    void mailSent(QString);


    void on_pb_envoyer_mail_clicked();

private:
    Ui::MainWindow *ui;
    Plats P;
    Specialites S;
    Ingredients I;
};
#endif // MAINWINDOW_H
