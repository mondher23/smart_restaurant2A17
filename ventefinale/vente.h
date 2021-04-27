#ifndef VENTE_H
#define VENTE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class vente
{
public:
vente();
vente(int,qreal,QString);
bool ajouter();
QSqlQueryModel *afficher();
bool supprimer (int);
QSqlQueryModel *chercher(int);
bool modifier(int);
private:
int id_comv;
qreal prix_comv;
QString temps_livraison;
};

#endif // VENTE_H
