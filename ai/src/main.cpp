/*
** EPITECH PROJECT, 2019
** zappy_ai
** File description:
** main function of project
*/

#include "ai.hpp"

int main(int ac, char **av, char **envp)
{
	(void)av;

	if (!envp[0] || ac < 5)
		return (MY_EXIT_ERROR);
	return (MY_EXIT_SUCCESS);
}
