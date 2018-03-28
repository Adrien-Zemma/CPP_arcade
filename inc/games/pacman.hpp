/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef PACMAN_HPP_
	#define PACMAN_HPP_

#include "IGame.hpp"

class Pacman : public IGame
{
public:
	Pacman();
	~Pacman();
	bool	gamePlay();
	void	setKey(std::string key);
	std::pair<bool, IGame::state>	gameEnd();
	std::vector<std::vector<std::string>>	getMap();
	std::vector<std::vector<std::string>>	getGameAssets();
	std::vector<std::pair<std::string, std::string>>	getInfos();
private:
	void	dumpMap();
	void	createMap();
	void	makesprite();
	void	mouveEnemy();
	void	mouvePlayer();
	void	initSetPacman();
	void	initWallPacman();
	void	initPersoPacman();
	bool	checkColide(std::pair<int, int>);
	std::vector<std::string> readLine(std::string line);
	std::pair<std::string, std::pair<int, int>>	mouveSpritePlayer();

	size_t	_score = 0;
	std::string	_key;
	size_t	_nbPacdot = 0;
	size_t	_playerLife = 3;
	std::vector<std::string>	_menu;
	std::pair<size_t, size_t>	_posPlayer;
	std::vector<std::pair<size_t, size_t>> _gate;
	std::map <std::string, std::string> _setting;
	std::vector<std::vector<std::string>>	_map;
	std::vector<std::vector<std::string>> _assets;
	std::vector<std::pair<size_t, size_t>> _posEnemy;
};

#endif /* !PACMAN_HPP_ */
