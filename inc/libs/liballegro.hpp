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

class Lib
{
public:
	Lib();
	~Lib();
private:
	void	createMapAssest();
	void	draw(int x, int y, std::string type);
	void	makeSprite(std::map<std::string, std::string> input);
	void	loadSprite(std::pair<std::string, std::string> input, std::string);
	void	makeFont();
	sf::RenderWindow	*_window;
	std::map<std::string, sf::Sprite> _assest;
	sf::Font _font;
};

#endif /* !LIBSFML_HPP_ */
