/******************************************************************************/
/************** Carte principale Robot 1 : DSPIC33FJ128MC804*******************/
/******************************************************************************/
/* Fichier 	: autom.c
 * Auteur  	: Quentin
 * Revision	: 1.0
 * Date		: 01 f�vrier 2015, 17:11
 *******************************************************************************
 *
 *
 ******************************************************************************/

/******************************************************************************/
/******************************** INCLUDES ************************************/
/******************************************************************************/

#include "system.h"

/******************************************************************************/
/***************************** FONCTIONS DIVERSES *****************************/
/******************************************************************************/

#ifdef CARTE_BALISE

void son_evitement (uint8_t melodie)
{
    //Nop();
    //commande_AX12(100, _4PARAM, WRITE_DATA, 0x29, 10);
    //commande_AX12(100, _4PARAM, WRITE_DATA, 0x28, melodie);
}



/******************************************************************************/
/********************************  FONCTION AX12  *****************************/
/******************************************************************************/


/******************************************************************************/
/**************************** FONCTIONS D'INITS *******************************/
/******************************************************************************/

/******************************************************************************/
/******************************** FONCTIONS AUTOM *****************************/
/******************************************************************************/

/******************************************************************************/
/******************************** FONCTION BOUCLE *****************************/
/******************************************************************************/

void autom_20ms (void)
{
    static uint8_t compteur_checkup_ax12 = 0;
    
    //fonction qui definit les actions
    switch (FLAG_ACTION)
    {
        case NE_RIEN_FAIRE:
            break;
        default :
            break;
    }
        
    // Checkup que les ax12 vont bien toutes les 500 ms
    compteur_checkup_ax12++;
    if (compteur_checkup_ax12 == 25) // 500 ms
    {
        checkup_com_ax12();
    }
    
}


/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

#endif
