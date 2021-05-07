#ifndef AVIS_H
#define AVIS_H
#include <QString>
#include <QSqlQueryModel>


class Avis
{
public:
    //constructeur par dÃƒÂ©faut:
    Avis();
    //constructeur paramÃƒÂ©trÃƒÂ©:
    Avis(int,QString,qreal);

    //implementation des getters:
    int get_id_a();
    QString get_avis();
    qreal get_note();

    //implementation des setters:
    void set_id_a(int);
    void set_avis(QString);
    void set_note(qreal);
    //implementation des methodes (CRUD):
    bool ajouter();
    QSqlQueryModel *afficher();
    QSqlQueryModel *stat();
    QSqlQueryModel *trier(QString);
    bool supprimer (int);
    QSqlQueryModel *chercher(int);
    bool modifier(int);

private:
    int id_a;
    QString avis;
    qreal note;
};

#endif // AVIS_H
