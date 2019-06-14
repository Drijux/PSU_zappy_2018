/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** check_arg_nb.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "server.h"

bool check_port(info_game_t *info, char **av)
{
    info->port = strtol(av[1], NULL, 10);
    if (info->port == INT_MIN || info->port == INT_MAX) {
            dprintf(STDERR_FILENO, "Failed: Number is incorrect\n");
        return (false);
    }
    if (info->port < 1) {
        dprintf(STDERR_FILENO, "Failed: Expected port upper than 0\n");
        return (false);
    }
    return (true);
}

bool check_width(info_game_t *info, char **av)
{
    info->width = strtol(av[1], NULL, 10);
    if (info->width == INT_MIN || info->width == INT_MAX) {
            dprintf(STDERR_FILENO, "Failed: Number is incorrect\n");
        return (false);
    }
    if (info->width < 1) {
        dprintf(STDERR_FILENO, "Failed: Expected width upper than 0\n");
        return (false);
    }
    return (true);
}

bool check_heigth(info_game_t *info, char **av)
{
    info->heigth = strtol(av[1], NULL, 10);
    if (info->heigth == INT_MIN || info->heigth == INT_MAX) {
            dprintf(STDERR_FILENO, "Failed: Number is incorrect\n");
        return (false);
    }
    if (info->heigth < 1) {
        dprintf(STDERR_FILENO, "Failed: Expected heigth upper than 0\n");
        return (false);
    }
    return (true);
}

bool check_nbclient(info_game_t *info, char **av)
{
    info->nb_clt = strtol(av[1], NULL, 10);
    if (info->nb_clt == INT_MIN || info->nb_clt == INT_MAX) {
            dprintf(STDERR_FILENO, "Failed: Number is incorrect\n");
        return (false);
    }
    if (info->nb_clt < 1) {
        dprintf(STDERR_FILENO, "Failed: Expected clientsNB upper than 0\n");
        return (false);
    }
    return (true);
}

bool check_freq(info_game_t *info, char **av)
{
    info->freq = strtol(av[1], NULL, 10);
    if (info->freq == INT_MIN || info->freq == INT_MAX) {
            dprintf(STDERR_FILENO, "Failed: Number is incorrect\n");
        return (false);
    }
    if (info->freq < 1) {
        dprintf(STDERR_FILENO, "Failed: Expected freq upper than 0\n");
        return (false);
    }
    return (true);
}