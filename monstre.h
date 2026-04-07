#include "main.h"
#include "action.h"
#include "statistique.h"

class Monstre:public Statistique{
    private:
        int id;
        string nom;
        string type;
        string mercy;
        Action* actions;
        bool resultat_combat;
    public:
        Monstre(string nom = "", string type = "", string mercy = "", Action* actions = nullptr, bool resultat_combat = false);
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