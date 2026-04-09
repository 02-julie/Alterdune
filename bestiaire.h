#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "monstre.h"
using  namespace std;

class Bestiaire{
    private:
        Monstre monstres[10];
        int nb_tue;
        int nb_epargne;
        int nb_victoire; 
    public:
        Bestiaire(Monstre monstres[10] = {}, int nb_tue = 0
        , int nb_epargne = 0, int nb_victoire = 0);
        void afficher();
        int getNbTue();
        int getNbEpargne();
        int getNbVictoire();
        void ajouterMonstre(Monstre monstre);
};