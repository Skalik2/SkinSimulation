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
SkinCell hero[TABSIZE][TABSIZE];
bool switchSkin = false;

CellArray skinTab;
int ArraysizeX, ArraysizeY;

std::vector<std::vector<SkinCell>> skinCellTab(TABSIZE,std::vector<SkinCell>(TABSIZE));

void init() 
{
	skinTab.init();
}

void draw() {
	for (int x = 0; x < ArraysizeX; x++)
	{
		for (int y = 0; y < ArraysizeY; y++)
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
				ArraysizeY -= 1;
				skinTab.size(ArraysizeX, ArraysizeY);
				draw();
			}
			if (event.key.code == sf::Keyboard::Right) {
				ArraysizeX += 1;
				skinTab.size(ArraysizeX, ArraysizeY);
				skinTab.update();
				draw();
			}
			if (event.key.code == sf::Keyboard::Left) {
				ArraysizeX -= 1;
				skinTab.size(ArraysizeX, ArraysizeY);
				skinTab.update();
				draw();
			}
			if (event.key.code == sf::Keyboard::Down) {
				ArraysizeY += 1;
				skinTab.size(ArraysizeX, ArraysizeY);
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
	ArraysizeX = TABSIZE;
	ArraysizeY = TABSIZE;
	skinTab.size(ArraysizeX, ArraysizeY);

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
