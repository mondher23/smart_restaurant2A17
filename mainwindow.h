#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plats.h"
#include "specialites.h"

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

    void on_tab_plat_activated(const QModelIndex &index);

    void on_tabWidget_tabBarClicked(int index);

    void on_pb_ajoutersp_clicked();

    void on_pb_suppsp_clicked();

    void on_pb_trierplat_clicked();

private:
    Ui::MainWindow *ui;
    Plats P;
    Specialites S;
};
#endif // MAINWINDOW_H
