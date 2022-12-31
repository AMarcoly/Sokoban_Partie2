#ifndef _SDL2_H
#define _SDL2_H

#pragma once

#include "../install_dir/include/SDL2/SDL.h"
#include "grid.h"

/**
 * @brief typedef de la structure SDLContext
 * 
 */
typedef struct SDLContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width;
  int height;
} SDLContext;

/**
 * @brief typedef de l'enumeration des evenements
 * 
 */
typedef enum event{
  quit,
  left, 
  right,
  up,
  down,
  none,
} Event;



/* @brief 
 * Initialise une variable global `context` de type SDLContext
 *
 * Si il y a erreur pendant l'intialisation:
 *  context.window = NULL
 *  ou 
 *  context.renderer = NULL
 *
 * Les deux cas sont à testé !
 * 
 */
void sdl_init();
/**
 * nettoie la variable global context 
 */
void sdl_quit();

/**
 * @brief Fonction qui affiche le jeu en SDL2
 * 
 * @param grid 
 */
void display_sdl2(Grid * grid);

/**
 * @brief fonction qui recupere un evenement clavier sur sdl2
 * 
 * @return Event 
 */
Event event_sdl2();

/**
 * @brief fonction ecouteur d'evenements sur console / eviter les inclusions multiples
 * 
 * @return Event 
 */
Event event();
#endif
