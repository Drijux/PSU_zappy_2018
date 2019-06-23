/*
** EPITECH PROJECT, 2019
** zappy_ai
** File description:
** Arguments handling
*/

#include <iostream>
#include <unistd.h>
#include <ctype.h>
#include "parameter.hpp"
#include "structure.hpp"

static bool set_parameters(int ac, char **av, args_t *args)
{
    int opt = 0;

    while ((opt = getopt(ac, av, OPTSTRING)) != -1) {
		switch (opt) {
			case 'p':
				args->port = optarg;
				break;
			case 'n':
				args->team = optarg;
				break;
			case 'h':
				args->machine = optarg;
				break;
			default:
				return (false);
		}
	}
    return (true);
}

args_t *arg_parsing(int ac, char **av)
{
    args_t *arguments = (args_t *) malloc(sizeof(args_t));

    if (!arguments || !set_parameters(ac, av, arguments))
        return (NULL);
    for (int i = 0; arguments->port[i]; i++)
        if (!isdigit(arguments->port[i]))
            return (NULL);
    return (arguments);
}

int help_display(char *binary)
{
    std::cout << "USAGE: " << binary;
    for (int i = 0; HELP[i]; i++)
        std::cout << HELP[i] << std::endl;
    return (SUCCESS);
}