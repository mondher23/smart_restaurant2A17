#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include "achat.h"
#include <QMainWindow>
#include "connection.h"
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
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



    void on_pb_trier_clicked();

    void on_pb_rechercher_clicked();

    void on_tab_fournisseur_activated(const QModelIndex &index);

    void on_pb_modifier_2_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();

    void on_add_clicked();


    void on_remove_clicked();

    void on_multy_clicked();

    void on_div_clicked();

    void on_pb_ajouter1_clicked();

    void on_tab_achat_activated(const QModelIndex &index);

    void on_pb_modifer1_clicked();

    void on_pb_supprimer1_clicked();

    void on_pb_tri1_clicked();

    void on_pb_rechercher1_clicked();

private:
    Ui::MainWindow *ui;
    Fournisseur F;
    Achat A;
};
#endif // MAINWINDOW_H
