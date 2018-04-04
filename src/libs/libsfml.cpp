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
	_window = new sf::RenderWindow(sf::VideoMode(SCREEN_X, SCREEN_Y), "Arcade");
	_window->clear(sf::Color::Black);
	makeFont();
	makeMusic();
}

Sfml::~Sfml()
{
	delete _music;
	delete _window;
}

void	Sfml::makeMusic()
{
	_music = new sf::Music;
	if (_music->openFromFile("./assets/pacman/song.ogg"))
	{
		//TODO:
		//_music->play();
		_music->setLoop(true);
	}
}

void	Sfml::clear()
{
	sf::Event event;
	while (_window->pollEvent(event));
	_window->clear(sf::Color::Black);
}

void	Sfml::refresh()
{
	_window->display();
}

void	Sfml::drawText(std::vector<std::pair<std::string, std::string>> text)
{
	float x = SCREEN_X / 5 * 2;
	float y = SCREEN_Y / 10;
	for (auto el:text)
	{
		sf::Text to_display(el.first + ":\t" + el.second, _font_title, 15);
		to_display.setPosition(x, y += 15);
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

ILib::Key Sfml::getEvent()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return LEFT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return RIGHT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return UP;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return DOWN;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return ESCAPE;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		return RETURN;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		return C;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		return V;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		return B;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		return N;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		return G;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		return H;
	return UNKNOW;
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

void	Sfml::drawTitle(std::string txt)
{
	sf::Text title(txt, _font_title, 50);
	title.setPosition(SCREEN_X / 2 - ((txt.size() / 2) * 50), SCREEN_Y / 20 * 4);
	_window->draw(title);
}

void	Sfml::drawBack()
{
	sf::Texture texture;
	texture.create(SCREEN_X, SCREEN_Y);
	texture.loadFromFile("./assets/back.jpg");
	sf::Sprite sprite(texture);
	_window->draw(sprite);
}

std::string	Sfml::drawChoise()
{
	static size_t index = 0;
	static float y = 370;
	static ILib::Key old_key = UNKNOW;
	ILib::Key key = getEvent();
	sf::Text arrow("->", _font_text, 15);
	arrow.setPosition(150, y);
	if (key == UP && index > 0 && key != old_key)
	{
		arrow.setPosition(150, y -= 21);
		index -= 1;
	}
	else if (key == DOWN && index < _available_games.size() -1 && key != old_key)
	{
		arrow.setPosition(150, y += 21);
		index += 1;
	}
	old_key = key;
	_window->draw(arrow);
	if (key == RETURN)
		return _available_games[index];
	return "";
}

std::string	Sfml::drawStartMenu()
{
	sf::Event event;
	std::string tmp;
	auto	next_frame = std::chrono::steady_clock::now();
	while (getEvent() != ESCAPE)
	{
		while (_window->pollEvent(event));
		next_frame += std::chrono::milliseconds(1000 / 120);
		_window->clear(sf::Color::Black);
		drawBack();
		drawTitle("ARCADE");
		getContentDir();
		tmp = drawChoise();
		if (tmp != "")
			return tmp;
		_window->display();
		std::this_thread::sleep_until(next_frame);
	}
	return "";
}

void	Sfml::writeScore(std::vector<std::pair<std::string, std::string>> infos, std::string txt)
{
}

std::string	Sfml::drawNameBox()
{
	return "adrien";
}

void	Sfml::drawEndGame(std::vector<std::pair<std::string, std::string>> infos, std::string txt)
{
	clear();
	drawBack();
	drawTitle(std::string("YOU") + txt);
	writeScore(infos, drawNameBox());
}