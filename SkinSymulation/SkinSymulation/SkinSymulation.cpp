#include <SFML/Graphics.hpp>    
#include <string.h>
#include <iostream>
#include "SkinCell.h"

#define TABSIZE 12

sf::Vector2f viewSize(TABSIZE * 60, TABSIZE * 60);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Symulacja tkanki", sf::Style::Default);
SkinCell hero[TABSIZE][TABSIZE];
bool switchSkin = false;

void init() {
	for (int x = 0; x < TABSIZE; x++)
	{
		for (int y = 0; y < TABSIZE; y++)
		{
			hero[x][y].init(sf::Vector2f(60.f, 60.f) , sf::Vector2f(60 * x, 60 * y), 0);
		}
	}
}
void updateInput() {
	sf::Event event;
	// while there are pending events...
	while (window.pollEvent(event)) {
		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				std::cout << "Key up" << std::endl;
			}
			if (event.key.code == sf::Keyboard::Right) {
				switchSkin = true;
			}
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Right) {
				switchSkin = false;
			}
		}
	}
}
void draw() {
	for (int x = 0; x < TABSIZE; x++)
	{
		for (int y = 0; y < TABSIZE; y++)
		{
			window.draw(hero[x][y].getShape());
		}
	}

}

void update() {
	for (int x = 0; x < TABSIZE; x++)
	{
		for (int y = 0; y < TABSIZE; y++)
		{
			hero[x][y].update(rand() % 3 + 1);
		}
	}
}

int main() {
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
