/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "arcade.hpp"

Arcade::Arcade(std::string arg)
{
	//loadLib(arg);
	void *lib = dlopen(arg.c_str, RTLD_LAZY);
}

Arcade::~Arcade()
{
	dlclose(_handle);
}

void	Arcade::loadLib(std::string arg)
{
	_handle = dlopen(arg.c_str, RTLD_LAZY);
	if (_handle != NULL)
	{
		createLib = static_cast<ILib(*)()> (dlsym(_handle, "createLib"));
		createMapAssest = static_cast<void(*)()> (dlsym(_handle, "createMapAssest"));
		drawSprite = static_cast<void(*)(int, int, std::string)>(dlsym(_handle, "drawSprite"));
		makeSprite = static_cast<void(*)(std::map<std::string, std::string>)>(dlsym(_handle, "makeSprite"));
		loadSprite = static_cast<void(*)(std::pair<std::string, std::string>, std::string)>(dlsym(_handle, "loadSprite"));
		makeFont = static_cast<void(*)()>(dlsym(_handle, "makeFont"));
		drawStartMenu = static_cast<std::string(*)()>(dlsym(_handle, "drawStartMenu"));
		drawGameMenu = static_cast<void(*)()>(dlsym(_handle, "drawGameManu"));
	}
	else
		_exit_status = true;
}

std::pair<std::string, std::string>	Arcade::split(std::string str, char cut)
{
	size_t i = 0;
	std::pair<std::string, std::string> tmp;
	for (i = 0; str[i] != cut && i < str.size(); i++)
		tmp.first.append(str[i]);
	for (i++; i < str.size(); i++)
		tmp.second.append(str[i]);
	return tmp;
}

void	Arcade::readSet(std::ifstream file)
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

}

void	Arcade::initWallPacman()
{
	std::pair<std::string, std::string> tmp;
	tmp.first = "wall_H";
	tmp.second = "assets/pacman/wall_T.png";
	_assets.insert(tmp);
	tmp.first = "wall_V";
	tmp.second = "assets/pacman/wall_B.png";
	_assets.insert(tmp);
	tmp.first = "wall_P";
	tmp.second = "assets/pacman/wall_P.png";
	_assets.insert(tmp);
}

void	Arcade::initPersoPacman()
{
	std::pair<std::string, std::string> tmp;
	tmp.first = "perso_R";
	tmp.second = "assets/pacman/perso_R.png";
	_assets.insert(tmp);
	tmp.first = "perso_L";
	tmp.second = "assets/pacman/perso_T.png";
	_assets.insert(tmp);
	tmp.first = "perso_T";
	tmp.second = "assets/pacman/perso_T.png";
	_assets.insert(tmp);
	tmp.first = "perso_B";
	tmp.second = "assets/pacman/perso_B.png";
	_assets.insert(tmp);
	tmp.first = "perso_C";
	tmp.second = "assets/pacman/perso_C.png";
	_assets.insert(tmp);
}

void	Arcade::initAssetsLocal(std::string game)
{
	std::pair<std::string, std::string> tmp;
	tmp.first = "map";
	tmp.second = "assets/map.txt";
	_setting.insert(tmp);
	initWallPacman();
	initPersoPacman();
	(*makeSprite)(_assets);
}

void	Arcade::start()
{
	//initAssets((*drawStartMenu)());
	initAssetsLocal((*drawStartMenu)());
	gameloop();
}

void	Arcade::gameloop()
{
	while(1 || !_exit_status)
	{
	}
}