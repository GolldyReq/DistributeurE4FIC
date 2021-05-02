#include "Monnayeur.h"
#include <iostream>

using namespace std;

Monnayeur::Monnayeur()
{
    prix_produit = 0;
    somme_total = 0;
}

Monnayeur::~Monnayeur()
{
    //dtor
}

bool Monnayeur::exact()
{
    return somme_total==prix_produit;
}

bool Monnayeur::assez()
{
    return somme_total>=prix_produit;
}

void Monnayeur::memorise_prix(float prix)
{
    prix_produit = prix;
    cout<<"somme rendue : 0"<<endl;
    cout<<"prix a payer : "<<prix_produit<<endl;
}

void Monnayeur::recevoir(float value)
{

    somme_total += value;
    cout<<"somme deja paye : "<<somme_total<<endl;
}

float Monnayeur::rendre_monnaie()
{

    if(exact() || assez())
    {
        float somme_rendu = somme_total - prix_produit;
        cout<<"Somme rendue "<<somme_rendu<<endl;
        prix_produit = 0 ;
        somme_total = 0;
        return somme_rendu;
    }
    else
    {
        cout<<"somme rendue "<<somme_total<<endl;
        prix_produit =0;
        somme_total = 0;
        return somme_total;
    }

}

float Monnayeur::annulation()
{
    prix_produit = 0;
    return rendre_monnaie();
}

float Monnayeur::getPrix()
{
    return prix_produit;
}

float Monnayeur::getTotal()
{
    return somme_total;
}
