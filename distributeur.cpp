#include "Distributeur.h"
#include "Produit.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define NBMAXPROD 10;

//Constructeur
Distributeur::Distributeur()
{
    num_produit = -1; //Aucun produit demandé
    //initialisation des produits
    Produit *produit;
    ifstream readData("data.txt");
    if(readData)
    {
        cout<<"Lecture des donnees du distributeur..."<<endl;
        string product_line;
        while(getline(readData, product_line))
        {
            cout<<product_line<<endl;
            vector<string> result;
            stringstream ss (product_line);
            string item;
            while (getline (ss, item,',')) {
                result.push_back (item);
            }
            produit = new Produit((char*)result[0].c_str() , atof(result[1].c_str()));
            stock_produits.stocker(produit,atoi(result[2].c_str()));


        }
        cout<<"Fermeture du fichier de donnees"<<endl;
        readData.close();
    }
    else
        cout<<"Le fichier de données est introuvable !"<<endl;




    /*
    produit = new Produit("Orange" , 3.00);
    stock_produits.stocker(produit,5);

    produit = new Produit("Cafe_sans" , 5.00);
    stock_produits.stocker(produit,4);

    produit = new Produit("Cafe_unpeu" , 5.00);
    stock_produits.stocker(produit,3);

    produit = new Produit("Cafe_beaucoup" , 5.00);
    stock_produits.stocker(produit,2);
    */


}

//Fonction d'etat
int Distributeur::produit_demande() const
{
    return num_produit!=-1;
}

//Autres mehtodes
float Distributeur::delivre_produit()
{
    stock_produits.retirer(num_produit);
    float res = monnayeur.rendre_monnaie();
    if(stock_produits.est_limite())
        cout<<"[Appelez le remplisseur !] " <<endl;
    else
        cout<<"[Remplissage OK]"<<endl;

    //Appel fonction d'ecriture fichier
    updateData();

    return res;
}

void Distributeur::demande_produit(int num)
{
    num_produit = num;
    cout<<"Produit demande : " <<stock_produits.ieme(num_produit)->acces_nom()<<endl;
    monnayeur.memorise_prix(stock_produits.ieme(num_produit)->acces_prix());
}

void Distributeur::annule_demande()
{
    num_produit = -1;
    monnayeur.rendre_monnaie();
}

int Distributeur::getNbSortes()
{
    return stock_produits.nb_sortes();
}
int Distributeur::getMaxQuantite()
{
    return stock_produits.getMaxQuantite();
}

char* Distributeur::getProductName(int num)
{
    return stock_produits.ieme(num)->acces_nom();
}

float Distributeur::getProductPrice(int num)
{
    return stock_produits.ieme(num)->acces_prix();
}

void Distributeur::AjoutArgent(float qt)
{
    monnayeur.recevoir(qt);
}

float Distributeur::getSommeMise()
{
    return monnayeur.getTotal();
}

Monnayeur Distributeur::getMonnayeur()
{
    return monnayeur;
}

stock Distributeur::getStock()
{
    return stock_produits;
}


void Distributeur::ajoutProduit(int num_produit)
{
    stock_produits.stocker(stock_produits.ieme(num_produit),1);
    //Appel fonction d'ecriture fichier
    updateData();

}

void Distributeur::suppressionProduit(int num_produit)
{
    if(stock_produits.nb_unites(num_produit)>0)
        stock_produits.stocker(stock_produits.ieme(num_produit),-1);
    //Appel fonction d'ecriture fichier
    updateData();
}

void Distributeur::run()
{
    char rep1,rep2;
    int fini =0;
    float piece;
    while(!fini)
    {
        cout<<"[P]roduits , [M]onnayeur , [Q]uitter ? ";
        cin>>rep1;
        switch (rep1)
        {
            case 'P':
            case 'p':
                cout<< "[Q]uitter ou numero du produit ?";
                cin >>rep2;
                switch(rep2)
                {
                    case 'Q':
                    case 'q':
                        break;
                    case '1' :
                    case '2' :
                    case '3' :
                    case '4' :
                        demande_produit(atof(&rep2)-1); //Index des produits commence a 0
                }
                break;
            case 'm':
            case 'M':
                //monnayeur.Run();
                cout<<"[Q]uitter ou [A]nnulation ou "<<endl;
                cout<<"[0]: 0F50 , [1] : 1F , [2] : 2F ,[5] : 5F ,[D] : 10F ?";
                cin>>rep2;
                piece = 0.00;
                switch(rep2)
                {
                    case 'Q':
                        break;
                    case 'A':
                        annule_demande();
                        break;
                    case 'D' : piece += 5.00;
                    case '5' : piece += 3.00;
                    case '2' : piece += 1.00;
                    case '1' : piece += 0.50;
                    case '0' : piece += 0.50;
                        monnayeur.recevoir(piece);
                        if(monnayeur.exact() ||monnayeur.assez())
                        {
                            cout<<"vous avez mis assez d'argent"<<endl;
                            delivre_produit();
                        }
                        break;
                    default:
                            cout<<"Q ou A ou 0,1,2,5,D !"<<endl;
                } //switch 2
                break;
            case 'q' :
            case 'Q' :
                fini = 1;
                break;
            default :
                cout<< "P ou M ou Q !"<<endl;
        }//switch 1
    }//while ! fini
} //Run()

void Distributeur::updateData()
{
    ofstream writeData("data.txt");
    if(writeData)
    {
        for(int i=0 ; i<stock_produits.nb_sortes();i++)
        {
            string nom_produit = stock_produits.ieme(i)->acces_nom();
            float prix_produit = stock_produits.ieme(i)->acces_prix();
            int qt = stock_produits.nb_unites(i);
            writeData<<nom_produit<<","<<prix_produit<<","<<qt<<endl;
        }
    }
    else
    {
        cout<<"Impossible d'ouvrir le fichier "<<endl;
    }

}

void Distributeur::Start()
{

}
