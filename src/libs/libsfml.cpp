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
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Arcade");
	_window->clear(sf::Color::Black);
}

Lib::~Lib()
{
	delete _window;
}

void	Lib::clear()
{
	_window->clear(sf::Color::Black);
}

void	Lib::refresh()
{
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
	texture.create(16, 16);
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
	for (auto el : _assest)
		if (el.first == type)
		{
			el.second.setPosition(x * 16, y * 16);
			_window->draw(el.second);
		}
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return "echap";
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