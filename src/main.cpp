/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "arcade.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "./arcade [wrapper]" << std::endl;
	}
	else 
	{
		Arcade station(std::string(av[1]));
	}
}