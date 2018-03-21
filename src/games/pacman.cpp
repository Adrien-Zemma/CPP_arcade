/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "pacman.hpp"
#include <fstream>

extern "C" IGame	*createGame()
{
	std::cout << "idk quoi mettre" << std::endl;	
	return new Game();
}

Game::Game()
{
	std::cout << "game begin" << std::endl;
	createMap();
}

Game::~Game()
{
}

std::vector<std::string> Game::readLine(std::string line)
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
		if (line[i] == ' ')
			tmp.push_back("food");
	}
	return tmp;
}

void	Game::initWallPacman()
{
	std::pair<std::string, std::string> tmp;
	tmp.first = "wall_H";
	tmp.second = "assets/pacman/wall_T.png";
	_assets.insert(tmp);
	tmp.first = "wall_V";
	tmp.second = "assets/pacman/wall_B.png";
	_assets.insert(tmp);
	tmp.first = "wall_P";
	tmp.second = "assets/pacman/wall_P.png";
	_assets.insert(tmp);
}

void	Game::initPersoPacman()
{
	std::pair<std::string, std::string> tmp;
	tmp.first = "perso_R";
	tmp.second = "assets/pacman/perso_R.png";
	_assets.insert(tmp);
	tmp.first = "perso_L";
	tmp.second = "assets/pacman/perso_T.png";
	_assets.insert(tmp);
	tmp.first = "perso_T";
	tmp.second = "assets/pacman/perso_T.png";
	_assets.insert(tmp);
	tmp.first = "perso_B";
	tmp.second = "assets/pacman/perso_B.png";
	_assets.insert(tmp);
	tmp.first = "perso_C";
	tmp.second = "assets/pacman/perso_C.png";
	_assets.insert(tmp);
}

void	Game::initSetPacman()
{
	std::pair<std::string, std::string> tmp;
	tmp.first = "map";
	tmp.second = "assets/pacman/map.txt";
	_setting.insert(tmp);
}

void	Game::createMap()
{
	initSetPacman();
	initWallPacman();
	initPersoPacman();
	std::ifstream file;
	file.open("assets/pacman/map.txt");
	std::string str;
	while (std::getline(file, str)) 
		this->_map.push_back(readLine(str));
	dumpMap();
}

void Game::dumpMap()
{
	for(auto el:_map)
	{
		for (auto it:el)
			std::cout << it;
		std::cout << std::endl;
	}
}

void	Game::gameEnd()
{
	this->~Game();
}

void	Game::mouvePlayer()
{
}

void Game::mouveEnemy()
{
}

void Game::checkColide()
{
}

std::vector<std::vector<std::string>>	Game::gamePlay()
{
	mouvePlayer();
	mouveEnemy();
	checkColide();
	return _map;
}

std::vector<std::vector<std::string>>	Game::getMap()
{
	return _map;
}