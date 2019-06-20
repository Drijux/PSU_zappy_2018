/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** init_server.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "server.h"
#include "print.h"

void free_struct(team_t *team, int nb_team)
{
    for (int i = 0; i < nb_team; ++i) {
        free(team[i].name);
    }
    free(team);
}

team_t  *fill_struct_team(info_game_t *info)
{
    team_t *team = malloc(sizeof(team_t) * (info->nb_team));

    for (int i = 0; i < info->nb_team; ++i) {
        team[i].name = strdup(info->name_team[i]);
        free(info->name_team[i]);
        team[i].nb_clt = info->nb_clt;
    }
    free(info->name_team);
    return (team);
}

bool my_accept(int sd, int *id_clt)
{
    if ((*id_clt = accept(sd, NULL, NULL)) == -1) {
        perror("Failed accept");
        return (false);
    }
    return (true);
}