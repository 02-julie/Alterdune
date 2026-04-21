#pragma once
<<<<<<< HEAD

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <random>
=======
#include <iostream>
#include <string>
#include <memory>
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
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
        void afficher();
        string getNom();
        string getTexteDrole() ;
        int getEffetSurMercy() ;
        int getId() ;
};