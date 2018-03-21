/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "nibbler.hpp"

Nibbler::Nibbler()
{
	std::cout << "Oue un nibbler" << std::endl;
	create_map();
}

Nibbler::~Nibbler()
{
	
}

void Nibbler::create_map()
{
	std::ifstream file;
	std::string str;

	file.open("assets/nibbler/map.txt");
	while (std::getline(file, str))
		this->_map.push_back(readLine(str));
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
			tmp.push_back("food");
	}
	return tmp;
}

std::map <std::string, std::string>	Nibbler::getGameAssets()
{
	
}

bool					Nibbler::gamePlay()
{
	return false;	
}

std::vector<std::vector<std::string>>	Nibbler::getMap()
{
	
}