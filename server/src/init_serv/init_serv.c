/*
** EPITECH PROJECT, 2018
** zappy_serv
** File description:
** init_serv
*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.h"

static bool create_socket(info_game_t *info)
{
    if ((info->sd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed creation socket");
        return (false);
    }
    return (true);
}

static bool my_bind(info_game_t *info, struct sockaddr_in *servaddr)
{
    if (bind(info->sd, (struct sockaddr *)servaddr, sizeof(*servaddr)) != 0) {
        perror("Failed bind");
        return (false);
    }
    return (true);
}

static void fill_struct_sockaddr(info_game_t *info, struct sockaddr_in *serv)
{
    serv->sin_family = PF_INET;
    serv->sin_addr.s_addr = htonl(INADDR_ANY);
    serv->sin_port = htons(info->port);
}

static bool my_listen(info_game_t * info)
{
    if (listen(info->sd, (info->nb_team * info->nb_clt)) != 0) {
        perror("Failed listen");
        return (false);
    }
    return (true);
}

bool init_serv(info_game_t *info)
{
    struct sockaddr_in servaddr;

    fill_struct_sockaddr(info, &servaddr);
    if (!create_socket(info)
        || !my_bind(info, &servaddr)
        || !my_listen(info)) {
        return (false);
    }
    return (true);
}