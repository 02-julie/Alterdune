#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using  namespace std;
#include "action.h"
#include "statistique.h"


class Monstre : public Statistique{
    private:
        int id;
        string nom;
        string type;
        string mercy;
        vector<Action> actions;
        bool resultat_combat;
    public:
        Monstre(string nom, string type, string mercy, bool resultat_combat);
        Monstre();
        void afficher();
        void afficherActions();
        string getNom();
        string getType();
        string getMercy();
        vector <Action> getActions();
        bool getResultatCombat();
        void setResultatCombat(bool resultat_combat);
        void setMercy(string mercy);
        void setActions(Action act);
};