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




class Arcade
{
public:
	Arcade(std::string arg);
	Arcade();
	~Arcade();
	void	start();
	void	gameloop();
private:
	void	loadLib(std::string arg);
	void	loadGame(std::string game);
	void	drawMap();
	ILib *lib;
	IGame *jeu;
	void	initAssets(std::string);
	ILib	*(*createLib)();
	IGame	*(*createGame)();
	void	*_handle_lib;
	void	*_handle_game;
	std::vector<std::vector<std::string>>	_map;
	bool	_exit_status = false;
	void	loadSet(std::ifstream file);
	void	readSet(std::ifstream file);
	static	std::pair<std::string, std::string>	split(std::string str, char cut);
	void	initAssetsLocal(std::string game);

	void	initWallPacman();
	void	initPersoPacman();
	void	initSetPacman();

	std::vector<std::vector<std::string>> _assets;
	std::map <std::string, std::string> _setting;
};

#endif /* !ARCANE_HPP_ */
