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
#include <unistd.h>

class Sfml : public ILib
{
public:
	Sfml();
	~Sfml();
	void	clear();
	void	refresh();
	void	makeFont();
	void	drawBack();
	Key	getEvent();
	Sfml	createLib();
	std::string	drawStartMenu();
	void	drawSprite(float x, float y, std::string type);
	static std::string	clearGameName(std::string line);
	void	makeSprite(std::vector<std::vector<std::string>> input);
	void	drawText(std::vector<std::pair<std::string, std::string>> text);
	void	drawEndGame(std::vector<std::pair<std::string, std::string>> infos, std::string txt);
private:
	
	void	updateEvent();
	void	getContentDir();
	std::string	drawChoise();
	void	drawTitle(std::string);
	void	drawLittleText(std::string str);
	std::string 	keyToString(ILib::Key key)	;
	sf::String	getTextEntered(sf::String tmp);
	std::string	drawNameBox(std::string status);
	void	drawLittleText(std::string str, int pos);
	void	loadSprite(std::vector<std::string> input);
	void	writeScore(std::vector<std::pair<std::string, std::string>> infos, std::string txt);

	sf::Event	_event;
	sf::Music 	*_music;
	sf::Font	_font_text;
	sf::Font	_font_title;
	sf::RenderWindow	*_window;
	std::vector<std::string>	_available_games;
	std::map<std::string, std::pair<sf::Sprite *, sf::Texture *>>	_assets;
};

#endif /* !LIBSFML_HPP_ */
