#include <SFML/Graphics.hpp>    
#include <string.h>
#include <iostream>
#include "SkinCell.h"

sf::Vector2f viewSize(720, 720);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Symulacja tkanki", sf::Style::Default);
SkinCell hero[12][12];

void init() {
	for (int x = 0; x < 12; x++)
	{
		for (int y = 0; y < 12; y++)
		{
			hero[x][y].init("Assets/graphics/skin60.png", sf::Vector2f(60 * x + 30, 60 * y + 30), 1);
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
		}
	}
}
void draw() {
	for (int x = 0; x < 12; x++)
	{
		for (int y = 0; y < 12; y++)
		{
			window.draw(hero[x][y].getSprite());
		}
	}
	
}
int main() {
	sf::Clock clock;
	window.setFramerateLimit(120);
	init();

	while (window.isOpen()) {
		updateInput();
		sf::Time dt = clock.restart();
		window.clear(sf::Color::Red);
		draw();
		window.display();
	}
	return 0;
}
