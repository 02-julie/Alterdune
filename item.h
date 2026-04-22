#pragma once
<<<<<<< HEAD

=======
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <random>
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
<<<<<<< HEAD
        void set_id(int quantite);
=======
        void set_quantite(int quantite);
        
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
        void Afficher();

};