#include "system.h"


char* liste_ID_IR[4];

struct module liste_modules[4];
int liste_stockage[4];


int ramassage_goblet(uint8_t ID_module){
    
    struct module module = liste_modules[ID_module];
    uint8_t position_stockage = liste_stockage[ID_module];
    
    angle_AX12(module.ID_AX12_porte, POSITION_OUVERTE_AX12, 100, SANS_ATTENTE);                 //on s'assure que la porte est ouverte
    
    avancer_reculer(100,100);                                                                     //on palce le goblet dans le module
    
    if(position_stockage==1 || position_stockage==2){
        change_etat_pompe(module.ID_relais_pompe_rail);                                         //on allume la pompe du rail
    }
    
    if(position_stockage==1 || position_stockage==2){       //on veut stocker le goblet en hauteur 
        angle_AX12(module.ID_AX12_bielle, POSITION_BASSE_AX12, 100, SANS_ATTENTE);              //on met la pince en bas

        angle_AX12(module.ID_AX12_porte, POSITION_FERMEE_AX12, 100, AVEC_ATTENTE);              //on ferme la porte

        
        if(position_stockage==2){                           //on veut stocker le goblet en haut
            change_etat_pompe(module.ID_relais_pompe_plafond);                                  //on allume la pompe pour maintenir le goblet au plafond

            angle_AX12(module.ID_AX12_bielle, POSITION_HAUTE_AX12, 100, SANS_ATTENTE);          //on place la bielle en haut
            
            change_etat_pompe(module.ID_relais_pompe_rail);                                     //on eteind la pompe de la bielle 
            
        }
        else if(position_stockage==1){                      //on veut stocker le goblet a mis hauteur
            angle_AX12(module.ID_AX12_bielle, POSITION_MOYENNE_AX12, 100, SANS_ATTENTE);        //on place la bielle à mis hauteur
        }
        
        angle_AX12(module.ID_AX12_porte, POSITION_OUVERTE_AX12, 100, SANS_ATTENTE);             //on rouvre la porte
    }
    else{                                                   //on veut stocker le goblet en bas
        angle_AX12(module.ID_AX12_porte, POSITION_FERMEE_AX12, 100, SANS_ATTENTE);              //on referme la porte pour maintenir le goblet
    }
    
    liste_stockage[ID_module]++;                                                                //on indique que le goblet est stocké
    
    return 0;
}


void depose_goblet(uint8_t ID_module){
    int position_goblet  = liste_stockage[ID_module];
    struct module module = liste_modules[ID_module];
    
    angle_AX12(module.ID_AX12_porte, POSITION_OUVERTE_AX12, 100, SANS_ATTENTE);                 //on ouvre la porte
            
    switch(position_goblet)
    {
        case 1:                 //1 goblet: stocké en haut
            angle_AX12(module.ID_AX12_bielle, POSITION_HAUTE_AX12, 100, SANS_ATTENTE);          //on met la pince en haut
            change_etat_pompe(module.ID_relais_pompe_rail);                                     //on attrape le goblet avec la pince
            
            
            change_etat_pompe(module.ID_relais_pompe_plafond);                                  //on lache libère le goblet du plafond
            
            
            angle_AX12(module.ID_AX12_bielle, POSITION_BASSE_AX12, 100, SANS_ATTENTE);          //on met la pince en bas
            change_etat_pompe(module.ID_relais_pompe_rail);                                     //on lache le goblet
            
            
            break;
            
        case 2:                 //2 goblets: stockés en haut et à mis hauteur
                angle_AX12(module.ID_AX12_bielle, POSITION_BASSE_AX12, 100, SANS_ATTENTE);      //on met la pince en bas
                change_etat_pompe(module.ID_relais_pompe_rail);                                 //on libère le goblet
            break;
        case 3:                 //3 goblets: stockés en haut, à mis hauteur et en bas
                
            break;
        default:
            break;
    }
    
    avancer_reculer(-100,100);                      //on recule
    
    liste_stockage[ID_module]--;
}


void change_etat_pompe(uint8_t ID_pompe){
    PutcUART(UART_XBEE, ID_pompe);
    attendre(TEMPS_ALLUME_POMPE);
}


uint8_t get_ID_module(char* ID_IR){
    int i;
    for(i=0; i<4; i++){
        if(liste_modules[i].ID_IR == ID_IR){
            return i;
        }
    }
    return -1;
}


void initialiser_parametres_module(){               //attribue les ID aux composants du module correspondants
    /*
     * IR: 25, 27, 29, 31
     * Relais: 5, 7, 9, 11, 13, 15, 17
     */
    
    //module avant gauche
    liste_modules[0].ID_AX12_bielle         =   0;
    liste_modules[0].angle_bielle_bas       =   0;
    liste_modules[0].angle_bielle_mis_haut  =   0;
    liste_modules[0].angle_bielle_haut      =   0; 
	
    liste_modules[0].ID_AX12_porte          =   0;
    liste_modules[0].angle_porte_ouverte    =   0;
    liste_modules[0].angle_porte_ferme      =   0;
    liste_modules[0].angle_porte_garage     =   0;
	
    liste_modules[0].ID_IR                  =   "";
	
    liste_modules[0].ID_relais_pompe_rail   =   0;
    liste_modules[0].etat_pompe_rail        =   0;
	
    liste_modules[0].ID_relais_pompe_plafond=   0;
    liste_modules[0].etat_pompe_plafond     =   0;
    
    //module avant droit
    liste_modules[1].ID_AX12_bielle         =   1;
    liste_modules[1].angle_bielle_bas       =   1;
    liste_modules[1].angle_bielle_mis_haut  =   1;
    liste_modules[1].angle_bielle_haut      =   1;
	
    liste_modules[1].ID_AX12_porte          =   1;
    liste_modules[1].angle_porte_ouverte    =   1;
    liste_modules[1].angle_porte_ferme      =   1;
    liste_modules[1].angle_porte_garage     =   1;
	
    liste_modules[1].ID_IR                  =   "";
	
    liste_modules[1].ID_relais_pompe_rail   =   1;
    liste_modules[1].etat_pompe_rail        =   0;
	
    liste_modules[1].ID_relais_pompe_plafond=   1;
    liste_modules[1].etat_pompe_plafond     =   0;
    
    //module arriere gauche
    liste_modules[2].ID_AX12_bielle         =   2;
    liste_modules[2].angle_bielle_bas       =   2;
    liste_modules[2].angle_bielle_mis_haut  =   2;
    liste_modules[2].angle_bielle_haut      =   2;
	
    liste_modules[2].ID_AX12_porte          =   2;
    liste_modules[2].angle_porte_ouverte    =   2;
    liste_modules[2].angle_porte_ferme      =   2;
    liste_modules[2].angle_porte_garage     =   2;
	
    liste_modules[2].ID_IR                  =   "";
	
    liste_modules[2].ID_relais_pompe_rail   =   2;
    liste_modules[2].etat_pompe_rail        =   0;
	
    liste_modules[2].ID_relais_pompe_plafond=   2;
    liste_modules[2].etat_pompe_plafond     =   0;
    
    //module arriere droit
    liste_modules[3].ID_AX12_bielle         =   3;
    liste_modules[3].angle_bielle_bas       =   3;
    liste_modules[3].angle_bielle_mis_haut  =   3;
    liste_modules[3].angle_bielle_haut      =   3;
    
	liste_modules[3].ID_AX12_porte          =   3;
    liste_modules[3].angle_porte_ouverte    =   3;
    liste_modules[3].angle_porte_ferme      =   3;
    liste_modules[3].angle_porte_garage     =   3;
	
    liste_modules[3].ID_IR                  =   "";
	
    liste_modules[3].ID_relais_pompe_rail   =   3;
    liste_modules[3].etat_pompe_rail        =   0;
	
    liste_modules[3].ID_relais_pompe_plafond=   3;
    liste_modules[3].etat_pompe_plafond     =   0;
    
    liste_ID_IR[0] = "25";
    liste_ID_IR[1] = "27";
    liste_ID_IR[2] = "29";
    liste_ID_IR[3] = "31";
    
    int i;
    for(i=0; i<4; i++){
        liste_modules[i].ID_IR = liste_ID_IR[i];
    }
    
    liste_stockage[0]=0;
    liste_stockage[1]=0;
    liste_stockage[2]=0;
    liste_stockage[3]=0;
}


int is_ID_IR(){
    int i;
    for(i=0; i<4; i++){
        if(check_string(0, liste_ID_IR[i])){
            return i;
        }
    }
    return -1;
}





#define NB_GOBLETS          24  
int* coordonnees_goblets[NB_GOBLETS];
int* ordre_rammasse_goblet[NB_GOBLETS];


void va_chercher(int i){
    int num_goblet = ordre_rammasse_goblet[i][0];
    int x_goblet = coordonnees_goblets[num_goblet][0];
    int y_goblet = coordonnees_goblets[num_goblet][1];
    int ID_module = ordre_rammasse_goblet[i][1];
    
    rejoindre(x_goblet, y_goblet, MARCHE_AVANT, 80);
    
    int rammasse = ramassage_goblet(ID_module);
    
    if(rammasse<0){
        decalage_liste_ordre(i);
    }
    
}


void decalage_liste_ordre(int i){
    int u;
    int* tmp = ordre_rammasse_goblet[i];
    
    for(u=i; u<NB_GOBLETS-1; u++){
        ordre_rammasse_goblet[u] = ordre_rammasse_goblet[u+1];
    }
    
    ordre_rammasse_goblet[u+1] = tmp;
    
}