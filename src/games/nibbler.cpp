/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "nibbler.hpp"

extern "C" IGame	*createGame()
{
	return new Nibbler();
}

extern "C" void	destroyGame(IGame *jeu)
{
	delete jeu;
}

Nibbler::Nibbler()
{
	std::cout << "Oue un nibbler" << std::endl;
	create_map();
	initWall();
}

Nibbler::~Nibbler()
{
}

void Nibbler::create_map()
{
	std::ifstream file;
	std::string str;

	file.open("assets/nibbler/map.txt");
	if (!file)
		return ;
	while (std::getline(file, str))
		this->_map.push_back(readLine(str));
	std::cout << "Loaded map" << std::endl;
}

std::vector<std::string> Nibbler::readLine(std::string line)
{
	std::vector<std::string> tmp;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] == '-')
			tmp.push_back("wall_H");
		else if (line[i] == '|')
			tmp.push_back("wall_V");
		else if (line[i] == '0')
			tmp.push_back("wall_P");
		if (line[i] == ' ')
			tmp.push_back("void");
		if (line[i] == 'H')
			tmp.push_back("head");
		if (line[i] == 'B')
			tmp.push_back("body");
	}
	return tmp;
}

void	Nibbler::initWall()
{
	_assets.clear();
	_assets.push_back(std::vector<std::string>{"wall_H", "assets/nibbler/wall_H.png", "-", "0"});
	_assets.push_back(std::vector<std::string>{"wall_V", "assets/nibbler/wall_V.png", "-", "0"});
	_assets.push_back(std::vector<std::string>{"wall_P", "assets/nibbler/wall_P.png", "-", "0"});
	_assets.push_back(std::vector<std::string>{"head", "assets/nibbler/head.png", "-", "0"});
	_assets.push_back(std::vector<std::string>{"skin", "assets/nibbler/skin.png", "-", "0"});
}

void	Nibbler::initPerso()
{
}

std::vector<std::vector<std::string>>	Nibbler::getGameAssets()
{
	return _assets;
}

bool					Nibbler::gamePlay()
{
	return false;	
}

std::vector<std::vector<std::string>>	Nibbler::getMap()
{
	return _map;
}

std::pair<bool, IGame::state>			Nibbler::gameEnd()
{
	return {true, WIN};
}

void Nibbler::setKey(std::string key)
{
}

std::vector<std::string>	Nibbler::getInfos()
{
	return std::vector<std::string>({"Coucou", "Tokou il ai pede"});
}