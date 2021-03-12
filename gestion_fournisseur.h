#ifndef GESTION_FOURNISSEUR_H
#define GESTION_FOURNISSEUR_H

#include <QDialog>

namespace Ui {
class gestion_fournisseur;
}

class gestion_fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_fournisseur(QWidget *parent = nullptr);
    ~gestion_fournisseur();

private:
    Ui::gestion_fournisseur *ui;
};

#endif // GESTION_FOURNISSEUR_H
