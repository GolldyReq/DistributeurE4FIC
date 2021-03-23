#ifndef DISTRIBUTEUR_H
#define DISTRIBUTEUR_H

#include "stock.h"
#include "monnayeur.h"


class Distributeur
{
    public:
        // Constructeur / Destructeur
        Distributeur();
        ~Distributeur() {};
        // Fonctions d'etat
        int produit_demande() const;
        // Autres methodes
        void delivre_produit();
        void annule_demande();
        void demande_produit( int num );
        void run();
        int getNbSortes();
        int getMaxQuantite();
        char* getProductName(int num);
        float getProductPrice(int num);
        void AjoutArgent(float qt);
        float getSommeMise();
        Monnayeur getMonnayeur();
    // Donnees membres
    private:
        int num_produit;
        stock stock_produits;
        Monnayeur monnayeur;

};

#endif // DISTRIBUTEUR_H
