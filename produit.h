#ifndef PRODUIT_H
#define PRODUIT_H


class Produit
{
    private:
        char *nom;
        float prix;

    public:
        Produit();
        Produit(char *p_nom , float p_prix);
        virtual ~Produit();
        //Accesseurs
        char* acces_nom();
        float acces_prix();

};

#endif // PRODUIT_H
