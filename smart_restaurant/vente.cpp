#include "vente.h"

vente::vente()
{

}
vente::vente(int id_comv,qreal prix_comv,QString temps_livraison)
{
    this->id_comv=id_comv;
    this->prix_comv=prix_comv;
    this->temps_livraison=temps_livraison;
}
bool vente::ajouter(){


    QSqlQuery query;
    //QString age_string= QString::number(age);
    query.prepare("INSERT INTO VENTE (ID_COMV,PRIX_COMV, TEMPS_LIVRAISON) "
                  "VALUES (:id_comv, :prix_comv, :temps_livraison)");
    query.bindValue(":id_comv",id_comv);
    query.bindValue(":prix_comv", prix_comv);
    query.bindValue(":temps_livraison", temps_livraison);

    return   query.exec();


}
bool vente::supprimer(int id_comv){

 QSqlQuery query;

    query.prepare("Delete from VENTE where ID_COMV=:ID_COMV");
    query.bindValue(0, id_comv);

    return   query.exec();

}
QSqlQueryModel* vente::afficher(){

    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM VENTE");

    return model;
}
QSqlQueryModel * vente::chercher(int id_comv)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString rech=QString::number(id_comv);
    model->setQuery("select * from VENTE where ID_COMV like '"+rech+"%'");

        return model;
}
bool vente::modifier(int id_comv)
{
    QSqlQuery query;
    query.prepare("update VENTE set PRIX_COMV=:prix_comv , TEMPS_LIVRAISON=:temps_livraison  where ID_COMV=:id_comv");
    query.bindValue(":id_comv", id_comv);
    query.bindValue(":prix_comv",prix_comv);
    query.bindValue(":temps_livraison",temps_livraison);


    return   query.exec();
}
QSqlTableModel* vente::statistiquevente(){
    QSqlTableModel* model= new QSqlTableModel();
    model->setTable("vente");
    model->select();

    return model;
}
