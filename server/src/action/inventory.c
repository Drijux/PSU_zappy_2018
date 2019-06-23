/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** inventory.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "action.h"
#include "minerai.h"

bool inventory(client_t *clt
    , UNUSED map_t *map
    , info_game_t *info
    , UNUSED char *msg)
{
    char buff[20];
    double time = 0;


    clt->msg = calloc(LEN_MAX, sizeof(char));
    clt->msg = strcat(clt->msg, "[");
    for (int i = 1; i < 7; ++i) {
        if (i > 1)
            clt->msg = strcat(clt->msg, ",");
        clt->msg = strcat(clt->msg, minerai[i]);
        clt->msg = strcat(clt->msg, " ");
        sprintf(buff, "%d", clt->inventory[i]);
        clt->msg = strcat(clt->msg, buff);
    }
    clt->msg = strcat(clt->msg, "]");
    time = ((double)clock() / CLOCKS_PER_SEC) + (1 / info->freq);
    add_msg_to_queue(clt, clt->msg, time);
    free(clt->msg);
    return (true);
}