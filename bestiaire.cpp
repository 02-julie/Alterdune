#include "main.h"




Bestiaire::Bestiaire(Monstre monstres[10], int nb_tue, int nb_epargne, int nb_victoire){
    for(int i = 0; i < 10; i++){
        this->monstres[i] = monstres[i];
    }
    this->nb_tue = nb_tue;
    this->nb_epargne = nb_epargne;
    this->nb_victoire = nb_victoire;
}

void Bestiaire::afficher(){
    cout<<"Bestiaire : "<<endl;
    for(int i = 0; i < nb_victoire; i++){
        monstres[i].afficher();
    }
    cout<<"Nombre de monstres tués : "<<nb_tue<<endl;
    cout<<"Nombre de monstres épargnés : "<<nb_epargne<<endl;
    cout<<"Nombre de victoires : "<<nb_victoire<<endl;
}

int Bestiaire::getNbTue(){
    return nb_tue;
}

int Bestiaire::getNbEpargne(){
    return nb_epargne;
}

int Bestiaire::getNbVictoire(){
    return nb_victoire;
}

void Bestiaire::ajouterMonstre(Monstre monstre){
    monstres[nb_victoire] = monstre;
    nb_victoire++;
    if(monstre.getResultatCombat()){
        nb_tue++;
    }
    else{
        nb_epargne++;
    }
    nb_victoire++;
}
