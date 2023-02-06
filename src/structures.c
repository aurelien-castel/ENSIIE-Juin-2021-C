#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include "../headers/structures.h"
#include "../headers/machine.h"

/**
 * @brief Fonction qui va créer une liste chainée en l'initialisant a null
 * 
 * @return une liste vide de type Liste
 */
Liste *initialisation()
{
    Liste *liste = (Liste*) malloc(sizeof(Liste));
    Element *element = (Element*) malloc(sizeof(Element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

/**
 * @brief Fonction qui va ajouter nvNombre au début de la liste donnée en paramètre
 * pour se faire, on va créer un nouvel espace de stockage pour nvNombre, puis le lui attribuer
 * a la suite de cela, on l'insert en début de liste, puis on le fait pointer vers son successeur
 * qui est l'actuel premier élément de la liste
 * 
 * @param liste
 * @param nvNombre
 */
void insertion(Liste *liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

/**
 * @brief Fonction qui supprimer le premier élément de la liste passée en paramètre
 * on va d'abord vérifier que la liste n'est pas null, auquel cas on lance une erreur
 * puis on vérifie que que la liste n'est pas vide, sinon il n'y aurait rien a faire
 * enfin, on change la tête de la liste qui devient le prédecesseur de la tête actuelle
 * puis on supprime l'ancienne tête.
 *
 */
void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

/**
 * @brief Fonction qui va permettre d'afficher la liste et son contenu
 *
 */
void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}