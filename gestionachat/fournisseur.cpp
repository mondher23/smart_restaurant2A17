#include <QtDebug>
#include <QObject>
#include "connection.h"
#include "connection.h"
#include "fournisseur.h"

Fournisseur::Fournisseur()
{
idf=0;
nomf="";
adressef="";
telf="";
numcompte=0;

}

Fournisseur::Fournisseur(int idf,QString nomf,QString adressef,QString telf,int numcompte)
{
    this->idf=idf;
    this->nomf=nomf;
    this->adressef=adressef;
    this->telf=telf;
    this->numcompte=numcompte;

}

int Fournisseur::getidf(){return idf ;}
QString Fournisseur::getnomf(){return nomf ;}
QString Fournisseur::getadressef(){return adressef;}
QString Fournisseur::gettelf(){return telf;}
int Fournisseur::getnumcompte(){return numcompte; }

void Fournisseur::setidf(int idf){this->idf=idf;}
void Fournisseur::setnomf(QString nomf){this->nomf=nomf;}
void Fournisseur::setadressef(QString adressef){this->adressef=adressef;}
void Fournisseur::settelf(QString telf){this->telf=telf;}
void Fournisseur::setnumcompte(int numcompte){this->numcompte=numcompte;}

bool Fournisseur::ajouterfournisseur()
{
QString idf_string=QString::number(idf);
QString numcompte_string=QString::number(numcompte);
    QSqlQuery query;
    query.prepare("INSERT INTO fournisseur (idf,nomf,adressef,telf,numcompte)"
                  "VALUES (:idf,:nomf,:adressef,:telf,:numcomptef)" );
    query.bindValue(0,idf_string);
    query.bindValue(1,nomf);
    query.bindValue(2,adressef);
    query.bindValue(3,telf);
    query.bindValue(4,numcompte_string);
    return query.exec();

}
QSqlQueryModel* Fournisseur::afficherfournisseur(){


    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT* FROM fournisseur");
    return model;



}
