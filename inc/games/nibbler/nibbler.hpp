/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef NIBBLER_HPP_
	#define NIBBLER_HPP_

#include "IGame.hpp"
#include <string>

class Nibbler : public IGame
{
public:
	Nibbler();
	~Nibbler();
	std::vector<std::vector<std::string>>	getGameAssets();
	bool					gamePlay();
	std::vector<std::vector<std::string>>	getMap();
	void					setKey(std::string key);
	std::vector<std::string>		getInfos();
	std::pair<bool, IGame::state>			gameEnd();
private:
	std::vector<std::string> readLine(std::string line);
	void	initPerso();
	void	initWall();
	void create_map();
	std::vector<std::vector<std::string>>	_map;
	std::pair<size_t, size_t>	_posPlayer;
	std::vector<std::pair<size_t, size_t>> _posBonus;
	std::vector<std::vector<std::string>> _assets;
};

#endif /* !NIBBLER_HPP_ */
