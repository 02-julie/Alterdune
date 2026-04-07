#include <iostream>
#include <string>
#include <memory>
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
        Item::Item(int id,string nom,string descriptif,double effet, int quantite);
        Item::Item();
        int Item::get_id() ;
        string Item::get_nom();
        string Item::get_descriptif();
        double Item::get_effet();
        int Item::get_quantite();
        void Item::set_id(int quantite);
        void Item::Afficher();

};