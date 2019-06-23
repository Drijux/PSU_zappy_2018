/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** look.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "action.h"
#include "minerai.h"

void choose_dir(client_t *clt, int *x, int *y, int *mov)
{
    if (clt->axe == NORTH) {
        *x = -1;
        *y = 1;
        *mov = 1;
    } else if (clt->axe == SOUTH) {
        *x = 1;
        *y = -1;
        *mov = -1;
    } else if (clt->axe == EAST) {
        *x = 1;
        *y = 1;
        *mov = -1;
    } else {
        *x = -1;
        *y = -1;
        *mov = 1;
    }
}

void find_ress(map_t *map, client_t *clt)
{

    int i = 0;
    bool flag = false;

    for (; i < 7; ++i) {
        if (flag == true && map->inventory[i] > 0) {
            clt->msg = strcat(clt->msg, " ");
            clt->msg = strcat(clt->msg, minerai[i]);
        }
        if (flag == false && map->inventory[i] > 0) {
            clt->msg = strcat(clt->msg, minerai[i]);
            flag = true;
        }
    }
}

void find_tile(client_t *clt, map_t *map, int x, int y)
{
    int i = 0;

    for (; map[i].x != x && map[i].y != y; ++i);
    if (map[i].ress == true) {
        find_ress(&map[i], clt);
    }
}

void check_mov(client_t *clt, map_t *map, int len, int i)
{
    int mov = 0;
    int x = 0;
    int y = 0;


    choose_dir(clt, &x, &y, &mov);
    if (clt->axe == NORTH || clt->axe == SOUTH) {
        for (int l = 0; l < len; ++l) {
            clt->msg = strcat(clt->msg, ",");
            find_tile(clt, map, (clt->x + (x * i)) + (l * mov)
                , clt->y + (y * i));
        }
    } else {
        for (int l = 0; l < len; ++l) {
            clt->msg = strcat(clt->msg, ",");
            find_tile(clt, map, clt->x + (x * i)
                , (clt->y + (y * i)) + (l * mov));
        }
    }
}

bool look(client_t *clt
    , map_t *map
    , info_game_t *info
    , UNUSED char *msg)
{
    int len = 3;
    double time = 0;

    if ((clt->msg = calloc(LEN_MAX, sizeof(char))) == NULL)
        return (false);
    clt->msg = strcat(clt->msg, "[player");
    for (int i = 0; i < clt->lvl; ++i) {
        check_mov(clt, map, len, i);
        len += 2;
    }
    clt->msg = strcat(clt->msg, "]");
    time = ((double)clock() / CLOCKS_PER_SEC) + (7 / info->freq);
    add_msg_to_queue(clt, clt->msg, time);
    free(clt->msg);
    return (true);
}