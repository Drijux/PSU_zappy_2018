/*
** EPITECH PROJECT, 2019
** zappy_ai
** File description:
** create client
*/

#include <cstring>
#include <stdbool.h>
#include "ai.hpp"

Client::Client(arg_t argument)
{
	_sock = -1;
	_port = atoi(argument.port);
	_addr = argument.machine;
}

bool Client::create_socket()
{
	if (_sock != -1) {
		std::cout << "Socket already created" << std::endl;
		return false;
	}
	_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (_sock == -1) {
		perror("Failed socket");
		return false;
	}
	return true;
}

void Client::create_sockaddr_in(std::string str, int port)
{
	if (std::strcmp(str.c_str(), "localhost") == 0) {
		_server.sin_addr.s_addr = inet_addr("127.0.0.1");
	} else {
		_server.sin_addr.s_addr = inet_addr(str.c_str());
	}
	_server.sin_family = AF_INET;
	_server.sin_port = htons(port);
}

bool Client::connection(void)
{
	if (connect(_sock, (struct sockaddr *) &_server, sizeof(_server)) == -1) {
		perror("Failed connect");
		return false;
	}
	return true;
}

bool Client::loop(void)
{

	while (1) {
		write(_sock, "FORWARD", 7);
		//Client send message to server
	}
	close(_sock);
}

bool Client::preorder(void)
{
	if (create_socket() == false)
		return false;
	create_sockaddr_in(_addr, _port);
	if (connection() == false)
		return false;
	loop();
	return true;
}
