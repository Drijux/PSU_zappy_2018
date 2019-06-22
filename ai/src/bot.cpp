//
// EPITECH PROJECT, 2019
// IA
// File description:
// main function of AI
//

#include "bot.hpp"

Bot::Bot(int sock, char *team) :
_sock(sock), _team(team), _orderstack(FIRSTORDERS)
{
    // std::vector<order_t>::iterator i;

    // for (i = _orderstack.begin(); i != _orderstack.end(); ++i)
    //     std::cout << i->order << std::endl;
}

Bot::~Bot(void)
{}

void Bot::run(void)
{
    // char *order;

    while (true) {
        dprintf(_sock, "Forward");
    }
    close(_sock);
}

void Bot::botLogic(void)
{}

void Bot::sendOrder(void)
{}

void Bot::setInventory(std::string inventory)
{
    (void)inventory;
}

void Bot::getView(void)
{}

void Bot::getInventory(void)
{}