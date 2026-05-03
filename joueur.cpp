#include "joueur.h"
#include <fstream>
#include <sstream>

Joueur::Joueur(string nom):Entity( hp=100,  attaque=20, defense=10)
{
    this->nom=nom;
    this->nb_items=5;
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
        double effet=0.0;
        int quantite=0;
        getline(ss,nom,',');
        getline(ss,descriptif,',');
        getline(ss,streffet,',');
        getline(ss,strquantite,',');
        try
        {
            effet=stod(streffet);
            quantite=stoi(strquantite);
            Item it(compteur, nom, descriptif, effet, quantite);
        
        
            if (compteur < this->nb_items) {
                items[compteur] = it;
                compteur++;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        
        
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
    cout<<"nom : "<<nom<<endl;
    Entity::Afficher();
    
    
}
void Joueur::AfficherInventaire()
{
    cout<<"Le hero "<<nom<<" possede : "<<endl;
    for(int i=0;i<nb_items;i++)
    {
        cout<<"\nItem "<<i+1<<": "<<endl;
        items[i].Afficher();
    }
    
}
