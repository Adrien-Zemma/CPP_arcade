/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** 
*/

#ifndef ARCANE_HPP_
	#define ARCANE_HPP_

#include <iostream>
#include <dlfcn.h>
#include <Ilib.hpp>
#include <fstream>
#include <string.h>
#include <cstring>
#include "libsfml.hpp"
#include "IGame.hpp"

class Arcade
{
public:
	Arcade(std::string arg);
	~Arcade();
	void	start();
	void	loadLib(std::string arg);
	void	gameloop();
private:
	//IGame game;
	Lib lib;
	void	initAssets(std::string);

	Lib (*createLib)();
	void	*_handle;
	bool	_exit_status = false;
	void	loadSet(std::ifstream file);
	void	readSet(std::ifstream file);
	static	std::pair<std::string, std::string>	split(std::string str, char cut);
	void	initAssetsLocal(std::string game);

	void	initWallPacman();
	void	initPersoPacman();
	void	initSetPacman();

	std::map <std::string, std::string> _assets;
	std::map <std::string, std::string> _setting;
};

#endif /* !ARCANE_HPP_ */
