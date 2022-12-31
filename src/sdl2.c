#include "../include/sdl2.h"

//variable declare globalement
SDLContext context;
/**
 * @brief fonction qui initialise la fenetre sdl
 * @param 
 */
void sdl_init() {
  int const width = 1280;
  int const height = 720;
  context = (SDLContext){NULL, NULL, .width = 0, .height = 0};
  if (SDL_Init(SDL_INIT_VIDEO)) {
    return;
  }

  SDL_Window *window =
      SDL_CreateWindow("Sokoban", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
  if (!window) {
    return;
  }
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  context = (SDLContext){
      .window = window, .renderer = renderer, .width = width, .height = height};
}

/**
 * @brief fonction permettant de quitter l'affichage sdl
 * 
 */
void sdl_quit() {
  SDL_DestroyWindow(context.window);
  SDL_DestroyRenderer(context.renderer);
  context.window = NULL;
  context.renderer = NULL;
  SDL_Quit();
}


/**
 * @brief fonction affichant la grille en mode sdl
 * 
 * @param grid 
 */
void display_sdl2(Grid * grid){
  int width_square=0; //largeur un rectangle
  int height_square=0;  //hauteur un rectangle
  width_square = context.width / grid->column_number;  //nombre de rectangle en largeur
  height_square = context.height / grid->row_number; //nombre de rectangle en longueur

  SDL_SetRenderDrawColor(context.renderer, 126, 126, 126, 255); // couleur grise
  SDL_RenderClear(context.renderer); // On dessine toute la fenêtre en gris 
  SDL_Rect rect = {    .x = 0,
                            .y = 0,
                            .w = width_square,
                            .h = height_square
                        };
  for (int i =0; i<grid->row_number;i++){
		for (int j = 0; j < grid->column_number; j++)
		{ 	
			if(i==grid->player.y && j==grid->player.x){
					SDL_SetRenderDrawColor(context.renderer, 0, 0, 255, 255); // on choisit la couleur bleue
          SDL_RenderFillRect(context.renderer, &rect); // On dessine le rectangle
			}
			else{
        if(grid->game_grid[i][j]==WALL){
          	SDL_SetRenderDrawColor(context.renderer, 211, 84, 0, 255); // on choisit la couleur rouge
          	SDL_RenderFillRect(context.renderer, &rect); // On dessine le rectangle
        }//fin if
        if(grid->game_grid[i][j]==BOX){
          	SDL_SetRenderDrawColor(context.renderer, 255, 0, 0, 255); // on choisit la couleur rouge
          	SDL_RenderFillRect(context.renderer, &rect); // On dessine le rectangle
        }//fin if
        if(grid->game_grid[i][j]==GOAL){
          	SDL_SetRenderDrawColor(context.renderer, 0, 255, 0, 255); // on choisit la couleur rouge
          	SDL_RenderFillRect(context.renderer, &rect); // On dessine le rectangle
        }//fin if
      }//fin 2eme boucle
      rect.x+=width_square;
    }//fin 1er boucle
    rect.x=0;
    rect.y+=height_square;
  }
  SDL_RenderPresent(context.renderer); // On affiche tout
}

/**
 * @brief 
 * 
 * @return Event 
 */
Event event_sdl2(){
  SDL_Event ev; //variable ev
  Event e=none;//variable e 

  SDL_WaitEvent(&ev);//attends clique au clavier

  if(ev.type==SDL_QUIT)
    e=quit;
  else if(ev.type==SDL_KEYDOWN){
    switch(ev.key.keysym.sym)
    {
      case SDLK_UP:
        e=up;
          break;
      case SDLK_LEFT:
        e=left;
          break;
      case SDLK_DOWN:
        e=down;
          break;
      case SDLK_RIGHT:
        e=right;
         break;
      default:
        e=none;
        break;
    }
  }
  return e;
}

Event event(){
char caractere=fgetc(stdin);
Event e;  //initialisation ecouteur d'evenements

  switch(caractere){
    case 'q':
      e=quit;
        break;
    case 'k':
      e=up;
        break;
    case 'j':
      e=down;
        break;
    case 'h':
      e=left;
        break;
    case 'l':
      e=right;
        break;
    default:
      e=none;

  }
  return e;
}
