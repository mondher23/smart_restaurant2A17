#include "mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::on_pb_ajouter_clicked()
{
    int idp=ui->le_id->text().toInt();
    Qstring nomp=ui->le_nom->text();
    Qstring prenomp=ui->le_prenom->text();
    Qstring adressep=ui->la_adresse->text();
    int telp=ui->le_tel->text().toInt();
    Personnel P(idp,nomp,prenomp,adressep,telp);
    bool test=P.ajouter();
    QMessageBox msgBox;

    if(test)
    {msgBox.setText("Ajout avec succes.");
        ui->tab_personnel->setModel(P.afficher());
        else {
            msgBox.setText("Echec.");
            }
            msgBox.exec();

}

}




void mainwindow::on_pb_supprimer_clicked()
{
    Personnels E1;
    E1.setidp(ui->le_id_supprimer->text().toInt());
    bool test=E1.supprimer(E1.getidp());
    QMessageBox msgBox;
    if (test)
    {msgBpx.setText("suppression avec succes.");
        ui->tab_personnels->setModel(E.afficher());
        else{ msgBox.setText("La suppression a echouee."):}

                msgBox.exec();
        }
    }
