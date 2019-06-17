/*
** EPITECH PROJECT, 2018
** zappy_sever
** File description:
** send_recv.c
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "server.h"

void send_msg(int id_clt, char *msg)
{
    dprintf(id_clt, "<--%s\n", msg);
    dprintf(1, "<--%s\n", msg);
}

bool read_msg(int id_clt, char **msg)
{
    memset(*msg, 0, MAX_MSG - 1);
    if (read(id_clt, *msg, MAX_MSG - 1) <= 0) {
        perror("Failed read");
        return (false);
    }
    dprintf(1, "-->%s", *msg);
    return (true);
}