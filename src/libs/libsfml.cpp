/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "libsfml.hpp"

extern "C" ILib *createLib()
{
	ILib *tmp = new Lib();
	return tmp;
}

extern "C" void	destroyLib(ILib *lib)
{
	lib->~ILib();
}

Lib::Lib()
{
	_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML window");
	sf::Text text;
	text.setString("Hello world");
}

Lib::~Lib()
{
	free(_window);
}

void	Lib::refresh()
{
	_window->clear();
	_window->display();
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

void	Lib::loadSprite(std::pair<std::string, std::string> input)
{
	sf::Texture texture;
	std::pair<std::string, sf::Sprite> tmp;
	texture.loadFromFile(input.second);
	sf::Sprite sprite(texture);
	tmp.first = input.first;
	tmp.second = sprite;
	_assest.insert(tmp);
}

void	Lib::makeFont()
{
}

void	Lib::makeSprite(std::map<std::string, std::string> input)
{
	for (auto &el: input)
		loadSprite(el);
}

void	Lib::drawSprite(int x, int y, std::string type)
{
	sf::Vector2i pos(x, y);
	_window->setPosition(pos);
	_window->draw(_assest.at(type));
}

std::string Lib::getEvent()
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

std::string	Lib::drawGameMenu()
{
	return "pacman";
}

std::string	Lib::drawStartMenu()
{
	return "pacman";
}