#ifndef PERSONNELS_H
#define PERSONNELS_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>

class Personnels
{
public:
    Personnels();
    Personnels(int,QString,QString,QString,int);

    int getidp();
    QString getnomp();
    QString getprenomp();
    QString getadressep();
    int gettelp();

    void setidp(int);
    void setnomp(QString);
    void setprenomp(QString);
    void setadressep(QString);
    void settelp(int);
    bool ajouterpersonnels();
    QSqlQueryModel* afficherpersonnels();
    bool supprimerpersonnels(int);
    QSqlQueryModel* trierpersonnels();
    bool modifierpersonnels(int);
    QSqlQueryModel* rechercherpersonnels(int);
    QSqlTableModel* statistiquepersonnel();

private:
    int idp;
    QString nomp;
    QString prenomp;
    QString adressep;
    int telp;



};

#endif // PERSONNELS_H
