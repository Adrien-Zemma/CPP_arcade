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
	return new Game();
}

Game::Game()
{
	initSetPacman();
	initWallPacman();
	initPersoPacman();
	createMap();
}

Game::~Game()
{
}

std::vector<std::string> Game::readLine(std::string line)
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

void	Game::initWallPacman()
{
	std::pair<std::string, std::string> tmp;
	tmp.first = "wall_H";
	tmp.second = "assets/pacman/wall_H.png";
	_assets.insert(tmp);
	tmp.first = "wall_V";
	tmp.second = "assets/pacman/wall_V.png";
	_assets.insert(tmp);
	tmp.first = "wall_P";
	tmp.second = "assets/pacman/wall_P.png";
	_assets.insert(tmp);
	tmp.first = "food";
	tmp.second = "assets/pacman/pacdot.png";
	_assets.insert(tmp);
	tmp.first = "back";
	tmp.second = "assets/pacman/back.png";
	_assets.insert(tmp);
}

void	Game::initPersoPacman()
{
	std::pair<std::string, std::string> tmp;
	tmp.first = "perso_R";
	tmp.second = "assets/pacman/perso_R.png";
	_assets.insert(tmp);
	tmp.first = "perso_L";
	tmp.second = "assets/pacman/perso_L.png";
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
	std::ifstream file;
	file.open("assets/pacman/map.txt");
	std::string str;
	while (std::getline(file, str)) 
		this->_map.push_back(readLine(str));
}

void Game::dumpMap()
{
	for(auto el : _map)
	{
		for (auto it:el)
			std::cout << it + " ";
		std::cout << std::endl;
	}
}

std::pair<std::string, std::pair<int, int>>	Game::mouveSpritePlayer()
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

void	Game::setKey(std::string key)
{
	_key = key;
}

void	Game::mouvePlayer()
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

void Game::mouveEnemy()
{
}

std::vector<std::string>	Game::getInfos()
{
	std::vector<std::string> tmp;
	tmp.push_back(std::to_string(_score));
	tmp.push_back(std::to_string(_playerLife));
	std::cout << _score << std::endl;
	return tmp;
}

bool Game::checkColide(std::pair<int, int> input)
{
	std::pair<int, int>tmp = {_posPlayer.first + input.first, _posPlayer.second + input.second};
	if (_map[tmp.first][tmp.second] == "food")
		_score++;
	if (_map[tmp.first][tmp.second] == "food" || _map[tmp.first][tmp.second] == "back")
		if (tmp.second >= 0 && tmp.second < int(_map[tmp.first].size()) - 1)
			return true;
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

bool	Game::gamePlay()
{
	mouvePlayer();
	mouveEnemy();
	return true;
}

std::vector<std::vector<std::string>>	Game::getMap()
{
	return _map;
}

std::map <std::string, std::string>	Game::getGameAssets()
{
	return _assets;
}
