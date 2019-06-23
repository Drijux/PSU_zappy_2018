/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** connect_nbr.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "action.h"

bool connect_nbr(client_t *clt
    , UNUSED map_t *map
    , info_game_t *info)
{
    int i = 0;

    clt->msg = calloc(LEN_MAX, sizeof(char));
    for (; info->name_team[i]; ++i) {
        if (strcmp(info->name_team[i], clt->team_name) == 0)
            break;
    }
    sprintf(clt->msg, "%d", info->client_per_team[i]);
    add_msg_to_queue(clt, clt->msg, 0.0);
    free(clt->msg);
    return (true);
}