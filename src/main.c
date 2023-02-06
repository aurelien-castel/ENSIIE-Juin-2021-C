#include <stdio.h>
#include <stdlib.h>
#include "../headers/interface.h"
#include "../headers/carte.h"
#include "../headers/personnel.h"
#include "../headers/structures.h"
#include "../headers/machine.h"
#include "../headers/data_game.h"

// gcc -Wall -Wextra -std=c99
// gcc -Wall -Wextra -std=c99 main.c -o main.o

/**
 * @brief main
 * 
 * @return int 
 */
int main()
{
    initializeGame();

    /**
     * @brief initialisation
     * 
     */
    int sizeMap = size_map(); // demande à l'utilisateur ce qu'il veut comme taille de carte
    Carte* infos_carte = createCarte(sizeMap); // création de la carte (mémoire déjà alloué)
    setEntreeSortie(infos_carte); // on définit de manière aléatoire la source et la porte

    /**
     * @brief boucle principale du jeu
     * 
     */
    while(playerStatut->ressourceStocked < 10000){ // un jeu avec des tours

        print_map(infos_carte); // affichage de la carte TODO
        int choix_action = set_action(); // on demande ce que le joueur veut faire
        // Coordinates* coord = malloc(sizeof(Coordinates)); // allocation mémoire pour les coordonnées souhaitées TODO à enlever ?

        switch(choix_action){
            case 0: 
                endTurn(infos_carte); // terminer le tours
                break;
            case 1:
                createFise(); // ajouter FISE
                break;
            case 2:
                createFisa(); // ajouter FISA
                break;
            case 3:
                changeRessource("ressource"); 
                break;
            case 4: ;

                int choix_action_machine = select_action(); // selection action machine
                switch(choix_action_machine){
                    case 0: 
                        //Machine* newMachine = add_machine();
                        add_machine(infos_carte);  // ajouter une machine
                        break;
                    case 1: 
                        upMachine(select_machine(infos_carte)); // modification de la machine
                        break;
                    case 2:
                        destroyMachine(select_machine(infos_carte)); // destruction de la machine
                        break;
                }
                break;
            case 5:
                addPersonnel(select_staff()); 
                break;
            case 6:
                exit(0);
                break;    
            default:
                printf("Erreur");
                break;
        }      
    }

    if (playerStatut->ressourceStocked == 10000)
    {
        printf("Bravo vous avez gagne !!!!!\n");
    }
    

    /**
     * @brief destruction de la carte à la fin du jeu
     * 
     */
    freeMemoryCarte(infos_carte);
    freeData();

    return 0;
}