/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "pacman.hpp"

#include <fstream>

Game::Game()
{
	createMap();
}

Game::~Game()
{
}

extern "C" std::vector<std::string> Game::readLine(std::string line)
{
	std::vector<std::string> tmp;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] == '-')
			tmp.push_back("wall_H");
		if (line[i] == '|')
			tmp.push_back("wall_V");
		if (line[i] == '0')
			tmp.push_back("wall_P");
	}
	return tmp;
}

extern "C" void	Game::createMap()
{
	std::ifstream file;
	file.open("assest/pacman/map.txt");
	std::string str;
	std::getline(file, str);
	this->_map.push_back(readLine(str));
	for(; !file.eof(); std::getline(file, str)) {
		this->_map.push_back(readLine(str));
	}
	dumpMap();
}

extern "C" void Game::dumpMap()
{
	for(auto el:_map)
	{
		for (auto it:el)
			std::cout << it;
		std::cout << std::endl;
	}
}

extern "C" Game	Game::gameStart()
{
	Game tmp;
	return tmp;
}

extern "C" void	Game::gameEnd()
{
	this->~Game();
}

extern "C" void	Game::mouvePlayer()
{
}

extern "C" void Game::mouveEnemy()
{
}

extern "C" void checkColide()
{
}

extern "C" void	Game::gamePlay()
{
	mouvePlayer();
	mouveEnemy();
	checkColide();
}