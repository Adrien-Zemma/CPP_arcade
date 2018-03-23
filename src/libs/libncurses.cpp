/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "libncurses.hpp"

extern "C" ILib *createLib()
{
	return new Ncurses();
}

Ncurses::Ncurses()
{
	initscr();
}

Ncurses::~Ncurses()
{
	endwin();
}

void	Ncurses::makeFont()
{}

std::string	Ncurses::drawGameMenu()
{
	return "pacman";
}

std::string	Ncurses::drawStartMenu()
{
	return "lib_arcade_pacman.so";
}

std::string	Ncurses::getEvent()
{
	noecho();
	//nocbreak();
	cbreak();
	printw("lol");
	int key = getch();
	if (key == KEY_LEFT)
		return "left";
	else if (key == KEY_RIGHT)
		return "right";
	else if (key == KEY_UP)
		return "up";
	else if (key == KEY_DOWN)
		return "down";
	else if (key == KEY_EXIT)
		return "echap";
	else if (key == KEY_ENTER)
		return "insert";
	return "";
}

void	Ncurses::drawSprite(float x, float y, std::string type)
{
	for(auto el: _assets)
	{
		if (el.first == type)
		{
			mvprintw(x, y,"%s",el.second);
		}
	}
}

void	Ncurses::drawText(std::vector<std::string> text)
{
	int x = 3;
	int y = 0;
	for (auto el: text)
	{
		mvprintw(x, y,"%s",el);
		y += el.size();
	}
}

void	Ncurses::makeSprite(std::vector<std::vector<std::string>>  input)
{
	for(auto el:input)
		_assets.insert({el[0], el[2]});
}

void	Ncurses::refresh()
{
	refresh();
}

void	Ncurses::clear()
{}