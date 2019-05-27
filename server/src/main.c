/*
** EPITECH PROJECT, 2019
** zappy_server
** File description:
** main function of project
*/

#include <string.h>
#include "server.h"
#include "usage.h"

int main(int ac, char **av, char **envp)
{
    (void)av;
    
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        help();
        return (0);
    }
    if (!envp[0] || ac < 13)
        return (MY_EXIT_ERROR);
    return (MY_EXIT_SUCCESS);
}
