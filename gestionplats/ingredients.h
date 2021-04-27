#ifndef INGREDIENTS_H
#define INGREDIENTS_H
#include <QString>
#include <QSqlQueryModel>


class Ingredients
{
public:
    Ingredients();
    Ingredients(int,QString,QString,QString,int);

    int getidig();
    QString getnomig();
    QString getqttig();
    QString getdateig();
    int getidp();


    void setidig(int);
    void setnomig(QString);
    void setqttig(QString);
    void setdateig(QString);
     void setidp(int);

    bool ajouteringredient();
    QSqlQueryModel* afficheringredient();
    bool supprimeringredient(int);
    QSqlQueryModel* trieringredient();
    bool modifieringredient(int);
    QSqlQueryModel* rechercheringredient(QString);

private:
    int idig,idp;
    QString nomig,qttig,dateig;





};

#endif // INGREDIENTS_H
