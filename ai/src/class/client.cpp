/*
** EPITECH PROJECT, 2019
** zappy_ai
** File description:
** methods of client class
*/

#include <cstring>

#include "parameter.hpp"
#include "client.hpp"

Client::Client(args_t *arguments) : _sock(-1)
{
	_port = atoi(arguments->port);
	_addr = arguments->machine;
	_team = arguments->team;
}

Client::~Client(void)
{}

void Client::createSockaddrIn(void)
{
    if (!strcmp(_addr.c_str(), "localhost")) {
		_server.sin_addr.s_addr = inet_addr("127.0.0.1");
	} else {
		_server.sin_addr.s_addr = inet_addr(_addr.c_str());
	}
	_server.sin_family = AF_INET;
	_server.sin_port = htons(_port);
}

bool Client::createSocket(void)
{
    if((_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Client::createSocket : Failed to create socket");
        return (false);
    }
    return (true);
}

int Client::callServer(void)
{
    char buffer[1024];
    int reader = 0;
    int stack = 0;
    int nbclient = 0;

    while (true) {
        reader = read(_sock, buffer, 1024);
        buffer[reader - 1] = '\0';
        if (!std::strcmp("WELCOME", buffer)) {
            dprintf(_sock, "%s\n", _team.c_str());
            stack += 1;
        } else if (stack == 1 && reader > 0) {
            nbclient = atoi(buffer);
            stack += 1;
        } else if ((stack == 2 && reader > 0) || \
        (stack == 2 && nbclient < 1))
            break;
    }
    return (nbclient);
}

bool Client::connection(void)
{
    if (connect(_sock, (struct sockaddr *)&_server, sizeof(_server)) == -1) {
		perror("Client::connect : Failed to connect client");
        return (false);
	}
    if (callServer() < 1) {
        close(_sock);
        return (false);
    }
    std::cout << "Connection established" << std::endl;
    return (true);
}

int Client::startBot(void)
{
    Mybot mybot = Mybot(_sock, _team);

    return (mybot.run());
}

int Client::launch(void)
{
    createSockaddrIn();
    if (!createSocket() || !connection())
        return (FAILURE);
    return (startBot());
}