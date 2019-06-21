//
// EPITECH PROJECT, 2019
// zappy_ai
// File description:
// definition of Bot class
//

#ifndef BOT_HPP_
# define BOT_HPP_

#include <unordered_map>
#include <iostream>
#include <vector>

typedef struct order {
    std::string order;
    bool sended;
} order_t;

typedef struct data {
    std::string ressource;
    int x;
    int y;
} data_t;

static const std::vector<order_t> FIRSTORDERS = {
    {"first order", false}
};

class Bot
{
    public:
        Bot(int sock, char *team);
        ~Bot(void);

        void botRun(void);
        void botLogic(void);

        void sendOrder(void);

        void setInventory(std::string inventory);

        void getView(void);
        void getInventory(void);

    private:
        int _sock;
        std::string _team;

        std::vector<order_t> _orderstack;
        std::unordered_map<std::string, int> _inventory;

    protected:
};

#endif /* BOT_HPP_ */