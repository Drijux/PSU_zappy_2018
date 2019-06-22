//
// EPITECH PROJECT, 2019
// zappy_ai
// File description:
// .h for zappy_ai project
//

#ifndef AI_HPP_
#define AI_HPP_

static const int MY_EXIT_ERROR = 84;
static const int MY_EXIT_SUCCESS = 0;

#include <string.h>
#include <unistd.h>
#include <iostream>
#include <ostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "structure.hpp"

class Client
{
public:
	Client(arg_t argument);
	bool create_socket();
	void create_sockaddr_in(std::string addr, int port);
	bool connection(void);
	bool loop(void);
	bool preorder(void);
private:
	int _sock;
	std::string _addr;
	int _port;
	std::string _team;
	struct sockaddr_in _server;
};

#endif /* AI_HPP_ */