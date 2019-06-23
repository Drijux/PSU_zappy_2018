/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** handle_poll.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "print.h"
#include "server.h"
#include "action.h"

static int handle_new_clt(struct pollfd *fd
    , info_game_t *info
    , client_t *clt
    , map_t *map)
{
    if (info->nfds > info->clt_tot
        && ((fd = realloc(fd, info->nfds)) == NULL
            || (clt = realloc(clt, info->nfds)) == NULL)) {
        perror("Failed realloc");
        return (0);
    }
    clt->sd = fd->fd;
    send_msg(clt->sd, WELCOME);
    if (!check_new_clt(clt, map, info))
        return (0);
    return (1);
}

static void treat_msg(char *msg
    , client_t *clt
    , info_game_t *info
    , map_t *map)
{
    for (int i = 0; i < MAX_ACTION; ++i) {
        if (strncmp(MY_ACTION[i].name, msg, MY_ACTION[i].len) == 0
            && MY_ACTION[i].function(clt, map, info))
            return;
    }
    dprintf(clt->sd, "ko\n");
}

static void handle_new_msg(client_t *clt
    , info_game_t *info
    , map_t *map)
{
    char *msg = calloc(MAX_MSG, sizeof(char));

    if (read_msg(clt->sd, &msg))
        treat_msg(msg, clt, info, map);
    free(msg);
}

void handle_poll(struct pollfd *fd
    , info_game_t *info
    , map_t *map
    , client_t *clt)
{
    int id_clt = -1;

    for (int i = 0; i < info->nfds; ++i) {
        if (fd[i].revents == 0)
            continue;
        if (fd[i].revents == POLLIN
            && fd[i].fd == fd[0].fd && my_accept(fd[0].fd, &id_clt)) {
            fd[info->nfds].fd = id_clt;
            fd[info->nfds].events = POLLIN;
            info->nfds += handle_new_clt(&fd[info->nfds]
                , info, &clt[info->nfds], map);
        }
        if (fd[i].revents == POLLIN && fd[i].fd != fd[0].fd) {
            handle_new_msg(&clt[i], info, map);
        }
    }
}