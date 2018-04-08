/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "arcade.hpp"

int	main(int ac, char **av)
{
	if (ac == 2 && 
	(std::string(av[1]).find("lib_arcade") != std::string::npos &&
	std::string(av[1]).find(".so") != std::string::npos))
	{
		Arcade station(av[1]);
		station.start();
	}
	else
	{
		std::cout << "USAGE:\t"<< av[0] << " lib_name" << std::endl;
		return 84;
	}
}