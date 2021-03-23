#include "distributeurfenetre.h"+3
#include <iostream>
#include <string>
#include <stdlib.h>
#include <regex>

#include <QString>


using namespace std;

DistributeurFenetre::DistributeurFenetre() : QWidget()
{
}

DistributeurFenetre::DistributeurFenetre(int x,int y) : QWidget()
{
    setFixedSize(x, y);

    //Init logique
    choix =-1 ;
    distributeur = new Distributeur();
    somme_mise = 0;
    nb_produits = distributeur->getNbSortes();
    admin = false;


    //Layout
    final_layout = new QHBoxLayout();
    distrib_layout = new QGridLayout();
    touche_layout= new QGridLayout();
    top_distrib = new QHBoxLayout();
    top_distrib->setAlignment(Qt::AlignLeft);
    layout_info = new QGridLayout();
    status_layout = new QVBoxLayout();
    payment_layout = new QGridLayout();
    payment_layout->setAlignment(Qt::AlignLeft|Qt::AlignBottom);


    //Image du distributeur
    img_distrib = new QLabel();
    img_distrib->setPixmap(QPixmap("D:\\ESIEE\\E4\\2e semestre\\C++\\Qt\\Distributeur\\ProjetCDistributeur\\img\\distributeur.jpg"));
    distrib_layout->addWidget(img_distrib , 0,0,100,100);

    //Boutton de saisie
    int compteur = 0 ;
    for(int i = 0 ; i< 4 ; i++)
    {
        if(i!=3)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                QString str = QString::number(compteur+1);
                buttons[compteur] = new QPushButton( str );//, this);
                buttons[compteur]->setFixedSize(20,20);
                touche_layout->addWidget(buttons[compteur] , i+25,j+13);
                QObject::connect(buttons[compteur], SIGNAL(clicked()), this, SLOT(ToucheSaisie()));
                compteur++;
            }
        }
        else
        {
            buttons[compteur] = new QPushButton("");
            buttons[compteur]->setFixedSize(20,20);
            buttons[compteur]->setStyleSheet("background-color: red;");
            QObject::connect(buttons[compteur], SIGNAL(clicked()), this, SLOT(CancelSaisie()));
            touche_layout->addWidget(buttons[compteur] , i + 25 , 13);
            compteur++;
            buttons[compteur] = new QPushButton("0");
            buttons[compteur]->setFixedSize(20,20);
            touche_layout->addWidget(buttons[compteur] , i + 25 , 14);
            QObject::connect(buttons[compteur], SIGNAL(clicked()), this, SLOT(ToucheSaisie()));
            compteur++;
            buttons[compteur] = new QPushButton("");
            buttons[compteur]->setFixedSize(20,20);
            buttons[compteur]->setStyleSheet("background-color: green;");
            QObject::connect(buttons[compteur], SIGNAL(clicked()), this, SLOT(ValiderSaisie()));
            touche_layout->addWidget(buttons[compteur] , i + 25 , 15);
        }
    }
    //Screen
    textScreen = new QTextEdit();
    textScreen->setTextColor(QColor("green"));
    textScreen->setStyleSheet("background-color : black; font-weight : bold;");
    textScreen->insertPlainText("Produit ?");
    textScreen->setFixedSize(75,75);
    textScreen->setReadOnly(true);
    top_distrib->addWidget(textScreen);

    /*
    //Exemple progress Bar
    for(int i = 0 ; i<distributeur->getNbSortes() ; i++)
    {
        stock_produits[i] = new QProgressBar();
        stock_produits[i]->setMinimum(0);
        stock_produits[i] ->setMaximum(distributeur->getMaxQuantite());
        StatusLayout->addWidget(stock_produits[i]);
    }
    */

    //Affichage paiement
    string img_path[5] = {
        "D:\\ESIEE\\E4\\2e semestre\\C++\\Qt\\Distributeur\\ProjetCDistributeur\\img\\50ct.png",
        "D:\\ESIEE\\E4\\2e semestre\\C++\\Qt\\Distributeur\\ProjetCDistributeur\\img\\1e.png",
        "D:\\ESIEE\\E4\\2e semestre\\C++\\Qt\\Distributeur\\ProjetCDistributeur\\img\\2e.png",
        "D:\\ESIEE\\E4\\2e semestre\\C++\\Qt\\Distributeur\\ProjetCDistributeur\\img\\5e.png",
        "D:\\ESIEE\\E4\\2e semestre\\C++\\Qt\\Distributeur\\ProjetCDistributeur\\img\\10e.jpg"
    };
    string monney_values[5] = { "0.5" , "1" , "2" , "5" , "10"};

    for (int i = 0 ; i < 5 ; i++)
    {
        QPixmap pixmap(QString::fromStdString(img_path[i]));
        cout<<img_path[i]<<endl;
        QIcon ButtonIcon(pixmap);
        monney[i] = new QPushButton(QString::fromStdString(monney_values[i]));
        QObject::connect(monney[i], SIGNAL(clicked()), this, SLOT(AjoutArgent()));
        monney[i]->setStyleSheet("background-color: white;");
        monney[i]->setIcon(ButtonIcon);
        monney[i]->setIconSize(pixmap.rect().size());
        monney[i]->setFixedSize(50,50);
        monney[i]->setIconSize(QSize(50,50));
        payment_layout->addWidget(monney[i] , 0,i);

    }

    //Attribution des layouts
    distrib_layout->addLayout(top_distrib, 38,42 );//, 5 ,5);
    distrib_layout->addLayout(touche_layout ,48,42);// , 4 , 3);
    layout_info->addLayout(status_layout , 0 , 0 , 50 , 20);
    layout_info->addLayout(payment_layout,0,50,50,20);
    final_layout->addLayout(distrib_layout);
    final_layout->addLayout(layout_info);
    this->setLayout(final_layout);

}


void DistributeurFenetre::ToucheSaisie()
{

    QPushButton *push = qobject_cast<QPushButton *>(sender());

    if(!textScreen->toPlainText().toInt())
        textScreen->setText("");
    textScreen->insertPlainText(QString(push->text()));
    choix = textScreen->toPlainText().toInt();
    //textScreen->insertPlainText(QString::fromStdString("\nSomme : " ) + QString::number(distributeur->getSommeMise() , 10 , 2));
}

void DistributeurFenetre::CancelSaisie()
{
    textScreen->setText("");
    choix = -1;
    distributeur->annule_demande();
}

void DistributeurFenetre::ValiderSaisie()
{

    if(textScreen->toPlainText() == "1234")
    {
        //Activé/Desactivé le mode admin
        admin=!admin;
        if(admin)
        {
            cout<<"Mode Administrateur activé "<<endl;
            textScreen->setText("Mode Admin");
        }
        else
        {
            cout<<"Fin du mode admin"<<endl;
            textScreen->setText("Produit ?");
        }

    }
    else if (textScreen->toPlainText().toInt() <= nb_produits && textScreen->toPlainText().toInt()>0)
    {
        choix = textScreen->toPlainText().toInt()-1;
        //Demande du produit
        distributeur->demande_produit(choix);

        cout<<"test :"<<choix<<endl;
        //QString txt =QString::fromStdString("Produit : "+ to_string(choix) + " OK!");
        QString product_name = QString::fromStdString("Produit : "+ string(distributeur->getProductName(choix)));
        QString product_price = QString::fromStdString("\nPrix : ")+ QString::number(distributeur->getProductPrice(choix) , 10 , 2) + QString("€");
        QString TotalMise = QString::fromStdString("\nSomme : " ) + QString::number(distributeur->getSommeMise() , 10 , 2) + QString("€");
        QString txt =product_name + product_price + TotalMise;
        textScreen->setText(txt);
    }
}

void DistributeurFenetre::AjoutArgent()
{
    QPushButton *push = qobject_cast<QPushButton *>(sender());
    somme_mise+=push->text().toFloat();
    cout<<somme_mise<<endl;
    distributeur->AjoutArgent(push->text().toFloat());
    textScreen->setText("");
    textScreen->insertPlainText(QString::fromStdString("\nSomme : " ) + QString::number(distributeur->getSommeMise() , 10 , 2));
    if(distributeur->getMonnayeur().assez() || distributeur->getMonnayeur().exact())
    {
        cout<<"Vous avez mis assez d'argent"<<endl;
        distributeur->delivre_produit();
        textScreen->setText("Produit délivré");
    }
}
