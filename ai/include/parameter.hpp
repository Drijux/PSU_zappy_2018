//
// EPITECH PROJECT, 2019
// zappy_ai
// File description:
// variable and enum for zappy_ai
//

#ifndef PARAMETER_HPP_
# define PARAMETER_HPP_

#include <stdlib.h>

// EXIT RETURN VARIABLES OF PROJECT
static const __attribute__((unused)) int SUCCESS = 0;
static const __attribute__((unused)) int FAILURE = 84;

// FLAGS GESTION VARIABLES
static const __attribute__((unused)) char HELPFLAG[] = "-help";
static const __attribute__((unused)) char OPTSTRING[] = "p:n:h:";

//HELP OF PROJECT
static const __attribute__((unused)) char *HELP[5] = {
    " -p port -n name -h machine",
    "\tport    is the port number",
	"\tname    is the name of the team",
	"\tmachine is the name of the machine: localhost par default",
    NULL
};

#endif /* PARAMETER_HPP_ */