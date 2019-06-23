/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** take_object.c
*/

#include <stdio.h>
#include <string.h>
#include "minerai.h"
#include "action.h"

bool take_object(client_t *clt
    , map_t *map
    , UNUSED info_game_t *info
    , char *msg)
{
    int i = 0;
    double time = 0;

    for (; i < 7; ++i) {
        if (strncmp(minerai[i], msg, strlen(msg) - 2) == 0
            && map[clt->index_map].inventory[i] > 0) {
            time = ((double)clock() / CLOCKS_PER_SEC) + (7 / info->freq);
            add_msg_to_queue(clt, "ok", time);
            map[clt->index_map].inventory[i] -= 1;
            clt->inventory[i] += 1;
            return (true);
        }
    }
    time = ((double)clock() / CLOCKS_PER_SEC) + (7 / info->freq);
    add_msg_to_queue(clt, "ko", time);
    return (true);
}