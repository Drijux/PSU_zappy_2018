/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** server.c
*/

#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "action.h"
#include "print.h"

bool check_team(int sd, team_t *team, info_game_t *info, char *msg)
{
    for (int i = 0; i < info->nb_team; ++i) {
        if (strncmp(team[i].name, msg, strlen(team[i].name) - 1) == 0
            && info->nb_clt > 0) {
            dprintf(1, "<--%d\n", info->nb_clt);
            dprintf(sd, "<--%d\n", info->nb_clt);
            return (true);
        }
    }
    dprintf(1, "<--%d\n", info->nb_clt);
    dprintf(sd, "<--%d\n", info->nb_clt);
    return (false);
}

void handle_clt_poll(info_game_t *info
    , __attribute__((unused ))team_t *team
    , struct pollfd *fd)
{
    int length = (info->nb_clt * info->nb_team) + 1;
    int vl = 0;
    int nfds = 1;

    while (true) {
        if (my_poll(fd, nfds, &vl, 0))
            handle_poll(fd, &nfds, length);
    }
}

static void run_serv(info_game_t *info)
{
    int length = (info->nb_clt * info->nb_team) + 1;
    team_t *team = fill_struct_team(info);
    struct pollfd *fd = calloc(length, sizeof(struct pollfd));

    fd[0].fd = info->sd;
    fd[0].events = POLLIN;
    handle_clt_poll(info, team, fd);
    free_struct(team, info->nb_team);
}

int server(info_game_t *info)
{
    if (!init_serv(info))
        return (FAILURE);
    run_serv(info);
    shutdown(info->sd, SHUT_RDWR);
    close(info->sd);
    return (SUCCESS);
}