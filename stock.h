#ifndef STOCK_H
#define STOCK_H

#include "Produit.h"


class stock
{
    typedef Produit elem;

    //Definition des constantes
    static const int MAX_SORTES = 5;
    static const int MAX_QUANTITE = 10;
    static const int OK = 0;
    static const int ERR_INCONNU = -1;
    static const int ERR_INTERVALLE = 0;
    static const int ERR_PLEIN = 1;
    static const int ERR_VIDE = 2;
    static const int ERR_DEP = 3;


    //Membres privés
    private:
        // Donnees membres
        int index;
        int quantites[MAX_SORTES];
        elem* rails[MAX_SORTES];


    //Membres publiques
    public:
        //Constructeur/Destructeur
        stock();
        virtual ~stock();
        // Accesseurs
        int nb_sortes();
        int nb_unites( int );
        elem* ieme(int);
        // Fonctions d'etat
        int est_vide(int);
        int est_limite();
        // Autres fonctions
        int stocker(elem*, int);
        int retirer( int );
        int traite_vide( int );
        //fonctions internes
        int est_plein(int);
        int rechercher(elem* );
        int getMaxQuantite();
};

#endif // STOCK_H
