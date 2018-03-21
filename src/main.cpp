/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "arcade.hpp"

int	main(int ac, char **av)
{

	std::cout << "debut main" << std::endl;
	if (ac == 2)
	{
		Arcade station(av[1]);
		station.start();
	}
	std::cout << "fin main" << std::endl;
	(void)av;
}