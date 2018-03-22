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
#include <sys/types.h>
#include <dirent.h>
#include <thread>
#include <chrono>

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
	void	drawSprite(float x, float y, std::string type);
	void	makeSprite(std::map<std::string, std::string> input);
	void	refresh();
	void	getContentDir();
	void	clear();
	static std::string	clearGameName(std::string line);
private:
	void	drawTitle();
	void	drawBack();
	std::string	drawChoise();
	void	loadSprite(std::pair<std::string, std::string> input);
	sf::RenderWindow	*_window;
	std::map<std::string, std::pair<sf::Sprite *, sf::Texture *>>	_assets;
	sf::Font	_font_text;
	sf::Font	_font_title;
	std::vector<std::string>	_available_games;
};

#endif /* !LIBSFML_HPP_ */
