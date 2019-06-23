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

char *Mybot::sendMessage(std::string message)
{
    static char buffer[2048];
    int size = 0;

    dprintf(_sock, "%s\n", message.c_str());
    size = read(_sock, buffer, sizeof(buffer));
    buffer[size] = '\0';
    return (buffer);
}

void Mybot::look(void)
{
    std::string response = sendMessage("Look");
}

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