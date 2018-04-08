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
	_coords.push_back({0,0});
	create_map();
	initWall();
	initFood();
	_key = ILib::UNKNOW;
	_isDead = false;
}

Nibbler::~Nibbler()
{
}

void	Nibbler::makeFood()
{
	long int rand_x;
	long int rand_y;
	bool status = true;
	while (status)
	{
		rand_y = rand() % (_map.size() - 1);
		rand_x = rand() % (_map[0].size() - 1);
		if (_map[rand_y][rand_x] == "void")
		{
			_map[rand_y][rand_x] = "food";
			status = false;
			_nbFoods++;
		}
	}
}

void	Nibbler::initFood()
{
	srand(clock() / CLOCKS_PER_SEC);
	for (size_t i = 0; i < 10; i++) {
		makeFood();
	}
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
}

std::string	Nibbler::readLine(char c, int x, int y)
{
	switch (c)
	{
		case '-' : return "wall_H";
		break;
		case '|' : return "wall_V";
		break;
		case '0' : return "wall_P";
		break;
		case 'H' : _coords[0] = {y, x};
			return "head_L";
		break;
		case 'S' : _coords.push_back({y, x});
			return "skin";
		break;
		case ' ' : return "void";
		break;
	}
	return "";
}

std::vector<std::string> Nibbler::readLine(std::string line)
{
	int x = -1;
	static int y = -1;
	std::vector<std::string> tmp;
	y++;
	for (size_t i = 0; i < line.size(); i++)
	{
		x++;
		tmp.push_back(readLine(line[i], x, y));
	}
	return tmp;
}

void	Nibbler::initWall()
{
	_assets.clear();
	_assets.push_back(std::vector<std::string>{"wall_H", "assets/nibbler/wall_H.png", "-", "0", "4"});
	_assets.push_back(std::vector<std::string>{"wall_V", "assets/nibbler/wall_V.png", "|", "0", "4"});
	_assets.push_back(std::vector<std::string>{"wall_P", "assets/nibbler/wall_P.png", "O", "0", "4"});
	_assets.push_back(std::vector<std::string>{"head_U", "assets/nibbler/head_U.png", "H", "0", "7"});
	_assets.push_back(std::vector<std::string>{"head_L", "assets/nibbler/head_L.png", "H", "0", "7"});
	_assets.push_back(std::vector<std::string>{"head_D", "assets/nibbler/head_D.png", "H", "0", "7"});
	_assets.push_back(std::vector<std::string>{"head_R", "assets/nibbler/head_R.png", "H", "0", "7"});
	_assets.push_back(std::vector<std::string>{"skin", "assets/nibbler/skin.png", "H", "0", "3"});
	_assets.push_back(std::vector<std::string>{"food", "assets/nibbler/food.png", "$", "0", "2"});
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
	if (_nbFoods <= 3)
		while (_nbFoods != 10)
			makeFood();
	return true;
}

std::vector<std::vector<std::string>>	Nibbler::getMap()
{
	return _map;
}

std::pair<bool, IGame::state>			Nibbler::gameEnd()
{
	return {_isDead, (_isDead ? LOOSE : WIN)};
}

std::pair<std::string, std::pair<int, int>>	Nibbler::mouveSpritePlayer()
{
	switch (_key)
	{
		case ILib::LEFT : return {"head_R",{0, -1}};
		case ILib::RIGHT : return {"head_L", {0, 1}};
		case ILib::UP : return {"head_D", {-1, 0}};
		case ILib::DOWN : return {"head_U", {1, 0}};
		default: return {"void", {0, 0}};
	}
	return {"void", {0, 0}};
}

void Nibbler::moveChara(size_t i)
{
	std::pair<std::string, std::pair<int, int>>	tmp;

	tmp = mouveSpritePlayer();
	if (checkColide(_coords[i], tmp.second)) {
		if (tmp.first != "") {
			_map[_coords[i].first + tmp.second.first][_coords[i].second + tmp.second.second] = (i == 0 ? tmp.first : "skin");
			_coords[i].first += tmp.second.first;
			_coords[i].second += tmp.second.second;
		}
	}
}

void	Nibbler::goEat()
{
	if (_map[_coords[0].first][_coords[0].second].find("food") == std::string::npos)
		return;
	_nbFoods--;
	int y = _coords[_coords.size() - 1].first;
	int x = _coords[_coords.size() - 1].second;
	if (_map[y + 1][x].find("wall"))
		_coords.push_back({y + 1, x});
	else if (_map[y - 1][x].find("wall"))
		_coords.push_back({y - 1, x});
	else if (_map[y][x - 1].find("wall"))
		_coords.push_back({y, x -1});
	else if (_map[y][x + 1].find("wall"))
		_coords.push_back({y, x + 1});
}

std::string	Nibbler::moveHead()
{
	std::pair<std::string, std::pair<int, int>>	tmp;
	tmp = mouveSpritePlayer();
	if (checkColide(_coords[0], tmp.second)) {
		if (tmp.first != "void") {
			_coords[0].first += tmp.second.first;
			_coords[0].second += tmp.second.second;
			goEat();
		}			
	}
	return tmp.first;
}

void	Nibbler::moveBody()
{
}

void	Nibbler::movePlayer()
{
	std::string tmp;

	if (!checkColide(_coords[0], mouveSpritePlayer().second))
		return ;
	for (size_t i = _coords.size() -1; i > 0; i--) {
		_coords[i] = _coords[i - 1];
		if (i == 1)
			tmp = moveHead();
		_map[_coords[i].first][_coords[i].second] = "skin";
	}
	if (_map[_coords[0].first][_coords[0].second] == "skin")
		_isDead = true;
	_map[_coords[0].first][_coords[0].second] = tmp;
	_map[_coords[_coords.size() - 2].first][_coords[_coords.size() - 2].second] = "skin";
	_map[_coords[_coords.size() - 1].first][_coords[_coords.size() - 1].second] = "void";
}

bool Nibbler::checkColide(std::pair<int, int> input, std::pair<int, int> move)
{
	if (_map[input.first + move.first][input.second + move.second] == "skin") {
		_isDead = true;
		return true;
	}
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

	std::string tmp2 = std::to_string(_coords.size());
	tmp.push_back({"Number of food", std::to_string(_nbFoods)});
	tmp.push_back({"size", tmp2});
	return tmp;
}