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
	std::string	getEvent();
	void	drawSprite(float x, float y, std::string type);
	void	drawText(std::vector<std::string> text);
	void	makeSprite(std::vector<std::vector<std::string>>  input);
	void	refresh();
	void	clear();
private:
	std::map<std::string, std::string> _assets;
};

#endif /* !LIBSFML_HPP_ */
