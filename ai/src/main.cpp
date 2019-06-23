/*
** EPITECH PROJECT, 2019
** zappy_ai
** File description:
** main function of zappy_ai
*/

#include <string.h>

#include "parameter.hpp"
#include "zappyai.hpp"
#include "client.hpp"

static int client(args_t *arguments)
{
	Client client = Client(arguments);

	return (client.launch());
}

static int client_launcher(int ac, char **av)
{
	args_t *arguments = arg_parsing(ac, av);

	if (!arguments)
		return (FAILURE);
	return (client(arguments));
}

int main(int ac, char **av, char **envp)
{
	if (ac == 2 && !strcmp(av[1], HELPFLAG))
		return (help_display(av[0]));
	if (envp[0] && ac == 7)
		return (client_launcher(ac, av));
	return (FAILURE);
}