#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personnels.h"
#include "fonction.h"
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QtWidgets>

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

private:
    Ui::MainWindow *ui;
    Personnels P;
    Fonction F;
};
#endif // MAINWINDOW_H
