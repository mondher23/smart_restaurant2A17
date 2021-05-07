#ifndef SPECIALITES_H
#define SPECIALITES_H
#include <QString>
#include <QSqlQueryModel>

   class Specialites
        {
        public:
            Specialites();
             Specialites(int,QString,QString);

            int getidsp();
            QString getnomsp();
            QString gettypesp();


            void setidsp(int);
            void setnomsp(QString);
            void settypesp(QString);

            bool ajouterspecialite();
            QSqlQueryModel* afficherspecialite();
            bool supprimerspecialite(int);
            bool modifierspecialite(int);
            QSqlQueryModel* trierspecialite();
            QSqlQueryModel* rechercherspecialite(QString);



        private:
            int idsp;
            QString nomsp;
            QString typesp;




        };

        #endif // SPECIALITES_H
