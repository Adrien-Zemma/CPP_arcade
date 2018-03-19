/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "libsfml.hpp"

extern "C" Lib createLib()
{
	Lib tmp;
	return tmp;
}

extern "C" Lib::Lib()
{
	_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML window");
	makeFont();
}

extern "C" Lib::~Lib()
{
	free(_window);
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

extern "C" void	Lib::loadSprite(std::pair<std::string, std::string> input)
{
	sf::Texture texture;
	std::pair<std::string, sf::Sprite> tmp;
	texture.loadFromFile(input.second);
	sf::Sprite sprite(texture);
	tmp.first = input.first;
	tmp.second = sprite;
	_assest.insert(tmp);
}

extern "C" void	Lib::makeFont()
{
	std::cout << "ZA WARDO" << std::endl;
	_font.loadFromFile("assets/font/arial.ttf");
}

extern "C" void	Lib::makeSprite(std::map<std::string, std::string> input)
{
	for (auto &el: input)
		loadSprite(el);
}

extern "C" void	Lib::drawSprite(int x, int y, std::string type)
{
	sf::Vector2i pos(x, y);
	_window->setPosition(pos);
	_window->draw(_assest.at(type));
}

extern "C" std::string Lib::getEvent()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return "left";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return "right";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return "up";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return "down";
	return "";
}