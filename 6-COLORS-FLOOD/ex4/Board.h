#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <map>
#include <iterator>
#include "Rectangle.h"

class Board
{
public:
	Board();
	//utility function to create the board
	void createBoardGame(sf::Vector2f  start ,sf::Vector2f size);
	//returns the board data structure
	std::vector<std::vector<Rectangle>>& getBoard();
	//update the color of tile
	void updateColor();
	//part of AI algorithm
	void countColor(int x, int y, int color, int  & count);
	//draw the board
	void draw(sf::RenderWindow & window);
	//reset all data structures
	void clean();
	//flood fill the board using DFS recursion
	void floodFill(const int& n);
	//calculate the number of rectangles to determine winner
	const int getSumOfRectangles(const int&id);
	const int getAIColor()
	{
		return ai_color;
	}
	//part of AI algorithm 
	void floodFillByComputer(const int& new_color);
	//flood fill the board using DFS recursion
	void floodFillUtil(int x, int y, int prevC, int newC,const int&indentifier);
	//part of AI algorithm
	int computerAlgorithm();
	//reset algorithm d's
	void resetVectorBool();
	//copy algorithm d's
	void copyVectorNumbers(std::vector<std::vector<int>>& m_number_1, std::vector<std::vector<int>>& m_number_2);
	~Board() {}
private:
	//all data structurs required for the board
	std::vector<std::vector<Rectangle>> m_rectangle;
	std::vector<std::vector<int>> m_number;
	std::vector<std::vector<int>> m_number_copy;
	std::vector<std::vector<bool>> m_number_bool;
	int ai_color;

};

