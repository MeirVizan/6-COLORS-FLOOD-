#include "Board.h"
#include <cstdlib>
#include "Constants.h"
Board::Board()
	:ai_color(0)
{
	m_rectangle.resize(row * col);
	m_number.resize(row*col);
	m_number_copy.resize(row*col);
	m_number_bool.resize(row*col);
}

void Board::createBoardGame(sf::Vector2f  start, sf::Vector2f size)
{
	srand(time(NULL));
	sf::Vector2f new_point =start;
	int num = 0;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col ; j++)
		{
			num = rand() % 6 + 1;
			switch (num)
			{
			case red:
				//map_rec.insert(std::pair<int, Rectangle>(1,Rectangle(sf::Color::Red, start, size)));
				m_rectangle[i].push_back(Rectangle( sf::Color::Red, start,  size));
				m_number[i].push_back(1);
				m_number_copy[i].push_back(1);
				break;
			case yellow:
				m_rectangle[i].push_back(Rectangle(sf::Color::Yellow, start,  size));
				m_number[i].push_back(2);
				m_number_copy[i].push_back(2);
				break;
			case blue:
				m_rectangle[i].push_back(Rectangle(sf::Color::Blue, start,  size));
				m_number[i].push_back(3);
				m_number_copy[i].push_back(3);
				break;
			case cyan:
				m_rectangle[i].push_back(Rectangle(sf::Color::Cyan, start,  size));
				m_number[i].push_back(4);
				m_number_copy[i].push_back(4);				
				break;
			case green:
				m_rectangle[i].push_back(Rectangle(sf::Color::Green, start,  size));
				m_number[i].push_back(5);
				m_number_copy[i].push_back(5);
				break;
			case magenta:
				m_rectangle[i].push_back(Rectangle(sf::Color::Magenta, start,  size));
				m_number[i].push_back(6);
				m_number_copy[i].push_back(6);
				break;
			}
			start.x = start.x + size.x;
			//std::sqrt(std::pow(size.x, 2) + std::pow(size.y, 2));
			//std::cout << start.x << " " << start.y << std::endl;
		}
		start.y = start.y + size.y ;
		start.x = new_point.x;
	}
	
}



std::vector<std::vector<Rectangle>> & Board::getBoard()
{
	return m_rectangle;
}

void Board::updateColor()
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			switch (m_number[i][j])
			{
			case red:
				m_rectangle[i][j].changeColor(sf::Color::Red);
				break;
			case yellow:
				m_rectangle[i][j].changeColor(sf::Color::Yellow);
				break;
			case blue:
				m_rectangle[i][j].changeColor(sf::Color::Blue);
				break;
			case cyan:
				m_rectangle[i][j].changeColor(sf::Color::Cyan);
				break;
			case green:
				m_rectangle[i][j].changeColor(sf::Color::Green);
				break;
			case magenta:
				m_rectangle[i][j].changeColor(sf::Color::Magenta);
				break;
			}
		}
	}
}




void Board::draw(sf::RenderWindow & window)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			m_rectangle[i][j].draw(window);
		}
	}
}

void Board::clean()
{
	m_number.clear();
	m_rectangle.clear();
	m_rectangle.resize(row * col);
	m_number.resize(row*col);
}



const int Board::getSumOfRectangles(const int&id)
{
	int counter = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (m_rectangle[i][j].getIdentifier() == id)
					counter++;
			}
		}
	
   return counter;
}

void Board::floodFill(const int& new_color)
{
	int prev_color = m_number[0][0];

	floodFillUtil(0, 0, prev_color, new_color, 0);
	
}

void Board::floodFillByComputer(const int& new_color)
{
	int prev_color = m_number[row-1][col-1];
	floodFillUtil(row-1,col-1, prev_color, new_color,1);
	ai_color = new_color;
}


void Board::floodFillUtil(int x, int y, int prevC, int newC, const int& identifier)
{
	if (prevC == newC)
		return;
	// Base cases 
	if (x < 0 || x >= row || y < 0 || y >= col)
		return;

	if (m_number[x][y] != prevC)
		return;

	//player is active do not invade AI squares
	if (identifier == -1) {
		m_number[x][y] = newC;
		m_rectangle[x][y].setIdentifier(identifier);
	}
	else
	if (identifier == 0) {
	// Replace the color at (x, y) 
	if (m_rectangle[x][y].getIdentifier() != 1)
	{
		m_number[x][y] = newC;
		m_rectangle[x][y].setIdentifier(identifier);
	}
	else
		return;
	}
	else
	if(identifier==1)
	{
		if (m_rectangle[x][y].getIdentifier() != 0)
		{
			m_number[x][y] = newC;
			m_rectangle[x][y].setIdentifier(identifier);
		}
		else
			return;
	}
	// Recur for north, east, south and west 
	floodFillUtil( x + 1, y, prevC, newC,identifier);
	floodFillUtil( x - 1, y, prevC, newC,identifier);
	floodFillUtil( x, y + 1, prevC, newC,identifier);
	floodFillUtil( x, y - 1, prevC, newC,identifier);
}

void Board::countColor(int x, int y, int color, int & count)
{
	// Base cases 
	if (x < 0 || x >= row || y < 0 || y >= col)
		return;

	if (m_number[x][y] != color)
		return;

	if (m_number_bool[x][y] == true)
		return;

	if (m_number[x][y] == color) {
		count++;
		m_number_bool[x][y] = true;
	}

	// Replace the color at (x, y) 

	// Recur for north, east, south and west 
	countColor(x + 1, y, color, count);
	countColor(x - 1, y, color, count);
	countColor(x, y + 1, color, count);
	countColor(x, y - 1, color, count);
}

int Board::computerAlgorithm()
{
	int count = 0,max=0,color=0;
	copyVectorNumbers(m_number_copy, m_number);
	resetVectorBool();
	for (int i = 1; i < 7; i++)
	{
		floodFillByComputer(i);
		countColor(row-1, col-1, i, count);
		if (count > max)
		{
			max = count;
			color = i;
		}
		count = 0;
		resetVectorBool();
		copyVectorNumbers(m_number,m_number_copy);
	//	watchUpdate();
	}
	
	return color;
}



void Board::resetVectorBool()
{
	m_number_bool.clear();
	m_number_bool.resize(row*col);
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			m_number_bool[i].push_back(false);
		}
	}
}

void Board::copyVectorNumbers(std::vector<std::vector<int>> & m_number_1, std::vector<std::vector<int>> & m_number_2)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			m_number_1[i][j] = m_number_2[i][j];
		}
	}
}
