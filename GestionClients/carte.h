#ifndef CARTE_H
#define CARTE_H
#include <QString>
#include <QSqlQueryModel>

class Carte
{
public:
    Carte();
    Carte(int,int,QString);

    int  getcinc();
    int getpts();
    QString getexpire();

    void setcinc(int);
    void setpts(int);
    void setexpire(QString);

    bool ajouterCarte();
    QSqlQueryModel* afficherCarte();
    bool supprimerCarte(int);

private:
    int cinc,pts;
    QString expire;
};

#endif // CARTE_H
