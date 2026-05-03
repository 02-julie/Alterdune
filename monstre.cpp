#include "monstre.h"
#include <fstream>
#include <sstream>
#include <random>

Monstre::Monstre(string nom, string type, int mercy, int resultat_combat){
    this->nom = nom;
    this->type = type;
    this->mercy = mercy;
    this->resultat_combat = resultat_combat;
}

void Monstre::afficher(){
    cout<<"\033[4m"<<nom<<"\033[0m : \nType : "<<type<<"\nMercy : "<<mercy<<"\n"<<"Stats : "<<endl;
    cout<<"attaque : ";
    cout<<Entity::get_attaque();
    cout<<"\ndefense : ";
    cout<<Entity::get_defense();
    cout<<"\nHP : "<<getHP_initial()<<endl;
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

int Monstre::getHP_initial(){
    return HP_initial;
}

void Monstre::setHP_initial(int hp){
    this->HP_initial = hp;
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

