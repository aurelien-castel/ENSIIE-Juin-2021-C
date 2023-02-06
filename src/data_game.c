#include <stdlib.h>
#include "../headers/data_game.h" // inclusion de son fichier librairie .h qui permet aux autres .c du projet de savoir ce que contient notre .c actuel
#include "../headers/personnel.h"
#include "../headers/structures.h"

Personnel* initializePersonnel()
{
	Personnel *personnel = (Personnel*) malloc((24) *sizeof(struct Personnel));

	personnel[0].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[0].cost->E = 200;
	personnel[0].cost->DD = 20;
	personnel[0].name = "Fetia";
	personnel[0].firstName = "Bannour";
	personnel[0].descriptionSpe = "Le coût de construction des collecteurs diminue de 10E et 1DD (minimum 10E et 1DD).";
	
	personnel[1].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[1].cost->E = 100;
	personnel[1].cost->DD = 30;
	personnel[1].name = "Kevin";
	personnel[1].firstName = "Goilard";
	personnel[1].descriptionSpe = "Le coût de construction des tapis diminue de 3E et 1DD (minimum 3E et 1DD).";
	
	personnel[2].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[2].cost->E = 100;
	personnel[2].cost->DD = 30;
	personnel[2].name = "Vincent";
	personnel[2].firstName = "Jeannas";
	personnel[2].descriptionSpe = "Le coût de construction des croix diminue de 8E et 1DD (minimum 8E et 1DD).";

	personnel[3].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[3].cost->E = 100;
	personnel[3].cost->DD = 30;
	personnel[3].name = "Thomas";
	personnel[3].firstName = "Laurent";
	personnel[3].descriptionSpe = "Le coût de construction des centres de recyclage diminue de 25E et 2DD (minimum 25E et 2DD).";

	personnel[4].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[4].cost->E = 100;
	personnel[4].cost->DD = 30;
	personnel[4].name = "Massinissa";
	personnel[4].firstName = "Merabet";
	personnel[4].descriptionSpe = "Le coût de construction des déchetterie diminue de 5E et 5DD (minimum 5 et 5DD).";

	personnel[5].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[5].cost->E = 200;
	personnel[5].cost->DD = 100;
	personnel[5].name = "Stefi";
	personnel[5].firstName = "Nouleho";
	personnel[5].descriptionSpe = "Le coût d’amélioration des collecteurs diminue de 25E et 5DD (minimum 25E et 5DD).";

	personnel[6].cost = (Cost*) malloc((1) *sizeof(struct Cost));	
	personnel[6].cost->E = 200;
	personnel[6].cost->DD = 100;
	personnel[6].name = "Vitera";
	personnel[6].firstName = "Y";
	personnel[6].descriptionSpe = "Le coût d’amélioration des centres de recyclage diminue de 75E et 5DD (minimum 75E et 5DD).";

	personnel[7].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[7].cost->E = 200;
	personnel[7].cost->DD = 100;
	personnel[7].name = "Laurence";
	personnel[7].firstName = "Bourard";
	personnel[7].descriptionSpe = "Le coût d’amélioration des déchetterie diminue de 10E et 30DD (minimum 20E et 30DD).";

	personnel[8].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[8].cost->E = 100;
	personnel[8].cost->DD = 200;
	personnel[8].name = "Nicolas";
	personnel[8].firstName = "Brunel";
	personnel[8].descriptionSpe = "Le coût de destruction des collecteurs diminue de 3E et 10DD (minimum 3E et 10DD).";

	personnel[9].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[9].cost->E = 100;
	personnel[9].cost->DD = 200;
	personnel[9].name = "Anastase";
	personnel[9].firstName = "Charantonis";
	personnel[9].descriptionSpe = "Le coût de destruction des collecteurs diminue de 3E et 10DD (minimum 3E et 10DD).";

	personnel[10].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[10].cost->E = 100;
	personnel[10].cost->DD = 200;
	personnel[10].name = "Catherine";
	personnel[10].firstName = "Dubois";
	personnel[10].descriptionSpe = "Le coût de destruction des croix diminue de 3E et 10DD (minimum 3E et 10DD).";

	personnel[11].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[11].cost->E = 100;
	personnel[11].cost->DD = 200;
	personnel[11].name = "Stefania";
	personnel[11].firstName = "Dumbrava";
	personnel[11].descriptionSpe = "Le coût de destruction des centres de recyclage diminue de 5E et 25DD (minimum 5E et 25DD)";

	personnel[12].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[12].cost->E = 100;
	personnel[12].cost->DD = 200;
	personnel[12].name = "Alain";
	personnel[12].firstName = "Faye";
	personnel[12].descriptionSpe = "Le coût de destruction des déchetterie diminue de 5E et 10DD (minimum 5E et 10DD)";

	personnel[13].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[13].cost->E = 1000;
	personnel[13].cost->DD = 10;
	personnel[13].name = "Anne-Laure";
	personnel[13].firstName = "Ligozat";
	personnel[13].descriptionSpe = "La moitié des déchets de chaque case disparaissent.";

	personnel[14].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[14].cost->E = 1000;
	personnel[14].cost->DD = 400;
	personnel[14].name = "Christophe";
	personnel[14].firstName = "Mouilleron";
	personnel[14].descriptionSpe = "L’école recrute 20 FISE et 10 FISA.";

	personnel[15].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[15].cost->E = 1000;
	personnel[15].cost->DD = 400;
	personnel[15].name = "Marie";
	personnel[15].firstName = "Szafranski";
	personnel[15].descriptionSpe = "A chaque fois qu’une ressource est envoyée à la porte, elle compte double. Le nombre de déchet produit est toujours de 1.";

	personnel[16].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[16].cost->E = 1000;
	personnel[16].cost->DD = 400;
	personnel[16].name = "Gael";
	personnel[16].firstName = "Thomas";
	personnel[16].descriptionSpe = "Quand un déchet quitte la porte, il a une chance sur 10 de disparaître.";

	personnel[17].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[17].cost->E = 1000;
	personnel[17].cost->DD = 200;
	personnel[17].name = "Eric";
	personnel[17].firstName = "Lejeune";
	personnel[17].descriptionSpe = "Le coût des FISE diminue de 5E et 2DD (minimum 5E et 2DD).";

	personnel[18].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[18].cost->E = 1000;
	personnel[18].cost->DD = 200;
	personnel[18].name = "Christine";
	personnel[18].firstName = "Mathias";
	personnel[18].descriptionSpe = "Le coût des FISA diminue de 5E et 2DD (minimum 5E et 2DD).";

	personnel[19].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[19].cost->E = 1500;
	personnel[19].cost->DD = 300;
	personnel[19].name = "Katrin";
	personnel[19].firstName = "Salhab";
	personnel[19].descriptionSpe = "Les membres du personnel coûtent 50E et 20DD de moins (minimum 10E et 10DD).";

	personnel[20].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[20].cost->E = 2000;
	personnel[20].cost->DD = 500;
	personnel[20].name = "Julien";
	personnel[20].firstName = "Forest";
	personnel[20].descriptionSpe = "Les FISE produisent 1E et 1DD de plus chaque tours.";

	personnel[21].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[21].cost->E = 1000;
	personnel[21].cost->DD = 400;
	personnel[21].name = "Thomas";
	personnel[21].firstName = "Lim";
	personnel[21].descriptionSpe = "Les sources mettent un tour de moins à produire (minimum 1).";

	personnel[22].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[22].cost->E = 2000;
	personnel[22].cost->DD = 500;
	personnel[22].name = "Dimitri";
	personnel[22].firstName = "Watel";
	personnel[22].descriptionSpe = "Les FISA produisent 4E ou 4DD de plus tous les deux tours.";

	personnel[23].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	personnel[23].cost->E = 3000;
	personnel[23].cost->DD = 1000;
	personnel[23].name = "Laurent";
	personnel[23].firstName = "Prével";
	personnel[23].descriptionSpe = "Un dixième des FISE et des FISA de l’école sont diplômés. Ils quittent l’école mais chaque élève diplômé envoie une ressource à la porte.";

	return personnel;

}

MachineType* initializeMachineType()
{
	MachineType *machineType = (MachineType*) malloc((7) *sizeof(struct MachineType));

	machineType[0].type = 1;
	machineType[0].name = "Collecteur";

	machineType[0].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[0].cost->E = 200;
	machineType[0].cost->DD = 20;
	
	machineType[0].upgradeCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[0].upgradeCost->E = 500;
	machineType[0].upgradeCost->DD = 100;

	machineType[0].destructionCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[0].destructionCost->E = 60;
	machineType[0].destructionCost->DD = 200;

	machineType[0].minCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[0].minCost->E = 10;
	machineType[0].minCost->DD = 1;

	machineType[0].minUpgradeCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[0].minUpgradeCost->E = 25;
	machineType[0].minUpgradeCost->DD = 5;

	machineType[0].minDestructionCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[0].minDestructionCost->E = 3;
	machineType[0].minDestructionCost->DD = 10;


	machineType[1].type = 2;
	machineType[1].name = "Tapis";

	machineType[1].cost = (Cost*) malloc((1) * sizeof(struct Cost));
	machineType[1].cost->E = 60;
	machineType[1].cost->DD = 20;

	machineType[1].upgradeCost = (Cost*) malloc((1) * sizeof(struct Cost));
	machineType[1].upgradeCost->E = 0;
	machineType[1].upgradeCost->DD = 0;

	machineType[1].destructionCost = (Cost*) malloc((1) * sizeof(struct Cost));
	machineType[1].destructionCost->E = 60;
	machineType[1].destructionCost->DD = 200;

	machineType[1].minCost = (Cost*) malloc((1) * sizeof(struct Cost));
	machineType[1].minCost->E = 3;
	machineType[1].minCost->DD = 1;


	machineType[2].type = 3;
	machineType[2].name = "Croix";

	machineType[2].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[2].cost->E = 160;
	machineType[2].cost->DD = 20;
	
	machineType[2].upgradeCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[2].upgradeCost->E = 0;
	machineType[2].upgradeCost->DD = 0;

	machineType[2].destructionCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[2].destructionCost->E = 60;
	machineType[2].destructionCost->DD = 200;

	machineType[2].minCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[2].minCost->E = 8;
	machineType[2].minCost->DD = 1;

	machineType[2].minDestructionCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[2].minDestructionCost->E = 3;
	machineType[2].minDestructionCost->DD = 10;

	machineType[3].type = 4;
	machineType[3].name = "Déchetterie";

	machineType[3].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[3].cost->E = 100;
	machineType[3].cost->DD = 100;

	machineType[3].upgradeCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[3].upgradeCost->E = 200;
	machineType[3].upgradeCost->DD = 600;

	machineType[3].destructionCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[3].destructionCost->E = 100;
	machineType[3].destructionCost->DD = 200;

	machineType[3].minCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[3].minCost->E = 5;
	machineType[3].minCost->DD = 5;

	machineType[3].minUpgradeCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[3].minUpgradeCost->E = 20;
	machineType[3].minUpgradeCost->DD = 30;

	machineType[3].minDestructionCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[3].minDestructionCost->E = 5;
	machineType[3].minDestructionCost->DD = 10;

	machineType[4].type = 5;
	machineType[4].name = "Centre de recyclage";

	machineType[4].cost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[4].cost->E = 500;
	machineType[4].cost->DD = 40;

	machineType[4].upgradeCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[4].upgradeCost->E = 1500;
	machineType[4].upgradeCost->DD = 100;

	machineType[4].destructionCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[4].destructionCost->E = 100;
	machineType[4].destructionCost->DD = 500;

	machineType[4].minCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[4].minCost->E = 25;
	machineType[4].minCost->DD = 2;

	machineType[4].minUpgradeCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[4].minUpgradeCost->E = 75;
	machineType[4].minUpgradeCost->DD = 5;
	
	machineType[4].minDestructionCost = (Cost*) malloc((1) *sizeof(struct Cost));
	machineType[4].minDestructionCost->E = 5;
	machineType[4].minDestructionCost->DD = 25;

	
	machineType[5].type = 6;
	machineType[5].name = "Source";

	return machineType;
}

PlayerStatut* initializePlayerStatut()
{
	PlayerStatut *playerStatut = (PlayerStatut*) malloc((1) *sizeof(struct PlayerStatut));

	playerStatut->E = 100;
	playerStatut->DD = 100;
	playerStatut->ressourceStocked = 0;
	playerStatut->round = 1;
	playerStatut->ligozatSkillActived = false;
	playerStatut->szafranskiSkillActived = false;
	playerStatut->thomasSkillActived = 0;
	return playerStatut;
}

Fise* initializeFise()
{
	Fise *fise = (Fise*) malloc((1) *sizeof(struct Fise));
	fise->quantity = 5;
    fise->productE = 1;
    fise->productDD = 1;
	fise->delay = 1 ;
    Cost *costMalloc = (Cost*) malloc((1) *sizeof(struct Cost));
    fise->cost = costMalloc;
    fise->cost->E = 50;
    fise->cost->DD = 20;

	return fise;
}

Fisa* initializeFisa()
{
	Fisa *fisa = (Fisa*) malloc((1) *sizeof(struct Fisa));
	fisa->quantity = 5;
    fisa->speciality = 'D'; 
    fisa->productDD = 4;
	fisa->productE = 4;
    fisa->delay = 2;
	fisa->pending = 1;
    Cost *costMalloc = (Cost*) malloc((1) *sizeof(struct Cost));
    fisa->cost = costMalloc;
	fisa->cost->E = 50;
    fisa->cost->DD = 20;

	return fisa;
}

Source* initializeSource()
{
	Source *source = (Source*) malloc((1) *sizeof(struct Source));

	source->produce = 3;
	source->delay = 10;
	source->pending = 1;
	source->coordinates = (Coordinates*) malloc((1) *sizeof(struct Coordinates));

	return source;
}

Porte* initializePorte()
{
	Porte *porte = (Porte*) malloc((1) *sizeof(struct Porte));
	porte->quantityDechet = 0;
	porte->damageDD = -1;  //-1*quantity
	porte->delay = 1;
	porte->coordinates = (Coordinates*) malloc((1) *sizeof(struct Coordinates));
	porte->hasRessource = 0;

	return porte;
}

void initializeGame()
{
	playerStatut = initializePlayerStatut(); 
	fise = initializeFise();
	fisa = initializeFisa();
	personnelData = initializePersonnel();
	machineType = initializeMachineType();
	source1 = initializeSource();
	source2 = initializeSource();
	porte = initializePorte();
}

void initializeCreateMachine(Machine* machine)
{
	switch (machine->type)
	{
		case 1:
			machine->collecteur = (Collecteur*) malloc((1) *sizeof(struct Collecteur));
			machine->collecteur->level = 1;
			machine->collecteur->maxQuantity = 1;
			break;
		case 2 :
			machine->tapis = (Tapis*) malloc((1) *sizeof(struct Tapis));
			machine->tapis->delay = 1;
			break;
		case 3 :
			machine->croix = (Croix*) malloc((1) *sizeof(struct Croix));
			machine->croix->delay = 1;
			machine->croix->hasHRessource = 0;
			machine->croix->hasVRessource = 0;
			machine->croix->hasHDechet = 0;
			machine->croix->hasVDechet = 0;     
			machine->croix->hasNewVRessource = 0 ;
			machine->croix->hasNewHRessource= 0;
			machine->croix->hasNewVDechet= 0;
			machine->croix->hasNewHDechet= 0;
			break;
		case 4 :
			machine->dechetterie = (Dechetterie*) malloc((1) *sizeof(struct Dechetterie));
			machine->dechetterie->maxQuantity = 50;
			machine->dechetterie->quantity = 0;
			machine->dechetterie->level = 1;
			break;
		case 5 :
			machine->recyclage = (Recyclage*) malloc((1) *sizeof(struct Recyclage));
			machine->recyclage->maxQuantity = 100;
			machine->recyclage->quantity = 0;
			machine->recyclage->level = 1;
			machine->recyclage->delay = 1;
			machine->recyclage->damageDD = -1;  //*quantity
			machine->recyclage->produceRessource = 10; // quantity/10
			break;
	}
}

void freeData()
{
	free(playerStatut);
	free(fise);
	free(fisa);
	free(personnelData);
	free(machineType);
	free(source1);
	free(source2);
	free(porte);
}