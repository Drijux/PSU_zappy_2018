/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** check_arg_str.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "server.h"

static bool check_team_nbr(int nb_team)
{
    if (nb_team <= 1) {
        dprintf(STDERR_FILENO,"Error: Number of team is incorrect\n");
        return (false);
    }
    return (true);
}

static bool check_team_name(char **name_team)
{
    for (int i = 0; name_team[i] != NULL; i++) {
        for (int j = 0; name_team[j] != NULL; j++) {
            if (j != i && strcmp(name_team[i], name_team[j]) == 0) {
                dprintf(2, "Error: Team name are same between\n");
                return (false);
            }
        }
    }
    return (true);
}

static int get_nb_team(char **av)
{
    int nb_team = 1;

    for (; av[nb_team]; nb_team++) {
        if (av[nb_team][0] == '-')
            break;
    }
    return (nb_team - 1);
}

static bool my_malloc(info_game_t * info, int nb_team)
{
    if ((info->name_team = malloc(sizeof(char *) * (nb_team + 1))) == NULL) {
        perror("Failed malloc creation team");
        return (false);
    }
    if ((info->client_per_team = calloc(nb_team, sizeof(int))) == NULL) {
        perror("Failed calloc creation of int *");
        return (false);
    }
    return (true);
}

bool check_name(info_game_t *info, char **av)
{
    int nb_team = get_nb_team(av);

    if (!my_malloc(info, nb_team))
        return false;
    info->nb_team = nb_team;
    info->name_team[nb_team] = NULL;
    for (int i = 0; i < nb_team; ++i) {
        if ((info->name_team[i] = strdup(av[i + 1])) == NULL) {
            perror("Failed malloc creation of different team");
            return (false);
        }
    }
    if (!check_team_nbr(nb_team) || !check_team_name(info->name_team))
        return (false);
    return (true);
}