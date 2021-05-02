#include "stock.h"
#include <iostream>

using namespace std;

const int SEUIL = 2;
typedef Produit elem;


stock::stock()
{
    index = 0;
}

stock::~stock()
{
    //dtor
}

//b)
int stock::nb_sortes()
{
    return index;
}
//c)
int stock::nb_unites(int num_produit)
{
    return quantites[num_produit];
}
//d)
elem* stock::ieme (int num_produit)
{
    return rails[num_produit];
}

//e)
//1 : VRAI 0: FAUX
int stock::est_vide(int num_produit)
{
    if(quantites[num_produit] == 0)
        return 1;
    else
        return 0;

}

//f)
//1 : VRAI 0 : FAUX
int stock::est_limite()
{
    for (int i=0;i<index ; i++)
    {
        if(quantites[i] < SEUIL)
            return 1;
    }
    return 0;

}
//g)
int stock::stocker(elem* adr_produit, int quantite)
{

    if(rechercher(adr_produit) != ERR_INCONNU)
    {
        if(est_plein(rechercher(adr_produit)) == 1 && quantite!=-1)
        {
            return -1;
        }
        if(quantites[rechercher(adr_produit)] + quantite <= MAX_QUANTITE)
        {
            quantites[rechercher(adr_produit)] = quantites[rechercher(adr_produit)] + quantite;
            return 0;
        }
    }
    else
    {
        if(index == MAX_SORTES)
        {
            return ERR_PLEIN;
        }
        else
        {
            quantites[index]=quantite;
            rails[index]=adr_produit;
            index ++ ;
            return 0;
        }
    }
}


//h)
int stock::retirer( int num_produit)
{
    if(quantites[num_produit] == 0)
        traite_vide(num_produit);
    else
    {
       quantites[num_produit] --;
       return 0;
    }

}

//i)
int stock::traite_vide( int num_produit)
{
    return ERR_VIDE;

}

//j)

int stock::rechercher(elem* adr_produit )
{

    for(int i = 0 ; i<index ;i ++)
    {
        if(rails[i] == adr_produit)
        {
            return i;
        }
    }
    cout<<"je ne trouve pas le produit"<<endl;
    return ERR_INCONNU;

}

//k)
// 1 : VRAI 0 : FAUX
int stock::est_plein(int num_produit)
{

    if(quantites[num_produit] >= MAX_QUANTITE)
        return 1;
    else
        return 0;
}


int stock::getMaxQuantite()
{
    return MAX_QUANTITE;
}

elem* stock::getProduit(int num_produit)
{
    return ieme(num_produit);
}
