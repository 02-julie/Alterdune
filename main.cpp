#include "action.h"
#include "item.h"
#include "joueur.h"
#include "monstre.h"
#include "entity.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <random>


vector<Monstre*> CreationMonstres(vector<Action> vectActions){
    vector<Monstre*> monstres;
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
        
        Monstre* m = nullptr;

        if(type=="NORMAL"){
            nbActions = 2;
            string act1, act2;
            getline(ss, act1, ',');
            getline(ss, act2, ',');
            acts.push_back(act1);
            acts.push_back(act2);
            m = new MonstreNormal(nom, 0, 0); 
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
            m = new MonstreMiniboss(nom, 0, 0);
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
            m = new MonstreBoss(nom, 0, 0);
        }        

        for(int i = 0; i<nbActions; i++){
            for(int j = 0; j<vectActions.size(); j++){
                if(vectActions[j].getNom()==acts[i]){
                    m->setActions(vectActions[j]);
                }
            }
        } 

        try
        {
            m->set_hp(stoi(hp_str));
            m->setHP_initial(stoi(hp_str));
            m->setMercy(stoi(mercy_str));
            m->set_attaque(stoi(attaque_str));
            m->set_defense(stoi(defense_str));
        }
        catch(const exception& e)
        {
            std::cerr << e.what() << '\n';
        }   
        
        monstres.push_back(m);
    }

    return monstres;
}

void AfficherMenu(Joueur& joueur, Monstre& monstre)
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
    cout <<">";
}

int Degats(const Entity& entite)
{
    int hp=entite.get_hp();
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> distrib(0, hp);
    int degat = distrib(gen);
    return degat;
}

void Victoire(Joueur& j, Monstre& m)
{
    if(m.get_hp()<=0)
    {
        cout<<"Vous avez battu le monstre!"<<endl;
        m.setResultatCombat(-1);
    }
}

void Epargne(Joueur& j, Monstre& m)
{
    if(m.getMercy()>=100)
    {
        cout<<"Vous avez epargne le monstre!"<<endl;
        m.setResultatCombat(1);
    }
    
}

bool Defaite(Joueur& j, Monstre& m)
{
    if(j.get_hp()<=0)
    {
        
        return true;
    }
    return false;
}

void Effet_action(int i,Monstre& m)
{
    m.setMercy(m.getMercy()+m.getActions()[i].getEffetSurMercy());
    if(m.getMercy()>100)
    {
        m.setMercy(100);
    }
    else if (m.getMercy()<0){
        m.setMercy(0);
    }
    cout<<"Vous avez ajoute "<<m.getActions()[i].getEffetSurMercy()<<" points de Mercy au monstre"<<endl;
    cout<<"Le monstre a maintenant: "<<m.getMercy()<<" points de mercy"<<endl;
}

void Choix_item(int i, Joueur& j, Monstre& m)
{
    
    while(j.get_items()[i].get_quantite()==0)
    {
        cout<<"Vous ne pouvez pas utilser cet item, car sa quantite est nulle"<<endl;
        cout<<"Choisissez un autre item: ";
        cin>>i;
        i=i-1;
    }
    
    cout<<"Vous avez choisi l'item: "<<j.get_items()[i].get_nom()<<endl;
    if(j.get_items()[i].get_descriptif()=="HEAL")
    {
        j.set_hp(j.get_hp()+j.get_items()[i].get_effet());
    }
    else if(j.get_items()[i].get_descriptif()=="ATK")
    {
        j.set_attaque(j.get_attaque()+j.get_items()[i].get_effet());
    }
    else if(j.get_items()[i].get_descriptif()=="DEF")
    {
        j.set_defense(j.get_defense()+j.get_items()[i].get_effet());
    }
    j.get_items()[i].set_quantite(j.get_items()[i].get_quantite()-1);
    
    
    
}


bool Combat(Joueur& j, Monstre& m)
{
    bool epargne=true;
    int item_choisi;
    int act;
    int degats_finaux;
    while(j.get_hp()>0 && m.get_hp()>0 && epargne)
    {
        AfficherMenu(j,m);
        int action;
        cin>>action;
        while(action!=1&&action!=2&&action!=3&&action!=4)
        {
            cout<<"donner un entier entre 1 et 4";
            cin>>action;
        }
        switch(action)
        {
            case 1:
                //cout<<"Statistiques du monstres: \n ATTAQUE: "<<m.get_attaque()<<"\n DEFENSE: "<<m.get_defense()<<endl;
                degats_finaux=Degats(m)+j.get_attaque()-m.get_defense();
                if (degats_finaux < 0) degats_finaux = 0;
                cout<<"Vous enlevez "<<degats_finaux<<" au monstre!"<<endl;
                m.set_hp(m.get_hp()-degats_finaux);
                break;
                
            case 2:
            {
                cout<<"Choisir une action: "<<endl;
                m.afficherActions();
                cout<<"taper 0 pour revenir en arriere"<<endl;
                cin>>act;
                while(act<0 ||act>9)
                {
                    cout<<"Veuillez donner un nombre entre 0 et 9"<<endl;
                    cin>>act;
                }
                if(act!=0)
                {
                    Effet_action(act-1,m);
                }
                
                break;
            }
            case 3:
            {
        
                j.AfficherInventaire();
                cout<<"taper 0 pour revenir en arriere"<<endl;
                cout<<">";
                cin>>item_choisi;
                while(item_choisi<1||item_choisi>5)
                {
                    cout<<"Veuillez donner un nombre entre 1 et 5"<<endl;
                    cin>>item_choisi;
                }
                if(item_choisi!=0)
                {
                    Choix_item(item_choisi-1,j,m);
                }
                
            
                break;
            }
            
            case 4:
            {
                if(m.getMercy()>=100)
                {
                    Epargne(j,m);
                    epargne=false;
                    
                }
                else 
                {
                    cout << "Le monstre ne veut pas encore vous laisser partir..." << endl;
                }
                break;
            }
            
                
        }
        if (action == 2 && act == 0) continue; 
        if (action == 3 && item_choisi == 0) continue;
        if (action == 4 && m.getMercy() < 100) continue;
        if(epargne && m.get_hp() > 0)
        {
            //if(m.get_hp()!=0)
            
            degats_finaux=Degats(j)+m.get_attaque()-j.get_defense();
            if (degats_finaux < 0) degats_finaux = 0;
            j.set_hp(j.get_hp()-degats_finaux);
            cout<<m.getNom()<<" vous enleve "<<degats_finaux<<" HP!"<<endl;
            
        }
        item_choisi=1;
        act=1;
        

    }
    Victoire(j,m);
    Defaite(j,m);
    return j.get_hp() <= 0;
}

void AfficherIntro() {
    cout << "BIENVENUE DANS" << endl;
    cout << "=======================================" << endl;
    cout << "  / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ " << endl;
    cout << " ( A | L | T | E | R | D | U | N | E )" << endl;
    cout << "  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ " << endl;
    cout << "=======================================" << endl;    
    
    cout << "Un jeu ou chaque choix est crucial.\n" << endl;

    cout << "--- REGLES RAPIDES ---" << endl;
    cout << "1. COMBAT : Attaquez pour reduire les HP de l'ennemi a 0." << endl;
    cout << "2. ACT    : Augmenter la MERCY du monstre." << endl;
    cout << "3. MERCY  : A 100 points, vous pouvez EPARGNER le monstre ." << endl;
    cout << "4. ITEM   : Utilisez des objets pour vous soigner ou booster vos stats." << endl;
    cout << "5. FINS   : Vos actions menent a une fin Pacifiste, Neutre ou Genocidaire." << endl;
    
    cout << "\nBonne chance, l'humanite compte sur vous." << endl;
    cout << "=======================================" << endl;
}


int main(){
    
    Action a1("le monstre est content","caresse",20,"");
    Action a2("Bravo Tu as trouve son point faible ","snack",40,"");
    Action a3("@&#$!","insulte",-40,"");
    Action a4("Fayot!","compliment",20,"");
    Action a5("Mario est en colere attention!","peach",20,"");
    Action a6("Un peu de redbull pour te revigorer!","powerup",20,"");
    Action a7("Trop fort!","exoResolu",20,"");
    Action a8("20/20!","bonneNote",20,"");
    Action a9("Merci ChatGPT","triche",-20,"");
    
    vector<Action> actions= {a1,a2,a3,a4,a5,a6,a7,a8,a9};

    vector<Monstre*> monstres = CreationMonstres(actions);
    AfficherIntro();
    
    cout << "Entrer votre nom > ";
    string nom;
    cin >> nom;
    Joueur j(nom); 
    j.Afficher();
    j.AfficherInventaire();
    int a=-1;
    bool perdu=false;
    while(a!=0)
    {
        
        int nbVictoires = 0;
        for (const auto& m : monstres) {
            if (m->getResultatCombat() == -1) { 
                nbVictoires++;
            }
        } 
        int nbEpargne = 0;
        for (const auto& m : monstres) {
            if (m->getResultatCombat() == 1) { 
                nbEpargne++;
            }
        }
        while((a!=0 && !perdu)||(a!=0 && nbVictoires!=monstres.size())||(a!=0 && nbEpargne!=monstres.size())||(a!=0  && nbEpargne+nbVictoires!=monstres.size()))
        {
            cout<<"======================================="<<endl;
            cout<<"Menu : \ntaper 1 pour afficher tes stats \ntaper 2 pour afficher ton inventaire\ntaper 3 pour demarrer le combat contre un monstre\ntaper 4 pour afficher le bestiaire\ntaper 0 pour sortir\n>";
            cin>>a;
            switch (a) {
                case 1: {  
                    j.Afficher();
                    cout<<"Nombre de monstres tues: "<<nbVictoires<<endl;
                    cout<<"Nombre de monstres epargnes: "<<nbEpargne<<endl;
                    cout<<"Nombre de victoire: "<<nbVictoires+nbEpargne<<endl;
                    break;
                } 

                case 2:
                {
                    j.AfficherInventaire();
                    break;
                }


                case 3: 
                {
                    random_device rd;  
                    mt19937 gen(rd()); 
                    uniform_int_distribution<> distrib(0, monstres.size()-1); 

                    int index = distrib(gen);
                    while(monstres[index]->getResultatCombat()!=0)
                    {
                        index=distrib(gen);
                    } 
                    //cout<<index<<endl;
                    monstres[index]->afficher();
                    bool resultatDefaite = Combat(j, *monstres[index]); 
                    if(resultatDefaite)
                    {
                        cout<<"Vous avez perdu"<<endl;
                        perdu=true;
                        a=0;
                    }
                     nbVictoires = 0;
                    for (const auto& m : monstres) 
                    {
                        if (m->getResultatCombat() == -1) { 
                            nbVictoires++;
                        }
                    }
                    

                     nbEpargne = 0;
                    for (const auto& m : monstres) {
                        if (m->getResultatCombat() == 1) { 
                            nbEpargne++;
                        }
                    }
                    if(nbVictoires==monstres.size())
                    {
                        cout<<"Fin genocidaire: Bravo! Vous avez gagne la partie !"<<endl;
                        a=0;
                    }
                    else if(nbEpargne==monstres.size())
                    {
                        cout<<"Fin pacifiste: Bravo! Vous avez gagne la partie !"<<endl;
                        a=0;
                    }
                    else if(nbEpargne+nbVictoires==monstres.size())
                    {
                        cout<<"Fin neutre: Bravo! Vous avez gagne la partie !"<<endl;
                        a=0;
                    }
                
                    break;
                }
                case 4:
                {
                    int nbAfficher = 0;
                    for(Monstre* m : monstres){                        
                        if (m->getResultatCombat()==-1 ||m->getResultatCombat()==1){
                            m->afficher();
                            if(m->getResultatCombat()==-1){
                                cout<<"Tue"<<endl;
                            }
                            else{
                                cout<<"epargne"<<endl;
                            }
                            nbAfficher++;
                        }                        
                    }
                    if(nbAfficher==0){
                            cout<<"Aucun Monstre encore tue ou epargne"<<endl;
                        }
                    break;
                }
                case 0:
                {
                    cout<<"sortie du jeu";
                    break;
                }
                default:
                    break;
            }

            

        }  
    }
        
    return 0;
};