#include "main.h"

Statistique::Statistique(int hp, int attaque,int defense)
{
this->hp=hp;
this->attaque=attaque;
this->defense=defense;
}
<<<<<<< HEAD

int Statistique::get_hp()
=======
int Statistique::get_hp()const
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
{
    return hp;
}
int Statistique::get_attaque()
{
    return  attaque;
}
int Statistique::get_defense()
{
    return  defense;
}
void Statistique::set_hp(int hp)
{
    this->hp=hp;
}
void Statistique::set_attaque(int attaque)
{
    this->attaque=attaque;
}
void Statistique::set_defense(int defense)
{
    this->defense=defense;
}
void Statistique::Afficher()
{
    cout<<"HP: "<<hp<<"\nAttaque: "<<attaque<<"\nDefense: "<<defense<<endl;
}
