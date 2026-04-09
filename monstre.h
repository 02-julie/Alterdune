#pragma once

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
#include "statistique.h"
#include "action.h"

class Monstre:public Statistique{
    private:
        int id;
        string nom;
        string type;
        string mercy;
        Action* actions;
        bool resultat_combat;
    public:
        Monstre(string nom, string type, string mercy, Action* actions, bool resultat_combat);
        Monstre();
        void afficher();
        void afficherActions();
        string getNom();
        string getType();
        string getMercy();
        Action* getActions();
        bool getResultatCombat();
        void setResultatCombat(bool resultat_combat);
        void setMercy(string mercy);
};