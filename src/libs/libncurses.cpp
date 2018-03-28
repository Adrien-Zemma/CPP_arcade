/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** 
*/

#include "libncurses.hpp"

extern "C" ILib *createLib()
{
	return new Ncurses();
}

extern "C" void	destroyLib(ILib *lib)
{
	delete lib;
}
Ncurses::Ncurses()
{
	initscr();
	keypad(stdscr, TRUE);
	nodelay(stdscr, 0);
	timeout(0);
	noecho();
}

Ncurses::~Ncurses()
{
	endwin();
}

void	Ncurses::makeFont()
{}

std::string	Ncurses::drawGameMenu()
{
	return "pacman";
}

std::string	Ncurses::drawChoise()
{
	static size_t index = 0;
	static float y = 3;
	static std::string old_key = "";
	std::string key = getEvent();
	if (key == "up" && index > 0 && key != old_key)
	{
		mvprintw(y, 3, "->");
		index -= 1;
	}
	else if (key == "down" && index < _available_games.size() - 1 && key != old_key)
	{
		mvprintw(y, 3, "->");
		index += 1;
	}
	old_key = key;
	if (key == "insert")
		return _available_games[index];
	return "";
}

std::string	Ncurses::clearGameName(std::string line)
{
	line.erase(0, 11);
	line.erase(line.size()-3, 3);
	return line;
}

void	Ncurses::getContentDir()
{
	float y = 3;
	DIR *rep = opendir("./games");
	struct dirent *ent;
	_available_games.clear();
	while ( rep != NULL && (ent = readdir(rep)) != NULL)
	{
		std::string line(ent->d_name);
		if (line.find("lib_arcade_") != std::string::npos && 
			line.find(".so") != std::string::npos)
			{
				mvprintw(y, 15, "%s", clearGameName(line).data());
				y += 2;
				_available_games.push_back(line);
			}
	}
	if (rep != NULL)
		closedir(rep);
}

std::string	Ncurses::drawStartMenu()
{
	std::string tmp;
	auto	next_frame = std::chrono::steady_clock::now();
	while (getEvent() != "echap")
	{
		next_frame += std::chrono::milliseconds(1000 / 120);
		mvprintw(1, 15, "ARCADE");
		getContentDir();
		tmp = drawChoise();
		if (tmp != "")
			return tmp;
		std::this_thread::sleep_until(next_frame);
	}
	return "";
}

std::string	Ncurses::getEvent()
{
	int key = wgetch(stdscr);
	if (key == KEY_LEFT)
		return "left";
	else if (key == KEY_RIGHT)
		return "right";
	else if (key == KEY_UP)
		return "up";
	else if (key == KEY_DOWN)
		return "down";
	else if (key == 27)
		return "echap";
	else if (key == 10)
		return "insert";
	else if (key == 99)
		return "Lib -1";
	else if (key == 118)
		return "Lib +1";
	else if (key == 98)
		return "Game -1";
	else if (key == 110)
		return "Game +1";
	return "";
}

void	Ncurses::drawSprite(float x, float y, std::string type)
{
	for(auto el: _assets)
	{
		if (el.first == type)
		{
			mvprintw(y - 10, x, "%s", el.second.data());
		}
	}
}

void	Ncurses::drawText(std::vector<std::pair<std::string, std::string>> text)
{
	int x = 5;
	int y = 3;
	for (auto el: text)
	{
		mvprintw(y, x,"%s:\t%s",el.first.data(), el.second.data());
		x += (el.first.size() + el.second.size() + 3);
	}
}

void	Ncurses::makeSprite(std::vector<std::vector<std::string>>  input)
{
	for(auto el:input)
	{
		_assets.insert({el[0], el[2]});
	}
}

void	Ncurses::refresh()
{
	wrefresh(stdscr);
}

void	Ncurses::clear()
{
	wclear(stdscr);
}

void	Ncurses::drawBack()
{}