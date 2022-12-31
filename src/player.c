/**
 * @file player.c
 * @author Marcoly ANTOINE/ Adrien GAME
 * @brief code pour le joueur
 * @version 0.1
 * @date 2022-11-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/player.h"
#include "../include/grid.h"
#include <stdio.h>
#include <stdbool.h>

//CaseType tmp;   //Variable nous permettant de gerer les buts

/**
 * @brief Fonction permettant de deplacer le joueur dans la grille de jeu 
 * 
 * @param grid pointeur sur grille de jeu
 * @param direction la direction dans laquelle on se deplace
 * 
 */
 //precondition : si une boite arrive sur un point on ne doit plus le bouger
void move_player(Grid* grid, enum Direction direction){
    ///position x,y actuelle du joueur
    int x = grid->player.x; 
    int y = grid->player.y; 

    switch(direction){
        case Right :
            {
                if(grid->game_grid[y][x+1]==NONE || grid->game_grid[y][x+1]==GOAL){
                    grid->player.x++;
                }
                else if( 
                    grid->game_grid[y][x+1]== BOX && grid->game_grid[y][x+2]==NONE){
                    grid->game_grid[y][x+1]=NONE;
                    grid->game_grid[y][x+2]=BOX;
                    grid->player.x++;
                }else if ( 
                    grid->game_grid[y][x+1]== BOX && grid->game_grid[y][x+2]==GOAL){
                    grid->game_grid[y][x+1]=NONE;
                    grid->game_grid[y][x+2]=BOX;
                    grid->player.x++;
                    grid->pts_cibles_recouverts++;
                }

            }
            break;
        case Left :
        {
            if(grid->game_grid[y][x-1]==NONE || grid->game_grid[y][x-1]==GOAL){
                    grid->player.x--;
            }
            else if( 
                    grid->game_grid[y][x-1]== BOX && grid->game_grid[y][x-2]==NONE){
                    grid->game_grid[y][x-1]=NONE;
                    grid->game_grid[y][x-2]=BOX;
                    grid->player.x--;
            }else if ( 
                grid->game_grid[y][x-1]== BOX && grid->game_grid[y][x-2]==GOAL){
                grid->game_grid[y][x-1]=NONE;
                grid->game_grid[y][x-2]=BOX;
                grid->player.x--;
                grid->pts_cibles_recouverts++;
            }
        } 
            break;
        case Top:
        {
            if((grid->game_grid[y-1][x]== NONE || grid->game_grid[y-1][x]== GOAL  ))
            {
                grid->player.y--;
            }
            else if(
                    grid->game_grid[y-1][x]== BOX && grid->game_grid[y-2][x]==NONE){
                    grid->game_grid[y-1][x]=NONE;
                    grid->game_grid[y-2][x]=BOX;
                    grid->player.y--;
            }
            else if (
                grid->game_grid[y-1][x]== BOX && grid->game_grid[y-2][x]==GOAL){
                grid->game_grid[y-1][x]=NONE;
                grid->game_grid[y-2][x]=BOX;
                grid->player.y--;
                grid->pts_cibles_recouverts++;
            }
        }
            
            break;
        case Bottom:
        {
            if( 
             (grid->game_grid[y+1][x]== NONE || grid->game_grid[y+1][x]== GOAL  ))
            {
                grid->player.y++;
            }
            else if( 
                    grid->game_grid[y+1][x]== BOX && grid->game_grid[y+2][x]==NONE){
                    grid->game_grid[y+1][x]=NONE;
                    grid->game_grid[y+2][x]=BOX;
                    grid->player.y++;
            }
            else if ( 
                grid->game_grid[y+1][x]== BOX && grid->game_grid[y+2][x]==GOAL){
                grid->game_grid[y+1][x]=NONE;
                grid->game_grid[y+2][x]=BOX;
                grid->player.y++;
                grid->pts_cibles_recouverts++;
            }
        }     
        break;
    }

}
