/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "pacman.hpp"


bool operator==(const std::pair<int, int>& lhs, const std::pair<size_t, size_t>& rhs)
{
	std::pair<int, int> tmp = {rhs.first, rhs.second};
	if (tmp.first == lhs.first && tmp.second == lhs.second)
		return true;
	return false;
}

extern "C" IGame	*createGame()
{
	return new Pacman();
}

extern "C" void destroyGame(IGame *game)
{
	delete game;
}


Pacman::Pacman()
{
	initSetPacman();
	initWallPacman();
	initPersoPacman();
	createMap();
}

Pacman::~Pacman()
{
}

std::vector<std::string> Pacman::readLine(std::string line)
{
	static size_t x = -1;
	static size_t y = -1;
	std::vector<std::string> tmp;
	y++;
	for (size_t i = 0; i < line.size(); i++)
	{
		x++;
		if (line[i] == '-')
			tmp.push_back("wall_H");
		else if (line[i] == '|')
			tmp.push_back("wall_V");
		else if (line[i] == '0')
			tmp.push_back("wall_P");
		else if (line[i] == ' ')
		{
			tmp.push_back("food");
			_nbPacdot++;
		}
		else if (line[i] == 'P')
		{
			tmp.push_back("perso_R");
			_posPlayer = {y, x};
		}
		else if (line[i] == 'M')
		{
			tmp.push_back("monster_R");
			_posEnemy.push_back({y, x});
		}
		else if (line[i] == 'G')
		{
			tmp.push_back("gate");
			_gate.push_back({y, x});
		}
	}
	x = -1;
	return tmp;
}

void	Pacman::initWallPacman()
{
	_assets.push_back(std::vector<std::string>{"wall_H","assets/pacman/wall_H.png", "-", "0"});
	_assets.push_back(std::vector<std::string>{"wall_V","assets/pacman/wall_V.png", "|", "0"});
	_assets.push_back(std::vector<std::string>{"wall_P","assets/pacman/wall_P.png", "0", "0"});
	_assets.push_back(std::vector<std::string>{"food", "assets/pacman/pacdot.png", ".", "0"});
	_assets.push_back(std::vector<std::string>{"back", "assets/pacman/back.png", " ", "0"});
}

void	Pacman::initPersoPacman()
{
	_assets.push_back(std::vector<std::string>{"perso_R", "assets/pacman/perso_R.png", "<", "0"});
	_assets.push_back(std::vector<std::string>{"perso_L", "assets/pacman/perso_L.png", ">", "0"});
	_assets.push_back(std::vector<std::string>{"perso_T", "assets/pacman/perso_T.png", "u", "0"});
	_assets.push_back(std::vector<std::string>{"perso_B", "assets/pacman/perso_B.png", "n", "0"});
	_assets.push_back(std::vector<std::string>{"perso_C", "assets/pacman/perso_C.png", "o", "0"});
	_assets.push_back(std::vector<std::string>{"monster_R", "assets/pacman/monster.png", "M", "0"});
	_assets.push_back(std::vector<std::string>{"monster_L", "assets/pacman/monster.png", "M", "0"});
	_assets.push_back(std::vector<std::string>{"monster_T", "assets/pacman/monster.png", "M", "0"});
	_assets.push_back(std::vector<std::string>{"monster_B", "assets/pacman/monster.png", "M", "0"});
	_assets.push_back(std::vector<std::string>{"monster_C", "assets/pacman/monster.png", "M", "0"});
}

void	Pacman::initSetPacman()
{
	std::pair<std::string, std::string> tmp;
	tmp.first = "map";
	tmp.second = "assets/pacman/map.txt";
	_setting.insert(tmp);
}

void	Pacman::createMap()
{
	std::ifstream file;
	file.open("assets/pacman/map.txt");
	std::string str;
	while (std::getline(file, str)) 
		this->_map.push_back(readLine(str));
}

void Pacman::dumpMap()
{
	for(auto el : _map)
	{
		for (auto it:el)
			std::cout << it + " ";
		std::cout << std::endl;
	}
}

std::pair<std::string, std::pair<int, int>>	Pacman::mouveSpritePlayer()
{
	if (_key == "left")
		return {"perso_L",{0, -1}};
	else if (_key == "right")
		return {"perso_R", {0, 1}};
	else if (_key == "up")
		return {"perso_T", {-1, 0}};
	else if (_key == "down")
		return {"perso_B", {1, 0}};
	return {"", {0, 0}};
}

void	Pacman::setKey(std::string key)
{
	_key = key;
}

void	Pacman::mouvePlayer()
{
	std::pair<std::string, std::pair<int, int>> tmp;
	tmp  = mouveSpritePlayer();
	if (tmp.first != "" && checkColide(tmp.second))
	{
		_map[_posPlayer.first][_posPlayer.second] = "back";
		_posPlayer.first += tmp.second.first;
		_posPlayer.second += tmp.second.second;
		_map[_posPlayer.first][_posPlayer.second] = tmp.first;
	}
}

void Pacman::mouveEnemy()
{
	//for(auto el: _posEnemy)
	{
	}
}

std::vector<std::pair<std::string, std::string>>	Pacman::getInfos()
{
	std::vector<std::pair<std::string, std::string>> tmp;
	tmp.push_back({"score", std::to_string(_score)});
	tmp.push_back({"life", std::to_string(_playerLife)});
	return tmp;
}

bool Pacman::checkColide(std::pair<int, int> input)
{
	std::pair<int, int>tmp = {_posPlayer.first + input.first, _posPlayer.second + input.second};
	if (_map[tmp.first][tmp.second] == "food")
		_score++;
	if (_map[tmp.first][tmp.second] == "food" || _map[tmp.first][tmp.second] == "back")
		if (tmp.second >= 0 && tmp.second <= int(_map[tmp.first].size()) - 1)
			return true;
	if (_map[tmp.first][tmp.second].find("monster") != std::string::npos)
		_playerLife -= 1;
	if (_map[tmp.first][tmp.second] == "gate")
	{
		_map[_posPlayer.first][_posPlayer.second] = "back";
		if (tmp == _gate[0])
			_posPlayer = _gate[1];
		if (tmp == _gate[1])
			_posPlayer = _gate[0];
		_map[_posPlayer.first][_posPlayer.second] = "back";
		return false;
	}
	return false;
}

bool	Pacman::gamePlay()
{
	mouvePlayer();
	mouveEnemy();
	return true;
}

std::vector<std::vector<std::string>>	Pacman::getMap()
{
	return _map;
}

std::vector<std::vector<std::string>>	Pacman::getGameAssets()
{
	_assets.clear();
	initSetPacman();
	initWallPacman();
	initPersoPacman();
	return _assets;
}

std::pair<bool, IGame::state>	Pacman::gameEnd()
{
	if (_nbPacdot == _score)
	{
		return {false, WIN};
	}
	if (_playerLife == 0)
	{
		return {false, LOOSE};
	}
	else
	{
		return {true, NEXT_MAP};
	}
}