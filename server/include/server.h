/*
** EPITECH PROJECT, 2019
** zappy_server
** File description:
** .h of zappy_server project
*/

#ifndef SERVER_H_
# define SERVER_H_

static const int FAILURE = 84;
static const int SUCCESS = 0;
static const int NB_CMD = 6;

#include <stdbool.h>


typedef struct info_game {
    int port;
    int width;
    int heigth;
    int nb_clt;
    int freq;
    char **name_team;
} info_game_t;

typedef struct command {
    const char *name;
    bool (*function)(info_game_t *, char **);
}command_t;

bool check_port(info_game_t *, char **);
bool check_width(info_game_t *, char **);
bool check_heigth(info_game_t *, char **);
bool check_name(info_game_t *, char **);
bool check_nbclient(info_game_t *, char **);
bool check_freq(info_game_t *, char **);

static const command_t COMMAND[] = {
    {"-p", check_port},
    {"-x", check_width},
    {"-y", check_heigth},
    {"-n", check_name},
    {"-s", check_nbclient},
    {"-f", check_freq},
};


void init_struct(info_game_t *);
bool handle_error(int , char **, info_game_t *);
int print_usage(int );
bool check_name(info_game_t *, char **);

void free_struct(info_game_t *);

#endif /* SERVER_H_ */