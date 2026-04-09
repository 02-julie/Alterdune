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


class Statistique
{
    protected:
        int hp;
        int attaque;
        int defense;
    public:
        Statistique(int hp=0, int attaque=0,int defense=0);
        int get_hp();
        int get_defense();
        int get_attaque();
        void Afficher();
        void set_defense(int defense);
        void set_attaque(int attaque);
        void set_hp(int hp);
        
};