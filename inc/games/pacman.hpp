/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef PACMAN_HPP_
	#define PACMAN_HPP_

#include "IGame.hpp"
#include <vector>

class Game : public IGame
{
public:
	Game();
	~Game();
	Game	gameStart();
	void	gamePlay();
	void	gameEnd();
	void	setkey(std::string key);
private:
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
};

#endif /* !PACMAN_HPP_ */
