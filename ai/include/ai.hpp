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

#include <sys/socket.h>
#include <netinet/in.h>

class Client
{
public:
	Client();
	bool create_socket();
	void create_sockaddr_in(std::string addr, int port);
	bool connection(std::string str, int port);
	bool loop(void);
	bool preorder(void)
private:
	int _sock;
	std::string _addr;
	int _port;
	struct sockaddr_in _server;
};

#endif /* AI_HPP_ */