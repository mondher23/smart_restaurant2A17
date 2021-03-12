#include "gestion_achat.h"
#include "ui_gestion_achat.h"

gestion_achat::gestion_achat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_achat)
{
    ui->setupUi(this);
}

gestion_achat::~gestion_achat()
{
    delete ui;
}
