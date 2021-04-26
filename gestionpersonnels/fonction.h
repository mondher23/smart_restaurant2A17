#ifndef FONCTION_H
#define FONCTION_H
#include <QString>
#include <QSqlQueryModel>
class Fonction
{
public:
    Fonction();
    Fonction(QString,float,float,int);

        QString getfonctionp();
        float getsalairep();
        float getnombre_heurep();
        int getidp();


        void setfonctionp(QString);
        void setsalairep(float);
        void setnombre_heurep(float);
        void setidp(int);

        bool ajouterfonctions();
        QSqlQueryModel* afficherfonctions();
        bool supprimerfonctions(QString);
        QSqlQueryModel* trierfonctions();
        bool modifierfonctions(QString);
        QSqlQueryModel* rechercherfonctions(QString);
        QSqlQueryModel* stats();

    private:
        QString fonctionp;
        float salairep;
        float nombre_heurep;
        int idp;
    };


#endif // FONCTION_H
