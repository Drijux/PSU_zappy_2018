/*
** EPITECH PROJECT, 2019
** zappy_server
** File description:
** .h of zappy_server project
*/

#ifndef COMMAND_H_
#define COMMAND_H_

#include <server.h>

typedef struct action {
    const char *name;
    const int len;
    void (*function) (team_t *);
} action_t;

void forward(team_t *);
void broadcast(team_t *);
void right(team_t *);
void incantation(team_t *);
void left(team_t *);
void look(team_t *);
void inventory(team_t *);
void my_fork(team_t *);
void my_eject(team_t *);
void take_object(team_t *);
void set_object(team_t *);
void connect_nbr(team_t *);

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
};

#endif /* COMMAND_H_ */