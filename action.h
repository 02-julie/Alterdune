#pragma once
#include <iostream>
#include <string>
#include <memory>
using  namespace std;

class Action {
    private:
        int id;
        string nom;
        string texte_drole;
        int effet_sur_mercy;
        string autre_effet;
    public:
        Action(string texte_drole = "", string nom = "",int effet_sur_mercy = 0, string autre_effet = "");
        Action();
        void afficher();
        string getNom();
        string getTexteDrole() ;
        int getEffetSurMercy() ;
        int getId() ;
};