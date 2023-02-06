#pragma once // pour éviter que le header soit inclut plusieurs fois dans le projet

#include "machine.h"
#include "personnel.h"
#include "structures.h"
#include "machine.h"
#include "data_game.h"

typedef struct Case Case;
typedef struct Machine Machine;
typedef struct Source Source;
typedef struct Coordinates Coordinates;

void printDropEnDehorsDelaMap(bool isDechet,int quantity);
void printDrop(bool isDechet,int quantity, int x, int y);


/**
 * @brief la structure caractérisant les informations générales de la carte du jeu
 * 
 */
typedef struct Carte{
    Case** la_carte_du_jeu; // la carte 2D
    int taille_carte; // la taille de la carte, sachant que la carte est de taille: taille_carte*taille_carte
} Carte;

/**
 * @brief création de la Carte de taille n*n
 * 
 * @param n 
 * @return Carte* 
 */
Carte* createCarte(int n);

/**
 * @brief libération de la Carte 
 * 
 * @param infos_carte 
 */
void freeMemoryCarte(Carte* map);

/**
 * @brief une fonction pour recruter un FISE
 * 
 */
void createFise();

/**
 * @brief une fonction pour recruter un FISA
 * 
 */
void createFisa();

/**
 * @brief une fonction pour changer le type de ressource créée par les FISA
 * 
 */
void changeRessource();

/**
 * @brief une fonction pour terminer le tour
 * 
 */
void endTurn();

/**
 * @brief ajout une machine si le budget le permet
 * 
 * @return machine* 
 */
void addMachine(Machine* machine);

/**
 * @brief ameliore une machine si le budget le permet
 * 
 * @param machine 
 */
void upMachine(Machine* machine);

/**
 * @brief detruire une machine si le budget le permet
 * 
 * @param machine 
 */
void destroyMachine(Machine* machine);

/**
 * @brief ajout d'un personnel si le budget le permet
 * 
 * @param identifiant 
 */
void addPersonnel(int identifiant);


/**
 * @brief Set the Entree Sortie object
 * 
 * @param carte 
 */
void setEntreeSortie(Carte* carte);

/*
 * @brief produit une ressource si besoin
 * 
 * @return void
 */
void activeSource();

/*
 * @brief Les sources produit un ressource et les fait tomber sur les cases adjacentes
 * 
 * @return void
 */
void dropRessource(Source* source, Carte* info_carte, int idSource);


int checkCaseDropRessource(Carte* info_carte , int x , int y,int sourceProduce, char direction );

bool isAnEntryAvailable(char direction , Machine* machine , bool isDechet);


/*
 * @brief resultat de la porte selon le personnel acquis
 * 
 * @return void
 */
void activeSkillPorte(int ressources, Carte* carte);

/**
 * @brief Regarde pour chaque tapis si une ressource est présente ou non.
 * Si une autre machine est présente à son extrémité, la ressource lui est envoyée, sinon 
 * elle est détruite.
 * 
 * @param Carte carte
 */
void checkTapis(Carte* carte);

void dropDechetPorte(Carte* carte);

/**
 * @brief Pour chaque dechetterie ou centre de recyclage, on divise la quantité
 * de dechets de la machine par 2, mais egalement la quantité de déchet de la porte par 2
 * 
 * @param carte
 */
void activeLigozatSkill(Carte* carte);

void activeTapis(Carte* carte);

void dealMouvementTapis(Carte* carte, Machine* machine,int quantity , bool isDechet,char direction,bool isTapisMouvement);

void continueMove(Carte* carte, Machine* machine,int quantity ,Coordinates* nextCase, bool isDechet,char direction);

void activeMachine(Carte* carte);

void dealCollecteur(Machine* machine, Carte* carte);

void dealRecyclage(Machine* machine, Carte* carte);

void activeTapisPourDeVrai(Carte* carte);

/*
*active skill des fises et fisa
*/
void activeSkillEleve();

/*
 * @brief Appel toute les fonctions necessaire pour finir un tour
 * 
 * @return void
 */
void endTurn(Carte* carte);

