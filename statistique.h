<<<<<<< HEAD
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
=======
#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include <iostream>
#include <string>
#include <memory>

>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
using  namespace std;


class Statistique
{
    protected:
        int hp;
        int attaque;
        int defense;
    public:
<<<<<<< HEAD
        Statistique(int hp=0, int attaque=0,int defense=0);
        int get_hp();
=======
        Statistique(int hp=100, int attaque=10, int defense=10);
        int get_hp()const;
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
        int get_defense();
        int get_attaque();
        void Afficher();
        void set_defense(int defense);
        void set_attaque(int attaque);
        void set_hp(int hp);
        
};
#endif