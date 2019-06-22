/*
** EPITECH PROJECT, 2019
** zappy_server
** File description:
** .h of zappy_server project
*/

#ifndef COMMAND_H_
#define COMMAND_H_

#include <server.h>

#define MAX_ACTION 12

typedef struct action {
    const char *name;
    const int len;
    bool (*function) (client_t *clt, map_t *, info_game_t *);
} action_t;

bool forward(client_t *clt, map_t *, info_game_t *);
bool broadcast(client_t *clt, map_t *, info_game_t *);
bool right(client_t *clt, map_t *, info_game_t *);
bool incantation(client_t *clt, map_t *, info_game_t *);
bool left(client_t *clt, map_t *, info_game_t *);
bool look(client_t *clt, map_t *, info_game_t *);
bool inventory(client_t *clt, map_t *, info_game_t *);
bool my_fork(client_t *clt, map_t *, info_game_t *);
bool my_eject(client_t *clt, map_t *, info_game_t *);
bool take_object(client_t *clt, map_t *, info_game_t *);
bool set_object(client_t *clt, map_t *, info_game_t *);
bool connect_nbr(client_t *clt, map_t *, info_game_t *);
// void map_size(team_t *);
// void bct(team_t *);
// void mct(team_t *);
// void tna(team_t *);

static const action_t MY_ACTION[] = {
    {"Forward", 7, forward},
    {"Brodcast", 8, broadcast},
    {"Right", 5, right},
    {"Incantation", 11, incantation},
    {"Left", 4, left},
    {"Look", 4, look},
    {"Inventory", 9, inventory},
    {"Fork", 4, my_fork},
    {"Eject", 5, my_eject},
    {"Take object", 11, take_object},
    {"Set object", 10, set_object},
    {"Connect_nbr", 11, connect_nbr},
    // {"msz", 3, map_size},
    // {"bct", 3, bct},
    // {"mct", 3, mct},
    // {"tna", 3, tna},
};

#endif /* COMMAND_H_ */