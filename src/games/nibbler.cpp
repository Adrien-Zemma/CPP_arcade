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
	initCoords();
	_key = ILib::UNKNOW;
}

Nibbler::~Nibbler()
{
}

void	Nibbler::initCoords()
{
	for (size_t i = 0; i < _map.size(); i++) {
		for (size_t j = 0; j < _map[i].size(); j++) {
			if (_map[i][j] == "head_l" || _map[i][j] == "skin") {
				_coords.push_back({i, j});
			}
		}
	}
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
		if (line[i] == 'H')
			tmp.push_back("head_L");
		else if (line[i] == 'S')
			tmp.push_back("skin");
		else if (line[i] == ' ')
			tmp.push_back("void");
	}
	return tmp;
}

void	Nibbler::initWall()
{
	_assets.clear();
	_assets.push_back(std::vector<std::string>{"wall_H", "assets/nibbler/wall_H.png", "-", "0"});
	_assets.push_back(std::vector<std::string>{"wall_V", "assets/nibbler/wall_V.png", "|", "0"});
	_assets.push_back(std::vector<std::string>{"wall_P", "assets/nibbler/wall_P.png", "O", "0"});
	_assets.push_back(std::vector<std::string>{"head_D", "assets/nibbler/head_U.png", "H", "0"});
	_assets.push_back(std::vector<std::string>{"head_R", "assets/nibbler/head_L.png", "H", "0"});
	_assets.push_back(std::vector<std::string>{"head_U", "assets/nibbler/head_D.png", "H", "0"});
	_assets.push_back(std::vector<std::string>{"head_L", "assets/nibbler/head_R.png", "H", "0"});
	_assets.push_back(std::vector<std::string>{"skin", "assets/nibbler/skin.png", "H", "0"});
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
	movePlayer();
	return true;
}

std::vector<std::vector<std::string>>	Nibbler::getMap()
{
	return _map;
}

std::pair<bool, IGame::state>			Nibbler::gameEnd()
{
	return {true, WIN};
}

std::pair<std::string, std::pair<int, int>>	Nibbler::mouveSpritePlayer()
{
	if (_key == ILib::LEFT)
		return {"head_R",{0, -1}};
	else if (_key == ILib::RIGHT)
		return {"head_L", {0, 1}};
	else if (_key == ILib::UP)
		return {"head_D", {-1, 0}};
	else if (_key == ILib::DOWN)
		return {"head_U", {1, 0}};
	return {"", {0, 0}};
}

void Nibbler::moveChara(size_t i)
{
	std::pair<std::string, std::pair<int, int>>	tmp;

	tmp = mouveSpritePlayer();
	if (checkColide(_coords[i], tmp.second)) {
		if (tmp.first != "") {
			_map[_coords[i].first + tmp.second.first][_coords[i].second + tmp.second.second] = (i == 0 ? tmp.first : "skin");
			_map[_coords[i].first][_coords[i].second] = "void";
			_coords[i].first += tmp.second.first;
			_coords[i].second += tmp.second.second;
		}
	}
}

void	Nibbler::movePlayer()
{
	moveChara(0);
	for (size_t i = 0; i < _coords.size(); i++) {
		moveChara(i);
	}
}

bool Nibbler::checkColide(std::pair<int, int> input, std::pair<int, int> move)
{
	if (_map[input.first + move.first][input.second + move.second].find("wall") != std::string::npos)
		return false;
	return true;
}

void Nibbler::setKey(ILib::Key key)
{
	_key = key;
}

std::vector<std::pair<std::string, std::string>>	Nibbler::getInfos()
{
	std::vector<std::pair<std::string, std::string>> tmp;
	tmp.push_back({"Test", "Coucou"});
	return tmp;
}