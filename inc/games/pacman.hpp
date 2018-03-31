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
	bool	checkColide(std::pair<int, int>);
	std::vector<std::string> readLine(std::string line);
	std::pair<std::string, std::pair<int, int>>	mouveSpritePlayer();
	std::pair<int, int>	moveOneEnemy(std::pair<int, int> pos);
	std::pair<int, int>	checkColideEnemy(std::pair<int, int> tmp, std::pair<int, int> pos);

	size_t	_score = 0;
	ILib::Key	_key;
	size_t	_nbPacdot = 0;
	int	_playerLife = 3;
	std::pair<int, int>	_posPlayer;
	std::vector<std::string>	_menu;
	std::vector<std::pair<int, int>> _gate;
	std::vector<std::pair<int, int>> _posEnemy;
	std::map <std::string, std::string> _setting;
	std::vector<std::vector<std::string>>	_map;
	std::vector<std::vector<std::string>> _assets;
};

#endif /* !PACMAN_HPP_ */
