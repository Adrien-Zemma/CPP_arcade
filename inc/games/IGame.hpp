/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef IGAME_HPP_
	#define IGAME_HPP_


#include "pacman.hpp"
#include "nibbler.hpp"
#include <iostream>

class IGame
{
public:
	virtual ~IGame() = 0;
	virtual void gamePlay() = 0; //calcule une image du jeu
	virtual void gameEnd() = 0;
};

#endif /* !IGAME_HPP_ */
