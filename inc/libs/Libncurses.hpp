/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include <iostream>
#include <ncurses.h>

#ifndef LIB_HPP_
	#define LIB_HPP_

class Libncurses
{
public:
	Libncurses();
	~Libncurses();
	void	Draw_str(std::string str);
	void	refresh();
	void	change_color(int back, int front);
private:
	WINDOW	*_win;
};

#endif /* !LIB_HPP_ */
