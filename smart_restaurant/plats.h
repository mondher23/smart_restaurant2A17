#ifndef PLATS_H
#define PLATS_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>

class Plats
{
public:
    Plats();
    Plats(int,QString,float,int);

    int getidp();
    QString getnomp();
    float getprixp();
    int getidsp();


    void setidp(int);
    void setnomp(QString);
    void setprixp(float);
    void setidsp(int);

    bool ajouterplat();
    QSqlQueryModel* afficherplat();
    bool supprimerplat(int);
    QSqlQueryModel* trierplat();
    bool modifierplat(int);
    QSqlQueryModel* rechercherplat(QString);

    QSqlTableModel* statistiqueplat();

private:
    int idp;
    QString nomp;
    float prixp;
     int idsp;




};

#endif // PLATS_H
