#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
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

int  Client::getcinc(){return cinc;}
QString Client::getnom(){return nom;};
QString Client::getprenom(){return prenom;};
QString Client::getmail(){return mail;};
QString Client::getadresse(){return adresse;};
int Client::gettel(){return tel;};

void Client::setcin(int cinc){this->cinc=cinc;};
void Client::setnom(QString nom){this->nom=nom;};
void Client::setprenom(QString prenom){this->prenom=prenom;};
void Client::setmail(QString mail){this->mail=mail;};
void Client::setadresse(QString adresse){this->adresse=adresse;};
void Client::settel(int tel){this->tel=tel;};

bool Client::ajouterClient()
{ bool test=false;
    QSqlQuery query;
          query.prepare("INSERT INTO client (cinc, nom, prenom, mail, adresse, tel) "
                        "VALUES (:cinc, :nom, :prenom, :mail, :adresse, :tel)");
          query.bindValue(":cinc", cinc);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":mail", mail);
          query.bindValue(":adresse", adresse);
          query.bindValue(":tel", tel);
          query.exec();


}
