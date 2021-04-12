#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "carte.h"
#include "smtp.h"
#include <QtWidgets/QMessageBox>
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
    void sendMail();
    void mailSent(QString);

    void on_envoyer_clicked();



private:
    Ui::MainWindow *ui;
    Client C;
    Carte Cr;
};
#endif // MAINWINDOW_H
