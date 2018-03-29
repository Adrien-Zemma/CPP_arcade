/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef SFML_HPP_
	#define SFML_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <sys/types.h>
#include "Ilib.hpp"
#include "arcade.hpp"

class Sfml : public ILib
{
public:
	Sfml();
	~Sfml();
	void	makeFont();
	std::string	drawGameMenu();
	std::string	drawStartMenu();
	Key	getEvent();
	Sfml	createLib();
	void	drawSprite(float x, float y, std::string type);
	void	makeSprite(std::vector<std::vector<std::string>>);
	void	refresh();
	void	getContentDir();
	void	clear();
	static std::string	clearGameName(std::string line);
	void	drawText(std::vector<std::string> text);
private:

	void	drawTitle();
	void	drawBack();
	std::string	drawChoise();
	void	loadSprite(std::vector<std::string> input);
	sf::RenderWindow	*_window;
	std::map<std::string, std::pair<sf::Sprite *, sf::Texture *>>	_assets;
	sf::Font	_font_text;
	sf::Font	_font_title;
	std::vector<std::string>	_available_games;
};

#endif /* !LIBSFML_HPP_ */
