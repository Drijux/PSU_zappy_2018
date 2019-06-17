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

bool check_team(int fd, team_t *team, info_game_t *info, char *msg)
{
    for (int i = 0; i < info->nb_team; ++i) {
        if (strncmp(team[i].name, msg, strlen(team[i].name) - 1) == 0
            && info->nb_clt > 0) {
            dprintf(1, "<--%d\n", info->nb_clt);
            dprintf(fd, "<--%d\n", info->nb_clt);
            return (true);
        }
    }
    dprintf(1, "<--%d\n", info->nb_clt);
    dprintf(fd, "<--%d\n", info->nb_clt);
    return (false);
}

static void new_client(int id_clt, info_game_t *info, team_t *team)
{
    char *msg = calloc(MAX_MSG, sizeof(char));

    send_msg(id_clt, WELCOME);
    if (msg == NULL || !read_msg(id_clt, &msg))
        return;
    if (!check_team(id_clt, team, info, msg))
        return;
    while (strncmp(msg, "QUIT", strlen(msg) - 2) != 0) {
        read_msg(id_clt, &msg);
        for (int i = 0; i < 3; ++i) {
            if (strncmp(MY_ACTION[i].name, msg, strlen(msg) - 2) == 0)
                MY_ACTION[i].function(team);
        }
    }
    shutdown(id_clt, SHUT_RDWR);
    close(id_clt);
    free(msg);
}

static void run_serv(info_game_t *info)
{
    int id_clt = 0;
    team_t *team = fill_struct_team(info);

    while (true) {
        if (my_accept(info->sd, &id_clt)) {
            new_client(id_clt, info, team);
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