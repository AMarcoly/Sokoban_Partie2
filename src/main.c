/**
 * @file main.c
 * @author Marcoly ANTOINE/ Adrien GAME
 * @brief Fichier principal 
 * @version 0.1
 * @date 2022-11-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../include/grid.h"
#include "../include/player.h"
#include "../include/sdl2.h"

/**
 * @brief Fonction principale du programme
 * 
 * @return int : la sortie du programme
 */
 
int main(int argc, char * argv[]){
	
	bool modesdl2 = false; // 
	bool run = true; //booléen pour conditionner l'arrêt de la boucle principale
	printf("Bienvenue dans le jeu sokoban\nTaper q + Entrer pour quitter\n");
	printf("Déplacements : h = gauche , j = bas, k = haut , l = droite , r = recommencer le jeu\n");	
	Grid grid;
	init_level("level1.txt",&grid);
	
	void(*handle_display)(Grid * grid)=NULL;
	Event (*handle_event)()=NULL;

	//
	Event entry;

	if(argc<=1){
		//cas par defaut, on ouvre la console
		handle_display=&display;
		handle_event=&event;

	}
	else{
		if(!strcmp(argv[1],"--console")){
			handle_display=&display;
			handle_event=&event;
		}
		else if(!strcmp(argv[1],"--sdl2")){
			sdl_init();
			handle_display=&display_sdl2;
			handle_event=&event_sdl2;
			modesdl2=true;
		}
	}

	handle_display(&grid);
	while(run){
		if(equal_point(&grid)){
			run=false;
			printf("VOUS AVEZ GAGNE! FELICITATIONS!\n");
		}
		
		entry=handle_event();
		switch(entry){
			case quit : {
				run = false;
				
				break;
			}
			case right:
			{
				move_player(&grid,Right);
				handle_display(&grid);
				break;
			} 
			case left: {
				move_player(&grid,Left);
				handle_display(&grid);
				break;
			} 
			case up: 
			{
				move_player(&grid,Top);
				handle_display(&grid);
				break;
			} 
			case down:
			{
				move_player(&grid,Bottom);
				handle_display(&grid);
				break;
			} 
			default:{  
				break;
			}	
		}//fin switch	
	}
	if(modesdl2)
		sdl_quit();
		
	suppr_grid(&grid);
}

