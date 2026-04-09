#include "action.h"
#include "item.h"
#include "joueur.h"
#include "monstre.h"
#include "statistique.h"
#include <vector>
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

    
    int a=0;
    while(a!=4)
    {

        cout<<"Menu : \ntaper 1 pour creer un joueur et afficher ses stats et ses items\ntaper 2 pour creer un monstre et l'afficher\ntaper 3 pour afficher les actions\ntaper 4 pour sortir\n>";
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
            case 4:
                cout<<"sortie du jeu";
                break;

            default:
                break;
        }
    }     
        
        return 0;
    };