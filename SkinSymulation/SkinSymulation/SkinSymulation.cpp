#include <SFML/Graphics.hpp>    
#include <string.h>
#include <iostream>
#include <vector>

#include "CellArray.h"
#include "SkinCell.h"

#define TABSIZE 12

sf::Vector2f viewSize(720, 720);
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
				if (skinTab.getSizeY() != 1)
				{
					skinTab.setSize(skinTab.getSizeX(), skinTab.getSizeY() - 1);
					skinTab.resizeTab();
					draw();
				}
			}
			if (event.key.code == sf::Keyboard::Right) {
				if (skinTab.getSizeX() < 360)
				{
					skinTab.setSize(skinTab.getSizeX() + 1, skinTab.getSizeY());
					skinTab.initRight();
					draw();
				}
			}
			if (event.key.code == sf::Keyboard::Left) {
				if (skinTab.getSizeX() != 1)
				{
					skinTab.setSize(skinTab.getSizeX() - 1, skinTab.getSizeY());
					skinTab.resizeTab();
					draw();
				}
			}
			if (event.key.code == sf::Keyboard::Down) {
				if (skinTab.getSizeY() < 360)
				{
					skinTab.setSize(skinTab.getSizeX(), skinTab.getSizeY() + 1);
					skinTab.initDown();
					draw();
				}
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
	window.setFramerateLimit(60);
	init();
	while (window.isOpen()) {
		updateInput();

		if (clock.getElapsedTime().asMilliseconds() > 1000) {
			update();
			clock.restart();
		}
		window.clear(sf::Color::Black);
		draw();
		window.display();
	}
	return 0;
}
