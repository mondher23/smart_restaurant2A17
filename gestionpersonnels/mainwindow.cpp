#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personnels.h"
#include "fonction.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlQuery>
#include <QPrinter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stats->setModel(F.stats());
    ui->tab_personnels->setModel(P.afficherpersonnels());
    ui->tab_fonctions->setModel(F.afficherfonctions());
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pb_ajouter_clicked()
{bool controle=true;
    bool test=true;
    int idp=ui->le_idp->text().toInt();
    QString nomp=ui->le_nomp->text();
    QString prenomp=ui->le_prenomp->text();
    QString adressep=ui->le_adressep->text();
    int telp=ui->le_telp->text().toInt();
    if ((telp<10000000)||(telp>99999999))
        controle=false;
    if(controle==true){
    Personnels P(idp,nomp,prenomp,adressep,telp);
    test=P.ajouterpersonnels();}
    QMessageBox msgBox;

    if((test==true)&&(controle==true))
    {msgBox.setText("Ajout avec succes.");
        ui->tab_personnels->setModel(P.afficherpersonnels());}
        else {
            msgBox.setText("vérifier le num de tel");
            }
            msgBox.exec();

}


void MainWindow::on_pb_tri_clicked()
{
    ui->tab_personnels->setModel(P.trierpersonnels());
}



void MainWindow::on_pb_modifier_clicked()
{int idp=ui->le_idp1->text().toInt();
    QString nomp=ui->le_nomp1->text();
    QString prenomp=ui->le_prenomp1->text();
    QString adressep=ui->le_adressep1->text();
    int telp=ui->le_telp1->text().toUInt();
    Personnels P1(idp,nomp,prenomp,adressep,telp);
    bool test=P1.modifierpersonnels (P1.getidp());
    QMessageBox msgBox;
    if(test){
    msgBox.setText("MODIFICATION AVEC SUCCES");
    ui->tab_personnels->setModel(P.afficherpersonnels());
    }

}

void MainWindow::on_pb_supp_clicked()
{
    Personnels P1;
    P1.setidp(ui->le_idp1->text().toInt());
    bool test=P1.supprimerpersonnels (P1.getidp());
    QMessageBox msgBox;
    if(test){
        msgBox.setText("SUPPRESSION AVEC SUCCES");
        ui->tab_personnels->setModel(P.afficherpersonnels());
    }
}

void MainWindow::on_pb_rechercher_clicked()
{
    Personnels P1;
    P1.setidp(ui->le_idrechercher->text().toInt());
    ui->tab_personnels->setModel(P.rechercherpersonnels(P1.getidp()));
}

void MainWindow::on_tab_personnels_activated(const QModelIndex &index)
{
    QString val=ui->tab_personnels->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT* from personnels where idp=idp or nomp=:val or prenomp=:val or adressep=:val or telp=:val  ");
        query.bindValue(":val",val);
        query.bindValue(":val",val);
        query.bindValue(":val",val);
        query.bindValue(":val",val);
        query.bindValue(":val",val);
        if(query.exec()){

                while(query.next()){
                  ui->le_idp1->setText(query.value(0).toString());
                  ui->le_nomp1->setText(query.value(1).toString());
                  ui->le_prenomp1->setText(query.value(2).toString());
                  ui->le_adressep1->setText(query.value(3).toString());
                  ui->le_telp1->setText(query.value(4).toString());

                }}
}

void MainWindow::on_pb1_ajouter_clicked()
{bool test=true;
    bool controle=true;
    int idp=ui->le_idp2->text().toInt();
    float salairep=ui->le_salairep->text().toFloat();
    QString fonctionp=ui->le_fonctionp->text();
    float nombre_heurep=ui->le_nombre_heurep->text().toFloat();
    if ((fonctionp!="chef")&&(fonctionp!="serveur")&&(fonctionp!="gerant")&&(fonctionp!="ouvrier")&&(fonctionp!="livreur"))
        controle=false;
    if(controle){
    Fonction F(fonctionp,salairep,nombre_heurep,idp);
     test=F.ajouterfonctions();}
    QMessageBox msgBox;

    if((test)&&(controle))
    {msgBox.setText("Ajout avec succes.");
        ui->tab_fonctions->setModel(F.afficherfonctions());
    ui->stats->setModel(F.stats());}
        else {
            msgBox.setText("fonction non valide");
            }
            msgBox.exec();
}

void MainWindow::on_pb1_supprimer_clicked()
{
   Fonction F1;
   F1.setfonctionp (ui->le_fonctionp1->text());
    bool test=F1.supprimerfonctions (F1.getfonctionp());
    QMessageBox msgBox;
    if(test){
        msgBox.setText("SUPPRESSION AVEC SUCCES");
        ui->tab_fonctions->setModel(F.afficherfonctions());
        ui->stats->setModel(F.stats());
    }
}

void MainWindow::on_pb1_modifier_clicked()
{
    bool test=true;
        bool controle=true;
    int idp=ui->le_idp3->text().toInt();
    float salairep=ui->le_salairep1->text().toFloat();
        QString fonctionp=ui->le_fonctionp1->text();
        float nombre_heurep=ui->le_nombreheurep1->text().toFloat();
        if ((fonctionp!="chef")&&(fonctionp!="serveur")&&(fonctionp!="gerant")&&(fonctionp!="ouvrier")&&(fonctionp!="livreur"))
            controle=false;
        if(controle){
        Fonction F1(fonctionp,salairep,nombre_heurep,idp);
         test=F1.modifierfonctions (F1.getfonctionp());}
        QMessageBox msgBox;
        if((test)&&(controle)){
        msgBox.setText("MODIFICATION AVEC SUCCES");
        ui->tab_fonctions->setModel(F.afficherfonctions());
        ui->stats->setModel(F.stats());
        }
        else {
            msgBox.setText("fonction non valide");
            }
        msgBox.exec();
}

void MainWindow::on_pb1_rechercher_clicked()
{
    Fonction F1;
    F1.setfonctionp(ui->le_fonctionrechercher->text());
    ui->tab_fonctions->setModel(F.rechercherfonctions(F1.getfonctionp()));
}

void MainWindow::on_pb1_trier_clicked()
{
    ui->tab_fonctions->setModel(F.trierfonctions());
}

void MainWindow::on_tab_fonctions_activated(const QModelIndex &index)
{
    QString val=ui->tab_fonctions->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT* from fonction where fonctionp=:val or salairep=:val or nombre_heurep=:val or idp=:val  ");
        query.bindValue(":val",val);
        query.bindValue(":val",val);
        query.bindValue(":val",val);
        query.bindValue(":val",val);

        if(query.exec()){

                while(query.next()){
                  ui->le_fonctionp1->setText(query.value(0).toString());
                  ui->le_salairep1->setText(query.value(1).toString());
                  ui->le_nombreheurep1->setText(query.value(2).toString());
                  ui->le_idp3->setText(query.value(3).toString());
                }}
}

void MainWindow::on_pushButton_clicked()
{
    QString strStream;
                          QTextStream out(&strStream);

                           const int rowCount = ui->tab_personnels->model()->rowCount();
                           const int columnCount = ui->tab_personnels->model()->columnCount();
                          out <<  "<html>\n"
                          "<head>\n"
                                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                           <<  QString("<title>%1</title>\n").arg("strTitle")
                                           <<  "</head>\n"
                                           "<body bgcolor=#ffffff link=#5000A0>\n"

                                          //     "<align='center'> " << datefich << "</align>"
                                           "<center> <H1 style=""color:#ff8533"">Liste des personnels</H1><br><table border=1 cellspacing=0 cellpadding=2>\n";

                                       // headers
                                       out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                       out<<"<cellspacing=10 cellpadding=3>";
                                       for (int column = 0; column < columnCount; column++)
                                           if (!ui->tab_personnels->isColumnHidden(column))
                                               out << QString("<th>%1</th>").arg(ui->tab_personnels->model()->headerData(column, Qt::Horizontal).toString());
                                       out << "</tr></thead>\n";

                                       // data table
                                       for (int row = 0; row < rowCount; row++) {
                                           out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                           for (int column = 0; column < columnCount; column++) {
                                               if (!ui->tab_personnels->isColumnHidden(column)) {
                                                   QString data = ui->tab_personnels->model()->data(ui->tab_personnels->model()->index(row, column)).toString().simplified();
                                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                               }
                                           }
                                           out << "</tr>\n";
                                       }
                                       out <<  "</table> </center>\n"
                                           " <br><br><footer><div align='center'><img src='C:/Users/mondh/Desktop/koolsmart.png' width='100' height='100' ></img></div><p align='center'>copyright 2021 KOOLSMART</p></footer></body>\n"
                                           "</html>\n";

                                 QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                   if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                                  QPrinter printer (QPrinter::PrinterResolution);
                                   printer.setOutputFormat(QPrinter::PdfFormat);

                                 printer.setOutputFileName(fileName);

                                  QTextDocument doc;
                                   doc.setHtml(strStream);

                                   doc.print(&printer);
}
