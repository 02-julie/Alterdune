#pragma once
<<<<<<< HEAD

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

#include "monstre.h"
=======
#include <iostream>
#include <string>
#include <memory>
#include "monstre.h"
using  namespace std;
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf

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