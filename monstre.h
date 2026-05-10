#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
using  namespace std;
#include "action.h"
#include "entity.h"


class Monstre : public Entity{
    protected:
        int id;
        string nom;
        string type;
        int mercy;
        vector<Action> actions;
        int resultat_combat;
        int HP_initial;
    public:
        Monstre(string nom, string type, int mercy, int resultat_combat);
        virtual ~Monstre() = default;
        virtual void afficherActions() = 0;

        void afficher();        
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

class MonstreNormal : public Monstre {
    public:
        MonstreNormal(string nom, int mercy, int resultat_combat);
        void afficherActions() override;
};

class MonstreMiniboss : public Monstre {
    public:
        MonstreMiniboss(string nom, int mercy, int resultat_combat);
        void afficherActions() override;
};

class MonstreBoss : public Monstre {
    public:
        MonstreBoss(string nom, int mercy, int resultat_combat);
        void afficherActions() override;
};