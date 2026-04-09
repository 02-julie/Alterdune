#pragma once
#include <iostream>
#include <string>
#include <memory>

using  namespace std;

class Statistique
{
    protected:
        int hp;
        int attaque;
        int defense;
    public:
        Statistique(int hp, int attaque,int defense);
        int get_hp();
        int get_defense();
        int get_attaque();
        void Afficher();
        void set_defense(int defense);
        void set_attaque(int attaque);
        void set_hp(int hp);
        
};