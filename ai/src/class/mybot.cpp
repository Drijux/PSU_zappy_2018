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

// int Mybot::run(void)
// {
//     char *buffer = (char *)calloc(1024, sizeof(char));
//     int ret = 0;

//     while (true) {
//         if ((ret = read(_sock, buffer, 1024)) > 0) {
//             dprintf(1, "%s", buffer);
//             treat_msg(buffer, ret);
//         }
//         std::memset(buffer, 0, 1023);
//     }
//     free(buffer);
//     while(true);
//     close(_sock);
//     return (SUCCESS);
// }

int Mybot::run(void)
{
    char buffer[2048] = "ok";
    int reader = 2;

    while (true) {
        if (reader > 0 && !std::strcmp("ok", buffer)) {
            dprintf(_sock, "Forward\n");
            printf("Forward\n");
        }
        if (reader > 0 && !std::strcmp("dead", buffer)) {
            std::cout << "The bot is dead, long live the bot" << std::endl;
            break;
        }
        reader = read(_sock, buffer, 2048);
        buffer[reader - 1] = '\0';
    }
    close(_sock);
    return (SUCCESS);
}