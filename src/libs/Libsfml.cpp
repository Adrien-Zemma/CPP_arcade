/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "Libsfml.hpp"

Libsfml::Libsfml()
{
	_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML window");
	createMapAssest();
	makeFont();
}

void	Libsfml::createMapAssest()
{
	sf::Sprite tmp2;
	std::vector<std::string> tmp = {"wall_R", "wall_L", "wall_T", "wall_B",
	 "perso_R", "perso_L", "perso_T", "perso_T", "perso_B",
	 "perso_C", "background"};
	for(auto el : tmp)
		_assest.insert(std::pair<std::string, sf::Sprite>(el, tmp2));
}

Libsfml::~Libsfml()
{
	free(_window);
}

void	Libsfml::loadSprite(std::pair<std::string, std::string> input, std::string assest)
{
	sf::Texture texture;
	texture.loadFromFile(input.second);
	try {
		_assest.at(assest).setTexture(texture);
	}
	catch (std::out_of_range &e){}
}

void	Libsfml::makeFont()
{
	_font.loadFromFile("arial.ttf");
}

void	Libsfml::makeSprite(std::map<std::string, std::string> input)
{
	for (auto &el: input)
		for (auto &it: _assest)
			loadSprite(el, it.first);
}

void	Libsfml::draw(int x, int y, std::string type)
{
	_window->draw(_assest.at(type));
}
