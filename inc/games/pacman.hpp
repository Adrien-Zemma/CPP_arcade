/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef PACMAN_HPP_
	#define PACMAN_HPP_

#include "IGame.hpp"

class Game : public IGame
{
public:
	Game();
	~Game();
	bool	gamePlay();
	void	gameEnd();
	void	setKey(std::string key);
	std::vector<std::vector<std::string>>	getGameAssets();
	std::vector<std::vector<std::string>>	getMap();
	std::vector<std::string>	getInfos();
private:
	std::pair<std::string, std::pair<int, int>>	mouveSpritePlayer();
	void	initSetPacman();
	void	initPersoPacman();
	void	initWallPacman();
	void	mouvePlayer();
	void	mouveEnemy();
	bool	checkColide(std::pair<int, int>);
	void	makesprite();
	void	createMap();
	void	dumpMap();
	std::vector<std::string> readLine(std::string line);
	std::vector<std::vector<std::string>>	_map;
	std::vector<std::string>	_menu;
	std::string	_key;
	std::pair<size_t, size_t>	_posPlayer;
	std::vector<std::pair<size_t, size_t>> _posEnemy;
	std::vector<std::vector<std::string>> _assets;
	std::map <std::string, std::string> _setting;
	std::vector<std::pair<size_t, size_t>> _gate;
	size_t	_nbPacdot = 0;
	size_t	_score = 0;
	size_t	_playerLife = 3;
};

#endif /* !PACMAN_HPP_ */
