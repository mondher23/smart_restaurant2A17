#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlQuery>
#include <connection.h>
#include <QMessageBox>
#include <QTextDocument>
#include <QDebug>
#include "achat.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
 ui->setupUi(this);
 ui->tab_fournisseur->setModel(F.afficherfournisseur());
 ui->tab_achat->setModel(A.afficherachat());
 ui->tablestat->setModel(A.statistiqueachat());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{bool controle=true;
    bool test=true;
int idf=ui->le_idf->text().toInt();
QString nomf=ui->le_nomf->text();
QString adressef=ui->le_adressef->text();
QString telf=ui->le_telf->text();
int numcompte=ui->le_numcompte->text().toInt();
if (telf.length()!=8)
controle=false;
if(controle==true){
Fournisseur F(idf,nomf,adressef,telf,numcompte);
 test=F.ajouterfournisseur();}
QMessageBox msgBox;
if ((test==true)&&(controle==true))
{
    msgBox.setText("ajout avec succes");
    ui->tab_fournisseur->setModel(F.afficherfournisseur());

}
else
    msgBox.setText("le numéro du tel doit etre de 8 chiffres ou idf déja utilisé ");
msgBox.exec();
}



void MainWindow::on_pb_trier_clicked()
{
    QString selon=ui->comboBox->currentText();
ui->tab_fournisseur->setModel(F.trierfournisseur(selon));
}

void MainWindow::on_pb_rechercher_clicked()
{
    Fournisseur F1;
    F1.setnomf(ui->le_id_rechercher->text());
    ui->tab_fournisseur->setModel(F.rechercherfournisseur(F1.getnomf()));
}

void MainWindow::on_tab_fournisseur_activated(const QModelIndex &index)
{
    QString val=ui->tab_fournisseur->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT* from fournisseur where idf=:val or nomf=:val or adressef=:val or telf=:val or numcompte=:val ");
    query.bindValue(0,val);
    query.bindValue(1,val);
    query.bindValue(2,val);
    query.bindValue(3,val);
    query.bindValue(4,val);
    if(query.exec()){

            while(query.next()){
              ui->le_idf1->setText(query.value(0).toString());
              ui->le_nomf1->setText(query.value(1).toString());
              ui->le_adressef1->setText(query.value(2).toString());
              ui->le_telf1->setText(query.value(3).toString());
              ui->le_numcompte1->setText(query.value(4).toString());

            }
}
}

void MainWindow::on_pb_modifier_2_clicked()
{bool controle=true;
    bool test=true;
    int idf=ui->le_idf1->text().toInt();
    QString nomf=ui->le_nomf1->text();
    QString adressef=ui->le_adressef1->text();
    QString telf=ui->le_telf1->text();
    int numcompte=ui->le_numcompte1->text().toInt();
    if (telf.length()!=8)
    controle=false;
    if (controle==true){
    Fournisseur F2(idf,nomf,adressef,telf,numcompte);
     test=F2.modifierfournisseur(F2.getidf());}
    QMessageBox msgBox;
    if ((test==true)&&(controle==true)) {
        msgBox.setText("modification avec succes");
        ui->tab_fournisseur->setModel(F.afficherfournisseur());
    }
    else
        msgBox.setText("le numéro du tel doit etre de 8 chiffres ou idf déja utilisé ");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Fournisseur F1;
    F1.setidf(ui->le_idf1->text().toInt());
    bool test=F1.supprimerfournisseur(F1.getidf());
    QMessageBox msgBox;
    if (test) {
        msgBox.setText("supression avec succes");
        ui->tab_fournisseur->setModel(F.afficherfournisseur());
    }

}
void MainWindow::on_pushButton_clicked()
{
    QString strStream;
                          QTextStream out(&strStream);

                           const int rowCount = ui->tab_fournisseur->model()->rowCount();
                           const int columnCount = ui->tab_fournisseur->model()->columnCount();
                          out <<  "<html>\n"
                          "<head>\n"
                                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                           <<  QString("<title>%1</title>\n").arg("strTitle")
                                           <<  "</head>\n"
                                           "<body bgcolor=#ffffff link=#5000A0>\n"

                                          //     "<align='center'> " << datefich << "</align>"
                                           "<center> <H1 style=""color:#ff8533"">Liste des fournisseurs</H1><br><table border=1 cellspacing=0 cellpadding=2>\n";

                                       // headers
                                       out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                       out<<"<cellspacing=10 cellpadding=3>";
                                       for (int column = 0; column < columnCount; column++)
                                           if (!ui->tab_fournisseur->isColumnHidden(column))
                                               out << QString("<th>%1</th>").arg(ui->tab_fournisseur->model()->headerData(column, Qt::Horizontal).toString());
                                       out << "</tr></thead>\n";

                                       // data table
                                       for (int row = 0; row < rowCount; row++) {
                                           out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                           for (int column = 0; column < columnCount; column++) {
                                               if (!ui->tab_fournisseur->isColumnHidden(column)) {
                                                   QString data = ui->tab_fournisseur->model()->data(ui->tab_fournisseur->model()->index(row, column)).toString().simplified();
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



void MainWindow::on_add_clicked()
{
    float A = ui->a->text().toFloat();
        float B = ui->b->text().toFloat();
        ui->LabelResulta->setText( QString::number(A+B));
}

void MainWindow::on_remove_clicked()
{
    float A = ui->a->text().toFloat();
        float B = ui->b->text().toFloat();
       ui->LabelResulta->setText(  QString::number(A-B));
}

void MainWindow::on_multy_clicked()
{
    float A = ui->a->text().toFloat();
        float B = ui->b->text().toFloat();
      ui->LabelResulta->setText(  QString::number(A*B));
}

void MainWindow::on_div_clicked()
{
    float A = ui->a->text().toFloat();
        float B = ui->b->text().toFloat();
        if(B==0){
             ui->LabelResulta->setText( "inf");
        }else
        {
            ui->LabelResulta->setText(  QString::number(A/B));
        }

}

void MainWindow::on_pb_ajouter1_clicked()
{bool test=true;
    bool controle=true;
    int ida=ui->le_ida->text().toInt();
    float prixa=ui->le_prixa->text().toFloat();
    QString datea=ui->le_datea->text();
    int idf=ui->le_idf2->text().toInt();
    if((prixa<100)||(prixa>2500))
        controle=false;
    if(controle)
    {Achat A(ida,prixa,datea,idf);
     test=A.ajouterachat();}
    QMessageBox msgBox;
    if ((test)&&(controle))
    {
        msgBox.setText("ajout avec succes");
        ui->tab_achat->setModel(A.afficherachat());
          ui->tablestat->setModel(A.statistiqueachat());

    }
    else
        msgBox.setText("verifiez le prix");
    msgBox.exec();
}

void MainWindow::on_tab_achat_activated(const QModelIndex &index)
{
    QString val=ui->tab_achat->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT* from achat where ida=:val or prixa=:val or datea=:val or idf=:val ");
    query.bindValue(0,val);
    query.bindValue(1,val);
    query.bindValue(2,val);
    query.bindValue(3,val);
    if(query.exec()){

            while(query.next()){
              ui->le_ida1->setText(query.value(0).toString());
              ui->le_prixa1->setText(query.value(1).toString());
              ui->le_datea1->setText(query.value(2).toString());
              ui->le_idf3->setText(query.value(3).toString());


            }
}
}

void MainWindow::on_pb_modifer1_clicked()
{bool test=true;
    bool controle=true;
    int ida=ui->le_ida1->text().toInt();
    float prixa=ui->le_prixa1->text().toFloat();
    QString datea=ui->le_datea1->text();
    int idf=ui->le_idf3->text().toInt();
    if((prixa<100)||(prixa>2500))
        controle=false;
    if(controle){
    Achat A2(ida,prixa,datea,idf);
     test=A2.modifierachat(A2.getida());}
    QMessageBox msgBox;
    if((test)&&(controle)) {
        msgBox.setText("modification avec succes");
        ui->tab_achat->setModel(A.afficherachat());
    }
    else
        msgBox.setText("verifiez le prix");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer1_clicked()
{
    Achat A1;
    A1.setida(ui->le_ida1->text().toInt());
    bool test=A1.supprimerachat(A1.getida());
    QMessageBox msgBox;
    if (test) {
        msgBox.setText("supression avec succes");
        ui->tab_achat->setModel(A.afficherachat());}
    msgBox.exec();
}

void MainWindow::on_pb_tri1_clicked()
{
    ui->tab_achat->setModel(A.trierachat());
}

void MainWindow::on_pb_rechercher1_clicked()
{
    Achat A1;
    A1.setida(ui->le_ida_rechercher->text().toInt());
    ui->tab_achat->setModel(A.rechercherachat(A1.getida()));
}
