#include "personnels.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "connection.h"
Personnels::Personnels()
{
idp=0;
nomp="";
prenomp="";
adressep="";
telp=0;
}

Personnels::Personnels (int idp, QString nomp,QString prenomp,QString adressep,int telp)
{
    this->idp=idp;
    this->nomp=nomp;
    this->prenomp=prenomp;
    this->adressep=adressep;
    this->telp=telp;
}

int Personnels::getidp(){return idp;}
QString Personnels::getnomp(){return nomp;}
QString Personnels::getprenomp(){return prenomp;}
QString Personnels::getadressep(){return adressep;}
int Personnels::gettelp(){return telp;}

void Personnels::setidp(int idp){this->idp=idp;}
void Personnels::setnomp(QString nomp){this->nomp=nomp;}
void Personnels::setprenomp(QString prenomp){this->prenomp=prenomp;}
void Personnels::setadressep(QString adressep){this->adressep=adressep;}
void Personnels::settelp(int telp){this->telp=telp;}

bool Personnels::ajouterpersonnels()
{QString idp_String=QString::number(idp);
    QString telp_String=QString::number(telp);
QSqlQuery query;
query.prepare("INSERT INTO personnels (idp,nomp,prenomp,adressep,telp)"
              "VALUES (:idp,:nomp,:prenomp,:adressep,:telp)");
query.bindValue(0,idp_String);
query.bindValue(1,nomp);
query.bindValue(2,prenomp);
query.bindValue(3,adressep);
query.bindValue(4,telp_String);
return query.exec(); }

bool Personnels::supprimerpersonnels(int idp)
{ QSqlQuery query;
query.prepare(" Delete from personnels where idp=:idp");
query.bindValue(0,idp);
return query.exec(); }

QSqlQueryModel* Personnels::afficherpersonnels()

{ QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM personnels");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Telephone"));
    return model;
}

QSqlQueryModel* Personnels::trierpersonnels()

{ QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM personnels ORDER by nomp");
    return model;

}

bool Personnels::modifierpersonnels(int idp)
{
QString idp_string=QString::number(idp);
QString telp_string=QString::number(telp);
    QSqlQuery query;
    query.prepare("UPDATE personnels SET  idp=:idp, nomp=:nomp, adressep=:adressep, telp=:telp, prenomp=:prenomp WHERE idp=:idp " );
    query.bindValue(":idp",idp_string);
    query.bindValue(":nomp",nomp);
    query.bindValue(":adressep",adressep);
    query.bindValue(":prenomp",prenomp);
    query.bindValue(":telp",telp_string);
    query.bindValue(":idp",idp_string);
    return query.exec();
}



QSqlQueryModel* Personnels::rechercherpersonnels(int idp)
{
QString idp_string=QString::number(idp);
QSqlQuery query;
    QSqlQueryModel* model= new QSqlQueryModel();
   query.prepare("SELECT* FROM personnels where idp=:idp");
   query.bindValue(":idp",idp_string);
   query.exec();
   model->setQuery(query);
    return model;

}




