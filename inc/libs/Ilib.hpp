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
	virtual ~ILib() = default;
	virtual void	clear() = 0;
	virtual void	refresh() = 0;
	virtual void	makeFont() = 0;
	virtual	void	drawBack() = 0;
	virtual std::string	getEvent() = 0;
	virtual std::string	drawGameMenu() = 0;
	virtual std::string	drawStartMenu() = 0;
	virtual void	drawSprite(float x, float y, std::string type) = 0;
	virtual void	makeSprite(std::vector<std::vector<std::string>> input) = 0;
	virtual void	drawText(std::vector<std::pair<std::string, std::string>> text) = 0;
};

#endif /* !LIBSFML_HPP_ */
