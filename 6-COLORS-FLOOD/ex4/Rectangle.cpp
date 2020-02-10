#include "Rectangle.h"


Rectangle::Rectangle(sf::Color c, sf::Vector2f  p, sf::Vector2f  s)

	:m_color(c),m_position(p),m_size(s),m_identifier(-1)
{
	m_rec.setSize(m_size);
	m_rec.setFillColor(m_color);
	m_rec.setPosition(m_position);

	
	

}

sf::Vector2f & Rectangle::getPosition()
{
	return m_position;
}

sf::Color Rectangle::getColor()
{
	return m_color;
}


sf::RectangleShape Rectangle::getRectangle()
{
	return m_rec;
}

void Rectangle::draw(sf::RenderWindow & window)
{
	window.draw(m_rec);
}

void Rectangle::changeColor(sf::Color color)
{
	m_rec.setFillColor(color);
}


