#include "platswindow.h"
#include "ui_platswindow.h"
#include "plats.h"
#include "specialites.h"
#include "ingredients.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlQuery>
#include <excel.h>
#include <QTextStream>

platswindow::platswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::platswindow)
{
    ui->setupUi(this);
    ui->tab_plat->setModel(P.afficherplat());
    ui->tab_sp->setModel(S.afficherspecialite());
    ui->tab_ig->setModel(I.afficheringredient());
    ui->notes->hide();
    ui->btn_notes->hide();
    ui->tab_plat->setModel(P.afficherplat());
    ui->tab_sp->setModel(S.afficherspecialite());
    ui->tab_ig->setModel(I.afficheringredient());

    QPieSeries *Series = new QPieSeries();
     QSqlTableModel *Mymodels=P.statistiqueplat();
     Mymodels->setFilter("prixp < 30");
     int num=Mymodels->rowCount();
     Series->append(" moins de 30 dt ",num);
     Mymodels=P.statistiqueplat();
      Mymodels->setFilter("prixp between 30 and 80");
       num=Mymodels->rowCount();
      Series->append("entre 30 et 80 dt",num);
      Mymodels=P.statistiqueplat();
      Mymodels->setFilter("prixp between 80 and 200 ");
       num=Mymodels->rowCount();
      Series->append("entre 80 et 200 dt ",num);
      Mymodels=P.statistiqueplat();
      Mymodels->setFilter("prixp > 200");
       num=Mymodels->rowCount();
      Series->append(">200 dt ",num);
      QChart *chart = new QChart();
      chart->addSeries(Series);
      chart->setTitle("les prix des plats ");
      QChartView *chartview =new QChartView(chart);
      chartview->setParent(ui->horizontalFrame);
      timer=new QTimer(this);
      connect(timer,SIGNAL(timeout()),this,SLOT (myfunction()));
      timer->start(1000);
      QPixmap pix("C:/Users/mondh/Desktop/projet c++/gestionachat/smart.png");
     ui->image->setPixmap(pix.scaled(100,80,Qt::KeepAspectRatio));
     QFile file("C:/Users/mondh/Desktop/Historique1.txt");
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(0,"info",file.errorString());
        }
        QTextStream in (&file);
}

platswindow::~platswindow()
{
    delete ui;
}

void platswindow::myfunction()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh:mm:ss");
    ui->label_date->setText(time_text);
    QDate date = QDate::currentDate();
        QString date_text= date.toString("dd / MM / yyyy");
        ui->label_date1->setText(date_text);
}



void platswindow::on_pb_ajouter_clicked()
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
       }
            else if(test1==false){
                msgBox.setText("verifier le prix ");
                }
        else {msgBox.setText("echec de l'ajout ");}
                msgBox.exec();

    }

void platswindow::on_pb_supprimer_p_clicked()
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

void platswindow::on_pb_modifier_p_clicked()
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





void platswindow::on_pb_trierplat_clicked()
{ ui->tab_plat->setModel(P.trierplat());

}

void platswindow::on_pb_rechercher_p_clicked()
{ Plats p1;
    p1.setnomp(ui->le_nomp_3->text());
    ui->tab_plat->setModel(P.rechercherplat(p1.getnomp()));
}






void platswindow::on_pb_ajoutersp_clicked()
{bool test1=true,test=true;
    QFile file("C:/Users/mondh/Desktop/historique1.txt");
                   if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                       return;

          QTextStream cout(&file);
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
    {QString message2="\nVous avez ajouté une spécialité";
        cout << message2;
        QFile file("C:/Users/mondh/Desktop/historique1.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
      ui->textBrowser->setText(in.readAll());
        msgBox.setText("Ajout avec succes.");
        ui->tab_sp->setModel(S.afficherspecialite());}
        else if(test1==false) {
            msgBox.setText("verifier le type");}
    else { msgBox.setText("echec de l'ajout");}
            msgBox.exec();

}

void platswindow::on_pb_supprimer_sp_clicked()
{ QFile file("C:/Users/mondh/Desktop/historique1.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;

QTextStream cout(&file);
Specialites s1;
    s1.setidsp(ui->le_idsp_2->text().toInt());
    bool test=s1.supprimerspecialite(s1.getidsp());
    QMessageBox msgBox;
    if (test){
        QString message2="\nVous avez supprimé une spécialité";
                                       cout << message2;
                                       QFile file("C:/Users/mondh/Desktop/historique1.txt");
                                      if (!file.open(QIODevice::ReadOnly))
                                      {
                                          QMessageBox::information(0,"info",file.errorString());
                                      }
                                      QTextStream in (&file);
                                     ui->textBrowser->setText(in.readAll());
        msgBox.setText("supression avec succés");
        ui->tab_sp->setModel(S.afficherspecialite());
    }

}

void platswindow::on_pb_trier_sp_clicked()
{ ui->tab_sp->setModel(S.trierspecialite());

}







void platswindow::on_pb_rechercher_sp_clicked()
{
    Specialites s1;
       s1.setnomsp(ui->le_nomsp_3->text());
       ui->tab_sp->setModel(S.rechercherspecialite(s1.getnomsp()));
}

void platswindow::on_pb_modifier_sp_clicked()
{ bool test=true,test1=true;
    QFile file("C:/Users/mondh/Desktop/historique1.txt");
                   if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                       return;

          QTextStream cout(&file);
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
    {QString message2="\nVous avez modifié une spécialité";
        cout << message2;
        QFile file("C:/Users/mondh/Desktop/historique1.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
      ui->textBrowser->setText(in.readAll());
        msgBox.setText("Modif avec succes.");
        ui->tab_sp->setModel(S.afficherspecialite());}
        else if(test1==false) {
            msgBox.setText("verifier le nom");
            }
      else {msgBox.setText("echec de la modification");}
            msgBox.exec();
}





void platswindow::on_tab_plat_activated(const QModelIndex &index)
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

void platswindow::on_pb_ajouterig_clicked()
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

void platswindow::on_pb_modifier_ig_clicked()
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

void platswindow::on_pb_supprimer_ig_clicked()
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

void platswindow::on_pb_trier_ig_clicked()
{
    ui->tab_ig->setModel(I.trieringredient());

}

void platswindow::on_pb_rechercher_ig_clicked()
{

    Ingredients i1;
       i1.setnomig(ui->le_nomig_3->text());
       ui->tab_ig->setModel(I.rechercheringredient(i1.getnomig()));
    }

void platswindow::on_tab_ig_activated(const QModelIndex &index)
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




void platswindow::on_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                ExportExcelObject obj(fileName, "mydata", ui->tab_plat);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "id", "char(20)");
                obj.addField(1, "nom", "char(20)");
                obj.addField(2, "prix", "char(20)");
                obj.addField(3, "spécialité", "char(20)");


                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                             );
                }
}

void platswindow::on_btn_ajout_notes_clicked()
{
    ui->notes->show();
        ui->btn_notes->show();
}

void platswindow::on_btn_notes_clicked()
{
    QFile file("C:/Users/mondh/Desktop/notes.txt");
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
            QString message2="-"+ui->notes->toPlainText()+"\n";
                    cout << message2;
                    ui->notes->hide();
                    ui->btn_notes->hide();
}
