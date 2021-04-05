#include <QObject>
#include "specialites.h"
#include <QSqlQuery>
#include <QtDebug>
#include "connection.h"
Specialites::Specialites()
{
idsp=0;
nomsp="";
typesp="";
}

Specialites::Specialites (int idsp, QString nomsp,QString typesp)
{
    this->idsp=idsp;
    this->nomsp=nomsp;
    this->typesp=typesp;
}

int Specialites::getidsp(){return idsp;}
QString Specialites::getnomsp(){return nomsp;}
QString Specialites::gettypesp(){return typesp;}

void Specialites::setidsp(int idsp){this->idsp=idsp;}
void Specialites::setnomsp(QString nomsp){this->nomsp=nomsp;}
void Specialites::settypesp(QString typesp){this->typesp=typesp;}

bool Specialites::ajouterspecialite()
{QString idsp_string=QString::number(idsp);

QSqlQuery query;
query.prepare("INSERT INTO specialites (idsp,nomsp,typesp)"
              "VALUES (:idsp,:nomsp,:typesp)");
query.bindValue(0,idsp_string);
query.bindValue(1,nomsp);
query.bindValue(2,typesp);

return query.exec();}

QSqlQueryModel* Specialites::afficherspecialite()

{ QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM specialites");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idsp"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nomsp"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("typesp"));
return model;
}
bool Specialites::supprimerspecialite(int idsp)
{ QSqlQuery query;
query.prepare(" Delete from specialites where idsp=:idsp");
query.bindValue(0,idsp);
return query.exec(); }

