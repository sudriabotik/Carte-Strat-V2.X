/******************************************************************************/
/************** Carte principale Robot 1 : DSPIC33FJ128MC804*******************/
/******************************************************************************/
/* Fichier 	: srategie.c
 * Auteur  	: Quentin
 * Revision	: 1.0
 * Date		: 07 février 2015, 22:47
 *******************************************************************************
 *
 *
 ******************************************************************************/

/******************************************************************************/
/******************************** INCLUDES ************************************/
/******************************************************************************/

#include "system.h"


/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

void calage_init(){
    
    calage_X(0, 0, MARCHE_ARRIERE, 10);
    avancer_reculer(200,70);
    orienter(90,70);
    calage_Y(0, 0, MARCHE_ARRIERE, 10);
    
    avancer_reculer(1000,70);
    
    
    orienter(-90,70);
    calage_X(160, 0, MARCHE_ARRIERE, 10);
    avancer_reculer(40, 50);
    init_X(200);
    init_Y(1000+160);
    //avancer_reculer(250,20);
    //orienter(-45,70);
    //avancer_reculer(-300,20);
}

void tour_de_table(){
    rejoindre(750, 750, MARCHE_AVANT, 30);
        cibler(2250,750,30);
            //avancer_reculer(1000, 70);
            //init_X(2000);
            rejoindre(2250, 750, MARCHE_AVANT, 30);
            cibler(2250,1250,30);
            
            rejoindre(2250, 1250, MARCHE_AVANT, 30);
            cibler(750,1250,30);
            
            rejoindre(750, 1250, MARCHE_AVANT, 30);
            cibler(750,750,30);
            
            rejoindre(750, 750, MARCHE_AVANT, 30);
            //angle_AX12(6, 217, 50, SANS_ATTENTE);
            brake();
}

void strategie()
{  
#ifdef GROS_ROBOT
    
    EVITEMENT_ADV.actif = OFF;
    EVITEMENT_ADV.mode = STOP;
    
    CPT_TEMPS_MATCH.actif = OFF;
    
    COULEUR = couleur_depart();
    //STRATEGIE = strategie_depart();                 //TODO  
    
    brake();
    init_position_robot(0,0,0);
    
    printf("\nCoucou\n");
    
    //calage_init();
    //calage_X(144, 0, MARCHE_ARRIERE, 10);
    //rejoindre(1500, 1000, MARCHE_AVANT, 70);
    
    //unbrake();
    
    /*angle_AX12(8, 809, 200, SANS_ATTENTE);
    delay_ms(2000);
    angle_AX12(8, 585, 200, SANS_ATTENTE);*/
    
    /*while(1){
        
        if(SYS_JACK){
            //init_position_robot(0,0,0);
            //brake();
            //delay_ms(500);
            //avancer_reculer(2500,100);
            //orienter(-180,40);
            //avancer_reculer(- 1000,70);
            //faire_des_tours(2);
            
            //calage_X(144, 0, MARCHE_ARRIERE, 10);
            
            //init_position_robot(0,0,0);
            carre(MARCHE_AVANT);
            //tour_de_table();
            
            //angle_AX12(6, 217, 50, SANS_ATTENTE);
            brake();
            break;
        }
        

        //delay_ms(1000);
        
        //brake();

    }*/
    /*
    while(!SYS_JACK){
        brake();
    }*/
    
    //unbrake();

#endif

#ifdef PETIT_ROBOT
    
    EVITEMENT_ADV.actif = OFF;
    EVITEMENT_ADV.mode = STOP;
    
    CPT_TEMPS_MATCH.actif = OFF;
    
    COULEUR = couleur_depart();
    STRATEGIE = strategie_depart();
    
    //brake();
    
    //while(1){
        
        if(SYS_JACK){
            //orienter(90,10);
            //avancer_reculer(500,40);
            //avancer_reculer(-1000,100);
            faire_des_tours(5);
            //break;
        }
        else{
            avancer_reculer(500,40);
            //break;
        }
        //brake();
   // }
   
    brake();
    while(1);
    //angle_AX12(1,90,100,SANS_ATTENTE);
    /*while(1){
      //  brake();
    }
    
    while (1){
    angle_AX12(4, 800, 50, SANS_ATTENTE);
    delay_ms(1000);
    angle_AX12(4, 100, 50, SANS_ATTENTE);
    }
    
    calage_depart();
    while (!CAPTEUR5);
    while (CAPTEUR5);
    
    //angle_AX12(2, 840, 100, SANS_ATTENTE);
    
    
    //rack_couleur();

    rejoindre (1000, 780, MARCHE_AVANT, 50);
    rejoindre(1300, 1150, MARCHE_AVANT, 50);

    //delay_ms(3000);
    
    rejoindre(1300, 1500, MARCHE_AVANT, 80);
    cibler(500, 2000, 50);
    avancer_reculer(150,40);
    
    
    rejoindre(600, 550, MARCHE_AVANT, 50);
    rejoindre(350, 550, MARCHE_AVANT, 50);
    rejoindre(600, 550, MARCHE_ARRIERE, 50);
    
    rejoindre(600, 1050, MARCHE_AVANT, 50);
    //angle_AX12(2, 840, 100, SANS_ATTENTE);
    rejoindre(350, 1050, MARCHE_AVANT, 50);
    rejoindre(450, 1050, MARCHE_ARRIERE, 50);
    //AX12
    
    

    */
    
    

    //calage_X(0,0, MARCHE_ARRIERE, 20);
    delay_ms(500);    
    
}
    
    
    
#endif



void homologation()
{   
#ifdef GROS_ROBOT
    
    EVITEMENT_ADV.actif = OFF;
    EVITEMENT_ADV.mode = STOP;
    
    COULEUR = couleur_depart();
    STRATEGIE = strategie_depart();
    
    //Initialisation AX12
    init_AX12();
    //init_position_robot(140,450, 0.); //Pas utile
    
    calage_depart(); //Calage
    
    while(1){
        if(SYS_JACK){
        }}}
#endif

#ifdef PETIT_ROBOT
    
    
    
    COULEUR = couleur_depart();
    STRATEGIE = strategie_depart();
    
    calage_depart();
    while(!CAPTEUR5);
    while(CAPTEUR5);
    
    EVITEMENT_ADV.actif = ON;
    EVITEMENT_ADV.mode = STOP;
    
    CPT_TEMPS_MATCH.actif = ON;
    

    rejoindre (900, 780, MARCHE_AVANT, 30);
    rejoindre (900, 600, MARCHE_AVANT, 30);
    rejoindre(300, 600, MARCHE_AVANT, 30);
    rejoindre(500, 600, MARCHE_ARRIERE, 30);
    
    rejoindre (500, 1080, MARCHE_AVANT, 30);
    rejoindre(300, 1080, MARCHE_AVANT, 30);
    rejoindre(500, 1080, MARCHE_ARRIERE, 30);
#endif
}

//Initialise les positions des AX-12
void init_AX12(){
    #ifdef GROS_ROBOT
        //Init ax pompe
         //512
        /*if(COULEUR == BLEU) {
            angle_AX12(BRAS_POMPE,350,200,SANS_ATTENTE);
        }
        else {
            angle_AX12(BRAS_POMPE,650,200,SANS_ATTENTE);
        }
        //Init bras deux axes
        bras_repos();
        
        //Ouvre le bras droit
        angle_AX12(BRAS_DROIT, BRAS_DROIT_OUVERT, 100, AVEC_ATTENTE);
        //Ouvre le bras gauche
        angle_AX12(BRAS_GAUCHE, BRAS_GAUCHE_OUVERT, 100, AVEC_ATTENTE);

        //Les deux bras s'ouvrent pour voir si ils fonctionnent
        lancer_autom_AX12();
        delay_ms(2000); //On attend 2 seconde
        
        //Ferme le bras droit
        angle_AX12(BRAS_DROIT, BRAS_DROIT_FERME, 100, AVEC_ATTENTE);
        //ferme le bras gauche
        angle_AX12(BRAS_GAUCHE, BRAS_GAUCHE_FERME, 100, AVEC_ATTENTE);
        */
        //Les deux bras se ferment
        lancer_autom_AX12();
    #endif
    #ifdef PETIT_ROBOT
        bras_milieu_G();
        bras_milieu_D();
        delay_ms(2000);
        bras_haut_G();
        bras_haut_D();
        delay_ms(2000);
        bras_milieu_G();
        bras_milieu_D();
    #endif
}

void calage_depart(){
    init_position_robot(0., 0., 0.); //utile
    
    #ifdef GROS_ROBOT
    //avancer_reculer(1000,20);
    #endif

    #ifdef PETIT_ROBOT
    calage_X(0, 0, MARCHE_ARRIERE, 30);
    rejoindre(400, 0, MARCHE_AVANT, 30);
    orienter(90, 20);
    calage_Y(0, 90, MARCHE_ARRIERE, 30);
    rejoindre(400, 780, MARCHE_AVANT, 30);
    rejoindre(100, 780, MARCHE_ARRIERE, 30);
    #endif
}

/******************************************************************************/
/***************************** FONCTION STRATEGIE *****************************/
/******************************************************************************/

#ifdef GROS_ROBOT
#endif

#ifdef PETIT_ROBOT
void phare(){
    rejoindre(200,200, MARCHE_AVANT, 60);
    orienter(90,40);
    calage(400, 30);
    avancer_reculer(200,50);
}

void manche_a_air(){
    rejoindre(1800,200, MARCHE_AVANT, 60);
    orienter(200,40);
    // AX12 gauche en position horizontal
    rejoindre(1800, 620, MARCHE_AVANT, 60);     //profite de la rotation pour monter le manche a air
    orienter(180,20);
    orienter(250, 20);
    orienter(0,40);     //fait +/- un 360 pour monter le second manche a air
}

void rack_couleur(){
    rejoindre(200, 1562,MARCHE_AVANT,60);
    // AX12 gauche et droite en position "prise de gobelet" 2. 530
    orienter(180, 40);
    envoit_pwm(MOTEUR_X, 50);
    alimenter_moteur_Y(ON, MARCHE_AVANT);
    // toute les pompes
    avancer_reculer(70, 30);     //!\ pas fiable attention au 50mm
    avancer_reculer(-70, 30);    // on chope les gobelets et on recule
    // AX12 on range les gobelets 2.850
    // stop les pompes
    envoit_pwm(MOTEUR_X, 0);
    alimenter_moteur_Y(OFF, MARCHE_AVANT);
    rejoindre(200, 1712, MARCHE_AVANT, 60);
    // AX12 en position "prise de gobelet
    orienter(180,40);
    // toute les pompes
    envoit_pwm(MOTEUR_X, 50);
    alimenter_moteur_Y(ON, MARCHE_AVANT);
    avancer_reculer(70,30);     // on chope les autres gobelets
    avancer_reculer(-70, 30);
    
}

void rack_aleatoire(){
    rejoindre(200,737,MARCHE_AVANT,60);     // proche départ
    // AX12 en position "prise de gobelet"
    orienter(90, 40);
    //toute les pompes
    avancer_reculer(70, 30);    // on chope les premiers goblets
    avancer_reculer(-70, 30);
    // AX12 on range les gobelets
    // stop les pompes
    rejoindre(200, 962, MARCHE_AVANT, 60);
    // AX12 en position "prise de gobelet"
    orienter(90, 40);
    // toutes les pompes
    avancer_reculer(70, 30);    // on chope les 2 autres gobelets
    avancer_reculer(-70, 30);
}

#endif


/******************************************************************************/
/**************************** FONCTION ACTIONNEUR *****************************/
/******************************************************************************/

#ifdef GROS_ROBOT

#endif

#ifdef PETIT_ROBOT
void bras_milieu_G(){
    angle_AX12(4,500,200,SANS_ATTENTE);   
}
void bras_milieu_D(){
    angle_AX12(6,500,200,SANS_ATTENTE);
}

void bras_haut_G(){
    angle_AX12(4,875,200,SANS_ATTENTE);
}
void bras_haut_D(){
    angle_AX12(6,875,200,SANS_ATTENTE);
}

#endif


//Autre
void attendre(uint32_t ms)
{
    uint32_t temp = CPT_TEMPS_MATCH.t_ms;
    while(CPT_TEMPS_MATCH.t_ms - temp < ms); 
}


