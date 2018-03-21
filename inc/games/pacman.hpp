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
	std::vector<std::vector<std::string>>	gamePlay();
	void	gameEnd();
	std::vector<std::vector<std::string>>	getMap();
private:
	void	initSetPacman();
	void	initPersoPacman();
	void	initWallPacman();
	void	mouvePlayer();
	void	mouveEnemy();
	void	checkColide();
	void	makesprite();
	void	createMap();
	void	dumpMap();
	std::vector<std::string> readLine(std::string line);
	std::vector<std::vector<std::string>>	_map;
	std::vector<std::string>	_menu;
	std::string	_key;
	std::pair<size_t, size_t>	_posPlayer;
	std::vector<std::pair<size_t, size_t>> _posEnemy;
	std::map <std::string, std::string> _assets;
	std::map <std::string, std::string> _setting;
};

#endif /* !PACMAN_HPP_ */
