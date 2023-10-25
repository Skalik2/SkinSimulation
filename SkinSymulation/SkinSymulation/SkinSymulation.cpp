#include <SFML/Graphics.hpp>    
#include <string.h>
#include <iostream>
#include <vector>

#include "CellArray.h"
#include "SkinCell.h"

#define TABSIZE 12

sf::Vector2f viewSize(800, 800);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Symulacja tkanki", sf::Style::Default);

CellArray skinTab;


void init() 
{
	skinTab.init();
}

void draw() {
	for (int x = 0; x < skinTab.getSizeX(); x++)
	{
		for (int y = 0; y < skinTab.getSizeY(); y++)
		{
			window.draw(skinTab.get(x,y));
		}
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
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				std::cout << "up" << std::endl;
				skinTab.setSize(skinTab.getSizeX(), skinTab.getSizeY() - 1);
				skinTab.init();
				draw();
			}
			if (event.key.code == sf::Keyboard::Right) {
				std::cout << "Right" << std::endl;
				skinTab.setSize(skinTab.getSizeX() + 1, skinTab.getSizeY());
				skinTab.init();
				draw();
			}
			if (event.key.code == sf::Keyboard::Left) {
				std::cout << "Left" << std::endl;
				skinTab.setSize(skinTab.getSizeX() - 1, skinTab.getSizeY());
				skinTab.init();
				draw();
			}
			if (event.key.code == sf::Keyboard::Down) {
				std::cout << "Down" << std::endl;
				skinTab.setSize(skinTab.getSizeX(), skinTab.getSizeY() + 1);
				skinTab.init();
				draw();
			}
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Right) {

			}
		}
	}
}

int main() {
	skinTab.setSize(TABSIZE, TABSIZE);
	
	srand(time(NULL));
	sf::Clock clock;
	window.setFramerateLimit(120);
	init();
	while (window.isOpen()) {
		updateInput();

		if (clock.getElapsedTime().asMilliseconds() > 1) {
			update();
			clock.restart();
		}
		window.clear(sf::Color::Black);
		draw();
		window.display();
	}
	return 0;
}
