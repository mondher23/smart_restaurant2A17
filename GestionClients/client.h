#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>

class Client
{
public:
    Client();
    Client(int,QString,QString,QString,QString,int);

    int  getcinc();
    QString getnom();
    QString getprenom();
    QString getmail();
    QString getadresse();
    int gettel();

    void setcinc(int);
    void setnom(QString);
    void setprenom(QString);
    void setmail(QString);
    void setadresse(QString);
    void settel(int);

    bool ajouterClient();
    QSqlQueryModel* afficherClient();
    bool supprimerClient(int);

private:
    int cinc,tel;
    QString nom,prenom,mail,adresse;
};

#endif // CLIENT_H
