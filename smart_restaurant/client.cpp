#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "connection.h"
Client::Client()
{
    cinc=0;
    nom="";
    prenom="";
    mail="";
    adresse="";
    tel=0;
}

Client::Client(int cinc,QString nom,QString prenom,QString mail,QString adresse,int tel)
{
    this->cinc=cinc;
    this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
    this->adresse=adresse;
    this->tel=tel;
}

int  Client::getcinc(){return cinc;};
QString Client::getnom(){return nom;};
QString Client::getprenom(){return prenom;};
QString Client::getmail(){return mail;};
QString Client::getadresse(){return adresse;};
int Client::gettel(){return tel;};

void Client::setcinc(int cinc){this->cinc=cinc;};
void Client::setnom(QString nom){this->nom=nom;};
void Client::setprenom(QString prenom){this->prenom=prenom;};
void Client::setmail(QString mail){this->mail=mail;};
void Client::setadresse(QString adresse){this->adresse=adresse;};
void Client::settel(int tel){this->tel=tel;};

bool Client::ajouterClient()
{
    QSqlQuery query;
    QString cinc_string= QString::number(cinc);
    QString tel_string= QString::number(tel);

          query.prepare("INSERT INTO client (cinc, nom, prenom, mail, adresse, tel) "
                        "VALUES (:cinc, :nom, :prenom, :mail, :adresse, :tel)");
          query.bindValue(0, cinc_string);
          query.bindValue(1, nom);
          query.bindValue(2, prenom);
          query.bindValue(3, mail);
          query.bindValue(4, adresse);
          query.bindValue(5, tel_string);
          return query.exec();
}

bool Client::supprimerClient(int cinc)
{
    QSqlQuery query;

          query.prepare("DELETE FROM client WHERE cinc=:cinc");
          query.bindValue(":cinc", cinc);
          return query.exec();

}

QSqlQueryModel* Client::afficherClient()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM client");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Tel"));





    return model;
}

bool Client::modifierClient(int cinc)
{
    QString cinc_string=QString::number(cinc);
    QString tel_string=QString::number(tel);
    QSqlQuery query;
    query.prepare("UPDATE client SET cinc=:cinc, nom=:nom, prenom=:prenom, mail=:mail, adresse=:adresse, tel=:tel where cinc=:cinc");
    query.bindValue(":cinc", cinc_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tel", tel_string);
    query.bindValue(":cinc", cinc_string);
    return query.exec();
}

QSqlQueryModel* Client::trierClient()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM client order by nom");


    return model;
}

QSqlQueryModel* Client::rechercherClient(int cinc)
{
    QString cinc_string=QString::number(cinc);
    QSqlQuery query;
    QSqlQueryModel* model= new QSqlQueryModel();
    query.prepare("SELECT * FROM client where cinc=:cinc");
    query.bindValue(":cinc",cinc_string);
    query.exec();
    model->setQuery(query);
    return model;
}
