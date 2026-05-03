#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using  namespace std;
#include "action.h"
#include "entity.h"


class Monstre : public Entity{
    private:
        int id;
        string nom;
        string type;
        int mercy;
        vector<Action> actions;
        int resultat_combat;
        int HP_initial;
    public:
        Monstre(string nom, string type, int mercy, int resultat_combat);
        void afficher();
        void afficherActions();
        string getNom();
        string getType();
        int getMercy();
        vector <Action> getActions();
        int getResultatCombat()const;
        void setResultatCombat(int resultat_combat);
        void setMercy(int mercy);
        void setActions(Action act);
        int getHP_initial();
        void setHP_initial(int hp);
};