/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "arcade.hpp"

Arcade::Arcade(std::string arg)
{
	Arcade::loadLib(arg);
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
	_handle_lib = dlopen(arg.data(), RTLD_NOW);
	if (_handle_lib != NULL)
	{
		createLib = reinterpret_cast<ILib*(*)()>(dlsym(_handle_lib, "createLib"));
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

/*void	Arcade::readSet(std::ifstream file)
{
	std::string line;
	while (getline(file, line) && line.find("[") == std::string::npos
	&& line.find("]") == std::string::npos)
	{
		if (line.find("=") != std::string::npos)
			_setting.insert((split(line, '=')));
	}
}

void	Arcade::loadSet(std::ifstream file)
{
	std::string line;
	while (getline(file, line))
		if (line.find("[set]") != std::string::npos)
			readSet(file);
}

void	Arcade::initAssets(std::string game)
{
	std::ifstream file(game + ".ini");
	if (file)
	{
		loadSet(file);
		file.seekg(file.beg);
		loadSprite(file);
		file.close();
	}
	else 
	{
		std::cerr << "no config file" << std::endl;
		_exit_status = true;
	}

}*/

void	Arcade::loadGame(std::string game)
{
	std::string tmp = "./games/lib_arcade_" + game + ".so";
	_handle_game = dlopen(tmp.data(), RTLD_NOW);
	if (_handle_game != NULL)
	{
		createGame = reinterpret_cast<IGame*(*)()>(dlsym(_handle_game, "createGame"));
		jeu = (*createGame)();
	}
	else
	{
		std::cout << dlerror() << std::endl;
		_exit_status = true;
	}
}

void	Arcade::initAssetsLocal(std::string game)
{
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
	float x = 8;
	float y = 16;
	lib->clear();
	for (auto el: _map)
	{
		for (auto it: el)
		{
			x = x + 1;
			lib->drawSprite(x, y, it);
		}
		x = 8;
		y = y + 1;
	}
	lib->refresh();
}

void	Arcade::gameloop()
{
	while(lib->getEvent() != "echap")
	{
		jeu->gamePlay();
		_map = jeu->getMap();
		drawMap();
	}
}