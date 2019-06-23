/*
** EPITECH PROJECT, 2019
** zappy_ai
** File description:
** methods of client class
*/

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

bool Client::connection(void)
{
    if (connect(_sock, (struct sockaddr *)&_server, sizeof(_server)) == -1) {
		perror("Client::connect : Failed to connect client");
        return (false);
	}
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