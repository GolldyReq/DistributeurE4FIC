#ifndef DISTRIBUTEURFENETRE_H
#define DISTRIBUTEURFENETRE_H

//Include Qt
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QProgressBar>
#include <QTextEdit>
#include <QTextBlock>


//Project Include
#include "distributeur.h"
#include "monnayeur.h"
#include "stock.h"
#include "produit.h"

class DistributeurFenetre : public QWidget
{
    Q_OBJECT

    private :
        //Donnees
        Distributeur *distributeur;
        int choix;
        float somme_mise;
        int nb_produits;
        bool admin;


        //Layout
        QHBoxLayout *final_layout;
        //partie gauche de l'appli
        QGridLayout *distrib_layout; //Layout distributeur;
        QGridLayout *touche_layout;// Layout touche;
        QHBoxLayout *top_distrib; //Ecran & vitrine
        //partie droite de l'appli
        QGridLayout *layout_info;
        QVBoxLayout *status_layout;
        QGridLayout *payment_layout;



        //Visuels
        QLabel *img_distrib;
        QLabel *e05 , *e1 , *e2,*e5,*e10;
        QPushButton *buttons[12];
        QPushButton *monney[5];
        QProgressBar *stock_produits[5];
        QTextEdit *textScreen;
        QTextBlock *testScreen;


    public:
        DistributeurFenetre();
        DistributeurFenetre(int x,int y);
    public slots:
        void ToucheSaisie();
        void CancelSaisie();
        void ValiderSaisie();
        void AjoutArgent();
};

#endif // DISTRIBUTEURFENETRE_H
