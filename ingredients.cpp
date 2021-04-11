#include "ingredients.h"
#include <QObject>
#include "plats.h"
#include <QSqlQuery>
#include <QtDebug>
#include "connection.h"

Ingredients::Ingredients()
{
    idig=0;
    nomig="";
    qttig="";
    dateig="";
    idp=0;
}

Ingredients::Ingredients(int idig, QString nomig, QString qttig, QString dateig,int idp)
{
    this->idig=idig;
    this->nomig=nomig;
    this->qttig=qttig;
    this->dateig=dateig;
    this->idp=idp;
}

int Ingredients::getidig(){return idig;}
QString Ingredients::getnomig(){return nomig;}
QString Ingredients::getqttig(){return qttig;}
QString Ingredients::getdateig(){return dateig;}
int Ingredients::getidp(){return idp;}

void Ingredients::setidig(int idig){this->idig=idig;}
void Ingredients::setnomig(QString nomig){this->nomig=nomig;}
void Ingredients::setqttig(QString qttig){this->qttig=qttig;}
void Ingredients::setdateig(QString dateig){this->dateig=dateig;}
void Ingredients::setidp(int idp){this->idp=idp;}

bool Ingredients::ajouteringredient()
{QString idig_string=QString::number(idig);
    QString idp_string=QString::number(idp);
QSqlQuery query;
query.prepare("INSERT INTO ingredients (idig,nomig,qttig,dateig,idp)"
              "VALUES (:idig,:nomig,:qttig,:dateig,:idp)");
query.bindValue(0,idig_string);
query.bindValue(1,nomig);
query.bindValue(2,qttig);
query.bindValue(3,dateig);
query.bindValue(4,idp_string);

return query.exec();}


QSqlQueryModel* Ingredients::afficheringredient()

{ QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM ingredients");
return model;
}





bool Ingredients::supprimeringredient(int idig)
{ QSqlQuery query;
query.prepare(" Delete from ingredients where idig=:idig");
query.bindValue(0,idig);
return query.exec(); }

bool Ingredients::modifieringredient(int idig)
{QString idig_string=QString::number(idig);
    QString idp_string=QString::number(idp);
QSqlQuery query;
query.prepare("UPDATE  ingredients SET idig=:idig, nomig=:nomig, qttig=:qttig, dateig=:dateig,idp=:idp WHERE idig=:idig");
query.bindValue(":idig",idig_string);
query.bindValue(":nomig",nomig);
query.bindValue(":qttig",qttig);
query.bindValue(":dateig",dateig);
query.bindValue(":idp",idp_string);
query.bindValue(":idig",idig_string);
return query.exec();}

QSqlQueryModel* Ingredients::trieringredient()

{ QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM ingredients ORDER by nomig");

return model;
}

QSqlQueryModel* Ingredients::rechercheringredient(QString nomig)
{
QSqlQuery query;
 QSqlQueryModel* model=new QSqlQueryModel();
query.prepare(" SELECT * from ingredients where nomig=:nomig");
query.bindValue(":nomig",nomig);
query.exec();
model->setQuery(query);
return model;

}


