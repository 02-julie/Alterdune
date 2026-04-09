#include "monstre.h"
#include <fstream>
#include <sstream>
#include <random>

Monstre::Monstre(string nom, string type, string mercy, Action actions[], bool resultat_combat){
    this->nom = nom;
    this->type = type;
    this->mercy = mercy;
    this->actions = actions;
    this->resultat_combat = resultat_combat;
}

void Monstre::afficher(){
    cout<<nom<<" : \nType : "<<type<<"\nMercy : "<<mercy<<"\n"<<"Stats : "<<endl;
    Statistique::Afficher();
}

Monstre::Monstre(): Statistique(){
    try {
        ifstream fichier("monstres.csv");
        if(!fichier.is_open()){
            throw runtime_error("Erreur : impossible d'ouvrir le fichier");
        }

        int nombreDeLignes = 0;
        string ligneTemp;
        
        while (getline(fichier, ligneTemp)) {
            if (!ligneTemp.empty()) {
                nombreDeLignes++;
            }
        }

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, nombreDeLignes);

        int ligneCible = distrib(gen);
        fichier.clear();
        fichier.seekg(0);

        string ligneChoisie;
        int ligneActuelle = 0;

        while (getline(fichier, ligneTemp)) {
            if (!ligneTemp.empty()) {
                ligneActuelle++;
                if (ligneActuelle == ligneCible) {
                    ligneChoisie = ligneTemp; 
                    break;
                }
            }
        }
        fichier.close();

        stringstream ss(ligneChoisie);
        string nom, type, mercy, hp_str, attaque_str, defense_str;

        getline(ss, type, ',');
        getline(ss, nom, ',');
        getline(ss, mercy, ',');
        getline(ss, hp_str, ',');
        getline(ss, attaque_str, ',');
        getline(ss, defense_str, ',');
        
        try {
            Statistique::set_hp(stoi(hp_str));
            Statistique::set_attaque(stoi(attaque_str));
            Statistique::set_defense(stoi(defense_str));
        }
        catch (const exception& e) {
            throw invalid_argument("Erreur de conversion sur le monstre : " + nom);
        }

        this->nom = nom;
        this->type = type;
        this->mercy = mercy;
    }
    catch(const exception& e){
        cerr << e.what() << endl;
    }
}

string Monstre::getNom(){
    return nom;
}

string Monstre::getType(){
    return type;
}

string Monstre::getMercy(){
    return mercy;
}

Action* Monstre::getActions(){
    return actions;
}

bool Monstre::getResultatCombat(){
    return resultat_combat;
}

void Monstre::setResultatCombat(bool resultat_combat){
    this->resultat_combat = resultat_combat;
}

void Monstre::setMercy(string mercy){
    this->mercy = mercy;
}

void Monstre::afficherActions(){
    cout<<"Actions : "<<endl;
    int n = 0;
    if(type == "BOSS"){
        n = 4;
    }
    else if(type == "MINIBOSS"){
        n = 3;
    }
    else if(type == "NORMAL"){
        n = 2;
    }
    for(int i = 0; i < n; i++){
        actions[i].afficher();
    }
}

