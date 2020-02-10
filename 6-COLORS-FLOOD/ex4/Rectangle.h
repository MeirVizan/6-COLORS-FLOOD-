#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

//a wrapper class for sfml rectangle shape
class Rectangle 
{
public:
	//constructor
	Rectangle(sf::Color c, sf::Vector2f  p, sf::Vector2f  s);
	//returns the posistion
	sf::Vector2f & getPosition();
	//returns the color
	sf::Color getColor();
	//returns the rectangelshape
	sf::RectangleShape getRectangle();
	//draw the shape
	void draw(sf::RenderWindow & window);
	//set a custom color background
	void changeColor(sf::Color color);
	
	//~Rectangle() {}
	void setIdentifier(const int& i)
	{
		m_identifier = i;
	}
	const int getIdentifier()
	{
		return m_identifier;
	}

private:
	sf::RectangleShape m_rec;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	sf::Color m_color;
	int m_identifier;//0- player 1-AI
};

