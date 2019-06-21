/*
** EPITECH PROJECT, 2018
** zappy_sever
** File description:
** send_recv.c
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "server.h"

static bool my_str_isprintable(char const *str, size_t size)
{
    if (str == NULL)
        return (false);
    for (size_t i = 0; i < size; ++i) {
        if (!(str[i] >= '!' && str[i] <= '~'))
            return (false);
    }
    return (true);
}

void send_msg(int id_clt, char *msg)
{
    dprintf(id_clt, "%s\n", msg);
}

bool read_msg(int id_clt, char **msg)
{
    memset(*msg, 0, MAX_MSG - 1);
    if (read(id_clt, *msg, MAX_MSG - 1) < 0) {
        perror("Failed read");
        return (false);
    }
    if (!my_str_isprintable(*msg, strlen(*msg) - 2))
        return (false);
    return (true);
}