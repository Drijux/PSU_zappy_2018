/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** handle_clt.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print.h"
#include "server.h"

static void get_new_pos(client_t *client, map_t *map, info_game_t *info)
{
    int index = 0;
    int axe = 0;

    while (true) {
        index = rand()%(info->width * info->heigth);
        if (map[index].ground == true) {
            axe = rand()%4;
            free(map[index].file);
            map[index].file = strdup(GROUND);
            client->x = map[index].x;
            client->y = map[index].y;
            client->index_map = index;
            client->axe = axe;
            memset(&client->inventory, 0, sizeof(client->inventory));
            client->inventory[0] = 10;
            map[index].ground = false;
            map[index].perso = true;
            break;
        }
    }
}

static bool check_team(char *msg, info_game_t *info, int *save)
{
    if (strncmp(msg, "TEAM-", 5) != 0)
        return (false);
    for (int i = 0; info->name_team[i]; ++i) {
        if (strncmp(msg + 5, info->name_team[i], strlen(msg + 5) - 2) == 0) {
            *save = i;
            return (true);
        }
    }
    return (false);
}

static bool check_clt_in_team(client_t *clt, info_game_t *info, map_t *map, int save)
{
    dprintf(clt->sd, "%d\n", info->client_per_team[save]);
    if (info->client_per_team[save] < 1) {
        close(clt->sd);
        return (false);
    }
    get_new_pos(clt, map, info);
    dprintf(clt->sd, "%d %d\n", info->width, info->heigth);
    info->client_per_team[save] -= 1;
    return (true);
}

bool check_new_clt(client_t *clt, map_t *map, info_game_t *info)
{
    char *mg = "";
    int save = 0;

    while (true) {
        if ((mg = calloc(1024, sizeof(char))) != NULL && read_msg(clt->sd, &mg)
            && check_team(mg, info, &save)) {
            clt->team_name = strdup(strncpy(mg, mg + 5, strlen(mg + 5) - 2));
            if (clt->team_name != NULL)
                break;
        }
        dprintf(clt->sd, "ko\n");
    }
    if (!check_clt_in_team(clt, info, map, save))
        return (false);
    return (true);
}