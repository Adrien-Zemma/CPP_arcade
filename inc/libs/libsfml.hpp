/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef SFML_HPP_
	#define SFML_HPP_

#include "Ilib.hpp"
#include <sys/types.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Sfml : public ILib
{
public:
	Sfml();
	~Sfml();
	void	clear();
	void	refresh();
	void	drawBack();
	void	makeFont();
	Sfml	createLib();
	void	getContentDir();
	std::string	getEvent();
	std::string	drawGameMenu();
	std::string	drawStartMenu();
	void	drawSprite(float x, float y, std::string type);
	static std::string	clearGameName(std::string line);
	void	makeSprite(std::vector<std::vector<std::string>>);
	void	drawText(std::vector<std::pair<std::string, std::string>> text);
private:

	
	void	drawTitle();
	std::string	drawChoise();
	void	loadSprite(std::vector<std::string> input);

	sf::Font	_font_text;
	sf::Font	_font_title;
	sf::RenderWindow	*_window;
	std::vector<std::string>	_available_games;
	std::map<std::string, std::pair<sf::Sprite *, sf::Texture *>>	_assets;
};

#endif /* !LIBSFML_HPP_ */
