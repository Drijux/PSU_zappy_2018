/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** my_fork.c
*/

#include <stdio.h>
#include <string.h>
#include "action.h"

bool my_fork(client_t *clt
    , UNUSED map_t *map
    , info_game_t *info
    , UNUSED char *msg)
{
    int i = 0;
    double time = 0;

    for (; info->name_team[i]; ++i) {
        if (strcmp(info->name_team[i], clt->team_name) == 0)
            break;
    }
    info->client_per_team[i] += 1;
    time = ((double)clock() / CLOCKS_PER_SEC) + (42 / info->freq);
    add_msg_to_queue(clt, "ok", time);
    info->nfds++;
    return (true);
}