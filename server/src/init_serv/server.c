/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** server.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "server.h"

static void free_struct(team_t *team, int nb_team)
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

static bool my_accept(int sd, int *id_clt)
{
    struct sockaddr_in clt;
    socklen_t len = sizeof(clt);

    if ((*id_clt = accept(sd, (struct sockaddr *)&clt, &len)) == -1) {
        perror("Failed accept");
        return (false);
    }
    return (true);
}

void run_serv(info_game_t *info)
{
    int id_clt = 0;
    team_t *team = fill_struct_team(info);

    while (true) {
        if (my_accept(info->sd, &id_clt)) {

            id_clt = 0;
        }
    }
    free_struct(team, info->nb_team);
    shutdown(info->sd, SHUT_RDWR);
    close(info->sd);
}

int server(info_game_t *info)
{
    if (!init_serv(info))
        return (FAILURE);
    run_serv(info);
    return (SUCCESS);
}