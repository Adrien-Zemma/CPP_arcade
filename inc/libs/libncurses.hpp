/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef Ncurse_HPP_
	#define Ncurse_HPP_

#include <ncurses.h>
#include "Ilib.hpp"


class Ncurses: public ILib
{
public:
	Ncurses();
	~Ncurses();
	void	makeFont();
	std::string	drawGameMenu();
	std::string	drawStartMenu();
	Key	getEvent();
	void	drawSprite(float x, float y, std::string type);
	void	drawText(std::vector<std::string> text);
	void	makeSprite(std::vector<std::vector<std::string>>  input);
	void	refresh();
	void	clear();
private:

	void	getContentDir();
	std::string	drawChoise();
	std::string	clearGameName(std::string line);
	std::map<std::string, std::string> _assets;
	WINDOW *_screen;
	std::vector<std::string> _available_games;
	
};

#endif /* !LIBSFML_HPP_ */
