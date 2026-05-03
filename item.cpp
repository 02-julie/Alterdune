#include "item.h"

Item::Item(int id,string nom,string descriptif,double effet, int quantite)
{
    this->id=id;
    this->nom=nom;
    this->descriptif=descriptif;
    this->effet=effet;
    this->quantite=quantite;
}
int Item::get_id()
{
    return this->id;
}
string Item::get_nom()
{
    return this->nom;
}
string Item::get_descriptif()
{
    return this->descriptif;
}
double Item::get_effet()
{
    return this->effet;
}
int Item::get_quantite()
{
    return this->quantite;
}

void Item::set_quantite(int quantite)
{
    this->quantite=quantite;
}

void Item::Afficher()
{
    cout << left << setw(15) << nom 
         << left << setw(15) << descriptif 
         << left << setw(10) << effet 
         << left << setw(10) << quantite << endl;
}


