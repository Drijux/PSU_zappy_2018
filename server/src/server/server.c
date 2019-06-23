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
#include <SDL/SDL.h>
#include "action.h"
#include "print.h"
#include "server.h"

static void free_clts(client_t *clients, int nb)
{
    for (int i = 1; i < nb; ++i) {
        if (clients[i].file != NULL)
            free(clients[i].file);
        if (clients[i].team_name != NULL)
            free(clients[i].team_name);
    }
}

static void fill_struct_clts(client_t *clts, int nb)
{
    for (int i = 0; i < nb; ++i) {
        memset(&clts[i], 0, sizeof(clts[i]));
        clts[i].inventory[0] = 10;
    }
}

// static void handle_clt_poll(info_game_t *info
//     , struct pollfd *fd
//     , map_t *map)
// {
//     int vl = 0;
//     client_t clients[info->clt_tot + 1];
//     clients[0].sd = fd[0].fd;
//     SDL_Event event;

//     fill_struct_clts(clients, (info->clt_tot + 1));
//     while (true) {
//         SDL_WaitEvent(&event);
//         if (event.type == SDL_QUIT)
//             break;
//         if (my_poll(fd, info->nfds, &vl, 0))
//             handle_poll(fd, info, map, clients);
//     }
//     free_clts(clients, (info->clt_tot + 1));
// }

static void handle_clt_poll(info_game_t *info
    , struct pollfd *fd
    , map_t *map)
{
    int vl = 0;
    client_t clients[info->clt_tot + 1];
    clients[0].sd = fd[0].fd;

    fill_struct_clts(clients, (info->clt_tot + 1));
    while (true) {
        if (my_poll(fd, info->nfds, &vl, 0)) {
            handle_poll(fd, info, map, clients);
        }
        handle_msg_queue(clients, info);
    }
    free_clts(clients, (info->clt_tot + 1));
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
    map_t map[(info->heigth * info->width) + 1];

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

// int server(info_game_t *info)
// {
//     map_t map[info->heigth * info->width];

//     if (map == NULL || !init_map(map, info))
//         return (FAILURE);
//     if (!init_serv(info) || SDL_Init(SDL_INIT_VIDEO) == -1)
//         return (FAILURE);
//     SDL_SetVideoMode(1280, 960, 32, SDL_HWSURFACE | SDL_RESIZABLE);
//     SDL_WM_SetCaption("Zappy_Serveur", NULL);
//     run_serv(info, map);
//     shutdown(info->sd, SHUT_RDWR);
//     close(info->sd);
//     free_map_info(map, info);
//     SDL_Quit();
//     return (SUCCESS);
// }