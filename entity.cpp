#include "entity.h"

Entity::Entity(int hp, int attaque,int defense)
{
this->hp=hp;
this->attaque=attaque;
this->defense=defense;
}
int Entity::get_hp()const
{
    return hp;
}
int Entity::get_attaque()
{
    return  attaque;
}
int Entity::get_defense()
{
    return  defense;
}
void Entity::set_hp(int hp)
{
    this->hp=hp;
}
void Entity::set_attaque(int attaque)
{
    this->attaque=attaque;
}
void Entity::set_defense(int defense)
{
    this->defense=defense;
}
void Entity::Afficher()
{
    cout<<"HP: "<<hp<<"\nAttaque: "<<attaque<<"\nDefense: "<<defense<<endl;
}
