/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** 
*/

#ifndef ARCANE_HPP_
	#define ARCANE_HPP_

#include "Ilib.hpp"
#include "IGame.hpp"
#include <iostream>
#include <dlfcn.h>
#include <string.h>
#include <cstring>

#define MAP_POS_X 50
#define MAP_POS_Y 22
class Arcade
{
public:
	Arcade(std::string arg);
	Arcade();
	~Arcade();
	int	start();
	void	gameloop();
private:
	void	drawMap();
	void	readAllDir();
	void	readLibDir();
	void	readGameDir();
	void	initSetPacman();
	void	initWallPacman();
	void	initPersoPacman();
	bool	loadFunctionLib();
	void	initAssets(std::string);
	void	loadLib(std::string arg);
	void	loadNewLib(ILib::Key key);
	void	loadGame(std::string game);
	void	switchMenu(std::string txt);
	void	loadSet(std::ifstream file);
	void	readSet(std::ifstream file);
	ILib::Key	noBlink(ILib::Key key);
	void	setCurentGame(std::string name);
	void	initAssetsLocal(std::string game);
	static	std::pair<std::string, std::string>	split(std::string str, char cut);
	
	ILib *lib;
	IGame *jeu;
	void	*_handle_lib;
	void	*_handle_game;
	int	nbOfCurentLib;
	int	nbOfCurentGame;
	ILib	*(*createLib)();
	IGame	*(*createGame)();
	bool	_exit_status = false;
	void	(*destroyLib)(ILib *);
	void	(*destroyGame)(IGame *);
	std::vector<std::vector<std::string>>	_map;
	std::vector<std::vector<std::string>>	_assets;
	std::vector<std::string>	_available_libs;
	std::map <std::string, std::string>	_setting;
	std::vector<std::string>	_available_games;
};

#endif /* !ARCANE_HPP_ */
