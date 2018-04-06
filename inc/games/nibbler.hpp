/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef NIBBLER_HPP_
	#define NIBBLER_HPP_

#include "IGame.hpp"
#include <string>
#include <cstddef>

class Nibbler : public IGame
{
public:
	Nibbler();
	~Nibbler();
	std::vector<std::vector<std::string>>	getGameAssets();
	bool					gamePlay();
	std::vector<std::vector<std::string>>	getMap();
	void					setKey(ILib::Key key);
	std::vector<std::pair<std::string, std::string>>	getInfos();
	std::pair<bool, IGame::state>		gameEnd();
private:
	std::vector<std::string>		readLine(std::string line);
	void					initPerso();
	std::string					moveHead();
	void					moveBody();
	void					initWall();
	void					initFood();
	std::string				readLine(char c, int x, int y);
	void					goEat();
	void					makeFood();
	void					initCoords();
	void					moveChara(size_t i);
	void 					create_map();
	void					movePlayer();
	bool					checkColide(std::pair<int, int> input, std::pair<int, int> move);
	std::pair<std::string, std::pair<int, int>>	mouveSpritePlayer();
	std::vector<std::vector<std::string>>	_map;
	std::vector<std::vector<std::string>>	_assets;
	ILib::Key				_key;
	std::vector<std::pair<int, int>>	_coords;
	size_t					_nbFoods;
};

#endif /* !NIBBLER_HPP_ */
