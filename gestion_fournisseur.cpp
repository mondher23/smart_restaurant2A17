#include "gestion_fournisseur.h"
#include "ui_gestion_fournisseur.h"

gestion_fournisseur::gestion_fournisseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_fournisseur)
{
    ui->setupUi(this);
}

gestion_fournisseur::~gestion_fournisseur()
{
    delete ui;
}
