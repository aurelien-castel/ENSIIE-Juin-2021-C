#pragma once // pour éviter que le header soit inclut plusieurs fois dans le projet

#include "structures.h"
#include "data_game.h"
#include "machine.h"

typedef struct Cost Cost;

typedef struct Personnel
{
    int id;
    char* name;
    char* firstName;
    Cost* cost;   
    char* descriptionSpe;
}Personnel;

int getCostDDPersonnel(int id);
int getCostEPersonnel(int id);
char* getNamePersonnel(int id);
char* getFirstNamePersonnel(int id);
char* getDescriptionSpe(int id);

void setEffectCost(int id , int valueE , int valueDD);
void setEffectUpgradeCost(int id , int valueE , int valueDD);
void setEffectDestructionCost(int id , int valueE , int valueDD);
void setEffectPersonnel(int id);

void lowerCostPersonnel();

