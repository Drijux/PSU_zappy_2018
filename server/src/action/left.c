/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** left.c
*/

#include <stdio.h>
#include "action.h"

bool left(client_t *clt
    , UNUSED map_t *map
    , UNUSED info_game_t *info)
{
    if (clt->axe == NORTH)
        clt->axe = WEST;
    else if (clt->axe == SOUTH)
        clt->axe = EAST;
    else if (clt->axe == EAST)
        clt->axe = NORTH;
    else
        clt->axe = SOUTH;
    return (true);
}