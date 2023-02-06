#pragma once // pour éviter que le header soit inclut plusieurs fois dans le projet

#include <stdio.h> // TODO: supprimer ces trois lignes
#include <stdlib.h>
#include <string.h>

#include "carte.h"
#include "structures.h"
#include "machine.h"
#include "data_game.h"

/**
 * @brief Demande à l'utilisateur la taille de carte qu'il désire
 * 
 * @return int 
 */
int size_map();

/**
 * @brief Fonction qui va afficher la carte en fonction de la taille indiquée par l'utilisateur
 * 
 * @param infos_carte 
 */
void print_map(Carte* infos_carte);

/**
 * @brief Demande au joueur l'action qu'il veut effectuer 
 * 
 * @return int
 */
int set_action();

/**
 * @brief Fonction qui permet au joueur de selectionner le type de machine qu'il souhaite ajouter
 * 
 * @return machine
 */
void add_machine(Carte* carte);

/**
 * @brief Fonction qui permet à l'utilisateur de rentrer les infos nécessaire à la sélection d'une machine sur la carte.
 * 
 * @return Machine
 */
Machine* select_machine();

/**
 * @brief Fonction qui permet à l'utilisateur d'indiquer l'action qu'il souhaite effectuer sur la machine 
 * qu'il va selectionner: amélioration, suppression.
 * 
 * @return int
 */
int select_action();

/**
 * @brief Fonction qui permet au joueur de selectionner un membre du personnel. Un tableau lui est proposé, qui présente tout les membres ainsi que leurs fonctions
 * 
 * @return int 
 */
int select_staff();

/**
 * @brief Fonction affiche un message d'erreur si l'utilisateur n'a pas assez d'argent
 *
 * 
 */
void p_error();

void printDropEnDehorsDelaMap(bool isDechet,int quantity);
void printDrop(bool isDechet,int quantity, int x, int y);