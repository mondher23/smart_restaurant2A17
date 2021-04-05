#ifndef PLATS_H
#define PLATS_H
#include <QString>
#include <QSqlQueryModel>

class Plats
{
public:
    Plats();
    Plats(int,QString,float);

    int getidp();
    QString getnomp();
    float getprixp();


    void setidp(int);
    void setnomp(QString);
    void setprixp(float);

    bool ajouterplat();
    QSqlQueryModel* afficherplat();
    bool supprimerplat(int);
    QSqlQueryModel* trierplat();

private:
    int idp;
    QString nomp;
    float prixp;




};

#endif // PLATS_H
