#include <QObject>
#include "plats.h"
#include <QSqlQuery>
#include <QtDebug>
#include "connection.h"
Plats::Plats()
{
idp=0;
nomp="";
prixp=0;
}

Plats::Plats (int idp, QString nomp,float prixp)
{
    this->idp=idp;
    this->nomp=nomp;
    this->prixp=prixp;
}

int Plats::getidp(){return idp;}
QString Plats::getnomp(){return nomp;}
float Plats::getprixp(){return prixp;}

void Plats::setidp(int idp){this->idp=idp;}
void Plats::setnomp(QString nomp){this->nomp=nomp;}
void Plats::setprixp(float prixp){this->prixp=prixp;}

bool Plats::ajouterplat()
{QString idp_string=QString::number(idp);
    QString prixp_string=QString::number(prixp);
QSqlQuery query;
query.prepare("INSERT INTO plats (idp,nomp,prixp)"
              "VALUES (:idp,:nomp,:prixp)");
query.bindValue(0,idp_string);
query.bindValue(1,nomp);
query.bindValue(2,prixp_string);

return query.exec();}

QSqlQueryModel* Plats::afficherplat()

{ QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM plats");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nomp"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Prixp"));
return model;
}

bool Plats::supprimerplat(int idp)
{ QSqlQuery query;
query.prepare(" Delete from plats where idp=:idp");
query.bindValue(0,idp);
return query.exec(); }

QSqlQueryModel* Plats::trierplat()

{ QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM plats ORDER by Prixp");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nomp"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Prixp"));
return model;
}
