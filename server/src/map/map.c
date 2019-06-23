/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** map.c
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "print.h"
#include "server.h"

void free_map_info(map_t *map, info_game_t *info)
{
    for (int i = 0; i < (info->width * info->heigth); ++i)
        free(map[i].file);
    for (int i = 0; info->name_team[i]; ++i)
        free(info->name_team[i]);
    free(info->client_per_team);
    free(info->name_team);
}

static void fill_map_info(map_t *map, int y, int x)
{
    map->x = x;
    map->y = y;
    map->perso = false;
    map->ress = false;
    map->ground = true;
    memset(map->inventory, 0, sizeof(map->inventory));
    map->inventory[0] = 3;
    if ((map->file = strdup(GROUND)) == NULL)
        return;
}

bool init_map(map_t *map, info_game_t *info)
{
    int index = 0;

    for (int y = 0; y < info->heigth; ++y) {
        for (int x = 0; x < info->width; ++x) {
            fill_map_info(&map[index], y, x);
            index++;
        }
    }
    memset(&map[info->heigth * info->width], 0, sizeof(*map));
    return (true);
}