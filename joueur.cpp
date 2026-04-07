#include "joueur.h"

Joueur::Joueur(string nom,Item* items,int nb_items):Statistique( hp,  attaque, defense)
{
    this->nom=nom;
    this->nb_items=nb_items;
    this->items=new Item[nb_items];
    for(int i=0;i<nb_items;i++)
    {
        this->items[i]=items[i];
    }
}

string Joueur::get_nom()
{
    return this->nom;
}
Item* Joueur::get_items() 
{
    return this->items;
}
int Joueur::get_nb_items()
{
    return this->nb_items;
}
 void Joueur::set_nb_items(int nb_item)
 {
    this->nb_items=nb_item;
 }
 void Joueur::set_items(Item* items)
 {
    for(int i=0;i<nb_items;i++)
    {
        this->items[i]=items[i];
    }
}
void Joueur::Afficher()
{
    cout<<"Nom: "<<nom<<"\nItems: "<<endl;
    Statistique::Afficher();
    for(int i=0;i<nb_items;i++)
    {
        items[i].Afficher();
    }
    
}
