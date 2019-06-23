/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** right.c
*/

#include <stdio.h>
#include "action.h"

bool right(client_t *clt
    , UNUSED map_t *map
    , UNUSED info_game_t *info)
{
    if (clt->axe == NORTH)
        clt->axe = EAST;
    else if (clt->axe == SOUTH)
        clt->axe = WEST;
    else if (clt->axe == EAST)
        clt->axe = SOUTH;
    else
        clt->axe = NORTH;
    return (true);
}