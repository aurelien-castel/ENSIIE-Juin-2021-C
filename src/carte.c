#include <stdio.h>
#include <stdlib.h>  // rand(), srand()
#include <time.h>    // time()
#include <stdio.h>
#include <stdbool.h> 
#include "../headers/carte.h" // inclusion de son fichier librairie .h qui permet aux autres .c du projet de savoir ce que contient notre .c actuel
#include "../headers/personnel.h"
#include "../headers/data_game.h"
//#include "../src/main.c"

/**
 * @brief réation de la Carte de taille n*n
 * 
 * @param n 
 * @return Carte* 
 */
Carte* createCarte(int n)
{

    int taille_Carte = -1; // taille de la Carte -1 par défaut

    if (n > 0) {

        taille_Carte = n; // récupération de la taille et on la met dans une variable gloable privée à Carte.c
    
    }
    else {

        taille_Carte = 4; // cas s'il y a une erreur

    }

    Case** map = (Case**) malloc(taille_Carte * sizeof(Case)); // chaque Case du tableau 2D contient une structure de type Carte

    int compteur_global_des_cases = 0;

    for (int i = 0; i < taille_Carte ; i++) // tableau 2D
    {
        map[i] = (Case*) malloc(taille_Carte * sizeof(Case));

        for (int j = 0; j < taille_Carte ; j++){

            //allocation mémoire coord
            Coordinates* coord = malloc(1 * sizeof(Coordinates));
            coord->x = j;
            coord->y = i;

            // initialisation
            map[i][j].coordinates = coord;
            map[i][j].numero_case = compteur_global_des_cases;

            // machine
            map[i][j].machine = malloc(1 * sizeof(Machine)); 
            map[i][j].machine->type = 0;
            map[i][j].machine->coordinates = coord; // la machine et la case ont la même coordonnée car une machine apportient à une case
            // map[i]->personnel = malloc(1 * sizeof(Personnel)); 
            map[i][j].machine->hasRessource = 0;
            map[i][j].machine->hasDechet = 0;
            map[i][j].machine->hasNewRessource = 0;
            map[i][j].machine->hasNewDechet = 0;
            map[i][j].machine->orientation = malloc(1 * sizeof(Direction));
            map[i][j].machine->orientation->down = false;
            map[i][j].machine->orientation->top = false;
            map[i][j].machine->orientation->right = false;
            map[i][j].machine->orientation->left = false;
            compteur_global_des_cases += 1;
        }  
    }

    Carte* les_infos_generales_de_la_carte = (Carte*) malloc(sizeof(Carte));

    les_infos_generales_de_la_carte->la_carte_du_jeu = map;
    les_infos_generales_de_la_carte->taille_carte = taille_Carte;
    return les_infos_generales_de_la_carte;

}

/**
 * @brief libération de la Carte 
 * 
 * @param infos_carte 
 */
void freeMemoryCarte(Carte* infos_carte)
{
    Case** la_carte_du_jeu = infos_carte->la_carte_du_jeu;
    int taille = infos_carte->taille_carte;

    if (taille != -1) { // si c'est -1 alors la taille de la Carte n'a pas encore assignée
        for (int i = 0; i < taille; i++) { // méthode pour free le tableau 2D
            free(la_carte_du_jeu[i]); // on free sur le malloc Case*
        }
        free(la_carte_du_jeu); // on free sur le malloc Case** 
        free(infos_carte); // on free sur le malloc Carte*
    }
}

int checkBorder(int i, Carte* carte){
    
    int truc = i;
    
    if(truc == 0){
        truc += 1;
    }else if (truc == carte->taille_carte - 1)
    {
        truc -= 1;
    }else if (truc > carte->taille_carte -1)
    {
        truc = carte->taille_carte/2 ; 
    }

    return truc;
}

void setEntreeSortie(Carte* carte){
    int entree1x = 0;
    int entree1y = 0;
    int entree2x = 0;
    int entree2y = 0;
    int sortiex = 0;
    int sortiey = 0;
    int taille = carte->taille_carte;
    __time_t t;

    srand((unsigned) time(&t));
    entree1x = rand() % taille;
    entree1y = rand() % taille;
    entree2x = rand() % taille;
    entree2y = rand() % taille;
    sortiex = rand() % taille;
    sortiey = rand() % taille;

    if (entree1x == entree2x && entree1y == entree2y)
    {
        entree2x += 2;
        entree2y += 2;
    }
    if (entree1x == sortiex && entree1y == sortiey)
    {
        sortiex -= 2;
        sortiey -= 2;
    }
    if (entree2x == sortiex && entree2y == sortiey)
    {
        sortiex += 2;
        sortiey += 2;
    }
    
    
    
       
    carte->la_carte_du_jeu[checkBorder(entree1y, carte)][checkBorder(entree1x, carte)].machine->type = 6;
    carte->la_carte_du_jeu[checkBorder(entree2y, carte)][checkBorder(entree2x, carte)].machine->type = 6;
    carte->la_carte_du_jeu[checkBorder(sortiey, carte)][checkBorder(sortiex,carte)].machine->type = 7;

    source1->coordinates->x = entree1x;
    source1->coordinates->y = entree1y;
    source2->coordinates->x = entree2x;
    source2->coordinates->y = entree2y;
    porte->coordinates->x = sortiex;
    porte->coordinates->y = sortiey;
}


// Augmenter le nombre de fise de 1
void createFise()
{
	fise->quantity += 1;
    printf(" le nombre de fise est maintenant de: %d\n",fise->quantity );
}

// Augmenter le nombre de fisa de 1
void createFisa()
{
	fisa->quantity += 1;
    printf(" le nombre de fisa est maintenant de: %d\n",fisa->quantity );
}


/**
 * @brief une fonction pour changer le type de ressource créée par les FISA
 * 
 */
void changeRessource()
{
    if(fisa->speciality=='D')
    {
        fisa->speciality='E';
    }
    else
    {
        fisa->speciality='D';
    }
}

/**
 * @brief ajout une machine si le budget le permet
 * 
 * @return machine* 
 */
void addMachine(Machine* machine)
{
    if(getCostDDMachine(1)<=playerStatut->DD && getCostEMachine(1)<=playerStatut->E)
    {
        initializeCreateMachine(machine); 
    }
}

/*
 * @brief ajout un personnel si le budget le permet
 * 
 * @return void 
 */
void addPersonnel(int id)
{
    if(getCostDDPersonnel(id)<=playerStatut->DD && getCostEPersonnel(id)<=playerStatut->E)
    {
        setEffectPersonnel(id);      
        playerStatut->DD =  playerStatut->DD - getCostDDPersonnel(id);
        playerStatut->E = playerStatut->E - getCostEPersonnel(id);
        printf("Vous avez bien recrute %s %s\n\n", getNamePersonnel(id), getFirstNamePersonnel(id));
    }
    else
    {
        printf("Vous n'avez pas assez d'argent\n");
    }
}

/*
 * @brief upgrade une Machine
 * 
 * @return void
 */
void upMachine(Machine* machine)
{
   if (canLevelUpMachine(machine) && getCostUpgradeDDMachine(machine->type)<=playerStatut->DD && getCostUpgradeEMachine(machine->type)<=playerStatut->E && machine->type != 0 && machine->type != 6 && machine->type != 7)
   {
        levelUpMachine(machine);
        playerStatut->DD = playerStatut->DD - getCostUpgradeDDMachine(machine->type);
        playerStatut->E = playerStatut->E - getCostUpgradeEMachine(machine->type);
        printf("Votre machine a bien ete amelioree.\n");
    }
    else
    {
        printf("/!\\ Vous n'avez pas assez de fonds pour améliorer la machine ou il n'y a pas de machine a la position indiquee\n\n");
    }
}

/*
 * @brief Detruit une Machine
 * 
 * @return void
 */
void destroyMachine(Machine* machine)
{
    if(getCostDestructionDDMachine(machine->type)<=playerStatut->DD && getCostDestructionEMachine(machine->type)<=playerStatut->E && machine->type != 0 && machine->type != 6 && machine->type != 7)
    {
        playerStatut->DD -= getCostDestructionDDMachine(machine->type);
        playerStatut->E -= getCostDestructionEMachine(machine->type);
        machine->type = 0;
    }
    else
    {
        printf("\n/!\\ Vous n'avez pas assez de fonds pour détruire la machine, ou il n'y a pas de machine a la case indiquee.\n\n");
    }
}

/*
 * @brief produit une ressource si besoin
 * 
 * @return void
 */
void activeSource(Carte* info_carte)
{
    printf("\n\n\n\n~~~~~~Activation des Sources~~~~~~" );
    if (source1->pending == source1->delay)
    {
        source1->pending = 1 ; 
        dropRessource(source1,info_carte,1);     
    }
    else
    {
        source1->pending += 1 ; 
    }

    if (source2->pending == source2->delay)
    {
        source2->pending = 1 ; 
        dropRessource(source2,info_carte,2);
    }
    else
    {
         source2->pending += 1 ; 
    }
}

/*
 * @brief indique sur quel case la ressource va tomber
 * 
 * @return void
 */
void dropRessource(Source* source, Carte* info_carte, int idSource)
{
    int x = source->coordinates->x;
    int y = source->coordinates->y;

    int sourceProduce = source->produce ;
    printf("\n\nSource %i (%i,%i) drop %i ressources\n" ,idSource ,x , y, sourceProduce);

    if(source->produce == 3)
    {
       int random =  rand() % 4;    

       switch (random)
       {
            //ne drop pas sur la case du haut
	        case 0:        
                sourceProduce -= checkCaseDropRessource(info_carte, x+1, y, sourceProduce,'l');            
   
                if(sourceProduce>0)
                {
                    sourceProduce -= checkCaseDropRessource(info_carte,x, y+1, sourceProduce,'d');    
                }

                if(sourceProduce>0)
                {
                    sourceProduce -= checkCaseDropRessource(info_carte,(x-1), y, sourceProduce,'r');    
                }                
                break;	

            //ne drop pas sur la case de droite
            case 1:
                sourceProduce -= checkCaseDropRessource(info_carte, x, y-1, sourceProduce,'t');            
   
                if(sourceProduce>0)
                {                     
                    sourceProduce -= checkCaseDropRessource(info_carte,x, y+1, sourceProduce,'d');    
                }

                if(sourceProduce>0)
                {
                    sourceProduce -= checkCaseDropRessource(info_carte,(x-1), y, sourceProduce,'l');    
                }              
                break;

            //ne drop pas sur la case du bas
            case 2:
                sourceProduce -= checkCaseDropRessource(info_carte, x, y-1, sourceProduce,'t');            
   
                if(sourceProduce>0)
                {                     
                    sourceProduce -= checkCaseDropRessource(info_carte, x+1, y, sourceProduce,'r');    
                }

                if(sourceProduce>0)
                {
                    sourceProduce -= checkCaseDropRessource(info_carte,(x-1), y, sourceProduce,'l');    
                }          
                break;

            //ne drop pas sur la case de gauche
            case 3:
                sourceProduce -= checkCaseDropRessource(info_carte, x, y-1, sourceProduce,'t');            
   
                if(sourceProduce>0)
                {                     
                    sourceProduce -= checkCaseDropRessource(info_carte, x+1, y, sourceProduce,'r');    
                }

                if(sourceProduce>0)
                {
                    sourceProduce -= checkCaseDropRessource(info_carte,x, y+1, sourceProduce,'d');    
                }              
                break;
        }     
    }
    else
    {
        sourceProduce -= checkCaseDropRessource(info_carte, x, y-1, sourceProduce, 't');            

        if(sourceProduce>0)
        {                     
            sourceProduce -= checkCaseDropRessource(info_carte, x+1, y, sourceProduce,'r');    
        }

        if(sourceProduce>0)
        {
            sourceProduce -= checkCaseDropRessource(info_carte,x, y+1, sourceProduce,'d');    
        }  

        if(sourceProduce>0)
        {
            sourceProduce -= checkCaseDropRessource(info_carte,(x-1), y, sourceProduce,'l');    
        }                
    }  

    if(sourceProduce>0)
    {
        printf("La source %i a laissé tomber %i ressource(s) \n",idSource, sourceProduce);
    }  
}

/*
 * @brief handle quand la ressource tombe 
 * x et y sont les coordonees de la case arrivé 
 * 
 * @return void
 */
int checkCaseDropRessource(Carte* info_carte , int x , int y,int sourceProduce, char direction )
{
    int sourceCapacityMachine;
    
    if( x<0 || y<0 || x > info_carte->taille_carte ||  y > info_carte->taille_carte )
    {
        return 0;
    }

    if( isAnEntryAvailable( direction, info_carte->la_carte_du_jeu[y][x].machine, false) )
    {
        switch (info_carte->la_carte_du_jeu[y][x].machine->type)
        {           
            case 1 :
                sourceCapacityMachine = (info_carte->la_carte_du_jeu[y][x].machine->collecteur->maxQuantity) - (info_carte->la_carte_du_jeu[y][x].machine->hasRessource);    
                break;    
            case 2 :
                sourceCapacityMachine = 1;
                break;   
            case 3 :
                sourceCapacityMachine = 1;
                break; 
             case 7:
                sourceCapacityMachine = 0;
                porte->hasRessource += 1;
                printf("La porte a recu une ressource");
                break;
            default :
                sourceCapacityMachine = 0;
        }  
    }else{
         sourceCapacityMachine = 0;
    }
 
    int minusSource;

    if(sourceCapacityMachine !=0)
    {
            minusSource = (sourceProduce - sourceCapacityMachine >= 0 ) ? (sourceProduce - sourceCapacityMachine >= 0) : 0 ;   
            
            info_carte->la_carte_du_jeu[y][x].machine->hasRessource += minusSource;

            if(info_carte->la_carte_du_jeu[y][x].machine->type == 3)
            {
                if(direction == 't' || direction == 'd')
                {
                    info_carte->la_carte_du_jeu[y][x].machine->croix->hasVRessource += minusSource;
                }
                else{
                    info_carte->la_carte_du_jeu[y][x].machine->croix->hasHRessource += minusSource;
                }
            }                  

            printf("case %i,%i (%s) recupere : %i ressources\n",x ,y, machineType[info_carte->la_carte_du_jeu[y][x].machine->type -1].name, minusSource);
    }
    else{
        minusSource = 0 ;
    }

    return minusSource;
}


/*
    verifie si la ressource ou dechet peut atterir sur la case arrive
    machine : la machine sur la case d'arrivé
    direction : la direction de sortie de la ressource au départ exemple : la source drop une ressource en haut d'elle meme donc la direction sera haut 
*/
bool isAnEntryAvailable(char direction , Machine* machine , bool isDechet)
{   
    if(machine->type == 0)
    {
        return false;
    }
    else if(machine->type == 1 || machine->type == 2 || machine->type == 3 )
    {
        switch (direction)
        {
            case 't' :         
                if(machine->orientation->down)
                {
                    return false;
                }        
                break;
            case 'r' :
                if(machine->orientation->left)
                {
                    return false;
                }        
                break;
            case 'd' :
                if(machine->orientation->top)
                {
                    return false;
                }        
                break;
            case 'l' :
                if(machine->orientation->right)
                {
                    return false;
                }        
                break;      
        }
        return true;
    }
    else if(machine->type == 4)
    {
        if(isDechet){return true;}else{return false;};
    }
    else if( machine->type == 5 && !isDechet )
    {
        return false;
    }
    else if(machine->type == 6)
    {
        return false;
    }   
    else if(machine->type == 7)
    {
        return true;
    }

    return false; 
    
}

/*
 * @brief Active les skills si necessaire 
 * @Entry ressources : Total des ressources ammene a la porte pour ce tour 
 * @return void
 */
void activeSkillPorte(int ressources, Carte* carte)
{
    int dechet = ressources;

    if (playerStatut->szafranskiSkillActived)
    {
        ressources += ressources;
    }

    playerStatut->ressourceStocked += ressources;

    if (playerStatut->thomasSkillActived != 0)
    { 
        printf("\nVous avez %i lancer(s) pour tenter de faire disparaitre vos dechets grâce à l'aptitude de Thomas" , playerStatut->thomasSkillActived);
        int chance =  rand() % 11;

        int i = 1 ;
        while(i <= playerStatut->thomasSkillActived)
        {
            if(10 == chance)
            {
                dechet = 0;
                printf(" Lancer %i : Bravo !", i);
                i = playerStatut->thomasSkillActived + 1;
            }else{
                printf(" Lancer %i : Perdu !", i);
                i++;
            }          
        }
    }
    porte->quantityDechet += dechet ;
    porte->hasRessource = 0;;

    if(playerStatut->ligozatSkillActived)
    {
        activeLigozatSkill(carte);
    }
}

/*
 * @brief active les dmg des dechets de la porte
 * 
 * @return void
 */
void damagePorte()
{
    playerStatut->DD += porte->quantityDechet * porte->damageDD ;
    printf("\n\nIl y a %i de dechet(s) stockés dans la porte . Vous prenez %i de dégat DD !", porte->quantityDechet , porte->quantityDechet * porte->damageDD );
}

/**
 * @brief Regarde pour chaque tapis si une ressource est présente ou non.
 * Si une autre machine est présente à son extrémité, la ressource lui est envoyée, sinon 
 * elle est détruite.
 * 
 * @param Carte carte
 */
void checkTapis(Carte* carte){
    // Premiere boucle, on bouge les ressources et on les met dans les nouvelles ressources dans autres 
    // machines adjacentes
    for(int i = 0; i < carte->taille_carte; i++){
        for (int j = 0; j < carte->taille_carte; j++)
        {
            if (carte->la_carte_du_jeu[i][j].machine->type == 2)
            {
               // printf("Tapis case, %d %d\n", carte->la_carte_du_jeu[i][j].coordinates->x,carte->la_carte_du_jeu[i][j].coordinates->y);
                if (carte->la_carte_du_jeu[i][j].machine->hasDechet > 0 || carte->la_carte_du_jeu[i][j].machine->hasRessource > 0)
                {
                    if (carte->la_carte_du_jeu[i][j].machine->orientation->top)
                    {
                       if (i != 0)
                       {
                            //printf("Orientation top, %d %d\n", carte->la_carte_du_jeu[i][j].coordinates->x,carte->la_carte_du_jeu[i][j].coordinates->y);
                            // printf("Orientation top, %d %d\n", carte->la_carte_du_jeu[i-1][j].coordinates->x,carte->la_carte_du_jeu[i-1][j].coordinates->y);
                            switch (carte->la_carte_du_jeu[i-1][j].machine->type)
                            {
                                // On ne prend pas en compte le collecteur car il n'a pas de ressource

                            // Tapis
                            case 2:
                                if (!carte->la_carte_du_jeu[i-1][j].machine->orientation->down)
                                {
                                    carte->la_carte_du_jeu[i-1][j].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                    carte->la_carte_du_jeu[i-1][j].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }else{
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }
                                break;
                            // Croix
                            case 3:
                                if (carte->la_carte_du_jeu[i-1][j].machine->orientation->top || carte->la_carte_du_jeu[i][j-i].machine->orientation->right)
                                {
                                    carte->la_carte_du_jeu[i-1][j].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                    carte->la_carte_du_jeu[i-1][j].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }else{
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }
                                break;
                            // Dechetterie
                            case 4:
                                carte->la_carte_du_jeu[i-1][j].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                carte->la_carte_du_jeu[i-1][j].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                break;
                            // Centre de recyclage
                            case 5:
                                if (!carte->la_carte_du_jeu[i-1][j].machine->orientation->down)
                                {
                                    carte->la_carte_du_jeu[i-1][j].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                    carte->la_carte_du_jeu[i-1][j].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }else{
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }
                                break;
                            default:
                                carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                break;
                            }  
                       }else{
                            carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                            carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                        }
                       
                    }else if(carte->la_carte_du_jeu[i][j].machine->orientation->right){
                        if (i != carte->taille_carte -1)
                        {
                            printf("Orientation top, %d %d\n", carte->la_carte_du_jeu[i][j].coordinates->x,carte->la_carte_du_jeu[i][j].coordinates->y);
                            printf("Orientation top, %d %d\n", carte->la_carte_du_jeu[i][j+1].coordinates->x,carte->la_carte_du_jeu[i-1][j].coordinates->y);
                            switch (carte->la_carte_du_jeu[i][j+1].machine->type)
                            {
                                // On ne prend pas en compte le collecteur car il n'a pas de ressource

                            // Tapis
                            case 2:
                                if (!carte->la_carte_du_jeu[i][j+1].machine->orientation->left)
                                {
                                    carte->la_carte_du_jeu[i][j+1].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                    carte->la_carte_du_jeu[i][j+1].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }else{
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }
                                break;
                            // Croix
                            case 3:
                                if (carte->la_carte_du_jeu[i][j+1].machine->orientation->down || carte->la_carte_du_jeu[i][j-i].machine->orientation->right)
                                {
                                    carte->la_carte_du_jeu[i][j+1].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                    carte->la_carte_du_jeu[i][j+1].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }else{
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }
                                break;
                            // Dechetterie
                            case 4:
                                carte->la_carte_du_jeu[i][j+1].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                carte->la_carte_du_jeu[i][j+1].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                break;
                            // Centre de recyclage
                            case 5:
                                if (!carte->la_carte_du_jeu[i][j+1].machine->orientation->left)
                                {
                                    carte->la_carte_du_jeu[i][j+1].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                    carte->la_carte_du_jeu[i][j+1].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }else{
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }
                                break;
                            default:
                                carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                break;
                            }  
                        }
                        else{
                            carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                            carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                        }
                        
                    }else if(carte->la_carte_du_jeu[i][j].machine->orientation->down){
                        if (i != carte->taille_carte - 1)
                        {
                            printf("Orientation top, %d %d\n", carte->la_carte_du_jeu[i][j].coordinates->x,carte->la_carte_du_jeu[i][j].coordinates->y);
                            printf("Orientation top, %d %d\n", carte->la_carte_du_jeu[i+1][j].coordinates->x,carte->la_carte_du_jeu[i-1][j].coordinates->y);
                            switch (carte->la_carte_du_jeu[i+1][j].machine->type)
                            {
                                // On ne prend pas en compte le collecteur car il n'a pas de ressource

                            // Tapis
                            case 2:
                                if (!carte->la_carte_du_jeu[i+1][j].machine->orientation->top)
                                {
                                    carte->la_carte_du_jeu[i+1][j].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                    carte->la_carte_du_jeu[i+1][j].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }else{
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }
                                break;
                            // Croix
                            case 3:
                                if (carte->la_carte_du_jeu[i+1][j].machine->orientation->down || carte->la_carte_du_jeu[i][j-i].machine->orientation->left)
                                {
                                    carte->la_carte_du_jeu[i+1][j].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                    carte->la_carte_du_jeu[i+1][j].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }else{
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }
                                break;
                            // Dechetterie
                            case 4:
                                carte->la_carte_du_jeu[i+1][j].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                carte->la_carte_du_jeu[i+1][j].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                break;
                            // Centre de recyclage
                            case 5:
                                if (!carte->la_carte_du_jeu[i+1][j].machine->orientation->top)
                                {
                                    carte->la_carte_du_jeu[i+1][j].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                    carte->la_carte_du_jeu[i+1][j].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }else{
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }
                                break;
                            default:
                                carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                break;
                            }  
                        }else{
                            carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                            carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                        }
                        
                    }else if(carte->la_carte_du_jeu[i][j].machine->orientation->left){
                        if (i != 0)
                        {
                                printf("Orientation top, %d %d\n", carte->la_carte_du_jeu[i][j].coordinates->x,carte->la_carte_du_jeu[i][j].coordinates->y);
                            printf("Orientation top, %d %d\n", carte->la_carte_du_jeu[i][j-1].coordinates->x,carte->la_carte_du_jeu[i-1][j].coordinates->y);
                            switch (carte->la_carte_du_jeu[i][j-1].machine->type)
                            {
                                // On ne prend pas en compte le collecteur car il n'a pas de ressource

                            // Tapis
                            case 2:
                                if (!carte->la_carte_du_jeu[i][j-1].machine->orientation->right)
                                {
                                    carte->la_carte_du_jeu[i][j-1].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                    carte->la_carte_du_jeu[i][j-1].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }else{
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }
                                break;
                            // Croix
                            case 3:
                                if (carte->la_carte_du_jeu[i][j-1].machine->orientation->top || carte->la_carte_du_jeu[i][j-i].machine->orientation->left)
                                {
                                    carte->la_carte_du_jeu[i][j-1].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                    carte->la_carte_du_jeu[i][j-1].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }else{
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }
                                break;
                            // Dechetterie
                            case 4:
                                carte->la_carte_du_jeu[i][j-1].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                carte->la_carte_du_jeu[i][j-1].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                break;
                            // Centre de recyclage
                            case 5:
                                if (!carte->la_carte_du_jeu[i][j-1].machine->orientation->right)
                                {
                                    carte->la_carte_du_jeu[i][j-1].machine->hasNewRessource += carte->la_carte_du_jeu[i][j].machine->hasRessource;
                                    carte->la_carte_du_jeu[i][j-1].machine->hasNewDechet += carte->la_carte_du_jeu[i][j].machine->hasDechet;
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }else{
                                    carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                    carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                }
                                break;
                            default:
                                carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                                carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                                break;
                            }  
                        }else{
                            carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                            carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                        }
                        
                    }else{
                        carte->la_carte_du_jeu[i][j].machine->hasDechet = 0;
                        carte->la_carte_du_jeu[i][j].machine->hasRessource = 0;
                    }
                    
                }
                
            }
            
        }      
    }

    //Deuxieme boucle, on met toutes les ressources reçues dans les ressources actuelles
    for (int i = 0; i < carte->taille_carte; i++)
    {
        for (int j = 0; j < carte->taille_carte; j++)
        {
            if (carte->la_carte_du_jeu[i][j].machine->type != 0 && carte->la_carte_du_jeu[i][j].machine->type !=1)
            {
                carte->la_carte_du_jeu[i][j].machine->hasRessource += carte->la_carte_du_jeu[i][j].machine->hasNewRessource;
                carte->la_carte_du_jeu[i][j].machine->hasDechet += carte->la_carte_du_jeu[i][j].machine->hasNewDechet;
                carte->la_carte_du_jeu[i][j].machine->hasNewDechet = 0;
                carte->la_carte_du_jeu[i][j].machine->hasNewRessource = 0;
            }
        }   
    } 
}


/**
 * @brief Regarde pour chaque tapis si une ressource est présente ou non.
 * Si une autre machine est présente à son extrémité, la ressource lui est envoyée, sinon 
 * elle est détruite.  ------OBSOLETE (je pensais que les ressources sur les tapis arrivaient directement vers la fin de sa course)
 * 
 * @param Carte carte
 */
void activeTapis(Carte* carte)
{
    for(int i = 0; i < carte->taille_carte; i++)
    {
        for (int j = 0; j < carte->taille_carte; j++)
        {
            if (carte->la_carte_du_jeu[i][j].machine->type == 2 || carte->la_carte_du_jeu[i][j].machine->type == 3 )
            {
                Machine* machine = carte->la_carte_du_jeu[i][j].machine;

                bool hasDechet = machine->hasDechet > 0 ? true : false;
                bool hasRessource = machine->hasRessource > 0 ? true : false;          

                if(machine->type == 2)
                {
                    Coordinates* nextCase = getNextCase(machine,carte); 

                    if(hasRessource)
                    {
                        continueMove(carte,machine,machine->hasRessource,nextCase,false,getOrientation(machine));
                        machine->hasRessource = 0;
                    }
                    if (hasDechet)
                    {
                        continueMove(carte,machine,machine->hasDechet,nextCase,true,getOrientation(machine));
                        machine->hasDechet = 0;
                    }            
                }
                if(machine->type == 3)
                {
                    if (machine->croix->hasHRessource > 0)
                    {
                        Coordinates* nextCase = getCroixOrientationNextCase(machine,'h'); 
                        continueMove(carte,machine,machine->croix->hasHRessource,nextCase,false,getOrientationCroix(machine,'h'));
                        machine->hasRessource -= machine->croix->hasHRessource;
                        machine->croix->hasHRessource = 0;
                    }
                    if(machine->croix->hasVRessource > 0)
                    {
                        Coordinates* nextCase = getCroixOrientationNextCase(machine,'v');
                        continueMove(carte,machine,machine->croix->hasVRessource,nextCase,false,getOrientationCroix(machine,'v'));
                        machine->hasRessource -= machine->croix->hasVRessource;
                        machine->croix->hasVRessource = 0;
                    }
                    if (machine->croix->hasHDechet > 0)
                    {
                        Coordinates* nextCase = getCroixOrientationNextCase(machine,'h'); 
                        continueMove(carte,machine,machine->croix->hasHDechet,nextCase,true,getOrientationCroix(machine,'h'));
                        machine->hasDechet -= machine->croix->hasHDechet;
                        machine->croix->hasHDechet = 0;
                    }
                    if(machine->croix->hasVDechet > 0)
                    {
                        Coordinates* nextCase = getCroixOrientationNextCase(machine,'v');
                        continueMove(carte,machine,machine->croix->hasVDechet,nextCase,true,getOrientationCroix(machine,'v'));
                        machine->hasDechet -= machine->croix->hasVDechet;
                        machine->croix->hasVDechet = 0;
                    }                     
                }
                
            }    
        }
    }
}



/**
* @brief Resultat du mouvement de materiel effectué
*machine ici est la machine a l' arrivee ------OBSOLETE (je pensais que les ressources sur les tapis arrivaient directement vers la fin de sa course)
*/
void dealMouvementTapis(Carte* carte, Machine* machine,int quantity , bool isDechet,char direction,bool isTapisMouvement)
{
    Coordinates* nextCase;

    switch (machine->type)
    {
    case 1:
        if(isDechet)
        {
            machine->hasDechet += quantity;
            printf("\n**** Le collecteur a recu %i dechet(s)" , quantity );  
        }else{
            machine->hasRessource += quantity;
            printf("\n**** Le collecteur a recu %i ressources(s)" , quantity );
        }
        break;
    case 2:
        if(isTapisMouvement)
        {
            nextCase = getNextCase(machine,carte); 
            continueMove(carte, machine, quantity,nextCase, isDechet,getOrientation(machine));
        }
        else{
             if(isDechet)
            {
                machine->hasNewDechet = quantity;
            }
            else{
                machine->hasNewRessource = quantity;
            }
        }         
        break;
    case 3:
        if(isTapisMouvement)
        {
            if (direction == 'r' || direction == 'l' )
            {
                nextCase = getCroixOrientationNextCase(machine,'h');
                continueMove(carte,machine,quantity,nextCase,isDechet,getOrientationCroix(machine,'h'));     
            }
            else
            {
                nextCase =getCroixOrientationNextCase(machine,'v');
                continueMove(carte,machine,quantity,nextCase,isDechet,getOrientationCroix(machine,'v'));
            }
        }
        else{
            if(isDechet)
            {
                machine->hasNewDechet = quantity;
            }
            else{
                 machine->hasNewRessource = quantity;
            }
        }
        break;
    case 4:
        if(isDechet)
        {
            if(machine->dechetterie->quantity + quantity <= machine->dechetterie->maxQuantity)
            {
                machine->dechetterie->quantity += quantity; 
                printf("\n**** Dechetterie stocke %i dechet(s)" , quantity ); 
                printf("\n**** Dechetterie : il reste encore %i place(s) encore disponible" , machine->dechetterie->maxQuantity - machine->dechetterie->quantity );         
            }
            else
            {
                int dechetStock =  machine->dechetterie->maxQuantity - machine->dechetterie->quantity;
                machine->dechetterie->quantity += dechetStock; 
                printf("\n**** Dechetterie stocke %i dechet(s) -> La dechetterie est rempli" , dechetStock );

                porte->quantityDechet +=  quantity - dechetStock;
                printf("\n**** %i a été transporté jusqu'à la porte" , quantity - dechetStock ); 
            }
        }
        break;
    case 5:
            if(machine->recyclage->quantity + quantity <= machine->recyclage->maxQuantity)
            {
                machine->recyclage->quantity += quantity; 
                printf("\n**** Recyclage stocke %i dechet(s)" , quantity ); 
                printf("\n**** Recyclage : il reste encore %i place(s) encore disponible" , machine->recyclage->maxQuantity - machine->recyclage->quantity );        
            }
            else
            {
                int dechetStock =  machine->recyclage->maxQuantity - machine->recyclage->quantity;
                machine->recyclage->quantity += dechetStock; 
                printf("\n**** Recyclage stocke %i dechet(s) -> Recyclage est rempli" , dechetStock );

                porte->quantityDechet +=  quantity - dechetStock;
                printf("\n**** %i a été transporté jusqu'à la porte" , quantity - dechetStock ); 
            }
        break;
    case 7 :
        if(isDechet)
        {
            porte->quantityDechet += quantity;
            printf("\n**** La porte a recu %i dechet(s) \nJe crois que vous avez mal compris le but du jeu :)" , quantity );  
        }else{
            porte->hasRessource += quantity;
            printf("\n**** La porte  a recu %i ressources(s)" , quantity );
        }
       break;
    default:
        break;
    }
}

/**
* @brief Resultat du mouvement de materiel effectué
*machine : ici est la machine a l' arrivee.
*quantity :  de materiel
*isDechet : si c'est dechet
*direction :  de la case de depart vers la case d arrivé
*isTapisActive : si la fonction est appele depuis laction des tapis ou actionnement des machines 
*/
void dealMouvement(Machine* machine,int quantity , bool isDechet,char direction,bool isTapisActive)
{
    switch (machine->type)
    {
    case 1:
        if(isDechet)
        {
            if(machine->hasDechet + quantity <= machine->collecteur->maxQuantity)
            { 
                printf("\n     Collecteur(%i,%i) stocke %i dechets(s)" ,machine->coordinates->x ,machine->coordinates->y, quantity ); 
                machine->hasDechet += quantity; 
                printf("\n     Collecteur : il reste encore %i place(s) encore disponible" , machine->collecteur->maxQuantity - machine->hasDechet );
                                
            }else{
                int dechetStock =  machine->collecteur->maxQuantity - machine->hasDechet;
                machine->hasDechet += dechetStock; 
                printf("\n     Collecteur(%i,%i) stocke %i dechet(s) -> Collecteur est rempli" ,machine->coordinates->x ,machine->coordinates->y, dechetStock );
                porte->quantityDechet += quantity - dechetStock;
                printf("\n      %i dechet(s) renvoye a la porte !" , quantity - dechetStock );
            }
        }else{
            if(machine->hasRessource + quantity <= machine->collecteur->maxQuantity)
            {
                machine->hasRessource += quantity; 
                printf("\n     Collecteur(%i,%i) stocke %i ressource(s)" ,machine->coordinates->x ,machine->coordinates->y, quantity ); 
                printf("\n     Collecteur : il reste encore %i place(s) encore disponible" , machine->collecteur->maxQuantity - machine->hasRessource );  
            }else{
                int ressourceStock =  machine->collecteur->maxQuantity - machine->hasRessource;
                machine->hasRessource += ressourceStock; 
                printf("\n     Collecteur(%i,%i) stocke %i ressource(s) -> Collecteur est rempli" ,machine->coordinates->x ,machine->coordinates->y, ressourceStock );
                printf("\n      %i ressource(s) est donc tombe" , quantity - ressourceStock );
            }
        }
        break;
    case 2:
        if(isTapisActive)
        {
            if(isDechet)
            {
                printf("\n      Le tapis(%i,%i) a recu %i dechet(s)" ,machine->coordinates->x,machine->coordinates->y,  quantity ); 
                machine->hasNewDechet += quantity;
            }
            else{
                 printf("\n     Le tapis(%i,%i) a recu %i ressources(s)" ,machine->coordinates->x,machine->coordinates->y, quantity ); 
                machine->hasNewRessource += quantity;
            }
        }
        else{
            if(isDechet)
            {
                machine->hasDechet += quantity;
                printf("\n     Le tapis(%i,%i) a recu %i dechet(s)" ,machine->coordinates->x,machine->coordinates->y,  quantity ); 
            }
            else{
                machine->hasRessource += quantity;
                 printf("\n     Le tapis(%i,%i) a recu %i ressources(s)" ,machine->coordinates->x,machine->coordinates->y, quantity ); 
            }
        }         
        break;
    case 3:
        if (direction == 'r' || direction == 'l' )
        {
            if(isTapisActive)
            {
                if(isDechet)
                {
                    machine->croix->hasNewHDechet += quantity;
                    printf("\n     La croix(%i,%i) a recu %i dechet(s)" ,machine->coordinates->x,machine->coordinates->y, quantity ); 
                }
                else{
                    machine->croix->hasNewHRessource += quantity;
                    printf("\n     La croix(%i,%i) a recu %i ressources(s)" ,machine->coordinates->x,machine->coordinates->y, quantity ); 
                }
            }
            else{
                if(isDechet)
                {
                    machine->croix->hasHDechet += quantity;
                    machine->hasDechet += quantity;
                    printf("\n     La croix(%i,%i) a recu %i dechet(s)" ,machine->coordinates->x,machine->coordinates->y, quantity ); 
                }
                else{
                    machine->croix->hasHRessource += quantity;
                    machine->hasRessource += quantity;
                    printf("\n     La croix(%i,%i) a recu %i ressources(s)" ,machine->coordinates->x,machine->coordinates->y, quantity ); 
                }
            }         
        } 
        else{
             if(isTapisActive)
            {
                if(isDechet)
                {
                    machine->croix->hasNewVDechet += quantity;
                    printf("\n     La croix(%i,%i) a recu %i dechet(s)" ,machine->coordinates->x,machine->coordinates->y, quantity ); 
                }
                else{
                    machine->croix->hasNewVRessource += quantity;
                    printf("\n     La croix(%i,%i) a recu %i ressources(s)" ,machine->coordinates->x,machine->coordinates->y, quantity ); 
                }
            }
            else{
                if(isDechet)
                {
                    machine->croix->hasVDechet += quantity;
                    machine->hasDechet += quantity;
                    printf("\n     La croix(%i,%i) a recu %i dechet(s)" ,machine->coordinates->x,machine->coordinates->y, quantity ); 
                }
                else{
                    machine->croix->hasVRessource += quantity;
                    machine->hasRessource += quantity;
                    printf("\n     La croix(%i,%i) a recu %i ressources(s)" ,machine->coordinates->x,machine->coordinates->y, quantity ); 
                }
            }    
        }     
        break;
    case 4:
        if(isDechet)
        {
            if(machine->dechetterie->quantity + quantity <= machine->dechetterie->maxQuantity)
            {
                machine->dechetterie->quantity += quantity; 
                printf("\n     Dechetterie stocke %i dechet(s)" , quantity ); 
                printf("\n     Dechetterie : il reste encore %i place(s) encore disponible" , machine->dechetterie->maxQuantity - machine->dechetterie->quantity );         
            }
            else
            {
                int dechetStock =  machine->dechetterie->maxQuantity - machine->dechetterie->quantity;
                machine->dechetterie->quantity += dechetStock; 
                printf("\n     Dechetterie stocke %i dechet(s) -> La dechetterie est rempli" , dechetStock );

                porte->quantityDechet +=  quantity - dechetStock;
                printf("\n      %i a été transporté jusqu'à la porte" , quantity - dechetStock ); 
            }
        }
        break;
    case 5:
            if(machine->recyclage->quantity + quantity <= machine->recyclage->maxQuantity)
            {
                machine->recyclage->quantity += quantity; 
                printf("\n     Recyclage stocke %i dechet(s)" , quantity ); 
                printf("\n     Recyclage : il reste encore %i place(s) encore disponible" , machine->recyclage->maxQuantity - machine->recyclage->quantity );        
            }
            else
            {
                int dechetStock =  machine->recyclage->maxQuantity - machine->recyclage->quantity;
                machine->recyclage->quantity += dechetStock; 
                printf("\n     Recyclage stocke %i dechet(s) -> Recyclage est rempli" , dechetStock );

                porte->quantityDechet +=  quantity - dechetStock;
                printf("\n     %i a été transporté jusqu'à la porte" , quantity - dechetStock ); 
            }
        break;
    case 7 :
        if(isDechet)
        {
            porte->quantityDechet += quantity;
            printf("\n     La porte a recu %i dechet(s) \nJe crois que vous avez mal compris le but du jeu :)" , quantity );  
        }else{
            porte->hasRessource += quantity;
            printf("\n     La porte  a recu %i ressources(s)" , quantity );
        }
       break;
    default:
        break;
    }
}


/*
*
*Fonction qui verifie la case suite du mouvement 
*machine : machine sur la case de depart 
*quantité de materiel qui arrive
*next case : coord de la case d'arrivé
*isDechet : si le materiel est un dechet ou ressources
*char : direction d ou le materiel va allé 
 *------OBSOLETE (je pensais que les ressources sur les tapis arrivaient directement vers la fin de sa course)
* 
*/
void continueMove(Carte* carte, Machine* machine,int quantity ,Coordinates* nextCase, bool isDechet,char direction)
{
    if(nextCase->x != -1)
    {
        Machine* machineDarrive = carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine;
        printf("\n**** Continue dans le nouvement" );  

        bool isEntryOk = false;

        if(machine->type == 2)
        {
            isEntryOk = isAnEntryAvailable(direction,machineDarrive, false);
        }
        else if(machine->type == 3)
        {
            isEntryOk = isAnEntryAvailable(direction,machineDarrive, false);
        }
        

        printf("\n**** isEntryOk , %i" , isEntryOk); 

        if (!isDechet)
        {           
            if(isEntryOk)
            {
                dealMouvementTapis(carte, machineDarrive, quantity ,false, direction,true);
            }
            else
            {     
                printDrop(false, quantity,machineDarrive->coordinates->x,machineDarrive->coordinates->y);
            }
        }
        else
        {
            if(isEntryOk)
            {
                dealMouvementTapis(carte, machineDarrive, quantity, true, direction,true);
            }
             else
            {
                printDrop(true, quantity,machineDarrive->coordinates->x,machineDarrive->coordinates->y);
            }
        }
    }
    else{
        printDropEnDehorsDelaMap(isDechet,quantity);
    }

}

/**
* @brief Active les machines une a une pour le endTurn et appel la fonction correspondant a la machine
*
*/
void activeMachine(Carte* carte)
{
    printf("\n\n\n\n^^^^^^ Activation des machines ^^^^^^");

    for(int i = 0; i < carte->taille_carte; i++)
    {
        for (int j = 0; j < carte->taille_carte; j++)
        {
            switch (carte->la_carte_du_jeu[i][j].machine->type)
            {
                case 1:
                    printf("\n----Collecteur (%i,%i)", j , i );
                    dealCollecteur(carte->la_carte_du_jeu[i][j].machine,carte);
                    break;
                case 5:
                    printf("\n----Recyclage (%i,%i)", j , i );
                    dealRecyclage(carte->la_carte_du_jeu[i][j].machine,carte);
                    break;               
                default:
                    break;
            }
        }
    }
}

/**
 * @brief Activation des tapis ou des croix une a une 
 * 
 * @param Carte carte
 */
void activeTapisPourDeVrai(Carte* carte)
{
    printf("\n\n------ Activation des tapis ------");

    for(int i = 0; i < carte->taille_carte; i++)
    {
        for (int j = 0; j < carte->taille_carte; j++)
        {
            if(carte->la_carte_du_jeu[i][j].machine->type == 2)
            {           
                Machine* machine = carte->la_carte_du_jeu[i][j].machine;
                bool hasDechet = machine->hasDechet > 0 ? true : false;
                bool hasRessource = machine->hasRessource > 0 ? true : false;
                            
                if(hasDechet)
                {
                    printf("\n\n**** Activation tapis (%i,%i) pour deplacer dechet(s)\n\n" , machine->coordinates->x ,machine->coordinates->y); 
                    Coordinates* nextCase = getNextCase(machine,carte);
                    if(nextCase->x != -1)
                    {
                        if(isAnEntryAvailable(getOrientation(machine),carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,true))
                        {
                            dealMouvement(carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,machine->hasDechet,true,getOrientation(machine),true);
                        }
                        else{
                            printDrop(true,machine->hasDechet,nextCase->x,nextCase->y);
                        }
                    }
                    else{
                        printDropEnDehorsDelaMap(true,machine->hasDechet);
                    }
                    machine->hasDechet = 0;    
                }

                if(hasRessource)
                {
                    printf("\n\n**** Activation tapis (%i,%i) pour deplacer ressource(s)" , machine->coordinates->x ,machine->coordinates->y); 

                    Coordinates* nextCase = getNextCase(machine,carte);
                    if(nextCase->x != -1)
                    {
                        if(isAnEntryAvailable(getOrientation(machine),carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,false))
                        {
                            dealMouvement(carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,machine->hasRessource,false,getOrientation(machine),true);
                        }
                        else{
                            printDrop(false,machine->hasDechet,nextCase->x,nextCase->y);
                        }
                    }
                    else{
                        printDropEnDehorsDelaMap(false,machine->hasDechet);
                    }
                    machine->hasDechet = 0;        
                }
            }    
            
            if(carte->la_carte_du_jeu[i][j].machine->type == 3)
            {
                Machine* machine = carte->la_carte_du_jeu[i][j].machine;

                if (machine->croix->hasHRessource > 0)
                {
                    printf("\n\n**** Activation croix (%i,%i) pour deplacer ressource(s) dans le sens horizontal", machine->coordinates->x ,machine->coordinates->y); 
                    Coordinates* nextCase = getCroixOrientationNextCase(machine,'h'); 
        
                    if(nextCase->x != -1)
                    {
                        if(isAnEntryAvailable(getOrientationCroix(machine,'h'),carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,false))
                        {
                            dealMouvement(carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,machine->croix->hasHRessource,false,getOrientationCroix(machine,'h'),true);
                        }
                        else{
                            printDrop(false,machine->croix->hasHRessource,nextCase->x,nextCase->y);
                        }
                    }
                    machine->hasRessource -= machine->croix->hasHRessource;
                    machine->croix->hasHRessource = 0;
                }
                if(machine->croix->hasVRessource > 0)
                {
                    printf("\n\n**** Activation croix (%i,%i) pour deplacer ressource(s) dans le sens vertical", machine->coordinates->x ,machine->coordinates->y); 
                    Coordinates* nextCase = getCroixOrientationNextCase(machine,'v'); 
        
                    if(nextCase->x != -1)
                    {
                        if(isAnEntryAvailable(getOrientationCroix(machine,'v'),carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,false))
                        {
                            dealMouvement(carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,machine->croix->hasVRessource,false,getOrientationCroix(machine,'v'),true);
                        }
                        else{
                            printDrop(false,machine->croix->hasVRessource,nextCase->x,nextCase->y);
                        }
                    }
                    machine->hasRessource -= machine->croix->hasVRessource;
                    machine->croix->hasVRessource = 0;
                }
                if (machine->croix->hasHDechet > 0)
                {
                    printf("\n\n**** Activation croix (%i,%i) pour deplacer dechet(s) dans le sens horizontal", machine->coordinates->x ,machine->coordinates->y);                     
                    Coordinates* nextCase = getCroixOrientationNextCase(machine,'h'); 
        
                    if(nextCase->x != -1)
                    {
                        if(isAnEntryAvailable(getOrientationCroix(machine,'h'),carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,false))
                        {
                            dealMouvement(carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,machine->croix->hasHDechet,false,getOrientationCroix(machine,'h'),true);
                        }
                        else{
                            printDrop(true,machine->croix->hasHDechet,nextCase->x,nextCase->y);
                        }
                    }
                    machine->hasDechet -= machine->croix->hasHDechet;
                    machine->croix->hasHDechet = 0;

                }
                if(machine->croix->hasVDechet > 0)
                {
                    printf("\n\n**** Activation croix (%i,%i) pour deplacer dechet(s) dans le sens vertical", machine->coordinates->x ,machine->coordinates->y);  
                    Coordinates* nextCase = getCroixOrientationNextCase(machine,'v'); 
        
                    if(nextCase->x != -1)
                    {
                        if(isAnEntryAvailable(getOrientationCroix(machine,'v'),carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,false))
                        {
                            dealMouvement(carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,machine->croix->hasVDechet,false,getOrientationCroix(machine,'v'),true);
                        }
                        else{
                            printDrop(true,machine->croix->hasVDechet,nextCase->x,nextCase->y);
                        }
                    }
                    machine->hasDechet -= machine->croix->hasVDechet;
                    machine->croix->hasVDechet = 0;
                }            
            } 
        }
    }

    for(int i = 0; i < carte->taille_carte; i++)
    {
        for (int j = 0; j < carte->taille_carte; j++)
        {
            if(carte->la_carte_du_jeu[i][j].machine->type == 2)
            {
                carte->la_carte_du_jeu[i][j].machine->hasRessource += carte->la_carte_du_jeu[i][j].machine->hasNewRessource;
                carte->la_carte_du_jeu[i][j].machine->hasDechet += carte->la_carte_du_jeu[i][j].machine->hasNewDechet;
                carte->la_carte_du_jeu[i][j].machine->hasNewRessource = 0 ;
                carte->la_carte_du_jeu[i][j].machine->hasNewDechet = 0 ;
            }
            if(carte->la_carte_du_jeu[i][j].machine->type == 3)
            {
                Machine* machine = carte->la_carte_du_jeu[i][j].machine;

                machine->croix->hasHRessource += machine->croix->hasNewHRessource;
                machine->hasRessource += machine->croix->hasNewHRessource;
                machine->croix->hasNewHRessource = 0 ;

                machine->croix->hasVRessource += machine->croix->hasNewVRessource;
                machine->hasRessource += machine->croix->hasNewVRessource;
                machine->croix->hasNewVRessource = 0 ;

                machine->croix->hasVDechet += machine->croix->hasNewVDechet;
                machine->hasDechet += machine->croix->hasNewVDechet;
                machine->croix->hasNewVDechet = 0;

                machine->croix->hasHDechet += machine->croix->hasNewHDechet;
                machine->hasDechet += machine->croix->hasNewHDechet;
                machine->croix->hasNewHDechet = 0;
            }
        }
    }
}


/**
* @brief Fonction qui permet au collecteur de bouger ou non le materiel qu'il a stocké
*machine : machine sur qui on va effucté laction
*
*/
void dealCollecteur(Machine* machine, Carte* carte)
{
    if(machine->hasDechet>0)
    {
        Coordinates* nextCase = getNextCase(machine,carte);
        if(nextCase->x != -1)
        {
            if(isAnEntryAvailable(getOrientation(machine),carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,true))
            {
                dealMouvement(machine,machine->hasDechet,true,getOrientation(machine),false);
            }
            else{
                printDrop(true,machine->hasDechet,nextCase->x,nextCase->y);
            }
        }
        else{
            printDropEnDehorsDelaMap(true,machine->hasDechet);
        }
        machine->hasDechet = 0;        
    }
    if(machine->hasRessource>0)
    {
        Coordinates* nextCase = getNextCase(machine,carte);
        if(nextCase->x != -1)
        {
             if(isAnEntryAvailable(getOrientation(machine),carte->la_carte_du_jeu[nextCase->y][nextCase->x].machine,true))
            {
                dealMouvement(machine,machine->hasRessource,false,getOrientation(machine),false);
            }
            else{
                printDrop(false,machine->hasRessource,nextCase->x,nextCase->y);
            }
        }
        else{
            printDropEnDehorsDelaMap(true,machine->hasRessource);
        }
         machine->hasRessource = 0;    
    }
}



/**
* @brief Fonction qui permet au recyclage de s'activer
*machine : machine sur qui on va effucté laction
*
*/
void dealRecyclage(Machine* machine, Carte* carte)
{
    if( machine->recyclage->quantity > 10)
    {
        int nbRessourceProduce = ( machine->recyclage->quantity / 10 );
        int nbDechetMinus = ( machine->recyclage->quantity / 10 )*10;
        
        printf("\n     Recyclage(%i,%i) : %i dechet(s) recyclés", machine->coordinates->x, machine->coordinates->y, nbDechetMinus);   
        printf("\n     Recyclage(%i,%i) : %i ressources(s) produit", machine->coordinates->x, machine->coordinates->y, nbRessourceProduce);   
        
        machine->recyclage->quantity -= nbDechetMinus;
    
        Coordinates* nextCase = getNextCase(machine,carte);
        
        if(nextCase->x != -1)
        {
            if(isAnEntryAvailable(getOrientation(machine),machine,true))
            {
                dealMouvement(machine,nbRessourceProduce,false,getOrientation(machine),false);
            }
            else{
                printDrop(false,nbRessourceProduce,nextCase->x,nextCase->y);
            }
        }
        else{
            printDropEnDehorsDelaMap(true,nbRessourceProduce);
        }
        printf("\n     Recyclage(%i,%i) : il y a encore %i dechet(s) stockés", machine->coordinates->x, machine->coordinates->y, machine->recyclage->quantity);   


    }
}

/**
* @brief Chaque tour on peut recuperer les dechets de la porte
*
*/
void dropDechetPorte(Carte* carte)
{
    printf("\n\n\n\n------ Activation drop dechet porte ------");

    int x = porte->coordinates->x;
    int y = porte->coordinates->y;
   
    if ( (y-1) >=0 && (y-1) < carte->taille_carte )
    {
        if(carte->la_carte_du_jeu[y-1][x].machine->type == 1)
        {
            dealMouvement(carte->la_carte_du_jeu[y-1][x].machine,1,true,'v',false);
        }
    }
    if ( (x+1) >= 0 && (x+1) < carte->taille_carte)
    {
        if(carte->la_carte_du_jeu[y][x+1].machine->type == 1)
        {
            dealMouvement(carte->la_carte_du_jeu[y][x+1].machine,1,true,'h',false);
        }
    }
    if ( (y+1) >=0 && (y+1) < carte->taille_carte)
    {
        if(carte->la_carte_du_jeu[y+1][x].machine->type == 1)
        {
            dealMouvement(carte->la_carte_du_jeu[y+1][x].machine,1,true,'v',false);
        }
    }
    if ( (x-1) >=0 && (x-1) < carte->taille_carte)
    {
         if(carte->la_carte_du_jeu[y][x-1].machine->type == 1)
        {
            dealMouvement(carte->la_carte_du_jeu[y][x-1].machine,1,true,'h',false);
        }
    }
}




/**
 * @brief Skill de Ligozat : Pour chaque dechetterie ou centre de recyclage, on divise la quantité
 * de dechets de la machine par 2, mais egalement la quantité de déchet de la porte par 2
 * 
 * @param carte
 */
void activeLigozatSkill(Carte* carte)
{
    for (int i = 0; i < carte->taille_carte; i++)
    {
        for (int j = 0; j < carte->taille_carte; j++)
        {
            if (carte->la_carte_du_jeu[i][j].machine->type == 4 || carte->la_carte_du_jeu[i][j].machine->type == 5)
            {
                carte->la_carte_du_jeu[i][j].machine->hasDechet /= 2;
                porte->quantityDechet /= 2;
            }
        }   
    }
    porte->quantityDechet /=2;
}

/**
 * @brief Verifie chaque recyclage pour savoir si il va  infliger des degats ou non
 * 
 * @param carte
 */
void damageRecyclage(Carte* carte)
{
    for (int i = 0; i < carte->taille_carte; i++)
    {
        for (int j = 0; j < carte->taille_carte; j++)
        {
            if (carte->la_carte_du_jeu[i][j].machine->type == 5)
            {   
                playerStatut->DD = carte->la_carte_du_jeu[i][j].machine->recyclage->quantity * carte->la_carte_du_jeu[i][j].machine->recyclage->damageDD ;
                printf("\n\nIl y a %i de dechet(s) stockés dans le Recyclage(%i,%i) . Vous prenez %i de dégat DD !", carte->la_carte_du_jeu[i][j].machine->recyclage->quantity,carte->la_carte_du_jeu[i][j].machine->coordinates->x,carte->la_carte_du_jeu[i][j].machine->coordinates->y,carte->la_carte_du_jeu[i][j].machine->recyclage->quantity * carte->la_carte_du_jeu[i][j].machine->recyclage->damageDD);             
            }
        }   
    }
}

/**
 * @brief Active les skills des fise et fisa
 * 
 * @param carte
 */
void activeSkillEleve()
{
    int DDProduce = fise->quantity * fise->productDD ;
    int EProduce = fise->quantity * fise->productE ;
    printf("\n\n\n\nVous avez %i FISE qui ont produit : %i DD et %i E ! ",fise->quantity ,DDProduce, EProduce);
    playerStatut->DD += DDProduce;
    playerStatut->E += EProduce;

    if(fisa->pending == fisa->delay)
    {   
        fisa->pending = 1;
        if(fisa->speciality == 'D')
        {
            DDProduce = fisa->quantity * fisa->productDD ;
            printf("\n\nVous avez %i FISA qui ont produit : %i DD ! ",fisa->quantity ,DDProduce);
            playerStatut->DD += DDProduce;
        }else{
            EProduce = fisa->quantity * fisa->productE ;
            printf("\n\nVous avez %i FISA qui ont produit : %i E ! ",fisa->quantity ,EProduce);
            playerStatut->E += EProduce;
        }
    }
    else{
       fisa->pending++;
    }
}

/*
 * @briefAppel toute les fonctions necessaire pour finir un tour
 * 
 * @return void
 */
void endTurn(Carte* carte)
{   
    printf("\n\n+++++++ Fin du tour %i +++++++++++++++++++++ \n",playerStatut->round );

    activeTapisPourDeVrai(carte);
    activeSource(carte);
    activeMachine(carte);
    damageRecyclage(carte);
    activeSkillPorte(porte->hasRessource,carte);
    dropDechetPorte(carte);
    activeSkillEleve();
    damagePorte();
    
    playerStatut->round += 1 ;

    printf("\n\n\n\n++++++++++++++++++++++++++++++++++++++++\n\n");
}
