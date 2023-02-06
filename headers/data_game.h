#pragma once // pour éviter que le header soit inclut plusieurs fois dans le projet

#include "structures.h"
#include "personnel.h"

typedef struct Cost Cost;
typedef struct Coordinates Coordinates;
typedef struct Direction Direction;
typedef struct Personnel Personnel;
typedef struct Machine Machine;

#define ressourceGoal 1000;

// Statut du joueur , le joueur commence avec E : 100 et DD 100;
typedef struct PlayerStatut{
    int E;
    int DD; 
    int ressourceStocked;
    int round;
    bool ligozatSkillActived;
    bool szafranskiSkillActived;
    int thomasSkillActived;    
} PlayerStatut;


// Structure pour FISE et connaitre le nombre present sur la map, on commence avec 5
// Delay : produit tous les 1 tours
typedef struct Fise{
    int quantity;
    int productE;
    int productDD;
    int delay;
    Cost* cost;
}Fise;


// Structure pour FISA et connaitre le nombre present sur la map, on commence avec 5
// speciality : possede deux spe possible 'E' ou 'D' 
// Delay : produit tous les 2 tours selon sa specialite
typedef struct Fisa{
    int quantity;
    char speciality;
    int productE;
    int productDD;
    int delay;
    int pending;
    Cost* cost; 
} Fisa;


// Structure pour source
// Delay : au depart produit tous les 10 tours 3 ressources 
//le pending correspond au nombre de round depuis la derniere production
typedef struct Source{
    int produce;
    int delay;
    int pending;
    Coordinates* coordinates;
} Source;


// Structure pour Porte
// quantity : nombre de dechet present sur la map
// Damage :  -1 * quantity
// Delay : tous les tours
typedef struct Porte{
    int quantityDechet;
    int damageDD; //-1*quantity
    int delay;
    int hasRessource;
    Coordinates* coordinates;
} Porte;


// Structure pour machine
// type : 1: Collecteur,2: Tapis , 3: Croix, 4: Centre recyclage, 5: Dechetterie, 
// Cost cout de l'achat
// upgradeCost cout de l amelioration;
// destructionCost cout de la destruction;
typedef struct MachineType{
    int type;
    char* name;
    Cost* cost;
    Cost* upgradeCost;
    Cost* destructionCost;
    Cost* minCost;
    Cost* minUpgradeCost;
    Cost* minDestructionCost;
}MachineType;


// Structure pour Collecteur id 1
// Orientation : pour connaitre son orientation  -- Collecteur  posséde 1 orientation
// Entry : Struct pour connaitre ses entrées --- Le Collecteur possede 3 entree
// Ressource ou dechet rentre sur une case adjacente au collecteur et renvoie par l orientation 
// Le collecteur peut etre ameliorer
typedef struct  Collecteur{
    int maxQuantity;
    int level;
} Collecteur;


// Structure pour Tapis id 2
// Orientation : pour connaitre son orientation  -- Tapis  posséde 1 orientation
// Entry : pour connaitre ses entrées -- Tapis possede 3 entry 
// Ressource ou dechet rentre sur une case adjacente au tapis et renvoie par l orientation , il mettra 1 tour pour envoyer jusqu'a destination
typedef struct Tapis{
    int delay; //1
} Tapis;


// Structure pour Croix id 3
// Orientation : pour connaitre son orientation -- Croix  posséde 2 orientations
// Entry : pour connaitre ses entrées -- Croix possede 2 entry
// Ressource ou dechet rentre sur une case adjacente au tapis et renvoie par l orientation , il mettra 1 tour pour envoyer jusqu'a destination
//hasVRessource : ressource qui sera transporté sur la vertical
//hasHRessource : ressource qui sera transporté sur horizontal
//hasHRessource : 
typedef struct  Croix{
    int delay; //1
    int hasVRessource;
    int hasHRessource;
    int hasVDechet;
    int hasHDechet;

    int hasNewVRessource;
    int hasNewHRessource;

    int hasNewVDechet;
    int hasNewHDechet;
}Croix;


// Structure pour Dechetterie id 4
// Orientation : pour connaitre son orientation  --  posséde 0 sortie
// Entry : pour connaitre ses entrées -- possede 4 entry 
// Les dechets ne produisent pas de degat;
// Peut etre ameliorer;
typedef struct  Dechetterie{
    int maxQuantity; //50
    int quantity;
    int level;
}Dechetterie;


// Structure pour Recyclage id 5
// Orientation : pour connaitre son orientation  -- Recyclage  posséde 1 orientation
// Entry : pour connaitre ses entrées -- Recyclage possede 3 entry 
// A chaque tour produit une ressource pour 10 dechets , les dechets stocké produisent des degats.
// Peut etre ameliorer;
typedef struct  Recyclage{
    int maxQuantity; //100
    int quantity;
    int level;
    int delay; //1
    int damageDD; // -1*quantity
    int produceRessource; // quantity/10
}Recyclage;


PlayerStatut* playerStatut;
Fise* fise;
Fisa* fisa;
Personnel* personnelData;
MachineType* machineType;
Source* source1;
Source* source2;
Porte* porte;


Personnel* initializePersonnel();
MachineType* initializeMachineType();
PlayerStatut* initializePlayerStatut();
Fise* initializeFise();
Fisa* initializeFisa();
Source* initializeSource();
Porte* initializePorte();

void initializeGame();
void initializeCreateMachine(Machine* machine);
/**
 * @brief libere les mallocs
 * 
 */
void freeData();