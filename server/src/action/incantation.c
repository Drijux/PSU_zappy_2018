/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** incantation.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "action.h"
#include "incantation.h"

bool check_incantation(client_t *clt, map_t *map, int i, info_game_t *info)
{
    double time = 0;

    for (int j = 1; j < 8; ++j) {
        if (!(map[clt->index_map].inventory[j] >= elevation[i][j])) {
            time = ((double)clock() / CLOCKS_PER_SEC) + (300 / info->freq);
            add_msg_to_queue(clt, "ko", time);
            return (false);
        }
    }
    return (true);
}

bool incantation(client_t *clt
    , map_t *map
    , UNUSED info_game_t *info
    , UNUSED char *msg)
{
    double time = 0;
    int i = 0;

    for (; i < 7; ++i) {
        if (clt->lvl == (elevation[i][0] - 1))
            break;
    }
    if (!check_incantation(clt, map, i, info))
        return (true);
    if ((clt->msg = calloc(LEN_MAX, sizeof(char))) == NULL)
        return (true);
    clt->lvl += 1;
    sprintf(clt->msg, "Current level:%d", clt->lvl);
    for (int j = 1; j < 8; ++j)
        map[clt->index_map].inventory[j] -= elevation[i][j];
    time = ((double)clock() / CLOCKS_PER_SEC) + (300 / info->freq);
    add_msg_to_queue(clt, clt->msg, time);
    free(clt->msg);
    return (true);
}