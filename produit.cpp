#include "Produit.h"
#include <iostream>

using namespace std;

Produit::Produit()
{
    //ctor
}

Produit::Produit(char *p_nom , float p_prix)
{
    nom = new char[25];
    if(nom == NULL)
        cout<<"Erreur lors de l'allocation mémoire du nom du produit"<<endl;
    else
    {
        nom = p_nom;
        prix = p_prix;
    }
}

Produit::~Produit()
{
    //dtor
}

char* Produit::acces_nom(){return nom;}
float Produit::acces_prix(){return prix;}
