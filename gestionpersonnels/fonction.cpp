#include "fonction.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "connection.h"
Fonction::Fonction()
{
fonctionp="";
salairep=0;
nombre_heurep=0;
idp=0;
}

Fonction::Fonction ( QString fonctionp, float salairep,float nombre_heurep,int idp)
{
    this->fonctionp=fonctionp;
    this->salairep=salairep;
    this->nombre_heurep=nombre_heurep;
    this->idp=idp;

}

QString Fonction::getfonctionp(){return fonctionp;}
float Fonction::getsalairep(){return salairep;}
float Fonction::getnombre_heurep(){return nombre_heurep;}
int Fonction::getidp(){return idp;}


void Fonction::setfonctionp(QString fonctionp){this->fonctionp=fonctionp;}
void Fonction::setsalairep(float salairep){this->salairep=salairep;}
void Fonction::setnombre_heurep(float nombre_heurep){this->nombre_heurep=nombre_heurep;}
void Fonction::setidp(int idp){this->idp=idp;}

bool Fonction::ajouterfonctions()
{QString salairep_String=QString::number(salairep);
    QString nombre_heurep_String=QString::number(nombre_heurep);
    QString idp_String=QString::number(idp);
QSqlQuery query;
query.prepare("INSERT INTO fonction (fonctionp,salairep,nombre_heurep,idp)"
              "VALUES (:fonctionp,:salairep,:nombre_heurep,:idp)");
query.bindValue(0,fonctionp);
query.bindValue(1,salairep_String);
query.bindValue(2,nombre_heurep_String);
query.bindValue(3,idp_String);

return query.exec(); }

bool Fonction::supprimerfonctions(QString fonctionp)
{ QSqlQuery query;
query.prepare(" Delete from fonction where fonctionp=:fonctionp");
query.bindValue(0,fonctionp);
return query.exec(); }

QSqlQueryModel* Fonction::afficherfonctions()

{ QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM fonction");

    return model;
}

QSqlQueryModel* Fonction::trierfonctions()

{ QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM fonction ORDER by salairep");
    return model;

}

bool Fonction::modifierfonctions(QString fonctionp)
{
QString salairep_string=QString::number(salairep);
QString nombre_heurep_string=QString::number(nombre_heurep);
QString idp_String=QString::number(idp);
    QSqlQuery query;
    query.prepare("UPDATE fonction SET  fonctionp=:fonctionp, salairep=:salairep, nombre_heurep=:nombre_heurep, idp=:idp  WHERE fonctionp=:fonctionp " );
    query.bindValue(":fonctionp",fonctionp);
    query.bindValue(":salairep",salairep_string);
    query.bindValue(":nombre_heurep",nombre_heurep_string);
    query.bindValue(":idp",idp_String);
    query.bindValue(":fonctionp",fonctionp);

    return query.exec();
}



QSqlQueryModel* Fonction::rechercherfonctions(QString fonctionp)
{

QSqlQuery query;
    QSqlQueryModel* model= new QSqlQueryModel();
   query.prepare("SELECT* FROM fonction where fonctionp=:fonctionp");
   query.bindValue(":fonctionp",fonctionp);
   query.exec();
   model->setQuery(query);
    return model;

}
QSqlQueryModel* Fonction::stats()
{

    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT nombre_heurep,count(*) as nombre_employe from fonction group by nombre_heurep ");
    return model;

}
