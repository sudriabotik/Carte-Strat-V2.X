/* 
 * File:   strat_gr_robot.h
 * Author: Aymeric
 *
 * Created on 24 avril 2021, 22:28
 */



#ifndef STRAT_GR_ROBOT_H
#define	STRAT_GR_ROBOT_H

#define ALLUMER_POMPE   true
#define ETEINDRE_POMPE  false

#ifdef	__cplusplus
extern "C" {
#endif

#define POSITION_HAUTE_AX12                 0
#define POSITION_MOYENNE_AX12               0
#define POSITION_BASSE_AX12                 0

#define POSITION_OUVERTE_AX12               0
#define POSITION_FERMEE_AX12                0

#define TEMPS_ALLUME_POMPE                  100             //TODO meilleur temps pour attraper un goblet
    
    typedef struct module module;
    struct module
    {
        uint8_t ID_AX12_bielle;
        uint8_t angle_bielle_bas;
        uint8_t angle_bielle_mis_haut;
        uint8_t angle_bielle_haut;
        
        uint8_t ID_AX12_porte;
        uint8_t angle_porte_ouverte;
        uint8_t angle_porte_ferme;
        uint8_t angle_porte_garage;
        
        char* ID_IR;
        
        uint8_t ID_relais_pompe_rail;
        uint8_t etat_pompe_rail;
        
        uint8_t ID_relais_pompe_plafond;
        uint8_t etat_pompe_plafond;
        
    };
    

    int ramassage_goblet(uint8_t ID_module);
    void depose_goblet(uint8_t ID_module);
    void change_etat_pompe(uint8_t ID_pompe);
    uint8_t get_ID_module(char* ID_IR);
    void initialiser_parametres_module();
    int is_ID_IR();
    void decalage_liste_ordre(int i);

    
#ifdef	__cplusplus
}
#endif

#endif	/* STRAT_GR_ROBOT_H */

