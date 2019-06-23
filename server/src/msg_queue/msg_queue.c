/*
** EPITECH PROJECT, 2018
** zappy_server
** File description:
** msg_queue.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

int len_msg_queue(client_t *clt)
{
    int i = 0;
    for (; clt->msg_queue[i].msg; ++i) {
    }
    return (i);
}

void add_msg_to_queue(client_t *clt, char *msg, double time)
{
    int i = 0;

    if (len_msg_queue(clt) > 9)
        return;
    for (; clt->msg_queue[i].msg; ++i) {
    }
    clt->msg_queue[i].msg = strdup(msg);
    clt->msg_queue[i].time_end = time;
}

void delete_first_msg(client_t *clt)
{
    free(clt->msg_queue[0].msg);
    for (int i = 0; clt->msg_queue[i].msg; ++i) {
        clt->msg_queue[i].msg = clt->msg_queue[i + 1].msg;
        clt->msg_queue[i].time_end = clt->msg_queue[i + 1].time_end;
    }
}

void handle_msg_queue(client_t *clts, info_game_t *info)
{
    double time = 0;

    for (int i = 0; i < info->nfds; ++i) {
        time = (double)clock() / CLOCKS_PER_SEC;
        if (len_msg_queue(&clts[i]) > 0
            && time >= clts[i].msg_queue[0].time_end
            && clts[i].msg_queue[0].msg != NULL) {
            send_msg(clts[i].sd, clts[i].msg_queue[0].msg);
            delete_first_msg(&clts[i]);
        }
    }
}