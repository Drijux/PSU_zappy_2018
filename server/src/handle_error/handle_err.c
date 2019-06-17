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
                && !COMMAND[j].function(info, av + i))
                return (false);
        }
    }
    return (true);
}

int print_usage(int state)
{
    puts(USAGE);
    return (state);
}