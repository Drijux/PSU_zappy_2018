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

static bool my_str_isprintable(char const *str)
{
    if (str[0] == '\0')
        return (false);
    for (int i = 0; str[i] != '\0'; ++i) {
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
    if (!my_str_isprintable(*msg))
        return (false);
    return (true);
}