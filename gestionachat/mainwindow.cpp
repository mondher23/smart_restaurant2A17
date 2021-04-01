#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include <QIntValidator>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 ui->tab_fournisseur->setModel(f.afficherfournisseur());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
int idf=ui->le_idf->text().toUInt();
QString nomf=ui->le_nomf->text();
QString adressef=ui->le_adressef->text();
QString telf=ui->le_telf->text();
int numcompte=ui->le_numcompte->text().toInt();
Fournisseur F(idf,nomf,adressef,telf,numcompte);
bool test=F.ajouterfournisseur();
QMessageBox msgBox;
if (test)
{
    msgBox.setText("ajout avec succes");

}
else
    msgBox.setText("echec");
msgBox.exec();
}
