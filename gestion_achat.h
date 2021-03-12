#ifndef GESTION_ACHAT_H
#define GESTION_ACHAT_H

#include <QDialog>

namespace Ui {
class gestion_achat;
}

class gestion_achat : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_achat(QWidget *parent = nullptr);
    ~gestion_achat();

private:
    Ui::gestion_achat *ui;
};

#endif // GESTION_ACHAT_H
