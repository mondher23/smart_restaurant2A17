#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avis.h"
#include <QString>
#include <QMessageBox>
#include <QTextDocument>
#include <QDebug>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *gestion)
    : QMainWindow(gestion)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->line_id->setValidator(new QIntValidator(0,9999999,this));
    ui->tab_avis1->setModel(A.afficher());
    ui->tableView->setModel(A.stat());
    ui->tab_ventes->setModel(V.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_btn_ajout_clicked()
{
    bool controle=true;

    int id_a=ui->line_id->text().toInt();
        QString avis=ui->line_avis->text();
        qreal note=ui->line_note->text().toFloat();
        if((note>20)||(note<0))
            controle=false;
        Avis A(id_a,avis,note);

        if(controle==true)
        {
           if((A.ajouter()==true))
        {
            ui->line_id->setText("");
            ui->line_avis->setText("");
            ui->line_note->setText("");


            QMessageBox::information(nullptr, QObject::tr("Ajouter une avis"),
                               QObject::tr("Ajout avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_avis1->setModel(A.afficher());
            ui->tableView->setModel(A.stat());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Ajouter une avis"),
                                   QObject::tr("Erreur l'id existe deja!. ou note non valide\n"
                                               "Click Close to exit."), QMessageBox::Close);
            }


        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter une avis"),
                               QObject::tr(" note non valide!.\n"
                                           "Click Close to exit."), QMessageBox::Close);
        }
}


void MainWindow::on_btn_supp_clicked()
{
    Avis A1;
    int row=ui->tab_avis1->selectionModel()->currentIndex().row();
      A1.set_id_a(ui->tab_avis1->model()->index(row,0).data().toInt());
      bool test=A1.supprimer(A1.get_id_a());

      QMessageBox msgBox;

      if(test)
      {
          msgBox.setText("Suppression avec succès.");


          //Mettre à jour mon affichage après suppression:
          ui->tab_avis1->setModel(A.afficher());
          ui->tableView->setModel(A.stat());

          }
    else
      {
         msgBox.setText("Echec de la suppression!");
      }

        msgBox.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->lineEdit->text().toInt();
    ui->tab_avis1->setModel(A.chercher(id)); //rechercher

}

void MainWindow::on_pushButton_clicked()
{
    int     id_a=ui->line_id->text().toInt();
    QString avis=ui->line_avis->text();
        qreal note=ui->line_note->text().toFloat();
        Avis A(id_a,avis,note);


        if(A.modifier(id_a))
            {
            ui->line_id->setText("");
            ui->line_avis->setText("");
            ui->line_note->setText("");


            QMessageBox::information(nullptr, QObject::tr("modifier une avis"),
                               QObject::tr("modification avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_avis1->setModel(A.afficher());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("modifier une avis"),
                                   QObject::tr("Erreur l'id existe deja!.\n"
                                               "Click Close to exit."), QMessageBox::Close);
            }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString selon=ui->comboBox->currentText();
     ui->tab_avis1->setModel(A.trier(selon));
}

void MainWindow::on_pushButton_4_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                        const int rowCount = ui->tab_avis1->model()->rowCount();
                        const int columnCount = ui->tab_avis1->model()->columnCount();
                       out <<  "<html>\n"
                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                                        <<  QString("<title>%1</title>\n").arg("strTitle")
                                        <<  "</head>\n"
                                        "<body bgcolor=#ffc924 link=#5000A0>\n"
                                         "<img src='C:/Users/21627/OneDrive/Bureau/logo.PNG' width='100' height='100'>\n"
                                       //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Liste des avis</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                    // headers
                                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                    out<<"<cellspacing=10 cellpadding=3>";
                                    for (int column = 0; column < columnCount; column++)
                                        if (!ui->tab_avis1->isColumnHidden(column))
                                            out << QString("<th>%1</th>").arg(ui->tab_avis1->model()->headerData(column, Qt::Horizontal).toString());
                                    out << "</tr></thead>\n";

                                    // data table
                                    for (int row = 0; row < rowCount; row++) {
                                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                        for (int column = 0; column < columnCount; column++) {
                                            if (!ui->tab_avis1->isColumnHidden(column)) {
                                                QString data = ui->tab_avis1->model()->data(ui->tab_avis1->model()->index(row, column)).toString().simplified();
                                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                            }
                                        }
                                        out << "</tr>\n";
                                    }
                                    out <<  "</table> </center>\n"
                                        "</body>\n"
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

void MainWindow::on_btn_ajout_2_clicked()
{
    int id_comv=ui->line_id2->text().toInt();
    qreal prix_comv =ui->line_prix->text().toFloat();
    QString temps_livraison=ui->line_temps->text();
    //int     age=ui->line_age->text().toInt();
    vente V(id_comv,prix_comv,temps_livraison);
//enfant l(69,"nermin","fatatich",200);

        if(V.ajouter())
            {
            ui->line_id2->setText("");
            ui->line_prix->setText("");
            ui->line_temps->setText("");
            //ui->line_prenom->setText("");

            QMessageBox::information(nullptr, QObject::tr("Ajouter une vente"),
                               QObject::tr("Ajout avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_ventes->setModel(V.afficher());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Ajouter une vente"),
                                   QObject::tr("Erreur l'id existe deja!.\n"
                                               "Click Close to exit."), QMessageBox::Close);
            }
}

void MainWindow::on_btn_supp_2_clicked()
{
    vente V1;
    int row=ui->tab_ventes->selectionModel()->currentIndex().row();
    int id_comv=ui->tab_ventes->model()->index(row,0).data().toInt();
    bool test=V1.supprimer(id_comv);

      QMessageBox msgBox;

      if(test)
      {
          msgBox.setText("Suppression avec succès.");


          //Mettre à jour mon affichage après suppression:
          ui->tab_ventes->setModel(V1.afficher());

          }
    else
      {
         msgBox.setText("Echec de la suppression!");
      }

        msgBox.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    int id_comv=ui->lineEdit_2->text().toInt();
    ui->tab_ventes->setModel(V.chercher(id_comv));

}

void MainWindow::on_pushButton_8_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                        const int rowCount = ui->tab_ventes->model()->rowCount();
                        const int columnCount = ui->tab_ventes->model()->columnCount();
                       out <<  "<html>\n"
                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title>%1</title>\n").arg("strTitle")
                                        <<  "</head>\n"
                                        "<body bgcolor=#ffffff link=#5000A0>\n"
                                         "<img src='C:/Users/21627/OneDrive/Bureau/logo.PNG' width='100' height='100'>\n"

                                       //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Liste des ventes</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                    // headers
                                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                    out<<"<cellspacing=10 cellpadding=3>";
                                    for (int column = 0; column < columnCount; column++)
                                        if (!ui->tab_ventes->isColumnHidden(column))
                                            out << QString("<th>%1</th>").arg(ui->tab_ventes->model()->headerData(column, Qt::Horizontal).toString());
                                    out << "</tr></thead>\n";

                                    // data table
                                    for (int row = 0; row < rowCount; row++) {
                                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                        for (int column = 0; column < columnCount; column++) {
                                            if (!ui->tab_ventes->isColumnHidden(column)) {
                                                QString data = ui->tab_ventes->model()->data(ui->tab_ventes->model()->index(row, column)).toString().simplified();
                                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                            }
                                        }
                                        out << "</tr>\n";
                                    }
                                    out <<  "</table> </center>\n"
                                        "</body>\n"
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

void MainWindow::on_pushButton_7_clicked()
{
    int row=ui->tab_ventes->selectionModel()->currentIndex().row();
      int id=ui->tab_ventes->model()->index(row,0).data().toInt();
      QString res=QString::number(id);
    ui->tabWidget_3->setCurrentIndex(0);
    ui->line_id2->setText(res);
}

void MainWindow::on_pushButton_5_clicked()
{
    int id_v=ui->line_id2->text().toInt();
        qreal prix_comv=ui->line_prix->text().toFloat();
        QString temps_livraison=ui->line_temps->text();
        //int age = ui->line_age->text().toInt();

        vente V(id_v,prix_comv,temps_livraison);


        if(V.modifier(id_v))
            {
            ui->line_id2->setText("");
            ui->line_prix->setText("");
            ui->line_temps->setText("");
           // ui->line_age->setText("");

            QMessageBox::information(nullptr, QObject::tr("Modifier vente"),
                               QObject::tr("modification avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_ventes->setModel(V.afficher());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Modifier vente"),
                                   QObject::tr("Erreur!.\n"
                                               "Click Close to exit."), QMessageBox::Close);
            }
}

void MainWindow::on_pushButton_9_clicked()
{
    int row=ui->tab_avis1->selectionModel()->currentIndex().row();
      int id=ui->tab_avis1->model()->index(row,0).data().toInt();
      QString res=QString::number(id);
    ui->tabWidget->setCurrentIndex(0);
    ui->line_id->setText(res);
   /* int id_a=ui->line_id->text().toInt();
      QString avis=ui->line_avis->text();
      qreal note=ui->line_note->text().toFloat();
      //QString telf=ui->le_telf1->text();
     // int numcompte=ui->le_numcompte1->text().toInt();
     Avis A(id_a,avis,note);
      bool test=A.modifier(A.get_id_a());
      QMessageBox msgBox;
      if (test) {
          msgBox.setText("modification avec succes");
          ui->tab_avis1->setModel(A.afficher());
      }
      msgBox.exec();*/
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
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("dina.benmansour@esprit.tn", "191JFT2415", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("dina.benmansour@esprit.tn", ui->email->text() , ui->objet->text(),ui->code->text());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void MainWindow::on_senbtn_clicked()
{
   sendMail();
}
