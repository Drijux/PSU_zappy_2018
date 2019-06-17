/*
** EPITECH PROJECT, 2019
** zappy_ai
** File description:
** main function of project
*/

#include <iostream>
#include <string.h>
#include "ai.hpp"

void help()
{
	std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
	std::cout << "       port    is the port number" << std::endl;
	std::cout << "		 name    is the name of the team" << std::endl;
	std::cout << "		 machine is the name of the machine: localhost par default" << std::endl;
}

int main(int ac, char **av, char **envp)
{
	(void)av;

	if (ac == 2 && strcmp(av[1], "-help") == 0) {
		help();
		return (0);
	}
	if (!envp[0] || ac < 5)
		return (MY_EXIT_ERROR);
	return (MY_EXIT_SUCCESS);
}
