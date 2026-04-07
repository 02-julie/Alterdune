#include <iostream>
#include <string>
#include <memory>
using  namespace std;
#include "statistique.h"
#include "item.h"
class Joueur:public Statistique
{
    private:
        string nom;
        Item* items;
        int nb_items;
    public:
        Joueur::Joueur(string nom,Item* items,int nb_items);
        string Joueur::get_nom();
        Item* Joueur::get_items();
        int Joueur::get_nb_items();
        void Joueur::set_nb_items(int nb_item);
        void Joueur::set_items(Item* items);
        void Joueur::Afficher();
        

        

};
