/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** handle_poll.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "print.h"
#include "server.h"

static int handle_new_clt(struct pollfd *fd, int *nfds, int id_clt, int length)
{
    if (*nfds > length && (fd = realloc(fd, *nfds)) == NULL) {
        perror("Failed realloc");
        return (0);
    }
    fd[*nfds].fd = id_clt;
    fd[*nfds].events = POLLIN;
    send_msg(fd[*nfds].fd, WELCOME);
    return (1);
}

static void handle_new_msg(struct pollfd *fd)
{
    char *msg = calloc(MAX_MSG, sizeof(char));

    if (read_msg(fd->fd, &msg)) {
        // treat_msg(msg);
        dprintf(1, "%s", msg);
    }
    free(msg);
}

void handle_poll(struct pollfd *fd, int *nfds, int length)
{
    int id_clt = -1;

    for (int i = 0; i < *nfds; ++i) {
        if (fd[i].revents == 0)
            continue;
        if (fd[i].revents == POLLIN && fd[i].fd == fd[0].fd
            && my_accept(fd[0].fd, &id_clt))
            *nfds += handle_new_clt(fd, nfds, id_clt, length);
        if (fd[i].revents == POLLIN && fd[i].fd != fd[0].fd)
            handle_new_msg(&fd[i]);
    }
}