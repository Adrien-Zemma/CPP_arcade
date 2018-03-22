/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#ifndef BODY_HPP_
	#define BODY_HPP_

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Snake.hpp"

class Body
{
public:
	enum part {
		HEAD,
		BODY,
	};
	Body(part type);
	~Body();
private:
	part			_part;
};

#endif /* !BODY_HPP_ */