
#include "action.h"

Action::Action(string texte_drole, string nom, int effet_sur_mercy, string autre_effet) {
    this->texte_drole = texte_drole;
    this->nom = nom;
    this->effet_sur_mercy = effet_sur_mercy;
    this->autre_effet = autre_effet;
}

void Action::afficher() {
    cout <<nom<< " : \n" << texte_drole <<"\nEffet sur Mercy: " << effet_sur_mercy <<"\nAutre effet: " << autre_effet<<"\n" << endl;
}

string Action::getNom() {
    return nom;
}

string Action::getTexteDrole() {
    return texte_drole;
}

int Action::getEffetSurMercy() {
    return effet_sur_mercy;
}

int Action::getId() {
    return id;
}