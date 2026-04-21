<<<<<<< HEAD
#include "main.h"

Monstre::Monstre(string nom, string type, string mercy, Action actions[], bool resultat_combat):Statistique( hp,  attaque, defense){
=======
#include "monstre.h"
#include <fstream>
#include <sstream>
#include <random>

Monstre::Monstre(string nom, string type, int mercy, int resultat_combat){
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
    this->nom = nom;
    this->type = type;
    this->mercy = mercy;
    this->resultat_combat = resultat_combat;
}

<<<<<<< HEAD
=======

>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
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
<<<<<<< HEAD
        string nom, type, mercy, hp_str, attaque_str, defense_str;

        getline(ss, type, ',');
        getline(ss, nom, ',');
        getline(ss, mercy, ',');
        getline(ss, hp_str, ',');
        getline(ss, attaque_str, ',');
        getline(ss, defense_str, ',');
        
        try {
=======
        string nom, type, mercy_str, hp_str, attaque_str, defense_str;

        getline(ss, type, ',');
        getline(ss, nom, ',');        
        getline(ss, hp_str, ',');
        getline(ss, attaque_str, ',');
        getline(ss, defense_str, ',');
        getline(ss, mercy_str, ',');
        
        try {
            Statistique::set_hp(stoi(mercy_str));
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
            Statistique::set_hp(stoi(hp_str));
            Statistique::set_attaque(stoi(attaque_str));
            Statistique::set_defense(stoi(defense_str));
        }
        catch (const exception& e) {
            throw invalid_argument("Erreur de conversion sur le monstre : " + nom);
        }

        this->nom = nom;
        this->type = type;
<<<<<<< HEAD
        this->mercy = mercy;
=======
       
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
    }
    catch(const exception& e){
        cerr << e.what() << endl;
    }
}

void Monstre::afficher(){
<<<<<<< HEAD
    cout<<nom<<" : \nType : "<<type<<"\nMercy : "<<mercy<<"\n"<<endl;
    if(resultat_combat){
        cout<<"L'ennemie a ete tue !!"<<endl;
    }
    else{
        cout<<"L'ennemie a ete epargne "<<endl;
    }
=======
    cout<<"\033[4m"<<nom<<"\033[0m : \nType : "<<type<<"\nMercy : "<<mercy<<"\n"<<"Stats : "<<endl;
    Statistique::Afficher();
>>>>>>> 7b0cce95b1679a61b934e03fdbdd43f32f198aaf
}

string Monstre::getNom(){
    return nom;
}

string Monstre::getType(){
    return type;
}

int Monstre::getMercy(){
    return mercy;
}

vector<Action> Monstre::getActions(){
    return actions;
}

int Monstre::getResultatCombat()const{
    return resultat_combat;
}

void Monstre::setResultatCombat(int resultat_combat){
    this->resultat_combat = resultat_combat;
}

void Monstre::setMercy(int mercy){
    this->mercy = mercy;
}

void Monstre::setActions(Action act){
    actions.push_back(act);
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
        cout<<i+1<<")\n";
        actions[i].afficher();
    }
}

