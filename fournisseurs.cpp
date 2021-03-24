#include "fournisseurs.h"
#include <QSqlQuery>
#include <Qtdebug>


Fournisseur::Fournisseur()
{
idf=0;
nomf="";
adressef="";
telf="";
numcompte=0;

}

Fournisseur::Fournisseur(int idf,QString nomf,QString adressef,Qstring telf,int numcompte)
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
    bool test=false;
    QsqlQuery query;
    query.prepare("INSERT INTO fournisseur (idf,nomf,adressef,telf,numcompte)"
                  "VALUES (:idf,:nomf,:adressef,:telf,:numcomptef)" );
    query.bindValue(":idf",idf);
    query.bindValue(":nomf",nomf);
    query.bindValue(":adressef",adressef);
    query.bindValue(":telf",telf);
    query.bindValue(":numcompte",numcompte);
    query.exec();

}
