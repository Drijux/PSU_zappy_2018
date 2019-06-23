/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** left.c
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "action.h"

bool left(client_t *clt
    , UNUSED map_t *map
    , info_game_t *info
    , UNUSED char *msg)
{
    double time = 0;

    if (clt->axe == NORTH)
        clt->axe = WEST;
    else if (clt->axe == SOUTH)
        clt->axe = EAST;
    else if (clt->axe == EAST)
        clt->axe = NORTH;
    else
        clt->axe = SOUTH;
    time = ((double)clock() / CLOCKS_PER_SEC) + (7 / info->freq);
    add_msg_to_queue(clt, "ok", time);
    return (true);
}