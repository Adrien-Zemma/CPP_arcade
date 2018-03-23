/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "arcade.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		Arcade station(av[1]);
		station.start();
	}
}