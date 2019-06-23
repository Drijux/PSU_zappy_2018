//
// EPITECH PROJECT, 2019
// zappy_ai
// File description:
// Mybot class definition
//

#ifndef MYBOT_HPP_
# define MYBOT_HPP_

#include <iostream>
#include <unistd.h>

class Mybot
{
    public:
        Mybot(int socket, std::string team);
        ~Mybot(void);

        int run(void);
        void treat_msg(char *buf, int ret);
        void early(char *buf);

    private:
        int _sock;
        std::string _team;

    protected:
};

#endif /* MYBOT_HPP_ */