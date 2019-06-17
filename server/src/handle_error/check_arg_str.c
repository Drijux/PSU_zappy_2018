/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** check_arg_str.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "server.h"

bool check_name(info_game_t *info, char **av)
{
    int nb_team = 1;

    for (; av[nb_team] != NULL; nb_team++) {
        if (av[nb_team][0] == '-')
            break;
    }
    if ((info->name_team = malloc(sizeof(char *) * (nb_team))) == NULL) {
        perror("Failed malloc creation team");
        return (false);
    }
    info->nb_team = nb_team - 1;
    info->name_team[nb_team - 1] = NULL;
    for (int i = 0; i < nb_team - 1; ++i) {
        if ((info->name_team[i] = strdup(av[i + 1])) == NULL) {
            perror("Failed malloc creation of different team");
            return (false);
        }
    }
    return (true);
}