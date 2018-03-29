/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef Ncurse_HPP_
	#define Ncurse_HPP_

#include "Ilib.hpp"
#include <ncurses.h>


class Ncurses: public ILib
{
public:
	Ncurses();
	~Ncurses();
	void	clear();
	void	refresh();
	void	makeFont();
	void	drawBack();
	std::string	drawGameMenu();
	std::string	drawStartMenu();
	Key	getEvent();
	void	drawSprite(float x, float y, std::string type);
	void	makeSprite(std::vector<std::vector<std::string>>  input);
	void	drawText(std::vector<std::pair<std::string, std::string>> text);
private:

	void	getContentDir();
	std::string	drawChoise();
	std::string	clearGameName(std::string line);

	WINDOW *_screen;
	std::vector<std::string> _available_games;
	std::map<std::string, std::string> _assets;
};

#endif /* !LIBSFML_HPP_ */
