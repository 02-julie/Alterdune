#include "action.h"
#include "item.h"
#include "joueur.h"
#include "monstre.h"
#include "statistique.h"
#include <vector>
#include <fstream>
#include <sstream>

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
        string nom, type, mercy, hp_str, attaque_str, defense_str;

        getline(ss, type, ',');
        getline(ss, nom, ',');        
        getline(ss, hp_str, ',');
        getline(ss, attaque_str, ',');
        getline(ss, defense_str, ',');
        getline(ss, mercy, ',');

        int nbActions = 0;
        vector<string> acts;
        if(type=="NORMAL"){
            nbActions = 1;
            string act1;
            getline(ss, act1, ',');
            acts.push_back(act1);
        }
        else if(type=="MINIBOSS"){
            nbActions = 2;
            string act1, act2;
            getline(ss, act1, ',');
            getline(ss, act2, ',');            
            acts.push_back(act1);            
            acts.push_back(act2);
        }
        else{
            nbActions = 3;
            string act1, act2, act3;
            getline(ss, act1, ',');
            getline(ss, act2, ',');
            getline(ss, act3, ',');            
            acts.push_back(act1);            
            acts.push_back(act2);            
            acts.push_back(act3);
        }        

        Monstre m(nom, type, mercy, false);
        Action* actions = new Action[nbActions];
        m.setActions(actions);
        for(int i = 0; i<nbActions; i++){
            for(int j = 0; j<vectActions.size(); j++){
                if(vectActions[j].getNom()==acts[i]){
                    m.setActions(i, vectActions[j]);
                }
            }
        }

        try
        {
            m.set_hp(stoi(hp_str));
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


int main(){
    
    Action a1("ilicco est content","caresse",20,"");
    Action a2("Bravo!Tu as trouvé son point faible!","snack",20,"");
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

    int a=-1;
    while(a!=0)
    {

        cout<<"Menu : \ntaper 1 pour creer un joueur et afficher ses stats et ses items\ntaper 2 pour creer un monstre et l'afficher\ntaper 3 pour afficher les actions\ntaper 4 pour un exemple d'affichage de combats\ntaper 0 pour sortir\n>";
        cin>>a;
        Joueur* j = nullptr; 
        switch (a) {
            case 1: { 
                cout << "Entrer le nom du joueur: ";
                string nom;
                cin >> nom;
                j = new Joueur(nom); 
                j->Afficher();
                break;
            } 


            case 2: {
                Monstre monstre; 
                monstre.afficher();
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