/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef ILIB_HPP_
	#define ILIB_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class ILib
{
public:
	virtual ~ILib() = default;
	virtual void	makeFont() = 0;
	//virtual ILib	createLib() = 0;
	virtual std::string	drawGameMenu() = 0;
	virtual std::string	drawStartMenu() = 0;
	virtual std::string	getEvent() = 0;
	virtual void	drawSprite(int x, int y, std::string type) = 0;
	virtual void	makeSprite(std::map<std::string, std::string> input) = 0;
	virtual void	refresh() = 0;
	virtual void	clear() = 0;
};

//TODO ajouter une methode de config 

#endif /* !LIBSFML_HPP_ */
