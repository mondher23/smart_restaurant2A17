#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plats.h"
#include "specialites.h"
#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int idp=ui->le_idp->text().toInt();
        QString nomp=ui->le_nomp->text();
        float prixp=ui->le_prixp->text().toFloat();

        Plats P(idp,nomp,prixp);
        bool test=P.ajouterplat();
        QMessageBox msgBox;

        if(test)
        {msgBox.setText("Ajout avec succes.");
            ui->tab_plat->setModel(P.afficherplat());}
            else {
                msgBox.setText("Echec.");
                }
                msgBox.exec();

    }




void MainWindow::on_pb_supprimer_clicked()
{ Plats p1;
    p1.setidp(ui->le_idp_supp->text().toInt());
    bool test=p1.supprimerplat(p1.getidp());
    QMessageBox msgBox;
    if (test){
        msgBox.setText("supression avec succés");
        ui->tab_plat->setModel(P.afficherplat());
    }}

void MainWindow::on_pb_trierplat_clicked()
{ ui->tab_plat->setModel(P.trierplat());

}







void MainWindow::on_pb_ajoutersp_clicked()
{int idsp=ui->le_idsp->text().toInt();
    QString nomsp=ui->le_nomsp->text();
    QString typesp=ui->le_typesp->text();

    Specialites S(idsp,nomsp,typesp);
    bool test=S.ajouterspecialite();
    QMessageBox msgBox;

    if(test)
    {msgBox.setText("Ajout avec succes.");
        ui->tab_sp->setModel(S.afficherspecialite());}
        else {
            msgBox.setText("Echec.");
            }
            msgBox.exec();

}

void MainWindow::on_pb_suppsp_clicked()
{Specialites s1;
    s1.setidsp(ui->le_idp_supp->text().toInt());
    bool test=s1.supprimerspecialite(s1.getidsp());
    QMessageBox msgBox;
    if (test){
        msgBox.setText("supression avec succés");
        ui->tab_sp->setModel(S.afficherspecialite());
    }

}


