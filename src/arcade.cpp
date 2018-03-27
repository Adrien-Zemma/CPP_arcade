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
	dlclose(_handle_lib);
	dlclose(_handle_game);
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
		createLib = reinterpret_cast<ILib*(*)()>(dlsym(_handle_lib, "createLib"));
		destroyLib = reinterpret_cast<void(*)(ILib *)>(dlsym(_handle_lib, "destroyLib"));
		lib  = (*createLib)();
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
	std::cout << "coucou" << std::endl;
	if (_handle_game != NULL)
	{
		destroyGame(jeu);
		dlclose(_handle_game);
	}
	if (game != "")
	{
		std::cout << game << std::endl;
		_handle_game = dlopen(std::string("./games/" + game).data(), RTLD_NOW);
		std::cout << "dlopen fini"<< std::endl;
	}
	if (_handle_game != NULL)
	{
		std::cout << "Create game" << std::endl;
		createGame = reinterpret_cast<IGame*(*)()>(dlsym(_handle_game, "createGame"));
		std::cout << "destroy game" << std::endl;
		destroyGame = reinterpret_cast<void(*)(IGame *)>(dlsym(_handle_game, "destroyGame"));
		jeu = (*createGame)();
		std::cout << "Create NIBBLER" << std::endl;
	}
	else
	{
		if (_handle_game != NULL)
			std::cout << dlerror() << std::endl;
		_exit_status = true;
	}
}

void	Arcade::initAssetsLocal(std::string game)
{
	_assets.clear();
	loadGame(game);
	_assets = jeu->getGameAssets();
	lib->makeSprite(_assets);
	_map = jeu->getMap();
}

void	Arcade::start()
{
	initAssetsLocal(lib->drawStartMenu());
	gameloop();
}

void	Arcade::drawMap()
{
	float x = 4;
	float y = 16;
	for (auto el: _map)
	{
		for (auto it: el)
		{
			x = x + 1;
			lib->drawSprite(x, y, it);
		}
		x = 4;
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


void	Arcade::loadNewLib(std::string key)
{
	static size_t nb = 0;
	auto	next_frame = std::chrono::steady_clock::now();
	next_frame += std::chrono::milliseconds(1000 / 30);
	if (key.find("Lib") != std::string::npos)
	{
		key.erase(0, 4);
		nb += stoi(key);
		std::string tmp = "./lib/" + _available_libs[nb %  _available_libs.size()];
		loadLib(tmp);
		_assets = jeu->getGameAssets();
		lib->makeSprite(_assets);
		_map = jeu->getMap();
	}
	if (key.find("Game") != std::string::npos)
	{
		key.erase(0, 4);
		nb += stoi(key) ;
		std::string tmp = _available_games[nb % _available_games.size()];
		initAssetsLocal(tmp);
	}
	std::this_thread::sleep_until(next_frame);
	

}

void	Arcade::gameloop()
{
	std::string key = "";
	auto	next_frame = std::chrono::steady_clock::now();
	while(key != "echap" && jeu->gameEnd().first)
	{
		next_frame += std::chrono::milliseconds(1000 / 15);
		key  = lib->getEvent();
		jeu->setKey(key);
		readAllDir();
		loadNewLib(key);
		lib->clear();
		jeu->gamePlay();
		_map = jeu->getMap();
		lib->drawText(jeu->getInfos());
		drawMap();
		std::this_thread::sleep_until(next_frame);
	}
}