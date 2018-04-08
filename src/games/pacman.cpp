/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "pacman.hpp"

bool operator==(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
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
	_score = 0;
	_lastHit = 0;
	_nbPacdot = 0;
	_playerLife = 3;
	_nbPacdotEat = 0;
	_mobStatus = true;
	initSetPacman();
	initWallPacman();
	initPersoPacman();
	createMap();
}

Pacman::~Pacman()
{
}

std::string	Pacman::readLine(char c, int x, int y)
{
	switch (c)
	{
		case '-' : return "wall_H";
		case '|' : return "wall_V";
		case '0' : return "wall_P";
		case 'S' : return "food_S";
		case ' ' :
			_nbPacdot++;
			return "food";
		case 'P' :
			_posPlayer = {y, x};
			return "perso_R";
		case 'M' :
			_posEnemy.push_back({y, x});
			return "monster_R";
		case 'G' : 
			_gate.push_back({y, x});
			return "gate";
	}
	return "food";
}

std::vector<std::string> Pacman::readLine(std::string line)
{
	static int x = -1;
	static int y = -1;
	std::vector<std::string> tmp;
	y++;
	for (size_t i = 0; i < line.size(); i++)
	{
		x++;
		tmp.push_back(readLine(line[i], x, y));
	}
	x = -1;
	return tmp;
}

void	Pacman::initWallPacman()
{
	_assets.push_back(std::vector<std::string>{"wall_H","assets/pacman/wall_H.png", "-", "0", "6"});
	_assets.push_back(std::vector<std::string>{"wall_V","assets/pacman/wall_V.png", "|", "0", "6"});
	_assets.push_back(std::vector<std::string>{"wall_P","assets/pacman/wall_P.png", "0", "0", "6"});
	_assets.push_back(std::vector<std::string>{"food", "assets/pacman/pacdot.png", ".", "0", "2"});
	_assets.push_back(std::vector<std::string>{"food_S", "assets/pacman/food_S.png", "@", "0", "5"});
	_assets.push_back(std::vector<std::string>{"food_M", "assets/pacman/food_M.png", "W", "0", "4"});
	_assets.push_back(std::vector<std::string>{"back", "assets/pacman/back.png", " ", "0", "0"});
	_assets.push_back(std::vector<std::string>{"gate", "assets/pacman/back.png", "|", "0", "5"});
}

void	Pacman::initPersoPacman()
{
	_assets.push_back(std::vector<std::string>{"perso_R", "assets/pacman/perso_R.png", "<", "0", "3"});
	_assets.push_back(std::vector<std::string>{"perso_L", "assets/pacman/perso_L.png", ">", "0", "3"});
	_assets.push_back(std::vector<std::string>{"perso_T", "assets/pacman/perso_T.png", "u", "0", "3"});
	_assets.push_back(std::vector<std::string>{"perso_B", "assets/pacman/perso_B.png", "n", "0", "3"});
	_assets.push_back(std::vector<std::string>{"perso_C", "assets/pacman/perso_C.png", "o", "0", "3"});
	_assets.push_back(std::vector<std::string>{"monster_R", "assets/pacman/monster.png", "M", "0", "1"});
	_assets.push_back(std::vector<std::string>{"monster_L", "assets/pacman/monster.png", "M", "0", "1"});
	_assets.push_back(std::vector<std::string>{"monster_T", "assets/pacman/monster.png", "M", "0", "1"});
	_assets.push_back(std::vector<std::string>{"monster_B", "assets/pacman/monster.png", "M", "0", "1"});
	_assets.push_back(std::vector<std::string>{"monster_C", "assets/pacman/monster.png", "M", "0", "1"});
	_assets.push_back(std::vector<std::string>{"monster_W", "assets/pacman/monster.png", "M", "0", "4"});
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
	switch (_key)
	{
		case ILib::LEFT: return  {"perso_L",{0, -1}};
		case ILib::RIGHT : return {"perso_R", {0, 1}};
		case ILib::UP : return {"perso_T", {-1, 0}};
		case ILib::DOWN : return {"perso_B", {1, 0}};
		default : return {"", {0, 0}};
	}
}

void	Pacman::setKey(ILib::Key key)
{
	_key = key;
}

void	Pacman::movePlayer()
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

void	Pacman::playerGetDamage()
{
	if (_lastHit + 3 >= getTime())
	{
		_playerLife--;
		_lastHit = getTime();
	}
}

std::pair<int, int>	Pacman::checkColideEnemy(std::pair<int, int> tmp, std::pair<int, int> pos)
{
	static std::string stringOldPose = "back";
	_map[pos.first][pos.second] = stringOldPose;
	if (_map[pos.first + tmp.first][pos.second].find("wall") == std::string::npos
	&& _map[pos.first + tmp.first][pos.second].find("monster") == std::string::npos)
		pos.first += tmp.first;
	else if (_map[pos.first][pos.second + tmp.second].find("wall") == std::string::npos
	&& _map[pos.first][pos.second + tmp.second].find("monster") == std::string::npos)
		pos.second += tmp.second;
	if (_map[pos.first][pos.second].find("perso") != std::string::npos)
		playerGetDamage();
	stringOldPose = _map[pos.first][pos.second];
	_map[pos.first][pos.second] = "monster_C";
	return {pos.first, pos.second};
}

std::pair<int, int>	Pacman::moveOneEnemy(std::pair<int, int> pos)
{
	std::pair<int, int> tmp;
	tmp.first = pos.first > _posPlayer.first ? -1 : 1;
	tmp.second = pos.second > _posPlayer.second ? -1 : 1;
	return checkColideEnemy(tmp, pos);
}

size_t	Pacman::getTime()
{
	return (clock() / CLOCKS_PER_SEC);
}

std::pair<int, int>	Pacman::checkColideEnemyEscape(std::pair<int, int> tmp, std::pair<int, int> pos)
{
	static std::string stringOldPose = "back";
	_map[pos.first][pos.second] = stringOldPose;
	if (_map[pos.first + tmp.first][pos.second].find("wall") == std::string::npos
	&& _map[pos.first + tmp.first][pos.second].find("food_M") == std::string::npos)
		pos.first += tmp.first;
	if (_map[pos.first][pos.second + tmp.second].find("wall") == std::string::npos
	&& _map[pos.first][pos.second + tmp.second].find("food_M") == std::string::npos)
		pos.second += tmp.second;
	if (_map[pos.first][pos.second].find("perso") != std::string::npos)
	{
		stringOldPose = "back";
		return {10, 10};
	}
	stringOldPose = _map[pos.first][pos.second];
	_map[pos.first][pos.second] = "food_M";
	return {pos.first, pos.second};
}


std::pair<int, int>	Pacman::escapeOneEnemy(std::pair<int, int> pos)
{
	std::pair<int, int> tmp;
	_timeFood = getTime();
	tmp.first = pos.first > _posPlayer.first ? 1 : -1;
	tmp.second = pos.second > _posPlayer.second ? 1 : -1;
	return checkColideEnemyEscape(tmp, pos);
}

void Pacman::moveEnemy()
{
	int i = -1;
	if (_timeFood + 10 >= getTime())
	{
		_mobStatus = true;
		changeFoodToMonster();
	}
	if (!_mobStatus) 
		for(auto el: _posEnemy)
			_posEnemy[++i] = escapeOneEnemy(el);
	if (_mobStatus)
		for(auto el: _posEnemy)
			_posEnemy[++i] = moveOneEnemy(el);
}

std::vector<std::pair<std::string, std::string>>	Pacman::getInfos()
{
	std::vector<std::pair<std::string, std::string>> tmp;
	tmp.push_back({"score", std::to_string(_score)});
	tmp.push_back({"life", std::to_string(_playerLife)});
	tmp.push_back({"time", std::to_string(getTime())});
	tmp.push_back({"jeux", "pacman"});
	return tmp;
}

void	Pacman::changeMonsterToFood()
{
	_mobStatus = false;
	_timeFood = getTime();
	for (auto el: _posEnemy)
		_map[el.first][el.second] = "food_M";
}

void	Pacman::changeFoodToMonster()
{
	_timeFood = 0;
	for (auto el: _posEnemy)
		_map[el.first][el.second] = "monster";
}

void	Pacman::superFood(std::pair<int, int> tmp)
{
	if (_map[tmp.first][tmp.second].find("food") != std::string::npos)
	{
		if (_map[tmp.first][tmp.second] == "food")
			_score += 10;
		else if (_map[tmp.first][tmp.second] == "food_S")
		{
			changeMonsterToFood();
			_score += 100;
		}
		_nbPacdotEat++;
	}
}

bool Pacman::checkColide(std::pair<int, int> input)
{
	std::pair<int, int>tmp = {_posPlayer.first + input.first, _posPlayer.second + input.second};
	
	superFood(tmp);
	if ((_map[tmp.first][tmp.second].find("food") != std::string::npos) 
		|| _map[tmp.first][tmp.second] == "back")
		if (tmp.second >= 0 && tmp.second <= int(_map[tmp.first].size()) - 1)
			return true;
	if (_map[tmp.first][tmp.second].find("monster") != std::string::npos)
		playerGetDamage();
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
	static int i = 0;
	movePlayer();
	if (++i % 3 && getTime() > 3)
		moveEnemy();
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
	if (_nbPacdot == _nbPacdotEat)
		return {false, WIN};
	if (_playerLife == 0)
		return {false, LOOSE};
	else
		return {true, NEXT_MAP};
}