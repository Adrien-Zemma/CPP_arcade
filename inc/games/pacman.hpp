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

class Pacman : public IGame
{
public:
	Pacman();
	~Pacman();
	bool	gamePlay();
	std::pair<bool, IGame::state>	gameEnd();
	void	setKey(ILib::Key key);
	std::vector<std::vector<std::string>>	getGameAssets();
	std::vector<std::vector<std::string>>	getMap();
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
	std::pair<std::string, std::pair<int, int>>	mouveSpritePlayer();
	bool	checkColide(std::pair<int, int>);
	std::vector<std::string> readLine(std::string line);
	std::vector<std::vector<std::string>>	_map;
	std::vector<std::string>	_menu;
	ILib::Key	_key;
	std::pair<size_t, size_t>	_posPlayer;
	std::vector<std::pair<size_t, size_t>> _posEnemy;
	std::vector<std::vector<std::string>> _assets;
	std::map <std::string, std::string> _setting;
	std::vector<std::pair<size_t, size_t>> _gate;
	size_t	_nbPacdot = 0;
	size_t	_playerLife = 3;
	size_t	_score = 0;
};

#endif /* !PACMAN_HPP_ */
