#ifndef CARTE_H
#define CARTE_H
#include <QString>

class Carte
{
public:
    Carte();
    Carte(int,int,QString);

    int  getcinc();
    int getpts();
    QString getexpire();

    void setcinc(int);
    void setpts(int);
    void setexpire(QString);

    bool ajouterCarte();

private:
    int cinc,pts;
    QString expire;
};

#endif // CLIENT_H

