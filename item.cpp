<<<<<<< HEAD
#include "main.h"
=======
#include "item.h"
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf

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
    cout<<"nom: "<<nom<<"\nDescriptif: "<<descriptif<<"\nEffet : "<<effet<<"\nQuantite: "<<quantite<<endl;
}


