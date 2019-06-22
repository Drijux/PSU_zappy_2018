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
#include <time.h>

enum ressource {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

typedef enum axe {
    NORTH,
    WEST,
    EAST,
    SOUTH
} axe_t;

typedef struct msg_queue {
    char *msg;
    clock_t time_end;
} msg_queue_t;

typedef struct client {
    int sd;
    int x;
    int y;
    char *team_name;
    int index_map;
    int inventory[7];
    axe_t axe;
    msg_queue_t msg_queue[10];
} client_t;

typedef struct info_game {
    int sd;
    int port;
    int width;
    int heigth;
    int *client_per_team;
    int nb_clt;
    int nb_team;
    int clt_tot;
    int freq;
    int nfds;
    char **name_team;
} info_game_t;

typedef struct map {
    int x;
    int y;
    bool perso;
    bool ress;
    bool ground;
    int inventory[7];
    char *file;
} map_t;

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
bool my_accept(int , int *);

int server(info_game_t *);
void send_msg(int , char *);
bool read_msg(int , char **);

bool my_poll(struct pollfd *, int , int *, int );


void handle_poll(struct pollfd *, info_game_t *, map_t *, client_t *);
bool init_map(map_t *, info_game_t *);
void free_map_info(map_t *, info_game_t *);
bool check_new_clt(client_t *, map_t *, info_game_t *);

#endif /* SERVER_H_ */