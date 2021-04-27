#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "carte.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_cinc->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_client->setModel(C.afficherClient());
    ui->tab_carte->setModel(Cr.afficherCarte());
    ui->stats->setModel(Cr.statistique());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{ bool controle=true ;
  bool  test=true;
    int cinc=ui->le_cinc->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString mail=ui->le_mail->text();
    QString adresse=ui->le_adresse->text();
    int tel=ui->le_tel->text().toInt();
    if ((tel<10000000)||(tel>99999999))
            controle=false;
    if (controle)
    {Client C(cinc,nom,prenom,mail,adresse,tel);
     test=C.ajouterClient();}
    QMessageBox msgBox;

    if((test)&&(controle))
    {
        msgBox.setText("Ajout avec succes. ");
        ui->tab_client->setModel(C.afficherClient());
        ui->stats->setModel(Cr.statistique());
    }
    else
        msgBox.setText("Echec de l'ajout veuillez verifier le num tel(8 chiffres)");
        msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    int cinc=ui->le_cinc_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString mail=ui->le_mail_2->text();
    QString adresse=ui->le_adresse_2->text();
    int tel=ui->le_tel_2->text().toInt();
    Client C2(cinc,nom,prenom,mail,adresse,tel);
    bool test=C2.modifierClient(C2.getcinc());
    QMessageBox msgBox;
    if (test) {
        msgBox.setText("modification avec succes");
        ui->tab_client->setModel(C.afficherClient());
        ui->stats->setModel(Cr.statistique());
    }
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Client C1; C1.setcinc(ui->le_cinc_2->text().toInt());
    bool test=C1.supprimerClient(C1.getcinc());
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("Suppression avec succes. ");
        ui->tab_client->setModel(C.afficherClient());
        ui->stats->setModel(Cr.statistique());
    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}

void MainWindow::on_pb_rechercher_clicked()
{
     Client C1;
     C1.setcinc(ui->le_cinc_rech->text().toInt());
     ui->tab_client->setModel(C.rechercherClient(C1.getcinc()));

}

void MainWindow::on_tab_client_activated(const QModelIndex &index)
{
    QString val=ui->tab_client->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT* from client where cinc=:val or nom=:val or prenom=:val or mail=:val or adresse=:val or tel=:val ");
    query.bindValue(":val",val);
    query.bindValue(":val",val);
    query.bindValue(":val",val);
    query.bindValue(":val",val);
    query.bindValue(":val",val);
    query.bindValue(":val",val);
    if(query.exec())
    {
        while(query.next()){
            ui->le_cinc_2->setText(query.value(0).toString());
            ui->le_nom_2->setText(query.value(1).toString());
            ui->le_prenom_2->setText(query.value(2).toString());
            ui->le_mail_2->setText(query.value(3).toString());
            ui->le_adresse_2->setText(query.value(4).toString());
            ui->le_tel_2->setText(query.value(5).toString());
        }
    }
}



void MainWindow::on_pb_ajouter_2_clicked()
{bool controle=true;
    bool test=true;
    int cinc=ui->le_cincc->text().toInt();
    int pts=ui->le_pts->text().toInt();
    QString expire=ui->le_exp->text();
if ((expire!="oui")&&(expire!="non"))
    controle=false;
if(controle){
    Carte Cr(cinc,pts,expire);
     test=Cr.ajouterCarte();}
    QMessageBox msgBox;

    if((test)&&(controle))
    {
        msgBox.setText("Ajout avec succes. ");
        ui->tab_carte->setModel(Cr.afficherCarte());
        ui->stats->setModel(Cr.statistique());
    }
    else
        msgBox.setText("Echec de l'ajout expire doit etre oui ou non ");
        msgBox.exec();
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    Carte Cr1; Cr1.setcinc(ui->le_cincc_2->text().toInt());
    bool test=Cr1.supprimerCarte(Cr1.getcinc());
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("Suppression avec succes. ");
        ui->tab_carte->setModel(Cr.afficherCarte());
        ui->stats->setModel(Cr.statistique());
    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}


void MainWindow::on_pb_modifier_2_clicked()
{
    int cinc=ui->le_cincc_2->text().toInt();
    int pts=ui->le_pts_2->text().toInt();
    QString expire=ui->le_exp_2->text();

    Carte Cr2(cinc,pts,expire);
    bool test=Cr2.modifierCarte(Cr2.getcinc());
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("modifié avec succes. ");
        ui->tab_carte->setModel(Cr.afficherCarte());
        ui->stats->setModel(Cr.statistique());
    }
    else
        msgBox.setText("Echec de la modification");
        msgBox.exec();
}


void MainWindow::on_pb_rechercher_2_clicked()
{
     Carte Cr1;
     Cr1.setcinc(ui->le_cincc_rech->text().toInt());
     ui->tab_carte->setModel(Cr.rechercherCarte(Cr1.getcinc()));

}

void MainWindow::on_pb_tri_clicked()
{
    ui->tab_client->setModel(C.trierClient());
}

void MainWindow::on_pb_tri_2_clicked()
{
    ui->tab_carte->setModel(Cr.trierCarte());
}



void MainWindow::on_tab_carte_activated(const QModelIndex &index)
{
    QString val=ui->tab_carte->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT* from carte where cinc=:val or pts=:val or expire=:val ");
    query.bindValue(":val",val);
    query.bindValue(":val",val);
    query.bindValue(":val",val);
    if(query.exec())
    {
        while(query.next()){
            ui->le_cincc_2->setText(query.value(0).toString());
            ui->le_pts_2->setText(query.value(1).toString());
            ui->le_exp_2->setText(query.value(2).toString());

        }
    }
}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("mohamedaziz.bensalem@esprit.tn", "191JMT1634", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("mohamedaziz.bensalem@esprit.tn", ui->le_email->text() , ui->le_objet->text(),ui->le_texte->text());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void MainWindow::on_envoyer_clicked()
{
    sendMail();
}


