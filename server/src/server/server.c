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
// #include <SDL/SDL.h>
#include "action.h"
#include "print.h"
#include "server.h"

static void handle_clt_poll(info_game_t *info
    , struct pollfd *fd
    , map_t *map)
{
    int vl = 0;
    client_t client[info->clt_tot + 1];
    client[0].sd = fd[0].fd;

    while (true) {
        if (my_poll(fd, info->nfds, &vl, 0))
            handle_poll(fd, info, map, client);
    }
}

static void run_serv(info_game_t *info, map_t *map)
{
    int length = (info->nb_clt * info->nb_team) + 1;
    struct pollfd *fd = calloc(length, sizeof(struct pollfd));

    info->clt_tot = length;
    fd[0].fd = info->sd;
    fd[0].events = POLLIN;
    handle_clt_poll(info, fd, map);
}

int server(info_game_t *info)
{
    map_t map[info->heigth * info->width];

    if (map == NULL || !init_map(map, info))
        return (FAILURE);
    if (!init_serv(info))
        return (FAILURE);
    run_serv(info, map);
    shutdown(info->sd, SHUT_RDWR);
    close(info->sd);
    free_map_info(map, info);
    return (SUCCESS);
}