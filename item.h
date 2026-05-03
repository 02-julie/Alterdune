#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <iomanip>
using  namespace std;
class Item
{
    private:
        int id;
        string nom;
        string descriptif;
        double effet;
        int quantite;
  
    public:
        Item(int id=0,string nom="",string descriptif="",double effet=0.0, int quantite=0);
        int get_id() ;
        string get_nom();
        string get_descriptif();
        double get_effet();
        int get_quantite();
        void set_quantite(int quantite);
        
        void Afficher();

};