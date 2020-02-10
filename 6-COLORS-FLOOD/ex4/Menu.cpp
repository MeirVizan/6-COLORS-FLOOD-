#include "Menu.h"



Menu::Menu(int m_screen_width, int m_screen_height)
{
	


	font.loadFromFile("font.ttf");

	reset.setFont(font);
	reset.setCharacterSize(m_screen_height / 30);
	reset.setPosition(m_screen_width*0.01, m_screen_height*0.2);
	reset.setFillColor(sf::Color::Black);
	reset.setString("Restart");

	exit.setFont(font);
	exit.setCharacterSize(m_screen_height / 30);
	exit.setPosition(m_screen_width * 0.05, m_screen_height * 0.3);
	exit.setFillColor(sf::Color::Black);
	exit.setString("Exit");


	exit_game.setSize(sf::Vector2f(m_screen_width *0.18, m_screen_height / 15));
	exit_game.setFillColor(sf::Color::White);
	exit_game.setOutlineColor(sf::Color::Red);
	exit_game.setPosition(sf::Vector2f(m_screen_width * 0.005, m_screen_height * 0.3));

	reset_game.setSize(sf::Vector2f(m_screen_width * 0.18, m_screen_height / 15));
	reset_game.setFillColor(sf::Color::White);
	reset_game.setOutlineColor(sf::Color::Red);
	reset_game.setPosition(sf::Vector2f(m_screen_width * 0.005, m_screen_height * 0.2));


	rec_1.setSize(sf::Vector2f(m_screen_height/15, m_screen_height/15));
	rec_1.setFillColor(sf::Color::Red);
	rec_1.setPosition(sf::Vector2f(m_screen_width*0.22, m_screen_height*0.87));

	rec_2.setSize(sf::Vector2f(m_screen_height / 15, m_screen_height / 15));
	rec_2.setFillColor(sf::Color::Yellow);
	rec_2.setPosition(sf::Vector2f(m_screen_width *0.32, m_screen_height * 0.87));

	rec_3.setSize(sf::Vector2f(m_screen_height / 15, m_screen_height / 15));
	rec_3.setFillColor(sf::Color::Blue);
	rec_3.setPosition(sf::Vector2f(m_screen_width*0.42, m_screen_height * 0.87));

	rec_4.setSize(sf::Vector2f(m_screen_height / 15, m_screen_height / 15));
	rec_4.setFillColor(sf::Color::Cyan);
	rec_4.setPosition(sf::Vector2f(m_screen_width *0.52 , m_screen_height * 0.87));

	rec_5.setSize(sf::Vector2f(m_screen_height / 15, m_screen_height / 15));
	rec_5.setFillColor(sf::Color::Green);
	rec_5.setPosition(sf::Vector2f(m_screen_width * 0.62, m_screen_height * 0.87));

	rec_6.setSize(sf::Vector2f(m_screen_height / 15, m_screen_height / 15));
	rec_6.setFillColor(sf::Color::Magenta);
	rec_6.setPosition(sf::Vector2f(m_screen_width * 0.72, m_screen_height * 0.87));


}


int Menu::getGlobal(sf::Vector2f & mouse_world)
{
	if (rec_1.getGlobalBounds().contains(mouse_world))
		return 1;
	if (rec_2.getGlobalBounds().contains(mouse_world))
		return 2;
	if (rec_3.getGlobalBounds().contains(mouse_world))
		return 3;
	if (rec_4.getGlobalBounds().contains(mouse_world))
		return 4;
	if (rec_5.getGlobalBounds().contains(mouse_world))
		return 5;
	if (rec_6.getGlobalBounds().contains(mouse_world))
		return 6;
	if (reset_game.getGlobalBounds().contains(mouse_world))
		return 7;
	if (exit_game.getGlobalBounds().contains(mouse_world))
		return 8;

	return 0;
}

void Menu::draw(sf::RenderWindow & window)
{
	window.draw(rec_1);
	window.draw(rec_2);
	window.draw(rec_3);
	window.draw(rec_4);
	window.draw(rec_5);
	window.draw(rec_6);
	window.draw(reset_game);
	window.draw(reset);
	window.draw(exit_game);
	window.draw(exit);
}

Menu::~Menu()
{
}
