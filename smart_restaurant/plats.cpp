#include <QObject>
#include "plats.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlTableModel>
#include "connection.h"
Plats::Plats()
{
idp=0;
nomp="";
prixp=0;
idsp=0;
}

Plats::Plats (int idp, QString nomp,float prixp,int idsp)
{
    this->idp=idp;
    this->nomp=nomp;
    this->prixp=prixp;
    this->idsp=idsp;
}

int Plats::getidp(){return idp;}
QString Plats::getnomp(){return nomp;}
float Plats::getprixp(){return prixp;}
int Plats::getidsp(){return idsp;}

void Plats::setidp(int idp){this->idp=idp;}
void Plats::setnomp(QString nomp){this->nomp=nomp;}
void Plats::setprixp(float prixp){this->prixp=prixp;}
void Plats::setidsp(int idsp){this->idsp=idsp;}

bool Plats::ajouterplat()
{QString idp_string=QString::number(idp);
    QString prixp_string=QString::number(prixp);
    QString idsp_string=QString::number(idsp);
QSqlQuery query;
query.prepare("INSERT INTO plats (idp,nomp,prixp,idsp)"
              "VALUES (:idp,:nomp,:prixp,:idsp)");
query.bindValue(0,idp_string);
query.bindValue(1,nomp);
query.bindValue(2,prixp_string);
query.bindValue(3,idsp_string);

return query.exec();}

QSqlQueryModel* Plats::afficherplat()

{ QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM plats");
return model;
}

bool Plats::supprimerplat(int idp)
{ QSqlQuery query;
query.prepare(" Delete from plats where idp=:idp");
query.bindValue(0,idp);
return query.exec(); }

bool Plats::modifierplat(int idp)
{QString idp_string=QString::number(idp);
    QString prixp_string=QString::number(prixp);
    QString idsp_string=QString::number(idsp);
QSqlQuery query;
query.prepare("UPDATE  plats SET idp=:idp, nomp=:nomp, prixp=:prixp,idsp=:idsp WHERE idp=:idp");
query.bindValue(":idp",idp_string);
query.bindValue(":nomp",nomp);
query.bindValue(":prixp",prixp_string);
query.bindValue(":idsp",idsp_string);
query.bindValue(":idp",idp_string);
return query.exec();}

QSqlQueryModel* Plats::trierplat()

{ QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM plats ORDER by nomp");

return model;
}



QSqlQueryModel * Plats::rechercherplat(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString recher="select * from plats where nomp like '%"+rech+"%' ";
    model->setQuery(recher);
    return model;
}



QSqlTableModel* Plats::statistiqueplat(){
    QSqlTableModel* model= new QSqlTableModel();
    model->setTable("plats");
    model->select();

    return model;
}
