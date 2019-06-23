//
// EPITECH PROJECT, 2019
// zappy_ai
// File description:
// Client class definition
//

#ifndef CLIENT_HPP_
# define CLIENT_HPP_

#include <iostream>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "structure.hpp"
#include "mybot.hpp"

class Client
{
    public:
        Client(args_t *arguments);
        ~Client(void);

        int launch(void);
        int startBot(void);
        int callServer(void);
        bool connection(void);
        bool createSocket(void);
        void createSockaddrIn(void);

    private:
        int _port;
        std::string _addr;
        std::string _team;

        int _sock;
        struct sockaddr_in _server;

    protected:
};

#endif /* CLIENT_HPP_ */