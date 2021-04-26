/********************************************************************************
** Form generated from reading UI file 'achat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACHAT_H
#define UI_ACHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *le_idf;
    QLineEdit *le_nomf;
    QLineEdit *le_adressef;
    QLineEdit *le_telf;
    QLineEdit *le_numcompte;
    QPushButton *pb_ajouter;
    QWidget *tab_2;
    QTableView *tab_fournisseur;
    QPushButton *pb_trier;
    QLineEdit *le_id_rechercher;
    QPushButton *pb_rechercher;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *le_idf1;
    QLineEdit *le_nomf1;
    QLineEdit *le_adressef1;
    QLineEdit *le_telf1;
    QLineEdit *le_numcompte1;
    QPushButton *pb_modifier_2;
    QPushButton *pb_supprimer;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QWidget *tab_5;
    QPushButton *add;
    QPushButton *remove;
    QPushButton *multy;
    QPushButton *div;
    QLabel *LabelResulta;
    QLineEdit *a;
    QLineEdit *b;
    QWidget *tab_4;
    QTabWidget *tabWidget_3;
    QWidget *tab_6;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *le_ida;
    QLineEdit *le_prixa;
    QLineEdit *le_datea;
    QLineEdit *le_idf2;
    QPushButton *pb_ajouter1;
    QWidget *tab_7;
    QTableView *tab_achat;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *le_ida1;
    QLineEdit *le_prixa1;
    QLineEdit *le_datea1;
    QLineEdit *le_idf3;
    QLineEdit *le_ida_rechercher;
    QPushButton *pb_supprimer1;
    QPushButton *pb_modifer1;
    QPushButton *pb_imprimer1;
    QPushButton *pb_tri1;
    QPushButton *pb_rechercher1;
    QWidget *tab_8;
    QTableView *tablestat;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(908, 589);
        MainWindow->setStyleSheet(QLatin1String("background-color: #212529;\n"
"QPushButton\n"
"{\n"
"border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(90, 20, 671, 461));
        tabWidget_2->setStyleSheet(QLatin1String("QTabWidget::pane {\n"
"    background: transparent;\n"
"    border:0;\n"
"}\n"
"\n"
"QTabBar::tab\n"
"{\n"
"	background-color: rgba(42, 46, 50,0);\n"
"	color:#ffffff;\n"
"	width:200px;\n"
"	font-size:16px;\n"
"	font-family:Calibri;\n"
"\n"
"}\n"
"\n"
"QTabBar::tab:hover\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"		color:rgb(249, 167, 43);\n"
"}\n"
"\n"
"QTabBar::tab:focus\n"
"{\n"
"	background-color: rgb(59, 62, 66);\n"
"	border-style:solid;\n"
"	border-left-width:1px;\n"
"	border-bottom-width:1px;\n"
"	border-color: rgb(249, 167, 43);\n"
"	color:rgb(249, 167, 43);\n"
"}\n"
"QTabBar::tab:selected\n"
"{\n"
"	background-color: rgb(59, 62, 66);\n"
"	border-style:solid;\n"
"	border-left-width:1px;\n"
"	border-bottom-width:1px;\n"
"	border-color:   rgb(249, 167, 43);\n"
"	color:  rgb(249, 167, 43);\n"
"}"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget = new QTabWidget(tab_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 631, 401));
        tabWidget->setStyleSheet(QLatin1String("QTabWidget::pane {\n"
"    background: transparent;\n"
"    border:0;\n"
"}\n"
"\n"
"QTabBar::tab\n"
"{\n"
"	background-color: rgba(42, 46, 50,0);\n"
"	color:#ffffff;\n"
"	width:200px;\n"
"	font-size:16px;\n"
"	font-family:Calibri;\n"
"\n"
"}\n"
"\n"
"QTabBar::tab:hover\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"		color:rgb(249, 167, 43);\n"
"}\n"
"\n"
"QTabBar::tab:focus\n"
"{\n"
"	background-color: rgb(59, 62, 66);\n"
"	border-style:solid;\n"
"	border-left-width:1px;\n"
"	border-bottom-width:1px;\n"
"	border-color: rgb(249, 167, 43);\n"
"	color:rgb(249, 167, 43);\n"
"}\n"
"QTabBar::tab:selected\n"
"{\n"
"	background-color: rgb(59, 62, 66);\n"
"	border-style:solid;\n"
"	border-left-width:1px;\n"
"	border-bottom-width:1px;\n"
"	border-color:   rgb(249, 167, 43);\n"
"	color:  rgb(249, 167, 43);\n"
"}"));
        tabWidget->setTabsClosable(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 56, 16));
        label->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 56, 16));
        label_2->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 120, 56, 16));
        label_3->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 160, 56, 16));
        label_4->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);color: rgb(255, 255, 255);"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 200, 81, 16));
        label_5->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);color: rgb(255, 255, 255);"));
        le_idf = new QLineEdit(tab);
        le_idf->setObjectName(QStringLiteral("le_idf"));
        le_idf->setGeometry(QRect(150, 40, 113, 22));
        le_idf->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_nomf = new QLineEdit(tab);
        le_nomf->setObjectName(QStringLiteral("le_nomf"));
        le_nomf->setGeometry(QRect(150, 80, 113, 22));
        le_nomf->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_adressef = new QLineEdit(tab);
        le_adressef->setObjectName(QStringLiteral("le_adressef"));
        le_adressef->setGeometry(QRect(150, 120, 113, 22));
        le_adressef->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_telf = new QLineEdit(tab);
        le_telf->setObjectName(QStringLiteral("le_telf"));
        le_telf->setGeometry(QRect(150, 160, 113, 22));
        le_telf->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_numcompte = new QLineEdit(tab);
        le_numcompte->setObjectName(QStringLiteral("le_numcompte"));
        le_numcompte->setGeometry(QRect(150, 200, 113, 22));
        le_numcompte->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        pb_ajouter = new QPushButton(tab);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(340, 200, 93, 28));
        pb_ajouter->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_fournisseur = new QTableView(tab_2);
        tab_fournisseur->setObjectName(QStringLiteral("tab_fournisseur"));
        tab_fournisseur->setGeometry(QRect(240, 10, 361, 241));
        tab_fournisseur->setStyleSheet(QStringLiteral("color:rgb(249,167,43);"));
        pb_trier = new QPushButton(tab_2);
        pb_trier->setObjectName(QStringLiteral("pb_trier"));
        pb_trier->setGeometry(QRect(510, 270, 93, 28));
        pb_trier->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        le_id_rechercher = new QLineEdit(tab_2);
        le_id_rechercher->setObjectName(QStringLiteral("le_id_rechercher"));
        le_id_rechercher->setGeometry(QRect(380, 310, 113, 22));
        le_id_rechercher->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        pb_rechercher = new QPushButton(tab_2);
        pb_rechercher->setObjectName(QStringLiteral("pb_rechercher"));
        pb_rechercher->setGeometry(QRect(270, 310, 93, 28));
        pb_rechercher->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 60, 56, 16));
        label_12->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 90, 56, 16));
        label_13->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(30, 116, 56, 20));
        label_14->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(30, 150, 56, 16));
        label_15->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 180, 71, 20));
        label_16->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);color: rgb(255, 255, 255);"));
        le_idf1 = new QLineEdit(tab_2);
        le_idf1->setObjectName(QStringLiteral("le_idf1"));
        le_idf1->setGeometry(QRect(100, 60, 113, 22));
        le_idf1->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_nomf1 = new QLineEdit(tab_2);
        le_nomf1->setObjectName(QStringLiteral("le_nomf1"));
        le_nomf1->setGeometry(QRect(100, 90, 113, 22));
        le_nomf1->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_adressef1 = new QLineEdit(tab_2);
        le_adressef1->setObjectName(QStringLiteral("le_adressef1"));
        le_adressef1->setGeometry(QRect(100, 120, 113, 22));
        le_adressef1->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_telf1 = new QLineEdit(tab_2);
        le_telf1->setObjectName(QStringLiteral("le_telf1"));
        le_telf1->setGeometry(QRect(100, 150, 113, 22));
        le_telf1->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_numcompte1 = new QLineEdit(tab_2);
        le_numcompte1->setObjectName(QStringLiteral("le_numcompte1"));
        le_numcompte1->setGeometry(QRect(100, 180, 113, 22));
        le_numcompte1->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        pb_modifier_2 = new QPushButton(tab_2);
        pb_modifier_2->setObjectName(QStringLiteral("pb_modifier_2"));
        pb_modifier_2->setGeometry(QRect(120, 230, 93, 28));
        pb_modifier_2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        pb_supprimer = new QPushButton(tab_2);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(20, 230, 93, 28));
        pb_supprimer->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 310, 93, 28));
        pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(420, 270, 73, 22));
        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        add = new QPushButton(tab_5);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(270, 220, 31, 28));
        add->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        remove = new QPushButton(tab_5);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setGeometry(QRect(300, 190, 31, 28));
        remove->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        multy = new QPushButton(tab_5);
        multy->setObjectName(QStringLiteral("multy"));
        multy->setGeometry(QRect(330, 220, 31, 28));
        multy->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        div = new QPushButton(tab_5);
        div->setObjectName(QStringLiteral("div"));
        div->setGeometry(QRect(300, 250, 31, 28));
        div->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        LabelResulta = new QLabel(tab_5);
        LabelResulta->setObjectName(QStringLiteral("LabelResulta"));
        LabelResulta->setGeometry(QRect(240, 40, 151, 41));
        LabelResulta->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"font: 14pt \"MS Shell Dlg 2\";\n"
"font: 20pt \"MS Shell Dlg 2\";\n"
"font: 20pt \"MS Shell Dlg 2\";\n"
"font: 26pt \"MS Shell Dlg 2\";\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        a = new QLineEdit(tab_5);
        a->setObjectName(QStringLiteral("a"));
        a->setGeometry(QRect(210, 160, 51, 22));
        a->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        b = new QLineEdit(tab_5);
        b->setObjectName(QStringLiteral("b"));
        b->setGeometry(QRect(390, 161, 51, 21));
        b->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_5, QString());
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget_3 = new QTabWidget(tab_4);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(-10, 0, 641, 401));
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        label_6 = new QLabel(tab_6);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 40, 56, 16));
        label_6->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_7 = new QLabel(tab_6);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 90, 56, 16));
        label_7->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_8 = new QLabel(tab_6);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 140, 71, 16));
        label_8->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_9 = new QLabel(tab_6);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(80, 190, 91, 16));
        label_9->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_ida = new QLineEdit(tab_6);
        le_ida->setObjectName(QStringLiteral("le_ida"));
        le_ida->setGeometry(QRect(230, 40, 113, 22));
        le_ida->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_prixa = new QLineEdit(tab_6);
        le_prixa->setObjectName(QStringLiteral("le_prixa"));
        le_prixa->setGeometry(QRect(230, 90, 113, 22));
        le_prixa->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_datea = new QLineEdit(tab_6);
        le_datea->setObjectName(QStringLiteral("le_datea"));
        le_datea->setGeometry(QRect(230, 140, 113, 22));
        le_datea->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_idf2 = new QLineEdit(tab_6);
        le_idf2->setObjectName(QStringLiteral("le_idf2"));
        le_idf2->setGeometry(QRect(230, 190, 113, 22));
        le_idf2->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        pb_ajouter1 = new QPushButton(tab_6);
        pb_ajouter1->setObjectName(QStringLiteral("pb_ajouter1"));
        pb_ajouter1->setGeometry(QRect(390, 240, 93, 28));
        pb_ajouter1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        tabWidget_3->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tab_achat = new QTableView(tab_7);
        tab_achat->setObjectName(QStringLiteral("tab_achat"));
        tab_achat->setGeometry(QRect(320, 30, 321, 241));
        tab_achat->setStyleSheet(QStringLiteral("color:rgb(249,167,43);"));
        label_10 = new QLabel(tab_7);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(70, 70, 56, 16));
        label_10->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_11 = new QLabel(tab_7);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(70, 220, 56, 16));
        label_11->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_17 = new QLabel(tab_7);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(70, 170, 56, 16));
        label_17->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_18 = new QLabel(tab_7);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(70, 120, 56, 16));
        label_18->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_ida1 = new QLineEdit(tab_7);
        le_ida1->setObjectName(QStringLiteral("le_ida1"));
        le_ida1->setGeometry(QRect(150, 70, 113, 22));
        le_ida1->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_prixa1 = new QLineEdit(tab_7);
        le_prixa1->setObjectName(QStringLiteral("le_prixa1"));
        le_prixa1->setGeometry(QRect(150, 120, 113, 22));
        le_prixa1->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_datea1 = new QLineEdit(tab_7);
        le_datea1->setObjectName(QStringLiteral("le_datea1"));
        le_datea1->setGeometry(QRect(150, 170, 113, 22));
        le_datea1->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_idf3 = new QLineEdit(tab_7);
        le_idf3->setObjectName(QStringLiteral("le_idf3"));
        le_idf3->setGeometry(QRect(150, 220, 113, 22));
        le_idf3->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        le_ida_rechercher = new QLineEdit(tab_7);
        le_ida_rechercher->setObjectName(QStringLiteral("le_ida_rechercher"));
        le_ida_rechercher->setGeometry(QRect(500, 330, 113, 22));
        pb_supprimer1 = new QPushButton(tab_7);
        pb_supprimer1->setObjectName(QStringLiteral("pb_supprimer1"));
        pb_supprimer1->setGeometry(QRect(60, 270, 93, 28));
        pb_supprimer1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        pb_modifer1 = new QPushButton(tab_7);
        pb_modifer1->setObjectName(QStringLiteral("pb_modifer1"));
        pb_modifer1->setGeometry(QRect(180, 270, 93, 28));
        pb_modifer1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        pb_imprimer1 = new QPushButton(tab_7);
        pb_imprimer1->setObjectName(QStringLiteral("pb_imprimer1"));
        pb_imprimer1->setGeometry(QRect(120, 320, 93, 28));
        pb_imprimer1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        pb_tri1 = new QPushButton(tab_7);
        pb_tri1->setObjectName(QStringLiteral("pb_tri1"));
        pb_tri1->setGeometry(QRect(520, 290, 93, 28));
        pb_tri1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        pb_rechercher1 = new QPushButton(tab_7);
        pb_rechercher1->setObjectName(QStringLiteral("pb_rechercher1"));
        pb_rechercher1->setGeometry(QRect(400, 330, 93, 28));
        pb_rechercher1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}"));
        tabWidget_3->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tablestat = new QTableView(tab_8);
        tablestat->setObjectName(QStringLiteral("tablestat"));
        tablestat->setGeometry(QRect(100, 50, 341, 221));
        tablestat->setStyleSheet(QStringLiteral("color:rgb(249,167,43);"));
        tabWidget_3->addTab(tab_8, QString());
        tabWidget_2->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 908, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::RightToolBarArea, toolBar);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(1);
        tabWidget->setCurrentIndex(2);
        tabWidget_3->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "idf", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "nomf", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "adressef", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "telf", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "numcompte", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "ajouter fournisseur", Q_NULLPTR));
        pb_trier->setText(QApplication::translate("MainWindow", "trier", Q_NULLPTR));
        pb_rechercher->setText(QApplication::translate("MainWindow", "rechercher", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "idf", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "nomf", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "adressef", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "telf", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "numcompte", Q_NULLPTR));
        pb_modifier_2->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "imprimer pdf", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "idf", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nomf", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "afficher fournisseurs", Q_NULLPTR));
        add->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        remove->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        multy->setText(QApplication::translate("MainWindow", "*", Q_NULLPTR));
        div->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
        LabelResulta->setText(QApplication::translate("MainWindow", "scxez", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "calculatrice", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Gestion fournisseur", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "id achat", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "prix achat", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "date achat", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "id fournisseur", Q_NULLPTR));
        pb_ajouter1->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("MainWindow", "ajouter achat", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "id achat", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "id fournisseur", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "date achat", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "prix achat", Q_NULLPTR));
        pb_supprimer1->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        pb_modifer1->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        pb_imprimer1->setText(QApplication::translate("MainWindow", "imprimer PDF", Q_NULLPTR));
        pb_tri1->setText(QApplication::translate("MainWindow", "trier", Q_NULLPTR));
        pb_rechercher1->setText(QApplication::translate("MainWindow", "rechercher", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QApplication::translate("MainWindow", "afficher achat", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QApplication::translate("MainWindow", "statistique", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Gestion des achats", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACHAT_H
