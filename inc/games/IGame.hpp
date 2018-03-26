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
#include <fstream>

class IGame
{
public:
	virtual						~IGame() = default;
	virtual	std::vector<std::vector<std::string>>	getGameAssets() = 0;
	virtual bool					gamePlay() = 0; //calcule une image du jeu
	virtual std::vector<std::vector<std::string>>	getMap() = 0;
	virtual void	setKey(std::string key) = 0;
	virtual std::vector<std::string>	getInfos() = 0;
	virtual std::pair<bool, int> gameEnd() = 0;
};

#endif /* !IGAME_HPP_ */
