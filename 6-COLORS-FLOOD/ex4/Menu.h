#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
//a utility class to handle menu UI
class Menu
{
public:

   // constructor
	Menu(int m_screen_width, int m_screen_height);
	//detect clicks
	int getGlobal(sf::Vector2f& mouse_world);
	//draw the menu
	void draw(sf::RenderWindow& window);

	~Menu();

private:
//all private button shapes and fonts
	sf::RectangleShape rec_1, rec_2, rec_3,
		rec_4, rec_5, rec_6, reset_game, exit_game;
	sf::Text reset, exit;
	sf::Font font;
};

