/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef LIB_HPP_
	#define LIB_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Ilib.hpp"

class Lib : public ILib
{
public:
	Lib();
	~Lib();
	void	makeFont();
	std::string	drawGameMenu();
	std::string	drawStartMenu();
	std::string	getEvent();
	Lib	createLib();
	void	drawSprite(int x, int y, std::string type);
	void	makeSprite(std::map<std::string, std::string> input);
private:
	void	loadSprite(std::pair<std::string, std::string> input);
	sf::RenderWindow	*_window;
	std::map<std::string, sf::Sprite>	_assest;
	sf::Font	_font;
};

#endif /* !LIBSFML_HPP_ */
