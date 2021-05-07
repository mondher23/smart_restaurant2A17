#include "ventewindow.h"
#include "ui_ventewindow.h"
#include "avis.h"
#include <QString>
#include <QMessageBox>
#include <QTextDocument>
#include <QDebug>
#include <QIntValidator>
#include "excel.h"
#include <QTextStream>
#include <QPixmap>


ventewindow::ventewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventewindow)
{
    ui->setupUi(this);
    ui->line_id->setValidator(new QIntValidator(0,9999999,this));
    ui->tab_avis1->setModel(A.afficher());
    ui->tab_ventes->setModel(V.afficher());
    ui->notes->hide();
    ui->btn_notes->hide();
    ui->tab_avis1->setModel(A.afficher());
    ui->tab_ventes->setModel(V.afficher());
    QPieSeries *Series = new QPieSeries();
     QSqlTableModel *Mymodels=V.statistiquevente();
     Mymodels->setFilter("prix_comV < 30");
     int num=Mymodels->rowCount();
     Series->append(" moins de 30 dt ",num);
     Mymodels=V.statistiquevente();
      Mymodels->setFilter("prix_comV between 30 and 80");
       num=Mymodels->rowCount();
      Series->append("entre 30 et 80 dt",num);
      Mymodels=V.statistiquevente();
      Mymodels->setFilter("prix_comV between 80 and 200 ");
       num=Mymodels->rowCount();
      Series->append("entre 80 et 200 dt ",num);
      Mymodels=V.statistiquevente();
      Mymodels->setFilter("prix_comV > 200");
       num=Mymodels->rowCount();
      Series->append(">200 dt ",num);
      QChart *chart = new QChart();
      chart->addSeries(Series);
      chart->setTitle("les prix des plats ");
      QChartView *chartview =new QChartView(chart);
      chartview->setParent(ui->horizontalFrame);
      timer=new QTimer(this);
      connect(timer,SIGNAL(timeout()),this,SLOT (myfunction()));
      timer->start(1000);
      QPixmap pix("C:/Users/mondh/Desktop/projet c++/gestionachat/smart.png");
     ui->image->setPixmap(pix.scaled(100,80,Qt::KeepAspectRatio));

     QFile file("C:/Users/mondh/Desktop/Historique.txt");
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(0,"info",file.errorString());
        }
        QTextStream in (&file);
       ui->textBrowser->setText(in.readAll());
}

ventewindow::~ventewindow()
{
    delete ui;
}

void ventewindow::myfunction()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh:mm:ss");
    ui->label_date->setText(time_text);
    QDate date = QDate::currentDate();
        QString date_text= date.toString("dd / MM / yyyy");
        ui->label_date1->setText(date_text);
}

void ventewindow::on_btn_ajout_clicked()
{
    bool controle=true;

    int id_a=ui->line_id->text().toInt();
        QString avis=ui->line_avis->text();
        qreal note=ui->line_note->text().toFloat();
        if((note>20)||(note<0))
            controle=false;
        Avis A(id_a,avis,note);
        QFile file("C:/Users/mondh/Desktop/historique.txt");
               if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                   return;

      QTextStream cout(&file);

        if(controle==true)
        {
           if((A.ajouter()==true))
        {
               QString message2="\n Vous avez ajouté un avis";
                                  cout << message2;
                                  QFile file("C:/Users/mondh/Desktop/historique.txt");
                                 if (!file.open(QIODevice::ReadOnly))
                                 {
                                     QMessageBox::information(0,"info",file.errorString());
                                 }
                                 QTextStream in (&file);
                                ui->textBrowser->setText(in.readAll());
            ui->line_id->setText("");
            ui->line_avis->setText("");
            ui->line_note->setText("");


            QMessageBox::information(nullptr, QObject::tr("Ajouter une avis"),
                               QObject::tr("Ajout avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_avis1->setModel(A.afficher());



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


void ventewindow::on_btn_supp_clicked()
{
    Avis A1;
    int row=ui->tab_avis1->selectionModel()->currentIndex().row();
      A1.set_id_a(ui->tab_avis1->model()->index(row,0).data().toInt());
      bool test=A1.supprimer(A1.get_id_a());
      QFile file("C:/Users/mondh/Desktop/historique.txt");
             if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                 return;

    QTextStream cout(&file);

      QMessageBox msgBox;

      if(test)
      {
          QString message2="\nVous avez supprimé un avis";
                                         cout << message2;
                                         QFile file("C:/Users/mondh/Desktop/historique.txt");
                                        if (!file.open(QIODevice::ReadOnly))
                                        {
                                            QMessageBox::information(0,"info",file.errorString());
                                        }
                                        QTextStream in (&file);
                                       ui->textBrowser->setText(in.readAll());
          msgBox.setText("Suppression avec succès.");


          //Mettre à jour mon affichage après suppression:
          ui->tab_avis1->setModel(A.afficher());


          }
    else
      {
         msgBox.setText("Echec de la suppression!");
      }

        msgBox.exec();
}

void ventewindow::on_pushButton_2_clicked()
{
    int id=ui->lineEdit->text().toInt();
    ui->tab_avis1->setModel(A.chercher(id)); //rechercher

}

void ventewindow::on_pushButton_clicked()
{
    int     id_a=ui->line_id->text().toInt();
    QString avis=ui->line_avis->text();
        qreal note=ui->line_note->text().toFloat();
        Avis A(id_a,avis,note);
        QFile file("C:/Users/mondh/Desktop/historique.txt");
               if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                   return;

      QTextStream cout(&file);


        if(A.modifier(id_a))
            {
            QString message2="\nVous avez modifié un avis";
                               cout << message2;
                               QFile file("C:/Users/mondh/Desktop/historique.txt");
                              if (!file.open(QIODevice::ReadOnly))
                              {
                                  QMessageBox::information(0,"info",file.errorString());
                              }
                              QTextStream in (&file);
                             ui->textBrowser->setText(in.readAll());
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

void ventewindow::on_pushButton_3_clicked()
{
    QString selon=ui->comboBox->currentText();
     ui->tab_avis1->setModel(A.trier(selon));
}

void ventewindow::on_pushButton_4_clicked()
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

void ventewindow::on_btn_ajout_2_clicked()
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

void ventewindow::on_btn_supp_2_clicked()
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

void ventewindow::on_pushButton_6_clicked()
{
    int id_comv=ui->lineEdit_2->text().toInt();
    ui->tab_ventes->setModel(V.chercher(id_comv));

}

void ventewindow::on_pushButton_8_clicked()
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

void ventewindow::on_pushButton_7_clicked()
{
    int row=ui->tab_ventes->selectionModel()->currentIndex().row();
      int id=ui->tab_ventes->model()->index(row,0).data().toInt();
      QString res=QString::number(id);
    ui->tabWidget_3->setCurrentIndex(0);
    ui->line_id2->setText(res);
}

void ventewindow::on_pushButton_5_clicked()
{
    int id_v=ui->line_id2->text().toInt();
        qreal prix_comv=ui->line_prix->text().toFloat();
        QString temps_livraison=ui->line_temps->text();
        //int age = ui->line_age->text().toInt();

        vente V(id_v,prix_comv,temps_livraison);
        QFile file("C:/Users/mondh/Desktop/historique.txt");
               if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                   return;

      QTextStream cout(&file);
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

void ventewindow::on_pushButton_9_clicked()
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
void ventewindow::on_add_clicked()
{
    float A = ui->a->text().toFloat();
        float B = ui->b->text().toFloat();
        ui->LabelResulta->setText( QString::number(A+B));
}

void ventewindow::on_remove_clicked()
{
    float A = ui->a->text().toFloat();
        float B = ui->b->text().toFloat();
       ui->LabelResulta->setText(  QString::number(A-B));
}

void ventewindow::on_multy_clicked()
{
    float A = ui->a->text().toFloat();
        float B = ui->b->text().toFloat();
      ui->LabelResulta->setText(  QString::number(A*B));
}

void ventewindow::on_div_clicked()
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
/*void ventewindow::sendMail()
{
    Smtp* smtp = new Smtp("dina.benmansour@esprit.tn", "191JFT2415", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("dina.benmansour@esprit.tn", ui->email->text() , ui->objet->text(),ui->code->text());
}

void ventewindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void ventewindow::on_senbtn_clicked()
{
   sendMail();
}*/

void ventewindow::on_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                ExportExcelObject obj(fileName, "mydata", ui->tab_ventes);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "id", "char(20)");
                obj.addField(1, "prix", "char(20)");
                obj.addField(2, "tempsl", "char(20)");


                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                             );
                }
}

void ventewindow::on_btn_ajout_notes_clicked()
{
    ui->notes->show();
        ui->btn_notes->show();
}

void ventewindow::on_btn_notes_clicked()
{
    QFile file("C:/Users/mondh/Desktop/notes.txt");
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
            QString message2="-"+ui->notes->toPlainText()+"\n";
                    cout << message2;
                    ui->notes->hide();
                    ui->btn_notes->hide();
}
