/*
** EPITECH PROJECT, 2019
** zappy_ai
** File description:
** methods of mybot class
*/

#include <cstring>
#include "parameter.hpp"
#include "mybot.hpp"

Mybot::Mybot(int sock, std::string team) : _sock(sock), _team(team)
{}

Mybot::~Mybot(void)
{}

void Mybot::early(char *buf)
{
    // int ret = 0;

    dprintf(_sock, "%s\n", _team.c_str());
    // std::memset(buf, 0, 1023);
    // if ((ret = read(_sock, buf, 1024)) > 0)
    //     dprintf(1, "%s\n", _team.c_str());
    // std::memset(buf, 0, 1023);
    // if ((ret = read(_sock, buf, 1024)) > 0)
    //     dprintf(1, "%s\n", _team.c_str());
}

void Mybot::treat_msg(char *buf, int ret)
{
    if (std::strncmp("WELCOME", buf, ret - 2) == 0)
        early(buf);
    else
        dprintf(_sock, "Forward\n");
}

int Mybot::run(void)
{
    char *buffer = (char *)calloc(1024, sizeof(char));
    int ret = 0;

    while (true) {
        if ((ret = read(_sock, buffer, 1024)) > 0) {
            dprintf(1, "%s", buffer);
            treat_msg(buffer, ret);
        }
        std::memset(buffer, 0, 1023);
    }
    free(buffer);
    close(_sock);
    return (SUCCESS);
}

