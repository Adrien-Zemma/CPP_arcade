/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "libsfml.hpp"

extern "C" ILib *createLib()
{
	return new Sfml();
}

extern "C" void	destroyLib(ILib *lib)
{
	delete lib;
}

Sfml::Sfml()
{
	_window = new sf::RenderWindow(sf::VideoMode(450, 800), "Arcade");
	_window->clear(sf::Color::Black);
	makeFont();
}

Sfml::~Sfml()
{
	delete _window;
}

void	Sfml::clear()
{
	_window->clear(sf::Color::Black);
}

void	Sfml::refresh()
{
	_window->display();
}

/*
	wall horizontal
	wall vertical
	wall plein
	perso right
	perso left
	perso top
	perso botom
	perso corp
	background
	food 
	food special
*/

void	Sfml::drawText(std::vector<std::string> text)
{
	float x = 10;
	float y = 50;
	float next_x = x;
	for (auto el:text)
	{
		sf::Text to_display(el+"\t", _font_title, 15);
		to_display.setPosition(next_x, y);
		next_x = (el.size() * 15) * 2 + 1;
		_window->draw(to_display);
	}
}

void	Sfml::makeFont()
{
	_font_text.loadFromFile("./assets/font/AtariSmall.ttf");
	_font_title.loadFromFile("./assets/font/Forvertz.ttf");
}

void	Sfml::loadSprite(std::vector<std::string> input)
{
	sf::Texture *texture;
	sf::Sprite *sprite;

	texture = new sf::Texture;
	std::pair<std::string, std::pair<sf::Sprite *, sf::Texture *>> tmp;
	texture->create(16, 16);
	texture->loadFromFile(input[1]);
	sprite = new sf::Sprite(*texture);
	sprite->setRotation(stoi(input[3]));
	tmp.first = input[0];
	tmp.second.first = sprite;
	tmp.second.second = texture;
	_assets.insert(tmp);
}

void	Sfml::makeSprite(std::vector<std::vector<std::string>> input)
{
	_assets.clear();
	for (auto &el: input)
		loadSprite(el);
}

void	Sfml::drawSprite(float x, float y, std::string type)
{
	for (auto el : _assets)
		if (el.first == type)
		{
			el.second.first->setPosition(x * 16, y * 16);
			_window->draw(*el.second.first);
		}
}

std::string Sfml::getEvent()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return "left";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return "right";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return "up";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return "down";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return "echap";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		return "insert";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		return "Lib -1";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		return "Lib +1";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		return "Game -1";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		return "Game +1";
	return "";
}

std::string	Sfml::drawGameMenu()
{
	return "nibbler";
}

std::string	Sfml::clearGameName(std::string line)
{
	line.erase(0, 11);
	line.erase(line.size()-3, 3);
	return line;
}

void	Sfml::getContentDir()
{
	float y = 350;
	std::vector<sf::Text *> tmp;
	DIR *rep = opendir("./games");
	struct dirent *ent;
	_available_games.clear();
	while ( rep != NULL && (ent = readdir(rep)) != NULL)
	{
		std::string line(ent->d_name);
		if (line.find("lib_arcade_") != std::string::npos && 
			line.find(".so") != std::string::npos)
			{
				sf::Text *text = new sf::Text(clearGameName(line), _font_title, 20);
				text->setPosition(170, y += 21);
				_available_games.push_back(line);
				_window->draw(*text);
				tmp.push_back(text);
			}
	}
	if (rep != NULL)
		closedir(rep);
	if (tmp.size() == 0)
		_window->draw(sf::Text("No file found", _font_title, 50));
}

void	Sfml::drawTitle()
{
	sf::Text title("ARCADE", _font_title, 50);
	title.setPosition(100, 100);
	_window->draw(title);
}

void	Sfml::drawBack()
{
	sf::Texture texture;
	texture.create(600, 800);
	texture.loadFromFile("./assets/back.png");
	sf::Sprite sprite(texture);
	_window->draw(sprite);
}

std::string	Sfml::drawChoise()
{
	static size_t index = 0;
	static float y = 370;
	static std::string old_key = "";
	std::string key = getEvent();
	sf::Text arrow("->", _font_text, 15);
	arrow.setPosition(150, y);
	if (key == "up" && index > 0 && key != old_key)
	{
		arrow.setPosition(150, y -= 21);
		index -= 1;
	}
	else if (key == "down" && index < _available_games.size() -1 && key != old_key)
	{
		arrow.setPosition(150, y += 21);
		index += 1;
	}
	old_key = key;
	_window->draw(arrow);
	if (key == "insert")
		return _available_games[index];
	return "";
}

std::string	Sfml::drawStartMenu()
{
	std::string tmp;
	auto	next_frame = std::chrono::steady_clock::now();
	while (getEvent() != "echap")
	{
		next_frame += std::chrono::milliseconds(1000 / 120);
		_window->clear(sf::Color::Black);
		drawBack();
		drawTitle();
		getContentDir();
		tmp = drawChoise();
		if (tmp != "")
			return tmp;
		_window->display();
		std::this_thread::sleep_until(next_frame);
	}
	return "";
}