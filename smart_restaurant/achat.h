#ifndef ACHAT_H
#define ACHAT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
class Achat
{
public :
  Achat();
  Achat(int,float,QString,int);
  int getida();
  float getprixa();
  QString getdatea();
  int getidf();
  void setida(int);
  void setprixa(float);
  void setdatea(QString);
  void setidf(int);
  bool ajouterachat();
  QSqlQueryModel* afficherachat();
  bool supprimerachat(int);
  bool modifierachat(int);
  QSqlQueryModel* trierachat();
  QSqlQueryModel* rechercherachat(int);
  QSqlQueryModel* statistiqueachat();
QSqlTableModel* statistiqueachat1();
private :

  int ida;
  float prixa;
  QString datea;
  int idf;


};

#endif // ACHAT_H
