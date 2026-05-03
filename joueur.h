#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iomanip>
using  namespace std;
#include "item.h"
#include "entity.h"

class Joueur:public Entity
{
    private:
        string nom;
        Item* items;
        int nb_items;
    public:
        Joueur(string nom);
        Joueur();
        ~Joueur();
        string get_nom();
        Item* get_items();
        int get_nb_items();
        void set_nb_items(int nb_item);
        void set_items(Item* items);
        void Afficher();
        void AfficherInventaire();
        

        

};
