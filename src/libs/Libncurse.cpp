/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "Libncurses.hpp"

Libncurses::Libncurses()
{
	_win = initscr();
}

Libncurses::~Libncurses()
{
	endwin();
}

void	Libncurses::change_color(int back, int front)
{
}

void	Libncurses::Draw_str(std::string str)
{
	printw(str.c_str());
}

void	Libncurses::refresh()
{
	refresh();
}