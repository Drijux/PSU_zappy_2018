/*
** EPITECH PROJECT, 2019
** zappy_server
** File description:
** main function of project
*/

#include "server.h"

int main(int ac, char **av, char **envp)
{
	(void)av;

	if (!envp[0] || ac < 13)
		return (MY_EXIT_ERROR);
	
	return (MY_EXIT_SUCCESS);
}
