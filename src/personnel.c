#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/personnel.h"
// inclusion de son fichier librairie .h qui permet aux autres .c du projet de savoir ce que contient notre .c actuel


int getCostDDPersonnel(int id)
{
	return personnelData[(id-1)].cost->DD;
}

int getCostEPersonnel(int id)
{
	return personnelData[(id-1)].cost->E;
}

char* getNamePersonnel(int id)
{
    return personnelData[(id-1)].name;
}

char* getFirstNamePersonnel(int id)
{
    return personnelData[(id-1)].firstName;
}

char* getDescriptionSpe(int id)
{
    return personnelData[(id-1)].descriptionSpe;
}


void setEffectCost(int id , int valueE , int valueDD)
{
	machineType[id].cost->E =  ( (getCostEMachine(id) - valueE) <= getMinCostEMachine(id) ) ? getMinCostEMachine(id) : (getCostEMachine(id) - valueE);
	machineType[id].cost->DD =  ( (getCostDDMachine(id) - valueDD) <= getMinCostDDMachine(id) ) ? getMinCostDDMachine(id) : (getCostDDMachine(id) - valueDD);
}

void setEffectUpgradeCost(int id , int valueE , int valueDD)
{
	machineType[id].destructionCost->E = ( (getCostUpgradeEMachine(id) - valueE) <= getMinCostUpgradeEMachine(id) ) ? getMinCostUpgradeEMachine(id) : (getCostUpgradeEMachine(id) - valueE);
	machineType[id].destructionCost->DD = ( (getCostUpgradeDDMachine(id) - valueDD) <= getMinCostUpgradeDDMachine(id) ) ? getMinCostUpgradeDDMachine(id) : (getCostUpgradeDDMachine	(id) - valueDD);
}

void setEffectDestructionCost(int id , int valueE , int valueDD)
{
	machineType[id].destructionCost->E = ( (getCostDestructionEMachine(id) - valueE) <= getMinCostDestructionEMachine(id) ) ? getMinCostDestructionEMachine(id) : (getCostDestructionEMachine(id) - valueE);
	machineType[id].destructionCost->DD = ( (getCostDestructionEMachine(id) - valueDD) <= getMinCostDestructionEMachine(id) ) ? getMinCostDestructionEMachine(id) : (getCostDestructionEMachine(id) - valueDD);
}


void setEffectPersonnel(int id) 
{
	switch (id)
    {
		case 0:
			setEffectCost(1,10,1);
			break;			
		case 1:
			setEffectCost(2,3,1);
			break;	
		case 2:
			setEffectCost(3,8,1);
			break;
		case 3:
			setEffectCost(5,25,2);
			break;
		case 4:
			setEffectDestructionCost(4,5,5);
			break;	
		case 5:
			setEffectUpgradeCost(1,25,5);
			break;
		case 6:
			setEffectUpgradeCost(5,75,5);
			break;
		case 7:
			setEffectUpgradeCost(4,10,30);
			break;
		case 8:
			setEffectDestructionCost(1,3,10);
			break;
		case 9:
			setEffectDestructionCost(2,3,10);
			break;
		case 10:
			setEffectDestructionCost(3,3,10);
			break;
		case 11:
			setEffectDestructionCost(5,5,25);
			break;
		case 12:
			setEffectDestructionCost(4,5,10);
			break;
		case 13:
			playerStatut->ligozatSkillActived = true;
			//moitie des dechets de chaque case disparaissent
			break;
		case 14:
			fise->quantity += 20;
			fisa->quantity += 10;
			break;
		case 15:
			playerStatut->szafranskiSkillActived = true;
			//A chaque fois qu une ressource est envoyee a la porte, elle compte double. Le nombre de dechet produit est toujours de 1.
			break;
		case 16:
			playerStatut->thomasSkillActived += 1;
			//Quand un dechet quitte la porte, il a une chance sur 10 de disparaitre.
			break;
		case 17:
			fise->cost->E =  ( (fise->cost->E - 5) <= 5 ) ? 5 : (fise->cost->E - 5);
			fise->cost->DD =  ( (fise->cost->DD - 2) <= 2 ) ? 2 : (fise->cost->DD - 2);
			break;
		case 18:
			fisa->cost->E =  ( (fise->cost->E - 5) <= 5 ) ? 5 : (fise->cost->E - 5);
			fisa->cost->DD =  ( (fisa->cost->DD - 2) <= 2 ) ? 2 : (fisa->cost->DD - 2);
			break;
		case 19:
			lowerCostPersonnel();
			break;	
		case 20:
			fise->productE += 1;
			fise->productDD += 1;
			break;
		case 21:
			source1->delay =  ( (source1->delay - 1) <= 1 ) ? 1 : (source1->delay - 1);
			source2->delay =  ( (source2->delay - 1) <= 1 ) ? 1 : (source2->delay - 1);
			break;
		case 22:
			fisa->productE += 4;
			fisa->productDD += 4;
			break;
		case 23:
			if ( (fise->quantity < 10) &&  (fise->quantity > 0) )
			{
				int nbFise = fise->quantity;
				fise->quantity = fise->quantity - nbFise;
				porte->hasRessource += nbFise;
			}
			else if (fise->quantity > 0)
			{
				int nbFise = ( fise->quantity / 10 ) * 10;
				fise->quantity = fise->quantity - nbFise;
				porte->hasRessource += nbFise;
			}			
		
			if ( (fisa->quantity < 10)  &&  (fisa->quantity > 0) )
			{
				int nbFisa = fisa->quantity;
				fisa->quantity = fisa->quantity - nbFisa;
				porte->hasRessource += nbFisa;
			}
			else if (fisa->quantity > 0){
				int nbFisa = ( fisa->quantity / 10 ) * 10;
				fisa->quantity = fisa->quantity - nbFisa;
				porte->hasRessource += nbFisa;
			}
			break;
	}
}

void lowerCostPersonnel()
{
	 for (int id = 0; id < 23 ; id++)
	 {
		personnelData[id].cost->E += 1;
		personnelData[id].cost->E =  ( (getCostEPersonnel(id) - 50) <= 10 ) ? 10 : (getCostEPersonnel(id) - 50);
		personnelData[id].cost->DD =  ( (getCostDDPersonnel(id) - 20) <= 10 ) ? 10 : (getCostDDPersonnel(id) - 20);
	 }
}