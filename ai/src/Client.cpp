/*
** EPITECH PROJECT, 2019
** zappy_ai
** File description:
** create client
*/

#include "ai.hpp"
#include <stdbool.h>

Client::Client()
{
	_sock = -1;
	_port = 0;
	_addr = "";	
}

bool Client::create_socket()
{
	if (_sock != -1) {
		std::cout << "Socket already created" << std::endl;
		return false;
	}
	_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (_sock == -1) {
		std::cout << "Socket failed" << std::endl;
		return false;
	}
	return true;
}

void Client::create_sockaddr_in(std::string str, int port)
{
	_server.sin_addr.s_addr = inet_addr(str);
	_server.sin_family = AF_INET;
	_server.sin_port = htons(port);
}

bool Client::connection(std::string str, int port)
{
	if (connect(sock, (struct sockaddr *) &_server, sizeof(_server))) {
		std::cout << "Connect failed" << std::endl;
		return false;
	}
}

bool Client::loop(void)
{
	while (1) {
		write(_sock, "I'm a bg", strlen("I'm a bg"));
	}
	close(_sock);
}

bool Client::preorder(void)
{
	if (create_socket() == false)
		return false;
	create_sockaddr_in("bla", 42);
	if (connection("bla, port") == false)
		return false;
	loop();
}
