/*
** EPITECH PROJECT, 2019
** zappy_ai
** File description:
** main function of project
*/

#include <iostream>
#include <string.h>
#include "ai.hpp"
#include "structure.hpp"

void help()
{
	std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
	std::cout << "       port    is the port number" << std::endl;
	std::cout << "		 name    is the name of the team" << std::endl;
	std::cout << "		 machine is the name of the machine: localhost par default" << std::endl;
}

arg_t parse_arg(char *av[])
{
	arg_t argument;

	for (int i = 0; av[i]; i++) {
		if (av[i] == "-p") {
			i++;
			argument.port = av[i];
		}
		if (av[i] == "-n") {
			i++;
			argument.name = av[i];
		}
		if (av[i] == "-h") {
			i++;
			argument.machine = av[i];
		}
	}
	return (argument);
}

int main(int ac, char **av, char **envp)
{
	arg_t argument;

	if (ac == 2 && strcmp(av[1], "-help") == 0) {
		help();
		return (MY_EXIT_SUCCESS);
	}
	if (!envp[0] || ac != 7);
		return (MY_EXIT_ERROR);
	argument = parse_arg(av);
	//connect(argument);
	return (MY_EXIT_SUCCESS);
}
