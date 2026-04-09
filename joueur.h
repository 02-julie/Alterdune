#pragma once

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

#include "item.h"
#include "statistique.h"

class Joueur:public Statistique
{
    private:
        string nom;
        Item* items;
        int nb_items;
    public:
        Joueur(string nom,Item* items,int nb_items);
        string get_nom();
        Item* get_items();
        int get_nb_items();
        void set_nb_items(int nb_item);
        void set_items(Item* items);
        void Afficher();   
};
