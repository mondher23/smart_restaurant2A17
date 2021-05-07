#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "client.h"
#include "carte.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include "excel.h"
#include <QTextStream>

clientwindow::clientwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientwindow)
{
    ui->setupUi(this);
    ui->le_cinc->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_client->setModel(C.afficherClient());
    ui->tab_carte->setModel(Cr.afficherCarte());
    ui->notes->hide();
        ui->btn_notes->hide();
        ui->tab_client->setModel(C.afficherClient());
        ui->tab_carte->setModel(Cr.afficherCarte());
    QPieSeries *Series = new QPieSeries();
        QSqlTableModel *Mymodels=Cr.statistiquecarte();
        Mymodels->setFilter("pts == 0");
        int num=Mymodels->rowCount();
        Series->append(" 0 points ",num);
        Mymodels=Cr.statistiquecarte();
         Mymodels->setFilter("pts between 1 and 50");
          num=Mymodels->rowCount();
         Series->append("entre 1 et 50 points",num);
         Mymodels=Cr.statistiquecarte();
         Mymodels->setFilter("pts between 51 and 100 ");
          num=Mymodels->rowCount();
         Series->append("entre 51 et 100 points ",num);
         Mymodels=Cr.statistiquecarte();
         Mymodels->setFilter("pts between 101 et 200");
          num=Mymodels->rowCount();
         Series->append(" entre 101 et 200 points ",num);
        Mymodels=Cr.statistiquecarte();
         Mymodels->setFilter("pts > 200");
          num=Mymodels->rowCount();
         Series->append("plus de 200 points",num);
         QChart *chart = new QChart();
         chart->addSeries(Series);
         chart->setTitle("nombre de cartes de fidélité possédées par les clients");
         QChartView *chartview =new QChartView(chart);
         chartview->setParent(ui->horizontalFrame);
         timer=new QTimer(this);
         connect(timer,SIGNAL(timeout()),this,SLOT (myfunction()));
         timer->start(1000);
         QPixmap pix("C:/Users/mondh/Desktop/projet c++/gestionachat/smart.png");
        ui->image->setPixmap(pix.scaled(100,80,Qt::KeepAspectRatio));
        QFile file("C:/Users/mondh/Desktop/Historique3.txt");
           if (!file.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file.errorString());
           }
           QTextStream in (&file);

}

clientwindow::~clientwindow()
{
    delete ui;
}
void clientwindow::myfunction()
{
    QTime time = QTime::currentTime();
    QString time_text= time.toString("hh : mm : ss");
    ui->label_date->setText(time_text);
    QDate date = QDate::currentDate();
    QString date_text= date.toString("dd / MM / yyyy");
    ui->label_date1->setText(date_text);

}

void clientwindow::on_pb_ajouter_clicked()
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

    }
    else
        msgBox.setText("Echec de l'ajout veuillez verifier le num tel(8 chiffres)");
        msgBox.exec();
}

void clientwindow::on_pb_modifier_clicked()
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

    }
    msgBox.exec();
}

void clientwindow::on_pb_supprimer_clicked()
{
    Client C1; C1.setcinc(ui->le_cinc_2->text().toInt());
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

void clientwindow::on_pb_rechercher_clicked()
{
     Client C1;
     C1.setcinc(ui->le_cinc_rech->text().toInt());
     ui->tab_client->setModel(C.rechercherClient(C1.getcinc()));

}

void clientwindow::on_tab_client_activated(const QModelIndex &index)
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



void clientwindow::on_pb_ajouter_2_clicked()
{QFile file("C:/Users/mondh/Desktop/historique3.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;

QTextStream cout(&file);
    bool controle=true;
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
    {QString message2="\nVous avez ajouté une carte";
        cout << message2;
        QFile file("C:/Users/mondh/Desktop/historique3.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
      ui->textBrowser->setText(in.readAll());
        msgBox.setText("Ajout avec succes. ");
        ui->tab_carte->setModel(Cr.afficherCarte());

    }
    else
        msgBox.setText("Echec de l'ajout expire doit etre oui ou non ");
        msgBox.exec();
}

void clientwindow::on_pb_supprimer_2_clicked()
{QFile file("C:/Users/mondh/Desktop/historique.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;

QTextStream cout(&file);

    Carte Cr1; Cr1.setcinc(ui->le_cincc_2->text().toInt());
    bool test=Cr1.supprimerCarte(Cr1.getcinc());
    QMessageBox msgBox;

    if(test)
    {QString message2="\nVous avez supprimé une carte";
        cout << message2;
        QFile file("C:/Users/mondh/Desktop/historique.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
      ui->textBrowser->setText(in.readAll());
        msgBox.setText("Suppression avec succes. ");
        ui->tab_carte->setModel(Cr.afficherCarte());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}


void clientwindow::on_pb_modifier_2_clicked()
{QFile file("C:/Users/mondh/Desktop/historique3.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;

QTextStream cout(&file);
    int cinc=ui->le_cincc_2->text().toInt();
    int pts=ui->le_pts_2->text().toInt();
    QString expire=ui->le_exp_2->text();

    Carte Cr2(cinc,pts,expire);
    bool test=Cr2.modifierCarte(Cr2.getcinc());
    QMessageBox msgBox;

    if(test)
    {QString message2="\nVous avez modifié une carte";
        cout << message2;
        QFile file("C:/Users/mondh/Desktop/historique.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
      ui->textBrowser->setText(in.readAll());
        msgBox.setText("modifié avec succes. ");
        ui->tab_carte->setModel(Cr.afficherCarte());

    }
    else
        msgBox.setText("Echec de la modification");
        msgBox.exec();
}


void clientwindow::on_pb_rechercher_2_clicked()
{
     Carte Cr1;
     Cr1.setcinc(ui->le_cincc_rech->text().toInt());
     ui->tab_carte->setModel(Cr.rechercherCarte(Cr1.getcinc()));

}

void clientwindow::on_pb_tri_clicked()
{
    ui->tab_client->setModel(C.trierClient());
}

void clientwindow::on_pb_tri_2_clicked()
{
    ui->tab_carte->setModel(Cr.trierCarte());
}



void clientwindow::on_tab_carte_activated(const QModelIndex &index)
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

/*void clientwindow::sendMail()
{
    Smtp* smtp = new Smtp("mohamedaziz.bensalem@esprit.tn", "191JMT1634", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("mohamedaziz.bensalem@esprit.tn", ui->le_email->text() , ui->le_objet->text(),ui->le_texte->text());
}

void clientwindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void clientwindow::on_envoyer_clicked()
{
    sendMail();
}*/

void clientwindow::on_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                ExportExcelObject obj(fileName, "mydata", ui->tab_client);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "cin", "char(20)");
                obj.addField(1, "mail", "char(20)");
                obj.addField(2, "nom", "char(20)");
                obj.addField(3, "prénom", "char(20)");
                obj.addField(4, "adresse", "char(20)");
                obj.addField(5, "tel", "char(20)");


                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                             );
                }
}

void clientwindow::on_btn_ajout_notes_clicked()
{
    ui->notes->show();
        ui->btn_notes->show();
}

void clientwindow::on_btn_notes_clicked()
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
