#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plats.h"
#include "specialites.h"
#include "ingredients.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tab_plat->setModel(P.afficherplat());
    ui->tab_sp->setModel(S.afficherspecialite());
    ui->tab_ig->setModel(I.afficheringredient());
    ui->tablestat->setModel(P.statistiqueplat());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{ bool test1=true,test=true;
    int idp=ui->le_idp->text().toInt();
        QString nomp=ui->le_nomp->text();
        float prixp=ui->le_prixp->text().toFloat();
        int idsp=ui->le_idsp_4->text().toInt();
        if((prixp<0)||(prixp>500))
        test1=false;
        if(test1==true)
       { Plats P(idp,nomp,prixp,idsp);
        test=P.ajouterplat();}
        QMessageBox msgBox;

        if((test==true)&&(test1==true))
        {msgBox.setText("Ajout avec succes.");
            ui->tab_plat->setModel(P.afficherplat());
        ui->tablestat->setModel(P.statistiqueplat());}
            else if(test1==false){
                msgBox.setText("verifier le prix ");
                }
        else {msgBox.setText("echec de l'ajout ");}
                msgBox.exec();

    }

void MainWindow::on_pb_supprimer_p_clicked()
{
    Plats p1;
        p1.setidp(ui->le_idp_2->text().toInt());
        bool test=p1.supprimerplat(p1.getidp());
        QMessageBox msgBox;
        if (test){
            msgBox.setText("supression avec succés");
            ui->tab_plat->setModel(P.afficherplat());
        }

}

void MainWindow::on_pb_modifier_p_clicked()
{ bool test=true,test1=true;
    int idp=ui->le_idp_2->text().toInt();
    QString nomp=ui->le_nomp_2->text();
    float prixp=ui->le_prixp_2->text().toFloat();
    int idsp=ui->le_idsp_5->text().toInt();
    if((prixp<0)||(prixp>500))
    test1=false;
  if(test1==true)
    {Plats P2(idp,nomp,prixp,idsp);
     test=P2.modifierplat(P2.getidp());}
    QMessageBox msgBox;

    if((test==true)&&(test1==true))
    {msgBox.setText("modification  avec succes.");
        ui->tab_plat->setModel(P.afficherplat());}
        else if(test1==false) {
            msgBox.setText("verifier le prix");
            }
    else{msgBox.setText("verifier le prix");}
            msgBox.exec();

}





void MainWindow::on_pb_trierplat_clicked()
{ ui->tab_plat->setModel(P.trierplat());

}

void MainWindow::on_pb_rechercher_p_clicked()
{ Plats p1;
    p1.setnomp(ui->le_nomp_3->text());
    ui->tab_plat->setModel(P.rechercherplat(p1.getnomp()));
}






void MainWindow::on_pb_ajoutersp_clicked()
{bool test1=true,test=true;
    int idsp=ui->le_idsp->text().toInt();
    QString nomsp=ui->le_nomsp->text();
    QString typesp=ui->le_typesp->text();
    if((typesp[0]<'A')||(typesp[0]>'Z'))
    test1=false;
    if(test1==true)


    {Specialites S(idsp,nomsp,typesp);
     test=S.ajouterspecialite();}
    QMessageBox msgBox;

    if((test1==true)&&(test==true))
    {msgBox.setText("Ajout avec succes.");
        ui->tab_sp->setModel(S.afficherspecialite());}
        else if(test1==false) {
            msgBox.setText("verifier le type");}
    else { msgBox.setText("echec de l'ajout");}
            msgBox.exec();

}

void MainWindow::on_pb_supprimer_sp_clicked()
{Specialites s1;
    s1.setidsp(ui->le_idsp_2->text().toInt());
    bool test=s1.supprimerspecialite(s1.getidsp());
    QMessageBox msgBox;
    if (test){
        msgBox.setText("supression avec succés");
        ui->tab_sp->setModel(S.afficherspecialite());
    }

}

void MainWindow::on_pb_trier_sp_clicked()
{ ui->tab_sp->setModel(S.trierspecialite());

}







void MainWindow::on_pb_rechercher_sp_clicked()
{
    Specialites s1;
       s1.setnomsp(ui->le_nomsp_3->text());
       ui->tab_sp->setModel(S.rechercherspecialite(s1.getnomsp()));
}

void MainWindow::on_pb_modifier_sp_clicked()
{ bool test=true,test1=true;
    int idsp=ui->le_idsp_2->text().toInt();
    QString nomsp=ui->le_nomsp_2->text();
    QString typesp=ui->le_typesp_2->text();
    if((typesp[0]<'A')||(typesp[0]>'Z'))
    test1=false;
    if(test1==true)


    {Specialites S2(idsp,nomsp,typesp);
    test=S2.modifierspecialite(S2.getidsp());}
    QMessageBox msgBox;

    if((test==true)&&(test1==true))
    {msgBox.setText("Modif avec succes.");
        ui->tab_sp->setModel(S.afficherspecialite());}
        else if(test1==false) {
            msgBox.setText("verifier le nom");
            }
      else {msgBox.setText("echec de la modification");}
            msgBox.exec();
}





void MainWindow::on_tab_plat_activated(const QModelIndex &index)
{
    QString val=ui->tab_plat->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT* from plats where idp=:val or nomp=:val or prixp=:val or idsp=:val  ");
        query.bindValue(":val",val);
        query.bindValue(":val",val);
        query.bindValue(":val",val);
        query.bindValue(":val",val);

        if(query.exec()){

                while(query.next()){
                  ui->le_idp_2->setText(query.value(0).toString());
                  ui->le_nomp_2->setText(query.value(1).toString());
                  ui->le_prixp_2->setText(query.value(2).toString());
                    ui->le_idsp_5->setText(query.value(3).toString());
                }
    }
}

void MainWindow::on_pb_ajouterig_clicked()
{ bool test1=true,test=true;

    int idig=ui->le_idig->text().toInt();
        QString nomig=ui->le_nomig->text();
        QString qttig=ui->le_qtt->text();
        QString dateig=ui->le_date->text();
        int idp=ui->le_idp_4->text().toInt();
        if((qttig[0]!="1")&&(qttig[0]!="2")&&(qttig[0]!="3")&&(qttig[0]!="4")&&(qttig[0]!="5")&&(qttig[0]!="6")&&(qttig[0]!="7")&&(qttig[0]!="8")&&(qttig[0]!="9"))
        test1=false;
        if(test1==true)
        {Ingredients I(idig,nomig,qttig,dateig,idp);
         test=I.ajouteringredient();}
        QMessageBox msgBox;

        if((test==true)&&(test1==true))
        {msgBox.setText("Ajout avec succes.");
            ui->tab_ig->setModel(I.afficheringredient());}
            else if(test1==false) {
                msgBox.setText("verifier la quantite ");
                }
            else {
            msgBox.setText("echec de l'ajout ");
            }
                msgBox.exec();


}

void MainWindow::on_pb_modifier_ig_clicked()
{ bool test=true,test1=true;
    int idig=ui->le_idig_2->text().toInt();
        QString nomig=ui->le_nomig_2->text();
        QString qttig=ui->le_qtt_2->text();
        QString dateig=ui->le_date_2->text();
        int idp=ui->le_idp_5->text().toInt();
        if((qttig[0]!="1")&&(qttig[0]!="2")&&(qttig[0]!="3")&&(qttig[0]!="4")&&(qttig[0]!="5")&&(qttig[0]!="6")&&(qttig[0]!="7")&&(qttig[0]!="8")&&(qttig[0]!="9"))
        test1=false;
        if(test1==true)
        {Ingredients I2(idig,nomig,qttig,dateig,idp);
         test=I2.modifieringredient(I2.getidig());}
        QMessageBox msgBox;

        if((test==true)&&(test1==true))
        {msgBox.setText("Modification avec succes.");
            ui->tab_ig->setModel(I.afficheringredient());}
            else if(test==false) {
                msgBox.setText("verifier la quantite");
                }
        else{ msgBox.setText("echec de la modification");}
                msgBox.exec();

}

void MainWindow::on_pb_supprimer_ig_clicked()
{
    Ingredients i1;
        i1.setidig(ui->le_idig_2->text().toInt());
        bool test=i1.supprimeringredient(i1.getidig());
        QMessageBox msgBox;
        if (test){
            msgBox.setText("supression avec succes");
            ui->tab_ig->setModel(I.afficheringredient());
        }

}

void MainWindow::on_pb_trier_ig_clicked()
{
    ui->tab_ig->setModel(I.trieringredient());

}

void MainWindow::on_pb_rechercher_ig_clicked()
{

    Ingredients i1;
       i1.setnomig(ui->le_nomig_3->text());
       ui->tab_ig->setModel(I.rechercheringredient(i1.getnomig()));
    }

void MainWindow::on_tab_ig_activated(const QModelIndex &index)
{
  QString val=ui->tab_ig->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT* from ingredients where idig=:val or nomig=:val or qttig=:val or dateig=:val or idp=:val  ");
    query.bindValue(":val",val);
    query.bindValue(":val",val);
    query.bindValue(":val",val);
    query.bindValue(":val",val);
    query.bindValue(":val",val);

    if(query.exec()){

            while(query.next()){
              ui->le_idig_2->setText(query.value(0).toString());
              ui->le_nomig_2->setText(query.value(1).toString());
              ui->le_qtt_2->setText(query.value(2).toString());
              ui->le_date_2->setText(query.value(3).toString());
              ui->le_idp_5->setText(query.value(4).toString());
            }
}

}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("khadija.masmoudi@esprit.tn", "191JFT2121", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("khadija.masmoudi@esprit.tn", ui->le_mail_c->text() , ui->le_nom_c->text(),ui->le_objet_c->text());}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_pb_envoyer_mail_clicked()
{sendMail();

}
