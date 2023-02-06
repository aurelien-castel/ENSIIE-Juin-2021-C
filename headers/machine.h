#pragma once // pour éviter que le header soit inclut plusieurs fois dans le projet
#include "data_game.h"
#include "structures.h"
#include "personnel.h"
#include "carte.h"

typedef struct Coordinates Coordinates; // machine.h a besoins de structures.h https://stackoverflow.com/questions/3768966/c-recursive-header-file-inclusion-problem
typedef struct Collecteur Collecteur;
typedef struct Tapis Tapis;
typedef struct Croix Croix;
typedef struct Dechetterie Dechetterie;
typedef struct Recyclage Recyclage;
typedef struct Direction Direction;
typedef struct Carte Carte;

typedef struct Machine
{
	int type;
	Direction* orientation;
	Coordinates* coordinates;
	int hasRessource;
	int hasDechet;
	int hasNewRessource;
	int hasNewDechet;
	Collecteur* collecteur;//1
	Tapis* tapis;//2
	Croix* croix;//3
	Dechetterie* dechetterie;//4
	Recyclage* recyclage;//5 
	//6 source
	//7 porte
} Machine;



char* getTypeMachine(int id);

int getCostDDMachine(int id);
int getCostEMachine(int id);
int getCostUpgradeDDMachine(int id);
int getCostUpgradeEMachine(int id);
int getCostDestructionDDMachine(int id);
int getCostDestructionEMachine(int id);

int getMinCostDDMachine(int id);
int getMinCostEMachine(int id);
int getMinCostUpgradeDDMachine(int id);
int getMinCostUpgradeEMachine(int id);
int getMinCostDestructionDDMachine(int id);
int getMinCostDestructionEMachine(int id);

int getDamageDDMachine(Machine* machine);
int getLevelMachine(Machine* machine);
int getProduceRessource(Machine* machine);

bool canLevelUpMachine(Machine* machine);
void levelUpMachine(Machine* machine);

char getOrientation(Machine* machine);
Coordinates* getNextCase(Machine* machine , Carte* info_carte);

char getOrientationCroix(Machine* machine, char direction);
Coordinates* getCroixOrientationNextCase(Machine* machine , char direction) ;
