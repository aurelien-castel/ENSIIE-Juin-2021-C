#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/structures.h"
#include "../headers/machine.h"
#include "../headers/carte.h" 


char* getTypeMachine(int id)
{
	return machineType[(id-1)].name;
}

int getCostDDMachine(int id)
{
	return machineType[(id-1)].cost->DD;
}

int getCostEMachine(int id)
{
	return machineType[(id-1)].cost->E;
}

int getCostUpgradeDDMachine(int id)
{
	return machineType[(id-1)].upgradeCost->DD;
}

int getCostUpgradeEMachine(int id)
{
	return machineType[(id-1)].upgradeCost->E;
}

int getCostDestructionDDMachine(int id)
{
	return machineType[(id-1)].destructionCost->DD;
}

int getCostDestructionEMachine(int id)
{
	return machineType[(id-1)].destructionCost->E;
}

int getMinCostDDMachine(int id){
	return machineType[(id-1)].minCost->DD;
}

int getMinCostEMachine(int id){
	return machineType[(id-1)].minCost->E;
}

int getMinCostUpgradeDDMachine(int id){
	return machineType[(id-1)].minUpgradeCost->DD;
}

int getMinCostUpgradeEMachine(int id){
	return machineType[(id-1)].minUpgradeCost->E;
}

int getMinCostDestructionDDMachine(int id){
	return machineType[(id-1)].minDestructionCost->DD;
}

int getMinCostDestructionEMachine(int id){
	return machineType[(id-1)].minDestructionCost->E;
}

int getDamageDDMachine(Machine* machine)
{
	switch (machine->type)
	{
		case 1:
			return 0;
		case 2 :
			return 0;
		case 3 :
			return 0;
		case 4 :
			return 0;
		case 5 :
			return (machine->recyclage->damageDD * machine->recyclage->quantity);
	}
	return 0;
}

int getLevelMachine(Machine* machine)
{
	if(machine->type == 1 ||machine->type == 4 || machine->type == 5 )
	{
		return machine->collecteur->level;
	}

	return 0;
}

bool canLevelUpMachine(Machine* machine)
{
	switch (machine->type)
	{
		case 1:
			return true;
			break;
		case 4 :
			return true;
			break;
		case 5 :
			return true;
			break;
	}
	
	return false;
}


int getProduceRessource(Machine* machine)
{
	switch (machine->type)
	{
		case 1:
			return 0;
		case 2 :
			return 0;
		case 3 :
			return 0;
		case 4 :
			return 0;
		case 5 :
			return (machine->recyclage->quantity * machine->recyclage->produceRessource);
	}

	return 0;
}

void levelUpMachine(Machine* machine)
{
	switch (machine->type)
	{
		case 1:
			machine->collecteur->level +=  1;
			machine->collecteur->maxQuantity += 1;
			break;
		case 4 :
			machine->dechetterie->level += 1;
			machine->dechetterie->maxQuantity += 20;
			break;
		case 5 :
			machine->recyclage->level += 1;
			machine->recyclage->maxQuantity += 10;
			break;
	}
}

/*
*pour les machines avec 3 entree et une sortie
*machine sera ici la case de de printf("\n**** Le collecteur a %i ressources(s)" , machine->hasRessource );
*envoi -1 -1 si en dehors de la map il faut gerer ca apres 
*/
Coordinates* getNextCase(Machine* machine , Carte* info_carte) 
{
	Coordinates* coord = (Coordinates*) malloc((1) * sizeof(struct Coordinates));

	if(machine->type == 2 || machine->type == 1 || machine->type == 5)
	{
		if(machine->orientation->top == true)
		{
			coord->x = machine->coordinates->x;
			coord->y = machine->coordinates->y-1;
		}
		else if(machine->orientation->right == true)
		{
			coord->x = machine->coordinates->x+1;
			coord->y = machine->coordinates->y;
		}
		else if(machine->orientation->down == true)
		{
			coord->x = machine->coordinates->x;
			coord->y = machine->coordinates->y+1;
		}
		else if(machine->orientation->left == true)
		{
			coord->x = machine->coordinates->x-1;
			coord->y = machine->coordinates->y;
		}

		if(coord->x<0 || coord->y<0 || coord->x > info_carte->taille_carte ||  coord->y > info_carte->taille_carte)
		{
			coord->x = -1;
			coord->y = -1;
		}
	}
	else
	{
		coord->x = -1;
		coord->y = -1;
	}
	return coord;
}

//donne l orientation pour les machines avec 3 entree et une sortie
char getOrientation(Machine* machine)
{
	if(machine->type == 2 || machine->type == 5 || machine->type == 1)
	{
		if(machine->orientation->top == true)
		{
			return 't';
		}
		else if(machine->orientation->right == true)
		{
			return 'r';
		}
		else if(machine->orientation->down == true)
		{
			return 'd';
		}
		else if(machine->orientation->left == true)
		{
			return 'l';
		}		
	}
	else
	{
		return 'e';
	}

	return 'e';
}

char getOrientationCroix(Machine* machine, char direction)
{
	
	if(machine->type == 3)
	{
		switch (direction)
		{
		case 'v':
			if(machine->orientation->top == true)
			{
				return 't';
			}
			else if(machine->orientation->down == true)
			{
				return 'd';
			}
			break;
		
		case 'h':
			if(machine->orientation->right == true)
			{
				return 'r';
			}			
			else if(machine->orientation->left == true)
			{
				return 'l';
			}
			break;
		}
	}
	return 'e';
}

Coordinates* getCroixOrientationNextCase(Machine* machine , char direction) 
{
	Coordinates* coord = (Coordinates*) malloc((1) * sizeof(struct Coordinates));

	if(machine->type == 3)
	{
		switch (direction)
		{
		case 'v':
			if(machine->orientation->top == true)
			{
				coord->x = machine->coordinates->x;
				coord->y = machine->coordinates->y-1;
			}
			else if(machine->orientation->down == true)
			{
				coord->x = machine->coordinates->x;
				coord->y = machine->coordinates->y+1;
			}
			break;
		
		case 'h':
			if(machine->orientation->right == true)
			{
				coord->x = machine->coordinates->x+1;
				coord->y = machine->coordinates->y;
			}			
			else if(machine->orientation->left == true)
			{
				coord->x = machine->coordinates->x-1;
				coord->y = machine->coordinates->y;
			}
			break;
		}
	}
	else
	{
		coord->x = -1;
		coord->y = -1;
	}
	return coord;
}