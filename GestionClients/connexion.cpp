#include "connexion.h"

Connexion::Connexion()
{

}
bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("PROJET_2A");//inserer le nom de la source de données ODBC
db.setUserName("aziz");//inserer nom de l'utilisateur
db.setPassword("aziz");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
