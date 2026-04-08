#include "joueur.h"
#include <fstream>
#include <sstream>

Joueur::Joueur(string nom,Item* items,int nb_items):Statistique( hp,  attaque, defense)
{
    this->nom=nom;
    this->nb_items=nb_items;
    this->items=new Item[nb_items];
    int compteur=0;
    ifstream fichier("items.csv");
    if (!fichier.is_open()) {
        throw std::runtime_error("Erreur : impossible d'ouvrir le fichier ");
    }
    string ligne;
    while(getline(fichier,ligne))
    {
        stringstream ss(ligne);
        string nom;
        string descriptif;
        string streffet; 
        string strquantite;
        double effet;int quantite;
        getline(ss,nom,',');
        getline(ss,descriptif,',');
        getline(ss,streffet,',');
        getline(ss,strquantite,',');
        try
        {
            double  effet=stod(streffet);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            int quantite=stoi(strquantite);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        Item it=Item::Item(compteur,nom,descriptif,effet,quantite);
        items[compteur]=it;
        compteur++;


        
        


    }

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
