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
	Key	getEvent();
	void	makeFont();
	void	drawBack();
	std::string	drawStartMenu();
	void	drawTitle(std::string txt);
	void	drawSprite(float x, float y, std::string type);
	void	makeSprite(std::vector<std::vector<std::string>>  input);
	void	drawText(std::vector<std::pair<std::string, std::string>> text);
	void	drawEndGame(std::vector<std::pair<std::string, std::string>> infos, std::string txt);
private:

	void	getContentDir();
	std::string	drawChoise();
	std::string	drawNameBox(std::string txt);
	std::string	clearGameName(std::string line);
	void	drawWithColor(std::pair<int, int> pos, std::string txt, int color);
	void	writeScore(std::vector<std::pair<std::string, std::string>> infos, std::string txt);

	WINDOW *_screen;
	std::vector<std::string> _available_games;
	std::map<std::string, std::string> _assets;
	std::map<std::string, int> _asstesColors;
};

#endif /* !LIBSFML_HPP_ */
