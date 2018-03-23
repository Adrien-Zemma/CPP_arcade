/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "libcaca.hpp"

extern "C" ILib *createLib()
{
	return new Caca();
}

Caca::Caca()
{	
}

Caca::~Caca()
{
}

void	Caca::makeFont()
{}

std::string	Caca::drawGameMenu()
{}

std::string	Caca::drawStartMenu()
{}

std::string	Caca::getEvent()
{}

void	Caca::drawSprite(float x, float y, std::string type)
{}

void	Caca::drawText(std::vector<std::string> text)
{}

void	Caca::makeSprite(std::map<std::string, std::string> input)
{}

void	Caca::refresh()
{}

void	Caca::clear()
{}