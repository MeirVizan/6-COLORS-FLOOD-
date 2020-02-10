#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "Menu.h"



class Controller
{
public:
	Controller();
	//main game loop
	void run();
	//a utility function to run UI updates
	void update(sf::RenderWindow& window, sf::RectangleShape& winRec, Board& m_board, Menu& menu,sf::Text&);
	~Controller();

private:
	//dynamic screen dimension for multiple resolution support
	int m_screen_width, m_screen_height;
	//board for game
	Board m_board;
	//player identifier color
	int player_color;
	bool is_play_allowed,turn_consumed;
};

