/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** handle_err.c
*/

#include <string.h>
#include <stdio.h>
#include "usage.h"
#include "server.h"

bool handle_error(int ac, char **av, info_game_t *info)
{
    init_struct(info);
    for (int i = 0; i < ac; ++i) {
        for (int j = 0; j < NB_CMD; ++j) {
            if (strcmp(COMMAND[j].name, av[i]) == 0
                && !COMMAND[j].function(info, av + i)) {
                puts("");
                return (false);
            }
        }
    }
    if (info->port <= 0 || info->heigth <= 0
        || info->nb_clt <= 0)
        return (false);
    if (info->width <= 0 || info->name_team == NULL)
        return (false);
    return (true);
}

int print_usage(int state)
{
    puts(USAGE);
    return (state);
}