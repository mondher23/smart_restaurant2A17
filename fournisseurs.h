#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <QString>

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
private :

  int idf;
  QString nomf;
  QString adressef;
  QString telf;
  int numcompte ;

};

#endif // FOURNISSEURS_H
