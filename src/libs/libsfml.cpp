/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "libsfml.hpp"

Lib::Lib()
{
	_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML window");
	createMapAssest();
	makeFont();
}


extern "C" Lib::~Lib()
{
	free(_window);
}

extern "C" Lib Lib::createLib()
{
	Lib tmp;
	return tmp;
}

extern "C" void Lib::drawMenu(std::string game)
{

}

/*
	wall horizontal
	wall vertical
	wall plein
	perso right
	perso left
	perso top
	perso botom
	perso corp
	background
	food 
	food special
*/

extern "C" void	Lib::createMapAssest()
{
	sf::Sprite tmp2;
	std::vector<std::string> tmp = {"wall_H", "wall_V", "wall_P",
	 "perso_R", "perso_L", "perso_T", "perso_B",
	 "perso_C", "background", "food", "food_S"};
	for(auto el : tmp)
		_assest.insert(std::pair<std::string, sf::Sprite>(el, tmp2));
}


extern "C" void	Lib::loadSprite(std::pair<std::string, std::string> input, std::string assest)
{
	sf::Texture texture;
	texture.loadFromFile(input.second);
	try {
		_assest.at(assest).setTexture(texture);
	}
	catch (std::out_of_range &e){}
}

extern "C" void	Lib::makeFont()
{
	_font.loadFromFile("arial.ttf");
}

/*
	Cette fonctio doit etre appeler depuis l'arcade |
							v
	input first == nom du sprite second == path
*/

extern "C" void	Lib::makeSprite(std::map<std::string, std::string> input)
{
	for (auto &el: input)
		for (auto &it: _assest)
			loadSprite(el, it.first);
}

extern "C" void	Lib::drawSprite(int x, int y, std::string type)
{
	_window->draw(_assest.at(type));
}
