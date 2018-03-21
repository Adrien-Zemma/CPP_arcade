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
	//lib  = (*createLib)();
	//jeu = (*createGame)();
}

Arcade::~Arcade()
{
	dlclose(_handle_lib);
}

void	Arcade::loadLib(std::string arg)
{
	_handle_lib = dlopen(arg.data(), RTLD_NOW);
	if (_handle_lib != NULL)
		createLib = reinterpret_cast<ILib*(*)()>(dlsym(_handle_lib, "createLib"));
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

void	Arcade::initSetPacman()
{
	std::pair<std::string, std::string> tmp;
	tmp.first = "map";
	tmp.second = "assets/pacman/map.txt";
	_setting.insert(tmp);
}

void	Arcade::loadGame(std::string game)
{
	std::string tmp = "./games/lib_arcade_" + game;
	_handle_game = dlopen(tmp.data(), RTLD_NOW);
	if (_handle_game != NULL)
		createGame = reinterpret_cast<IGame*(*)()>(dlsym(_handle_game, "createGame"));
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
	jeu->getMap(); 
}

void	Arcade::start()
{
	initAssetsLocal(lib->drawStartMenu());
	gameloop();
}

void	Arcade::gameloop()
{
	while(1 || !_exit_status)
	{
	}
}