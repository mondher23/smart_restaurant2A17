#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "carte.h"
#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_cinc->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_client->setModel(C.afficherClient());
    ui->tab_carte->setModel(Cr.afficherCarte());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int cinc=ui->le_cinc->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString mail=ui->le_mail->text();
    QString adresse=ui->le_adresse->text();
    int tel=ui->le_tel->text().toInt();
    Client C(cinc,nom,prenom,mail,adresse,tel);
    bool test=C.ajouterClient();
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("Ajout avec succes. ");
        ui->tab_client->setModel(C.afficherClient());
    }
    else
        msgBox.setText("Echec de l'ajout");
        msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Client C1; C1.setcinc(ui->le_cin_supp->text().toInt());
    bool test=C1.supprimerClient(C1.getcinc());
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("Suppression avec succes. ");
        ui->tab_client->setModel(C.afficherClient());
    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int cinc=ui->le_cinc->text().toInt();
    int pts=ui->le_pts->text().toInt();
    QString expire=ui->le_exp->text();

    Carte Cr(cinc,pts,expire);
    bool test=Cr.ajouterCarte();
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("Ajout avec succes. ");
        ui->tab_carte->setModel(Cr.afficherCarte());
    }
    else
        msgBox.setText("Echec de l'ajout");
        msgBox.exec();
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    Carte Cr1; Cr1.setcinc(ui->le_carte_supp->text().toInt());
    bool test=Cr1.supprimerCarte(Cr1.getcinc());
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("Suppression avec succes. ");
        ui->tab_carte->setModel(Cr.afficherCarte());
    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void MainWindow::on_pb_tri_clicked()
{
    ui->tab_client->setModel(C.trierClient());
}

void MainWindow::on_pb_tri_2_clicked()
{
    ui->tab_carte->setModel(Cr.trierCarte());
}
