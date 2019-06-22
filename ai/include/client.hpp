//
// EPITECH PROJECT, 2019
// zappy_ai
// File description:
// definition of Client class
//

#ifndef CLIENT_HPP_
# define CLIENT_HPP_

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

    protected:
};


#endif /* CLIENT_HPP_ */