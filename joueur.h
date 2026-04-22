#pragma once
<<<<<<< HEAD

=======
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <random>
using  namespace std;
<<<<<<< HEAD

=======
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
#include "item.h"
#include "statistique.h"

class Joueur:public Statistique
{
    private:
        string nom;
        Item* items;
        int nb_items;
    public:
<<<<<<< HEAD
        Joueur(string nom,Item* items,int nb_items);
=======
        Joueur(string nom);
        Joueur();
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
        string get_nom();
        Item* get_items();
        int get_nb_items();
        void set_nb_items(int nb_item);
        void set_items(Item* items);
<<<<<<< HEAD
        void Afficher();   
=======
        void Afficher();
        void AfficherInventaire();
        

        

>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
};
