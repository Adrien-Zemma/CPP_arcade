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

Nibbler::Nibbler()
{
	std::cout << "Oue un nibbler" << std::endl;
	create_map();
	initWall();
	for (auto &it : _map) {
    		for (auto &el : it) {
			    std::cout << el;
		}
		std::cout << std::endl;
	}
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
		if (line[i] == '|')
			tmp.push_back("wall_V");
		if (line[i] == '0')
			tmp.push_back("wall_P");
		if (line[i] == ' ')
			tmp.push_back("void");
	}
	return tmp;
}

void	Nibbler::initWall()
{
	std::pair<std::string, std::string> tmp;
	tmp.first = "wall_H";
	tmp.second = "assets/nibbler/wall_H.png";
	_assets.insert(tmp);
	tmp.first = "wall_V";
	tmp.second = "assets/nibbler/wall_V.png";
	_assets.insert(tmp);
	tmp.first = "wall_P";
	tmp.second = "assets/nibbler/wall_P.png";
	_assets.insert(tmp);
}

void	Nibbler::initPerso()
{
}

std::map <std::string, std::string>	Nibbler::getGameAssets()
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