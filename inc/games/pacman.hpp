/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef PACMAN_HPP_
	#define PACMAN_HPP_

#include "IGame.hpp"
#include "Ilib.hpp"
#include <iostream>
#include <cstddef>

class Pacman : public IGame
{
public:
	Pacman();
	~Pacman();
	bool	gamePlay();
	void	setKey(ILib::Key key);
	std::pair<bool, IGame::state>	gameEnd();
	std::vector<std::vector<std::string>>	getMap();
	std::vector<std::vector<std::string>>	getGameAssets();
	std::vector<std::pair<std::string, std::string>>	getInfos();
private:
	void	dumpMap();
	size_t	getTime();
	void	createMap();
	void	moveEnemy();
	void	makesprite();
	void	movePlayer();
	void	initSetPacman();
	void	initWallPacman();
	void	playerGetDamage();
	void	initPersoPacman();
	void	changeFoodToMonster();
	void	changeMonsterToFood();
	bool	checkColide(std::pair<int, int>);
	void	superFood(std::pair<int, int> tmp);
	std::string	readLine(char c, int x, int y);
	std::vector<std::string> readLine(std::string line);
	std::pair<int, int>	moveOneEnemy(std::pair<int, int> pos);
	std::pair<int, int>	escapeOneEnemy(std::pair<int, int> pos);
	std::pair<std::string, std::pair<int, int>>	mouveSpritePlayer();
	std::pair<int, int>	checkColideEnemy(std::pair<int, int> tmp, std::pair<int, int> pos);
	std::pair<int, int>	checkColideEnemyEscape(std::pair<int, int> tmp, std::pair<int, int> pos);

	size_t	_score;
	size_t _lastHit;
	size_t	_timeFood;
	size_t	_nbPacdot;
	bool	_mobStatus;
	int	_playerLife;
	ILib::Key	_key;
	size_t	_nbPacdotEat;
	std::pair<int, int>	_posPlayer;
	std::vector<std::string>	_menu;
	std::vector<std::pair<int, int>> _gate;
	std::vector<std::pair<int, int>> _posEnemy;
	std::map <std::string, std::string> _setting;
	std::vector<std::vector<std::string>>	_map;
	std::vector<std::vector<std::string>> _assets;
};

#endif /* !PACMAN_HPP_ */
