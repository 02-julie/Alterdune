#include "monstre.h"

Monstre::Monstre(string nom, string type, string mercy, Action actions[], bool resultat_combat){
    this->nom = nom;
    this->type = type;
    this->mercy = mercy;
    this->actions = actions;
    this->resultat_combat = resultat_combat;
}

void Monstre::afficher(){
    cout<<nom<<" : \nType : "<<type<<"\nMercy : "<<mercy<<"\n"<<endl;
    if(resultat_combat){
        cout<<"L'ennemie a été tué !!"<<endl;
    }
    else{
        cout<<"L'ennemie a été épargné "<<endl;
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

