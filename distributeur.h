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
        float delivre_produit();
        void annule_demande();
        void demande_produit( int num );
        void run();
        int getNbSortes();
        int getMaxQuantite();
        char* getProductName(int num);
        float getProductPrice(int num);
        void AjoutArgent(float qt);
        float getSommeMise();
        void Start();

        Monnayeur getMonnayeur();
        stock getStock();
        void ajoutProduit(int num_produit);
        void suppressionProduit(int num_produit);
        void updateData();
    // Donnees membres
    private:
        int num_produit;
        stock stock_produits;
        Monnayeur monnayeur;

};

#endif // DISTRIBUTEUR_H
