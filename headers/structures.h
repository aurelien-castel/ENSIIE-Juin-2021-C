#pragma once // pour éviter que le header soit inclut plusieurs fois dans le projet

#include <stdlib.h>
#include <stdbool.h> 
#include "machine.h"
#include "personnel.h"

typedef struct Machine Machine; // structures.h a besoins de machine.h https://stackoverflow.com/questions/3768966/c-recursive-header-file-inclusion-problem
typedef struct Personnel Personnel;


// Position en x , position en y
typedef struct Coordinates{
	int x;
	int y;
} Coordinates;

typedef struct Case{
    Coordinates* coordinates;
    int numero_case;
    //a delete
    /*bool is_case_sortie;
    bool is_case_entree;*/
    Machine* machine;
} Case;

// E : Cout en E;
// DD: Cout en DD; 
typedef struct Cost
{
    int E;
    int DD;
}Cost;

typedef struct Direction{
    bool top;
    bool right;
    bool down;
    bool left;  
}Direction;

// Création de liste chainée

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

/**
 * @brief Fonction qui va créer une liste chainée en l'initialisant a null
 * 
 * @return une liste vide de type Liste
 */
Liste *initialisation();

/**
 * @brief Fonction qui va ajouter nvNombre au début de la liste donnée en paramètre
 * pour se faire, on va créer un nouvel espace de stockage pour nvNombre, puis le lui attribuer
 * a la suite de cela, on l'insert en début de liste, puis on le fait pointer vers son successeur
 * qui est l'actuel premier élément de la liste
 * 
 * @param liste
 * @param nvNombre
 */
void insertion(Liste *liste, int nvNombre);

/**
 * @brief Fonction qui supprimer le premier élément de la liste passée en paramètre
 * on va d'abord vérifier que la liste n'est pas null, auquel cas on lance une erreur
 * puis on vérifie que que la liste n'est pas vide, sinon il n'y aurait rien a faire
 * enfin, on change la tête de la liste qui devient le prédecesseur de la tête actuelle
 * puis on supprime l'ancienne tête.
 *
 */
void suppression(Liste *liste);

/**
 * @brief Fonction qui va permettre d'afficher la liste et son contenu
 *
 */
void afficherListe(Liste *liste);