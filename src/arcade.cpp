/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "arcade.hpp"
#include <thread>
#include <chrono>

Arcade::Arcade(std::string arg)
{
	_handle_game = NULL;
	_handle_lib = NULL;
	loadLib(arg);
	if (_exit_status == true)
		return ;
}

Arcade::~Arcade()
{
	if (_handle_game != NULL)
		dlclose(_handle_game);
	if (_handle_lib != NULL)
		dlclose(_handle_lib);
		
}

bool	Arcade::loadFunctionLib()
{
	createLib = reinterpret_cast<ILib*(*)()>(dlsym(_handle_lib, "createLib"));
	if (createLib == NULL)
		return false;
	destroyLib = reinterpret_cast<void(*)(ILib *)>(dlsym(_handle_lib, "destroyLib"));
	if (destroyLib == NULL)
		return false;
	return true;
}

void	Arcade::loadLib(std::string arg)
{
	if (_handle_lib != NULL)
	{
		destroyLib(lib);
		dlclose(_handle_lib);
	}
	_handle_lib = dlopen(arg.data(), RTLD_NOW);
	if (_handle_lib != NULL)
	{
		if (!loadFunctionLib())
			_exit_status = true;
		else
			lib = (*createLib)();
	}
	else
	{
		std::cout << dlerror() << std::endl;
		_exit_status = true;
	}
}

std::pair<std::string, std::string>	Arcade::split(std::string str, char cut)
{
	size_t i = 0;
	std::string stock;
	std::pair<std::string, std::string> tmp;
	for (i = 0; str[i] != cut && i < str.size(); i++)
		tmp.first.push_back(str[i]);
	for (i++; i < str.size(); i++)
		tmp.second.push_back(str[i]);
	return tmp;
}

void	Arcade::loadGame(std::string game)
{
	if (_handle_game != NULL)
	{
		destroyGame(jeu);
		dlclose(_handle_game);
	}
	if (game != "")
	{
		_handle_game = dlopen(std::string("./games/" + game).data(), RTLD_NOW);
	}
	if (_handle_game != NULL)
	{
		createGame = reinterpret_cast<IGame*(*)()>(dlsym(_handle_game, "createGame"));
		destroyGame = reinterpret_cast<void(*)(IGame *)>(dlsym(_handle_game, "destroyGame"));
		jeu = (*createGame)();
	}
	else
	{
		std::cout << "Can't open lib" << std::endl;
		if (_handle_game == NULL)
			std::cout << dlerror() << std::endl;
		_exit_status = true;
	}
}

void	Arcade::initAssetsLocal(std::string game)
{
	if (game == "")
		return ;
	_assets.clear();
	loadGame(game);
	_assets = jeu->getGameAssets();
	lib->makeSprite(_assets);
	_map = jeu->getMap();
}

void	Arcade::start()
{
	if (_exit_status)
		return ;
	std::string tmp = lib->drawStartMenu();
	if (tmp == "")
		return ;
	initAssetsLocal(tmp);
	gameloop();
}

void	Arcade::drawMap()
{
	float x = MAP_POS_X;
	float y = MAP_POS_Y ;
	for (auto el: _map)
	{
		for (auto it: el)
		{
			x = x + 1;
			lib->drawSprite(x, y, it);
		}
		x = MAP_POS_X;
		y = y + 1;
	}
	lib->refresh();
}

void	Arcade::readGameDir()
{
	DIR *rep = opendir("./games");
	struct dirent *ent;
	_available_games.clear();
	while ( rep != NULL && (ent = readdir(rep)) != NULL)
	{
		std::string line(ent->d_name);
		if (line.find("lib_arcade_") != std::string::npos && 
			line.find(".so") != std::string::npos)
			{
				_available_games.push_back(line);
			}
	}
	if (rep != NULL)
		closedir(rep);
}

void	Arcade::readLibDir()
{
	DIR *rep = opendir("./lib");
	struct dirent *ent;
	_available_libs.clear();
	while ( rep != NULL && (ent = readdir(rep)) != NULL)
	{
		std::string line(ent->d_name);
		if (line.find("lib_arcade_") != std::string::npos && 
			line.find(".so") != std::string::npos)
			{
				_available_libs.push_back(line);
			}
	}
	if (rep != NULL)
		closedir(rep);
}

void	Arcade::readAllDir()
{
	readGameDir();
	readLibDir();
}


void	Arcade::loadNewLib(ILib::Key key)
{
	static int nb = 0;
	if (key == ILib::G)
		lib->drawStartMenu();
	if ((key == ILib::C || key == ILib::V) && key != ILib::UNKNOW)
	{
		nb += key;
		loadLib("./lib/" + _available_libs[nb %  _available_libs.size()]);
		_assets = jeu->getGameAssets();
		lib->makeSprite(_assets);
		_map = jeu->getMap();
	}
	else if (key == ILib::B || key == ILib::N || key == ILib::H)
	{
		if (key == ILib::H)
			initAssetsLocal(_available_games[nb % _available_games.size()]);
		else 
		{
			nb += (key + 1);
			initAssetsLocal(_available_games[nb % _available_games.size()]);
		}
	}
}

void	Arcade::gameloop()
{
	ILib::Key key = ILib::UNKNOW;
	auto	next_frame = std::chrono::steady_clock::now();
	while(key != ILib::ESCAPE && jeu->gameEnd().first)
	{
		next_frame += std::chrono::milliseconds(1000 / 60);
		key  = lib->getEvent();
		readAllDir();
		loadNewLib(key);
		jeu->setKey(key);
		lib->clear();
		jeu->gamePlay();
		_map = jeu->getMap();
		lib->drawBack();
		lib->drawText(jeu->getInfos());
		drawMap();
		std::this_thread::sleep_until(next_frame);
	}
}