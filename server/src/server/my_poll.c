/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** my_poll.c
*/

#include <stdio.h>
#include "server.h"

bool my_poll(struct pollfd *fd, int nfds, int *vl, int time)
{
    if ((*vl = poll(fd, nfds, time)) == -1) {
        perror("Failed poll");
        return (false);
    }
    if (*vl == 0) {
        return (false);
    }
    return (true);
}