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
        int mercy;
        vector<Action> actions;
        int resultat_combat;
    public:
        Monstre(string nom, string type, int mercy, int resultat_combat);
        Monstre();
        void afficher();
        void afficherActions();
        string getNom();
        string getType();
        int getMercy();
        vector <Action> getActions();
        int getResultatCombat();
        void setResultatCombat(int resultat_combat);
        void setMercy(int mercy);
        void setActions(Action act);
};