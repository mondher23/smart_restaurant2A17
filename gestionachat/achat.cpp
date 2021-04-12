#include "achat.h"
#include <QtDebug>
#include <QObject>
#include "connection.h"
Achat::Achat()
{
    ida=0;
    prixa=0;
    datea="";
    idf=0;

}

Achat::Achat(int ida,float prixa,QString datea,int idf)
{

    this->ida=ida;
    this->prixa=prixa;
    this->datea=datea;
    this->idf=idf;

}

int Achat::getida(){return ida ;}
float Achat::getprixa(){return prixa ;}
QString Achat::getdatea(){return datea;}
int Achat::getidf(){return idf; }

void Achat::setida(int ida){this->ida=ida;}
void Achat::setprixa(float prixa){this->prixa=prixa;}
void Achat::setdatea(QString datea){this->datea=datea;}
void Achat::setidf(int idf){this->idf=idf;}


bool Achat::ajouterachat()
{
QString ida_string=QString::number(ida);
QString prixa_string=QString::number(prixa);
QString idf_string=QString::number(idf);
    QSqlQuery query;
    query.prepare("INSERT INTO achat (ida,prixa,datea,idf)"
                  "VALUES (:ida,:prixa,:datea,:idf)" );
    query.bindValue(0,ida_string);
    query.bindValue(1,prixa_string);
    query.bindValue(2,datea);
    query.bindValue(3,idf_string);

    return query.exec();

}
QSqlQueryModel* Achat::afficherachat(){


    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT* FROM achat");
    return model;


}
bool Achat::supprimerachat(int ida)
{
    QSqlQuery query ;
    query.prepare("Delete from achat where ida=:ida");
    query.bindValue(0,ida);
    return query.exec();
}
bool Achat::modifierachat(int ida)
{
    QString ida_string=QString::number(ida);
    QString prixa_string=QString::number(prixa);
    QString idf_string=QString::number(idf);
    QSqlQuery query;
    query.prepare("UPDATE achat SET  ida=:ida, prixa=:prixa, datea=:datea, idf=:idf WHERE ida=:ida " );
    query.bindValue(":ida",ida_string);
    query.bindValue(":prixa",prixa_string);
    query.bindValue(":datea",datea);
    query.bindValue(":idf",idf_string);
    query.bindValue(":ida",ida_string);
    return query.exec();

}
QSqlQueryModel* Achat::trierachat(){


    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT* FROM achat ORDER by prixa");
    return model;


}
QSqlQueryModel* Achat::rechercherachat(int ida){
QString ida_string=QString::number(ida);
QSqlQuery query;
    QSqlQueryModel* model= new QSqlQueryModel();
   query.prepare("SELECT* FROM achat where ida=:ida");
   query.bindValue(":ida",ida_string);
   query.exec();
   model->setQuery(query);
    return model;

}
QSqlQueryModel* Achat::statistiqueachat(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT idf,count(*) as nombre_achats from achat group by idf ");
    return model;
}
