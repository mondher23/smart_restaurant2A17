#ifndef PERSONNELS_H
#define PERSONNELS_H
#include <Qstring>

class Personnels
{
public:
    Personnels();
    Personnels(int,Qstring,Qstring,Qstring,int);

    int getIdP();
    Qstring getNomP();
    Qstring getPrenomP();
    Qstring getAdresseP();
    int getTelP();

    void setIdP(int);
    void setNomP(Qstring);
    void setPrenomP(Qstring);
    void setAdresseP(Qstring);
    void setTelP(int);

private:
    int IdP;
    Qstring NomP;
    Qstring PrenomP;
    Qstring AdresseP;
    int TelP;



};

#endif // PERSONNELS_H
