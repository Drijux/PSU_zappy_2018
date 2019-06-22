/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** init_server.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "server.h"
#include "print.h"

bool my_accept(int sd, int *id_clt)
{
    if ((*id_clt = accept(sd, NULL, NULL)) == -1) {
        perror("Failed accept");
        return (false);
    }
    return (true);
}