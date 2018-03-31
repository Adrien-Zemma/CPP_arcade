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
#include <ctime>
#include "Ilib.hpp"

class IGame
{
public:
	enum state
	{
		WIN,
		LOOSE,
		NEXT_MAP,
	};
	virtual	~IGame() = default;
	virtual bool	gamePlay() = 0; //calcule une image du jeu
	virtual void	setKey(ILib::Key key) = 0;
	virtual std::pair<bool, IGame::state> gameEnd() = 0;
	virtual std::vector<std::vector<std::string>>	getMap() = 0;
	virtual	std::vector<std::vector<std::string>>	getGameAssets() = 0;
	virtual std::vector<std::pair<std::string, std::string>>	getInfos() = 0;
	
};

#endif /* !IGAME_HPP_ */
