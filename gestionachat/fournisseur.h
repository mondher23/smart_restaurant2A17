#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQueryModel>

class Fournisseur
{
public :
  Fournisseur();
  Fournisseur(int,QString,QString,QString,int);
  int getidf();
  QString getnomf();
  QString getadressef();
  QString gettelf();
  int getnumcompte();
  void setidf(int);
  void setnomf(QString);
  void setadressef(QString);
  void settelf(QString);
  void setnumcompte(int);
  bool ajouterfournisseur();
  QSqlQueryModel* afficherfournisseur();
private :

  int idf;
  QString nomf;
  QString adressef;
  QString telf;
  int numcompte ;

};

#endif // FOURNISSEUR_H
