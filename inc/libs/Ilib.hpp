/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef ILIB_HPP_
	#define ILIB_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <dirent.h>
#include <thread>
#include <chrono>

#define SCREEN_X 1920
#define SCREEN_Y 1080

class ILib
{
public:
	enum Key {
		RETURN = 0,
		C = 1,
		V = -1,
		G = 8,
		H = 9,
		B = 2,
		N = -2,
		UP = 3,
		LEFT = 4,
		RIGHT = 5,
		DOWN = 6,
		ESCAPE = 7,
		UNKNOW = 42
	};
	virtual ~ILib() = default;
	virtual void	clear() = 0;
	virtual void	refresh() = 0;
	virtual void	makeFont() = 0;
	virtual	void	drawBack() = 0;
	virtual std::string	drawGameMenu() = 0;
	virtual std::string	drawStartMenu() = 0;
	virtual Key	getEvent() = 0;
	virtual void	drawSprite(float x, float y, std::string type) = 0;
	virtual void	makeSprite(std::vector<std::vector<std::string>> input) = 0;
	virtual void	drawText(std::vector<std::pair<std::string, std::string>> text) = 0;
};

#endif /* !LIBSFML_HPP_ */
