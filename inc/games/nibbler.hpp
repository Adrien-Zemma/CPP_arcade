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
	std::map <std::string, std::string>	getGameAssets();
	bool					gamePlay();
	std::vector<std::vector<std::string>>	getMap();
private:
	std::vector<std::string> readLine(std::string line);
	void create_map();
	std::vector<std::vector<std::string>>	_map;
	std::pair<size_t, size_t>	_posPlayer;
	std::vector<std::pair<size_t, size_t>> _posBonus;
	std::map <std::string, std::string> _assets;
};

#endif /* !NIBBLER_HPP_ */
