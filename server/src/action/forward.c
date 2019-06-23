/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** foward.c
*/

#include <stdio.h>
#include "action.h"

static void check_fwd_map(client_t *clt, map_t *map, info_game_t *info)
{
    for (int i = 0; i < (info->width * info->heigth); ++i) {
        if (map[i].x == clt->x && map[i].y == clt->y) {
            map[clt->index_map].perso = false;
            map[i].perso = true;
            clt->index_map = i;
            break;
        }
    }
}

static void check_forward(client_t *clt, map_t *map, info_game_t *info)
{
    if (clt->y < 0)
        clt->y = info->heigth - 1;
    if (clt->y == info->heigth)
        clt->y = 0;
    if (clt->x < 0)
        clt->x = info->width - 1;
    if (clt->x == info->width)
        clt->x = 0;
    check_fwd_map(clt, map, info);
}

bool forward(client_t *clt
    , map_t *map
    , info_game_t *info)
{
    if (clt->axe == NORTH)
        clt->y -= 1;
    else if (clt->axe == EAST)
        clt->x += 1;
    else if (clt->axe == WEST)
        clt->x -= 1;
    else
        clt->y += 1;
    check_forward(clt, map, info);
    return (true);
}