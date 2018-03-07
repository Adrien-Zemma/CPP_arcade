/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef LIB_HPP_
	#define LIB_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class ILib
{
public:
	virtual ~ILib() = 0;

private:
	virtual void	createMapAssest() = 0;
	virtual void	draw(int x, int y, std::string type) = 0;
	virtual void	makeSprite(std::map<std::string, std::string> input) = 0;
	virtual void	loadSprite(std::pair<std::string, std::string> input, std::string) = 0;
	virtual void	makeFont() = 0;
};

#endif /* !LIBSFML_HPP_ */
