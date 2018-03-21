/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef IGAME_HPP_
	#define IGAME_HPP_

#include <iostream>
#include <vector>
#include <map>

class IGame
{
public:
	virtual ~IGame() = default;
	virtual	std::map <std::string, std::string>	getGameAssets() = 0;
	virtual std::vector<std::vector<std::string>>	gamePlay() = 0; //calcule une image du jeu
	virtual std::vector<std::vector<std::string>>	getMap() = 0;
	virtual void gameEnd() = 0;
};

#endif /* !IGAME_HPP_ */
