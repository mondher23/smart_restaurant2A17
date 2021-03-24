#include "personnels.h"
#include <QSqlQuery>
#include <QtDebug>
Personnels::Personnels();
{
IdP=0;
NomP="";
PrenomP="";
AdresseP="";
TelP=0;
}

Personnels::Personnels (int IdP, QString NomP,QString PrenomP,QString AdresseP,int TelP)
{
    this->IdP=IdP;
    this->NomP=NomP;
    this->PrenomP=PrenomP;
    this->AdresseP=AdresseP;
    this->TelP=TelP;
}

int Personnels::getIdP(){return IdP};
QString Personnels::getNomP(){return NomP};
QString Personnels::getPrenomP(){return PrenomP};
QString Personnels::getAdresseP(){return AdresseP};
int Personnels::getTelP(){return TelP};

void Personnels::setIdP(int IdP){this->IdP=IdP};
void Personnels::setNomP(int NomP){this->NomP=NomP};
void Personnels::setPrenomP(int PrenomP){this->PrenomP=PrenomP};
void Personnels::setAdresseP(int IdP){this->AdresseP=AdresseP};
void Personnels::setTelP(int TelP){this->TelP=TelP};

bool Personnels::ajouterPersonnel()
{bool test=false;
QSqlQuery query;
query.prepare("INSERT INTO Personnels (IdP,NomP,PrenomP,AdresseP,TelP)"
              "VALUES (:IdP,:NomP,:PrenomP,:AdresseP,:TelP)"};
query.bindValue(":IdP",IdP);
query.bindValue(":NomP",NomP);
query.bindValue(":PrenomP",PrenomP);
query.bindValue(":AdresseP",AdresseP);
query.bindValue(":TelP",TelP);
query.exec();




