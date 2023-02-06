#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/interface.h" // inclusion de son fichier librairie .h qui permet aux autres .c du projet de savoir ce que contient notre .c actuel
#include "../headers/carte.h"
#include "../headers/structures.h"
#include "../headers/machine.h"
#include "../headers/data_game.h"
#include "../headers/personnel.h"

/**
 * @brief bloque le joueur et lui demande un nombre dans une intervalle
 * 
 * @return int 
 */
int choice(int min, int max){

    int answer;
    char temp;

    printf("===================================================\n");
    printf("= Entrez votre choix avec un chiffre entre %d et %d =\n", min, max);

    printf("> ");    
    
    scanf("%d", &answer);
    scanf("%c", &temp);

    while (!((answer >= min)&&(answer <= max))) { // statut invalide
        printf("= Désolé ce n'est pas un bon input, réésayez:\n");
        printf("> ");
        scanf("%d", &answer);
        scanf("%c", &temp);
    }
    printf("= Vous avez demandé %d\n", answer);  

    printf("==================================================\n");

    return answer;

}

/**
 * @brief Demande à l'utilisateur la taille de carte qu'il désire
 * 
 * @return int 
 */
int size_map(){

    int answer;

    printf("\n");
    printf("Choisir la taille de la grille:\n1: 10\n2: 20\n3: 30\n");
    switch(choice(1, 3)){
        case 1: answer = 10;
                break;
        case 2: answer = 20;
                break;
        case 3: answer = 30;
                break;
    }

    return answer;

}

/**
 * @brief Fonction qui va afficher la carte en fonction de la taille indiquée par l'utilisateur
 * 
 * @param infos_carte 
 */
void print_map(Carte* infos_carte){ 
    
    Case** la_carte_du_jeu = infos_carte->la_carte_du_jeu;
    int taille = infos_carte->taille_carte;

    printf("Tour numero %d\n", playerStatut->round);
    printf("Vous avez %d E et %d DD.\n",playerStatut->E, playerStatut->DD);
    if (fisa->speciality == 'E')
    {
        printf("Ressources des FISA: E\n");
    }else{
        printf("Ressources des FISA: DD\n");
    }
    printf("Nombre de ressources: %d/10.000\n",playerStatut->ressourceStocked);
    // Haut des cases
    for (int i = 0; i < taille; i++){
        if (i == 0) {
            printf(" ____");
        }
        else {
            printf("____");
        }
    }

    printf("\n");

    // Contour et intérieur des cases
    // En fonction du type de machine présente dans la case, on affiche un caractère correspondant

    for (int i = 0; i < taille; i++){

        for(int j = 0; j < taille; j++){
            switch (la_carte_du_jeu[i][j].machine->type){
                case 0: printf("|_ ");
                                      
                        break;
                case 1: if(la_carte_du_jeu[i][j].machine->orientation->top ){
                            printf("|_⥣");
                        }else if(la_carte_du_jeu[i][j].machine->orientation->down){
                            printf("|_⥥");
                        }else if(la_carte_du_jeu[i][j].machine->orientation->right){
                            printf("|_⥤");
                        }else{
                            printf("|_⥢");
                        }  
                        break;
                case 2: if(la_carte_du_jeu[i][j].machine->orientation->top ){
                            printf("|_↑");
                        }else if(la_carte_du_jeu[i][j].machine->orientation->down){
                            printf("|_↓");
                        }else if(la_carte_du_jeu[i][j].machine->orientation->right){
                            printf("|_→");
                        }else{
                            printf("|_←");
                        }
                        break;
                case 3: printf("|_+");
                        break;
                case 4: printf("|_D");
                        break;
                case 5: printf("|_R");
                        break;
                case 6: printf("|_S");        
                        break;
                case 7: 
                        printf("|_P");             
                        break;
            }
            if (j == taille - 1){ 
                printf("_|\n");
            } else {
                printf("_");
            }
        }

    }
     // On indique à l'utilisateur la relation entre les symboles et les machines
    printf("\nSignification des symboles:\n⥥: Collecteur\t↑→↓←: Tapis\n+: Croix\tD: Dechetterie\tR: Centre de recyclage\nS: Source\tP: Porte\n");
    printf("case: %d", la_carte_du_jeu[5][5].machine->type);

}



/**
 * @brief Demande au joueur l'action qu'il veut effectuer 
 * 
 * @return int 
 */
int set_action(){

    printf("\n");

    printf("Faites votre choix:\n");
    printf("0: Fin du tour\n");
    printf("1: Recruter un ou plusieurs eleve(s) FISE\n");
    printf("2: Recruter un ou plusieurs eleve(s) FISA\n");
    printf("3: Changer le type de ressource créée par les FISA\n");
    printf("4: Action machine\n");
    printf("5: Action personnel\n");
    //printf("6: Faire avancer les ressources\n");
    printf("6: Quitter le jeu\n");

    return choice(0, 6);
}

/**
 * @brief Fonction qui permet au joueur de selectionner le type de machine qu'il souhaite ajouter
 * 
 * @return machine
 */
void add_machine(Carte* carte){ 
    int t;
    int dir;
    int x = 0;
    int y = 0;
    int taille = carte->taille_carte;
    Case** carte2D = carte->la_carte_du_jeu;
    Machine* m;
    bool good = false;

    // Position de la machine
    printf("Choisissez la position x de votre machine\n");
    printf("\n");
    x = choice(0, (taille-1));
    printf("Choisissez la position y de votre machine\n");
    printf("\n");
    y = choice(0, (taille-1));

    // Selectionne le type de machine
    printf("Selectionnez un type de machine: \n");
    printf("1: Collecteur, cout: E= %d DD= %d\n", machineType[0].cost->E, machineType[0].cost->DD);
    printf("2: Tapis, cout: E= %d DD= %d\n", machineType[1].cost->E, machineType[1].cost->DD);
    printf("3: Croix, cout: E= %d DD= %d\n", machineType[2].cost->E, machineType[2].cost->DD);
    printf("4: Dechetterie, cout: E= %d DD= %d\n", machineType[3].cost->E, machineType[3].cost->DD);
    printf("5: Centre recyclage, cout: E= %d DD= %d\n", machineType[4].cost->E, machineType[4].cost->DD);
    printf("\n");
    t = choice(1, 5);

    
    if(getCostDDMachine(t)<=playerStatut->DD && getCostEMachine(t)<=playerStatut->E){

        if(carte2D[y][x].machine->type == 0)
        {
            m = carte2D[y][x].machine;
            good = true;
        }
        if (good == true)
        {
            m->type = t;

            if(t != 4)
            {
                // Orientation de la machine
                printf("Choisissez l'orientation:\n");
                printf("1: Haut\n");
                printf("2: Droite\n");
                printf("3: Bas\n");
                printf("4: Gauche\n");
                printf("\n");
                dir = choice(1, 4);

                char d1 ;

                switch (dir)
                {
                case 1:
                    m->orientation->top = true;
                    d1 = 'v';
                    break;
                case 2:
                    m->orientation->right = true;
                    d1 = 'h';
                    break;
                case 3:
                    m->orientation->down = true;
                    d1 = 'v';
                    break;
                case 4:
                    m->orientation->left = true;
                    d1 = 'h';
                    break;
                default:
                    printf("erreur direction machine");
                    break;
        
                }

                //Si la machine est une croix on demandera une deuxieme orientation 
                if(t == 3 )
                {
                    printf("Choisissez la deuxieme orientation:\n");
                    if (d1 == 'v')
                    {                   
                        printf("1: Gauche\n");
                        printf("2: Droite\n");    
                    }
                    else
                    {
                        printf("1: Bas\n");
                        printf("2: Haut\n");
                    
                    }
                    printf("\n");     

                    dir = choice(1, 2);

                    switch (dir)
                    {
                    case 1:
                        if(d1 == 'v')
                        {
                            m->orientation->left = true;
                        }
                        else{
                            m->orientation->down = true;
                        }
                        break;
                    case 2:
                        if(d1 == 'v')
                        {
                            m->orientation->right = true;
                        }
                        else{
                             m->orientation->top = true;
                        }
                        break;
                    default:
                        printf("erreur direction machine");
                        break;
                    }
                }     
            }


            initializeCreateMachine(m);
            playerStatut->DD -= getCostDDMachine(m->type);
            playerStatut->E -= getCostEMachine(m->type);
            printf("\nVotre machine a bien ete cree a la position (%d,%d)\n",x,y);
        }else{
            printf("/!\\ La case est deja occupee\n\n");
        }
           
    }else{
        printf("/!\\ Vous n'avez pas assez de fonds pour creer la machine\n\n");
    }
}




/**
 * @brief Fonction qui permet à l'utilisateur de rentrer les infos nécessaire à la sélection d'une machine sur la carte.
 * 
 * @return Machine
 */

Machine* select_machine(Carte* carte){
    
    int taille = carte->taille_carte;
    int x = 0;
    int y = 0;
    Case** carte2D = carte->la_carte_du_jeu;
    


    // Position de la machine
    printf("Choisissez la position x de votre machine\n");
    printf("\n");
    x = choice(0, (taille-1));
    printf("Choisissez la position y de votre machine\n");
    printf("\n");
    y = choice(0, (taille-1));

    Machine* m;
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            if (x == carte2D[i][j].coordinates->x && y == carte2D[i][j].coordinates->y)
            {
                if(carte2D[i][j].machine->type > 0){
                    m = carte2D[i][j].machine;
                }else{
                    m->type = 0;
                }
            }
            
        }
        
    }

    return m;
}


/**
 * @brief Fonction qui permet à l'utilisateur d'indiquer l'action qu'il souhaite effectuer sur une machine 
 * qu'il va selectionner: amélioration, suppression.
 * 
 * @return int
 */
int select_action(){

    printf("\n");

    printf("Quelle action voulez vous effectuer ?\n");
    printf("0: Ajouter une machine.\n");
    printf("1: Ameliorer la machine.\n");
    printf("2: Supprimer la machine.\n");
    return choice(0,2);
}


/**
 * @brief Fonction qui permet au joueur de selectionner un membre du personnel. Un tableau lui est proposé, qui présente tout les membres ainsi que leurs fonctions
 * 
 * @return int 
 */
int select_staff(){ // TODO 12/04 on prend un pointeur sur case et on ajoute un personnel cf struct case

    // une_case->personnel // exemple récupération information de la case

    printf("\n");

    int staff;
    printf("Choisissez un membre de l\'ecole\n");
    for (int i = 1; i < 24; i++)
    {
        printf("%2d: %12s %12s, E: %4d, DD: %4d, Description: %s\n",i,getNamePersonnel(i), getFirstNamePersonnel(i), getCostEPersonnel(i), getCostDDPersonnel(i), getDescriptionSpe(i));
    }
    
    staff = choice(1,24);
    return staff;
}

/**
 * @brief Fonction affiche un message d'erreur si l'utilisateur n'a pas assez d'argent
 *
 * 
 */
void p_error(){
    printf("Vous n'avez pas assez de ressources");
}

void printDropEnDehorsDelaMap(bool isDechet,int quantity)
{
    if(isDechet)
    {
        printf("\n**** %i Dechets(s) Tombé en dehors de la map" , quantity );
    }
    else{
        printf("\n**** %i Ressources(s) Tombé en dehors de la map" , quantity );
    }   
}

/*
 * 
 * 
 */
void printDrop(bool isDechet,int quantity, int x, int y)
{
    if(isDechet)
    {
        printf("\n     %i Dechets(s) Tombé par terre sur la case (%i,%i)" , quantity ,x,y);
    }
    else{
        printf("\n     %i ressource(s) Tombé par terre sur la case (%i,%i)" , quantity,x,y);
    }  
   
}