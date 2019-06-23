/*
** EPITECH PROJECT, 2019
** zappy_ai
** File description:
** methods of mybot class
*/

#include "parameter.hpp"
#include "mybot.hpp"

Mybot::Mybot(int sock, std::string team) : _sock(sock), _team(team)
{}

Mybot::~Mybot(void)
{}

int Mybot::run(void)
{
    char buffer[1024];
    int ret = 0;

    while (true) {
        dprintf(_sock, "Forward\n");
        ret = read(_sock, buffer, 3);
        buffer[ret] = '\0';
    }
    return (SUCCESS);
}

