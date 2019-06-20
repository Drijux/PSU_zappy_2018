/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** init_struc.c
*/

#include <stdlib.h>
#include "server.h"

void init_struct(info_game_t *info)
{
    info->sd = 0;
    info->port = -1;
    info->width = -1;
    info->heigth = -1;
    info->nb_clt = -1;
    info->freq = 100;
    info->nb_team = 0;
    info->freq = 100;
    info->name_team = NULL;
}