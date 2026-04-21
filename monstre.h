#pragma once
<<<<<<< HEAD

=======
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
#include <iostream>
#include <string>
#include <memory>
#include <vector>
<<<<<<< HEAD
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <random>
using  namespace std;
#include "statistique.h"
=======
using  namespace std;
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
#include "action.h"
#include "statistique.h"

<<<<<<< HEAD
class Monstre:public Statistique{
=======

class Monstre : public Statistique{
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
    private:
        int id;
        string nom;
        string type;
        int mercy;
        vector<Action> actions;
        int resultat_combat;
    public:
<<<<<<< HEAD
        Monstre(string nom, string type, string mercy, Action* actions, bool resultat_combat);
=======
        Monstre(string nom, string type, int mercy, int resultat_combat);
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
        Monstre();
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
};