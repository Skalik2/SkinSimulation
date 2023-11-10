#include <SFML/Graphics.hpp>    
#include <string.h>
#include <iostream>
#include <vector>
#include<windows.h>      

#include "CellArray.h"
#include "SkinCell.h"
#include "menu.h"

#define TABSIZE 12

sf::Vector2f viewSize(720, 720);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Symulacja tkanki", sf::Style::Default);

GameMenu gameMenu(window);
CellArray skinTab;

bool menu = true;

void init() 
{
	skinTab.init();
}

void draw(int stage) {
	switch (stage)
	{
		case 0:
			gameMenu.draw();
		break;

		case 1:
			for (int x = 0; x < skinTab.getSizeX(); x++)
			{
				for (int y = 0; y < skinTab.getSizeY(); y++)
				{
					window.draw(skinTab.get(x, y));
				}
			}
		break;
	}
}

void update() 
{
	skinTab.update();
}
void updateInput() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
			window.close();
		switch (event.type) {
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::W:
					case sf::Keyboard::Up:
						if (skinTab.getSizeY() != 1)
						{
							skinTab.setSize(skinTab.getSizeX(), skinTab.getSizeY() - 1);
							skinTab.resizeTab();
							draw(1);
						}
					break;
					case sf::Keyboard::D:
					case sf::Keyboard::Right:
						if (skinTab.getSizeX() < 360)
						{
							skinTab.setSize(skinTab.getSizeX() + 1, skinTab.getSizeY());
							skinTab.initRight();
							draw(1);
						}
					break;
					case sf::Keyboard::A:
					case sf::Keyboard::Left:
						if (skinTab.getSizeX() != 1)
						{
							skinTab.setSize(skinTab.getSizeX() - 1, skinTab.getSizeY());
							skinTab.resizeTab();
							draw(1);
						}
					break;
					case sf::Keyboard::S:
					case sf::Keyboard::Down:
						if (skinTab.getSizeY() < 360)
						{
							skinTab.setSize(skinTab.getSizeX(), skinTab.getSizeY() + 1);
							skinTab.initDown();
							draw(1);
						}
					break;
					case sf::Keyboard::P:
						if (menu == true)
							menu = false;
						else
							menu = true;
					break;
				}
			break;
		}
	}
}

int main() {
	skinTab.setSize(TABSIZE, TABSIZE);
	srand(time(NULL));
	sf::Clock clock;
	window.setFramerateLimit(60);
	init();
	while (window.isOpen()) {
		updateInput();

		if (clock.getElapsedTime().asMilliseconds() > 10) {
			update();
			clock.restart();
		}
		window.clear(sf::Color::Black);
		if (menu)
			draw(0);
		else
			draw(1);
		window.display();
	}
	return 0;
}
