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
        Statistique::Statistique(int hp, int attaque,int defense);
        int Statistique::get_hp();
        int Statistique::get_defense();
        int Statistique::get_attaque();
        void Statistique::Afficher();
        void Statistique::set_defense(int defense);
        void Statistique::set_attaque(int attaque);
        void Statistique::set_hp(int hp);
        
};