#include "carte.h"
#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Carte::Carte()
{
    cinc=0;
    pts=0;
    expire="";

}

Carte::Carte(int cinc,int pts,QString expire)
{
    this->cinc=cinc;
    this->pts=pts;
    this->expire=expire;

}

int  Carte::getcinc(){return cinc;};
int Carte::getpts(){return pts;};
QString Carte::getexpire(){return expire;};


void Carte::setcinc(int cinc){this->cinc=cinc;};
void Carte::setpts(int pts){this->pts=pts;};
void Carte::setexpire(QString expire){this->expire=expire;};

bool Carte::ajouterCarte()
{
    QSqlQuery query;
    QString cinc_string= QString::number(cinc);
    QString pts_string= QString::number(pts);

          query.prepare("INSERT INTO carte (cinc, pts, expire) "
                        "VALUES (:cinc, :pts, :expire)");
          query.bindValue(0, cinc_string);
          query.bindValue(1, pts_string);
          query.bindValue(2, expire);

          return query.exec();
}

bool Carte::supprimerCarte(int cinc)
{
    QSqlQuery query;

          query.prepare("DELETE FROM carte WHERE cinc=:cinc");
          query.bindValue(":cinc", cinc);
          return query.exec();

}

QSqlQueryModel* Carte::afficherCarte()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM carte");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Pts"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("expire"));

    return model;
}

bool Carte::modifierCarte(int cinc)
{
    QString cinc_string=QString::number(cinc);
    QString pts_string=QString::number(pts);
    QSqlQuery query;
    query.prepare("UPDATE client SET cinc=:cinc, pts=:pts, expire=:expire WHERE cinc=:cinc");
    query.bindValue(":cinc", cinc_string);
    query.bindValue(":pts", pts);
    query.bindValue(":expire", expire);

    return query.exec();
}

QSqlQueryModel* Carte::trierCarte()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM carte order by pts");


    return model;
}

QSqlQueryModel* Carte::rechercherCarte(int cinc)
{
    QString cinc_string=QString::number(cinc);
    QSqlQuery query;
    QSqlQueryModel* model= new QSqlQueryModel();
    query.prepare("SELECT * FROM carte where cinc=:cinc");
    query.bindValue(":cinc",cinc_string);
    query.exec();
    model->setQuery(query);
    return model;
}


