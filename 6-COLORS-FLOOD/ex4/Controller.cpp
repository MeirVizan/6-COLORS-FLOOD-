#include "Controller.h"
#include <thread>
#include <chrono>
#include "Constants.h"

Controller::Controller()
	:m_screen_width(0), m_screen_height(0), is_play_allowed(true), player_color(0), turn_consumed(true)
{  
}

void Controller::run()
{
	m_screen_width = sf::VideoMode::getDesktopMode().width*0.5;
	m_screen_height = sf::VideoMode::getDesktopMode().height*0.7;

	sf::RenderWindow window(sf::VideoMode(m_screen_width, m_screen_height, 32), "6 Colors",
		sf::Style::Titlebar | sf::Style::Close);
	sf::Vector2f position = sf::Vector2f(20, 20);

	sf::RectangleShape winRec(sf::Vector2f(m_screen_width, m_screen_height));
	winRec.setFillColor(sf::Color::Color(192,192,192));
	

	sf::RectangleShape reset_game(sf::Vector2f(m_screen_width / 7, m_screen_height/15));
	reset_game.setFillColor(sf::Color::White);
	reset_game.setOutlineColor(sf::Color::Red);
	reset_game.setPosition(sf::Vector2f(50,150));

	sf::Font font;
	font.loadFromFile("font.ttf");
	sf::Text reset;
	reset.setFont(font);
	reset.setCharacterSize(m_screen_height / 30);
	reset.setPosition(55,155);
	reset.setFillColor(sf::Color::Black);
	reset.setString("Restart");
	sf::Text turn;
	turn.setFont(font);
	turn.setCharacterSize(m_screen_height / 25);
	turn.setPosition(m_screen_width * 0.35,m_screen_height*0.01);
	turn.setFillColor(sf::Color::Black);
	turn.setString("Your Turn");
	int count=0;
	float x = m_screen_width / 5.2;
	float y = m_screen_height / 6;
	int tile_size = m_screen_height / 30;
	Menu menu(m_screen_width, m_screen_height);

    m_board.createBoardGame({x, y }, {(float)tile_size,(float) tile_size});
	//m_board.createBoardGame({ 295, 20 }, { (536 / 10)*0.72,(536 / 10)*0.72 });
	while (window.isOpen())
	{
		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				window.close();
				break;
			}
			turn_consumed = false;
			//get mouse position 
			
			if (event.type == sf::Event::MouseButtonPressed
				&&event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mouse = sf::Mouse::getPosition(window);
				sf::Vector2f mouse_world = window.mapPixelToCoords(mouse);
				//compute global boundries
				if (menu.getGlobal(mouse_world) == 8)
				{
					window.close();
					break;
				}

				if (menu.getGlobal(mouse_world) == 7) {
					m_board.clean();
					m_board.createBoardGame({ x, y }, { (float)tile_size,(float)tile_size });
					is_play_allowed = true;
				}

				if (menu.getGlobal(mouse_world) == 1&&is_play_allowed&&player_color!=1&&m_board.getAIColor()!=1)
				{
					turn_consumed = true;
					player_color = 1;
					m_board.floodFill(1);
					m_board.updateColor();
					turn.setString("AI Turn");
					if (m_board.getSumOfRectangles(0) > (col * row) / 2)
					{
						is_play_allowed = false;
						turn.setString("You Win!");
					}
					else if (m_board.getSumOfRectangles(1) > (col * row) / 2)
					{
						is_play_allowed = false;
						turn.setString("AI Win!");
					}
					update(window, winRec, m_board, menu,turn);
					std::this_thread::sleep_for(std::chrono::seconds(1));
					
				}

				if (menu.getGlobal(mouse_world) == 2&&is_play_allowed&&player_color!=2&&m_board.getAIColor() != 2)
				{
					turn_consumed = true;

					player_color = 2;
					m_board.floodFill(2);
					m_board.updateColor();
					turn.setString("AI Turn");
					if (m_board.getSumOfRectangles(0) > (col * row) / 2)
					{
						is_play_allowed = false;
						turn.setString("You Win!");
					}
					else if (m_board.getSumOfRectangles(1) > (col * row) / 2)
					{
						is_play_allowed = false;
						turn.setString("AI Win!");
					}
					update(window, winRec, m_board, menu,turn);

					std::this_thread::sleep_for(std::chrono::seconds(1));
				}
				if (menu.getGlobal(mouse_world) == 3&&is_play_allowed&&player_color!=3&&m_board.getAIColor() != 3)
				{
					turn_consumed = true;

					player_color = 3;
					m_board.floodFill(3);
					m_board.updateColor();
					turn.setString("AI Turn");
					if (m_board.getSumOfRectangles(0) > (col * row) / 2)
					{
						is_play_allowed = false;
						turn.setString("You Win!");
					}
					else if (m_board.getSumOfRectangles(1) > (col * row) / 2)
					{
						is_play_allowed = false;
						turn.setString("AI Win!");
					}
					update(window, winRec, m_board, menu,turn);

					std::this_thread::sleep_for(std::chrono::seconds(1));
				}
				if (menu.getGlobal(mouse_world) == 4&&is_play_allowed&&player_color!=4&&m_board.getAIColor()!=4)
				{
					turn_consumed = true;

					player_color = 4;
					m_board.floodFill(4);
					m_board.updateColor();
					turn.setString("AI Turn");
					if (m_board.getSumOfRectangles(0) > (col * row) / 2)
					{
						is_play_allowed = false;
						turn.setString("You Win!");
					}
					else if (m_board.getSumOfRectangles(1) > (col * row) / 2)
					{
						is_play_allowed = false;
						turn.setString("AI Win!");
					}
					update(window, winRec, m_board, menu,turn);

					std::this_thread::sleep_for(std::chrono::seconds(1));
				}
				if (menu.getGlobal(mouse_world) == 5&&player_color!=5)
				{
					turn_consumed = true;

					player_color = 5;
					m_board.floodFill(5);
					m_board.updateColor();
					turn.setString("AI Turn");
					if (m_board.getSumOfRectangles(0) > (col * row) / 2)
					{
						is_play_allowed = false;
						turn.setString("You Win!");
					}
					else if (m_board.getSumOfRectangles(1) > (col * row) / 2)
					{
						is_play_allowed = false;
						turn.setString("AI Win!");
					}
					update(window, winRec, m_board, menu,turn);

					std::this_thread::sleep_for(std::chrono::seconds(1));

				}
				if (menu.getGlobal(mouse_world) == 6&&is_play_allowed&&player_color!=6&&m_board.getAIColor()!=6)
				{
					turn_consumed = true;

					player_color = 6;
					m_board.floodFill(6);
					m_board.updateColor();
					turn.setString("AI Turn");
					if (m_board.getSumOfRectangles(0) > (col * row) / 2)
					{
						is_play_allowed = false;
						turn.setString("You Win!");
					}
					else if (m_board.getSumOfRectangles(1) > (col * row) / 2)
					{
						is_play_allowed = false;
						turn.setString("AI Win!");
					}
					update(window, winRec, m_board, menu,turn);
					
					std::this_thread::sleep_for(std::chrono::seconds(1));

				}

				//computer
				if (turn_consumed) {
					int color = m_board.computerAlgorithm();
					
						m_board.floodFillByComputer(color);
						m_board.updateColor();
					
					if (is_play_allowed)
						turn.setString("Your Turn");
				}
				update(window, winRec, m_board, menu, turn);


				
				
			}
			
			
		}
		
		update(window, winRec, m_board, menu,turn);

	}
}
void Controller::update(sf::RenderWindow& window, sf::RectangleShape& winRec, Board& m_board, Menu& menu,sf::Text&t)
{
	window.clear();
	window.draw(winRec);
	menu.draw(window);
	m_board.draw(window);
	window.draw(t);
	window.display();
}
Controller::~Controller()
{
}
