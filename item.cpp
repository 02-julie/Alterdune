#include "item.h"
Item::Item(int id,string nom,string descriptif,string effet, int quantite)
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
string Item::get_effet()
{
    return this->effet;
}
int Item::get_quantite()
{
    return this->quantite;
}

void Item::set_id(int quantite)
{
    this->quantite=quantite;
}

void Item::Afficher()
{
    cout<<"nom: "<<nom<<"\nDescriptif: "<<descriptif<<"\nEffet : "<<effet<<"\nQuantité: "<<quantite;
}


