#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>
#include <memory>

using  namespace std;

class Entity
{
    protected:
        int hp;
        int attaque;
        int defense;
    public:
        Entity(int hp=100, int attaque=10, int defense=10);
        int get_hp()const;
        int get_defense();
        int get_attaque();
        void Afficher();
        void set_defense(int defense);
        void set_attaque(int attaque);
        void set_hp(int hp);
        
};
#endif