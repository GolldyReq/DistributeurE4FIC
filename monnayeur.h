#ifndef MONNAYEUR_H
#define MONNAYEUR_H


class Monnayeur
{
    public:
        Monnayeur();
        virtual ~Monnayeur();
        bool exact();
        bool assez();
        void memorise_prix(float);
        void recevoir(float);
        float rendre_monnaie();
        float annulation();
        float getPrix();
        float getTotal();
    protected:

    private:
        float prix_produit;
        float somme_total;
};

#endif // MONNAYEUR_H
