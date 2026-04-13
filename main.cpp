#include "action.h"
#include "item.h"
#include "joueur.h"
#include "monstre.h"
#include "statistique.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <random>

vector<Monstre> CreationMonstres(vector<Action> vectActions){
    vector<Monstre> monstres;
    int compteur=0;
    ifstream fichier("monstres.csv");
    if (!fichier.is_open()) {
        throw runtime_error("Erreur : impossible d'ouvrir le fichier ");
    }
    string ligne;
    while(getline(fichier,ligne))
    {
        stringstream ss(ligne);
        string nom, type, mercy_str, hp_str, attaque_str, defense_str;

        getline(ss, type, ',');
        getline(ss, nom, ',');        
        getline(ss, hp_str, ',');
        getline(ss, attaque_str, ',');
        getline(ss, defense_str, ',');
        getline(ss, mercy_str, ',');

        int nbActions = 0;
        vector<string> acts;
        if(type=="NORMAL"){
            nbActions = 2;
            string act1, act2;
            getline(ss, act1, ',');
            getline(ss, act2, ',');
            acts.push_back(act1);
            acts.push_back(act2);
        }
        else if(type=="MINIBOSS"){
            nbActions = 3;
            string act1, act2, act3;
            getline(ss, act1, ',');
            getline(ss, act2, ',');
            getline(ss, act3, ',');            
            acts.push_back(act1);            
            acts.push_back(act2);
            acts.push_back(act3);
        }
        else{
            nbActions = 4;
            string act1, act2, act3, act4;
            getline(ss, act1, ',');
            getline(ss, act2, ',');
            getline(ss, act3, ','); 
            getline(ss, act4, ',');           
            acts.push_back(act1);            
            acts.push_back(act2);            
            acts.push_back(act3);
            acts.push_back(act4);
        }        

        Monstre m(nom, type, 0, 0);
        for(int i = 0; i<nbActions; i++){
            for(int j = 0; j<vectActions.size(); j++){
                if(vectActions[j].getNom()==acts[i]){
                    m.setActions(vectActions[j]);
                }
            }
        } 

        try
        {
            m.set_hp(stoi(hp_str));
            m.set_hp(stoi(mercy_str));
            m.set_attaque(stoi(attaque_str));
            m.set_defense(stoi(defense_str));
        }

        catch(const exception& e)
        {
            std::cerr << e.what() << '\n';
        }   
        

        monstres.push_back(m);
    }

    return monstres;
}

void AfficherMenu(Joueur joueur, Monstre monstre)
{
    cout <<"\033[4m"<<joueur.get_nom() << " VS " << monstre.getNom()<<"\033[0m"<<endl;
                cout<<"HP "<<joueur.get_nom()<<": ";
                for(int i = 0; i<joueur.get_hp(); i++){
                    cout<<"-";
                }
                cout << endl;
                cout<<"HP "<<monstre.getNom()<<": ";
                for(int i = 0; i<monstre.get_hp(); i++){
                    cout<<"-";
                }
                cout << endl;
                cout<<"Mercy "<<monstre.getNom()<<": "<<monstre.getMercy()<<endl;
    cout<<"Choisir l'action: "<<endl;
    cout<<"\033[1mFIGHT          ACT          ITEM          MERCY\033[0m"<<endl;
    cout<<"(1)           (2)           (3)          (4)"<<endl;   
    cout <<"\n" <<endl;
}

int Degats(const Statistique& entite)
{
    int hp=entite.get_hp();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(0, hp);
    int degat = distrib(gen);
    return degat;
}

void Victoire(Joueur j, Monstre m)
{
    if(m.get_hp()<=0)
    {
        cout<<"Vous avez battu le monstre!"<<endl;
        m.setResultatCombat(-1);
    }
}

void Epargne(Joueur j, Monstre m)
{
    cout<<"Vous avez epargné le monstre!"<<endl;
    m.setResultatCombat(1);
}

void Defaite(Joueur j, Monstre m)
{
    if(j.get_hp()<=0)
    {
        cout<<"Vous avez perdu"<<endl;
        
    }
}

void Effet_action(int i,Monstre m)
{
    m.setMercy(m.getMercy()-m.getActions()[i].getEffetSurMercy());
    cout<<"Vous avez enlevé "<<m.getActions()[i].getEffetSurMercy()<<" points de Mercy au monstre"<<endl;
}

void Choix_item(int i, Joueur j, Monstre m)
{
    
    while(j.get_items()[i].get_quantite()==0)
    {
        cout<<"Vous ne pouvez pas utilser cet item, car sa quantite est nulle"<<endl;
        cout<<"Choisissez un autre item: ";
        cin>>i;
        i=i-1;
    }
    
    cout<<"Vous avez choisi l'item: "<<j.get_items()[i].get_nom();
    if(j.get_items()[i].get_descriptif()=="HEAL")
    {
        j.set_hp(j.get_hp()+j.get_items()[i].get_effet());
    }
    else if(j.get_items()[i].get_descriptif()=="ATK")
    {
        m.set_hp(m.get_attaque()-j.get_items()[i].get_effet());
    }
    else if(j.get_items()[i].get_descriptif()=="DEF")
    {
        m.set_hp(m.get_defense()+j.get_items()[i].get_effet());
    }
    j.get_items()[i].set_quantite(j.get_items()[i].get_quantite()-1);
    
    
    
}

void Combat(Joueur j, Monstre m)
{
    while(j.get_hp()!=0 || m.get_hp()!=0||m.getMercy()!=0)
    {
        AfficherMenu(j,m);
        int action;
        cin>>action;
        while(action!=1||action!=2||action!=3||action!=4)
        {
            cout<<"donner un entier entre 1 et 4";
            cin>>action;
        }
        switch(action)
        {
            case 1:
                m.set_hp(m.get_hp()-Degats(m));
                break;
                
            case 2:
                cout<<"Choisir une action: "<<endl;
                m.afficherActions();
                int action;
                cin>>action;
                Effet_action(action-1,m);
                break;
            case 3:
                j.AfficherInventaire();
                int item_choisi;
                cin>>item_choisi;
                Choix_item(item_choisi-1,j,m);
                break;
            case 4:
                cout<<"Vous avez épargné le monstre"<<endl;
                m.setMercy(100);
                break;
        }
        if(m.get_hp()!=0)
        {
            j.set_hp(j.get_hp()-Degats(j));
        }

    }
    Victoire(j,m);
    Defaite(j,m);
    Epargne(j,m);
}


int main(){
    
    Action a1("ilicco est content","caresse",20,"");
    Action a2("Bravo Tu as trouvé son point faible ","snack",20,"");
    Action a3("@&#$!","insulte",20,"");
    Action a4("Fayot!","compliment",20,"");
    Action a5("Mario est en colère attention!","peach",20,"");
    Action a6("Un peu de redbull pour te revigorer!","powerup",20,"");
    Action a7("Trop fort!","exoResolu",20,"");
    Action a8("20/20!","bonneNote",20,"");
    Action a9("Merci ChatGPT","triche",20,"");
    vector<Action> actions= {a1,a2,a3,a4,a5,a6,a7,a8,a9};

    vector<Monstre> monstres = CreationMonstres(actions);

    monstres[0].afficher();
    monstres[0].afficherActions();

    cout << "Entrer le nom du joueur: ";
    string nom;
    cin >> nom;
    Joueur j(nom); 
    j.Afficher();
                

    int a=-1;
    while(a!=0)
    {

        cout<<"Menu : \ntaper 1 pour creer un joueur et afficher ses stats et ses items\ntaper 2 pour combattre un monstre\ntaper 3 pour afficher les actions\ntaper 4 pour un exemple d'affichage de combats\ntaper 0 pour sortir\n>";
        cin>>a;
        
        switch (a) {
            case 1: { 
                cout << "Entrer le nom du joueur: ";
                string nom;
                cin >> nom;
                Joueur j(nom); 
                j.Afficher();
                break;
            } 


            case 2: {
                Monstre monstre; 
                Combat(j,monstre);
                break;
            }
            case 3: {
                cout << "Actions disponibles : \n" << endl;
                for(int i = 0 ; i<9; i++){
                    actions[i].afficher();
                }
                break;
            }
            case 4: {
                Monstre monstre;
                Joueur joueur("Heros");
                cout <<"\033[4m"<<joueur.get_nom() << " VS " << monstre.getNom()<<"\033[0m"<<endl;
                cout<<"HP "<<joueur.get_nom()<<": ";
                for(int i = 0; i<joueur.get_hp(); i++){
                    cout<<"-";
                }
                cout << endl;
                cout<<"HP "<<monstre.getNom()<<": ";
                for(int i = 0; i<monstre.get_hp(); i++){
                    cout<<"-";
                }
                cout << endl;
                cout<<"Mercy "<<monstre.getNom()<<": "<<monstre.getMercy()<<endl;
                cout<<"\033[1mFIGHT          ACT          ITEM          MERCY\033[0m"<<endl;
                cout<<"(1)           (2)           (3)          (4)"<<endl;   
                cout <<"\n" <<endl;
                break;
            }
            case 0:
                cout<<"sortie du jeu";
                break;

            default:
                break;
        }
    }     
        
        return 0;
};