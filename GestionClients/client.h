#ifndef CLIENT_H
#define CLIENT_H
#include <QString>

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

    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setmail(QString);
    void setadresse(QString);
    void settel(int);

    bool ajouterClient();

private:
    int cinc,tel;
    QString nom,prenom,mail,adresse;
};

#endif // CLIENT_H
