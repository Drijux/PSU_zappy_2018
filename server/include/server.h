/*
** EPITECH PROJECT, 2019
** zappy_server
** File description:
** .h of zappy_server project
*/

#ifndef SERVER_H_
#define SERVER_H_

static const int FAILURE = 84;
static const int SUCCESS = 0;
static const int NB_CMD = 6;
static const int MAX_MSG = 1024;

#include <stdbool.h>
#include <poll.h>

typedef struct client
{
    int x;
    int y;
} client_t;

typedef struct team
{
    char *name;
    int nb_clt;
    client_t *client;
} team_t;

typedef struct info_game {
    int sd;
    int port;
    int width;
    int heigth;
    int nb_clt;
    int freq;
    int nb_team;
    char **name_team;
} info_game_t;

typedef struct command {
    const char *name;
    bool (*function)(info_game_t *, char **);
} command_t;

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
    {"-c", check_nbclient},
    {"-f", check_freq},
};

void init_struct(info_game_t *);
bool handle_error(int , char **, info_game_t *);
int print_usage(int );
bool check_name(info_game_t *, char **);

bool init_serv(info_game_t *);
team_t  *fill_struct_team(info_game_t *);
bool my_accept(int , int *);
void free_struct(team_t *, int );

int server(info_game_t *);
void send_msg(int , char *);
bool read_msg(int , char **);

void handle_poll(struct pollfd *, int *, int );
bool my_poll(struct pollfd *, int , int *, int );

#endif /* SERVER_H_ */