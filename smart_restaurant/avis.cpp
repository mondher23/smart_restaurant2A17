#include "avis.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

//définition du constructeur par défaut:
Avis::Avis()
{
id_a=0; avis=""; note=0;
}

//définition du constructeur paramétré:
Avis::Avis(int id_a,QString avis,qreal note){
this->id_a=id_a;
this->avis=avis;
this->note=note;
}


//définition des getters:
int Avis::get_id_a(){return id_a;}
QString Avis:: get_avis(){return avis;}
qreal Avis:: get_note(){return note;}


//définition des setters:
void Avis:: set_id_a(int id_a){this->id_a=id_a;}
void Avis:: set_avis(QString avis){this->avis=avis;}
void Avis:: set_note(qreal note){this->note=note;}


//définition de la méthode ajouter:
bool Avis::ajouter(){


    QSqlQuery query;  //declaration de requette sql
    //QString numero_string= QString::number(numero); //convertire num a QString
    query.prepare("INSERT INTO AVIS (ID_A, AVIS,NOTE) "
                  "VALUES (:id_a, :avis, :note)");   //preparation de requette
    query.bindValue(":id_a", id_a); //injection sql (securité)
    query.bindValue(":avis", avis);
    query.bindValue(":note", note);

    return   query.exec();


}



bool Avis::supprimer(int id_a){

 QSqlQuery query;

    query.prepare("Delete from AVIS where ID_A=:id_a");
    query.bindValue(0, id_a);

    return   query.exec();

}





QSqlQueryModel* Avis::afficher(){

    QSqlQueryModel* model=new QSqlQueryModel(); //representation graphique d un table sql

         model->setQuery("SELECT * FROM AVIS");

    return model;
}




QSqlQueryModel * Avis::chercher(int id_a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString rech=QString::number(id_a);
    model->setQuery("select * from AVIS where ID_A like '"+rech+"%'");

        return model;
}

bool Avis::modifier(int id_a)
{
    QSqlQuery query;
    query.prepare("update AVIS set AVIS=:avis,NOTE=:note where ID_A=:id_a");
    query.bindValue(":id_a", id_a);
    query.bindValue(":avis", avis);
    query.bindValue(":note", note);

   return   query.exec();




      /*  QSqlQuery query;
        query.prepare("UPDATE AVIS set ID_A=:id_a ,AVIS=:avis,NOTE=:note where ID_A=:id_a " );
        query.bindValue(":id_a", id_a);
        query.bindValue(":avis", avis);
        query.bindValue(":note", note);
        query.bindValue(":id_a", id_a);
        return query.exec();*/


}
QSqlQueryModel * Avis::trier(QString selon)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from AVIS order by "+selon+"");

        return model;
}
QSqlQueryModel * Avis::stat()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select NOTE,count(*) as nombre from AVIS group by NOTE");

        return model;
}
