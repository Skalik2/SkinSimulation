﻿#include <SFML/Graphics.hpp>    
#include <string.h>
#include <iostream>
#include <vector>

#include "CellArray.h"
#include "SkinCell.h"
#include "menu.h"

#define TABSIZE 12

sf::Vector2f viewSize(720, 720);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Symulacja tkanki", sf::Style::Default);

sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
sf::Vector2i centerPosition(desktop.width / 2 - viewSize.x / 2, desktop.height / 2 - viewSize.y / 2);
sf::Vector2u originalSize = window.getSize();

Menu gameMenu(window);
CellArray skinTab(window);

bool gameActive = false;
int stage = 0;

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
		case 2:
			for (int x = 0; x < skinTab.getSizeX(); x++)
			{
				for (int y = 0; y < skinTab.getSizeY(); y++)
				{
					window.draw(skinTab.get(x, y));
				}
			}
			break;

		case 3:
			gameMenu.drawSettings();
		break;
	}
}

void stageSwitch(int menuButton) 
{
	switch (menuButton)
	{
	case 0: //continue
		if (!gameActive)
			break;
		stage = 1;
		draw(stage);
		break;
	case 1: //new game
		gameActive = true;
		stage = 2;
		init();
		break;
	case 2: // settings
		stage = 3;
		draw(stage);
		break;
	case 3: //main menu 
		stage = 0;
		gameMenu.clearSelectedItem();
		gameMenu.clearMenuLevel();
		draw(stage);
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

		if (event.type == sf::Event::Closed)
			window.close();

		if (window.getSize() != originalSize) {
			window.setSize(originalSize);
			window.setPosition(centerPosition);
		}

		switch (event.type) {
			case sf::Event::KeyPressed:
				switch (event.key.code) {

				case sf::Keyboard::W:
				case sf::Keyboard::Up:
					if (stage == 0 || stage == 3)
						gameMenu.moveUp();
					if (skinTab.getSizeY() != 1 && (stage != 0 && stage !=3))
					{
						skinTab.setSize(skinTab.getSizeX(), skinTab.getSizeY() - 1);
						skinTab.resizeTab();
						draw(1);
					}
					break;
				case sf::Keyboard::D:
				case sf::Keyboard::Right:
					if (skinTab.getSizeX() < 360 && (stage != 0 && stage != 3))
					{
						skinTab.setSize(skinTab.getSizeX() + 1, skinTab.getSizeY());
						skinTab.initRight();
						draw(1);
					}
					break;
				case sf::Keyboard::A:
				case sf::Keyboard::Left:
					if (skinTab.getSizeX() != 1 && (stage != 0 && stage != 3))
					{
						skinTab.setSize(skinTab.getSizeX() - 1, skinTab.getSizeY());
						skinTab.resizeTab();
						draw(1);
					}
					break;
				case sf::Keyboard::S:
				case sf::Keyboard::Down:
					if (stage == 0 || stage == 3)
						gameMenu.moveDown();
					if (skinTab.getSizeY() < 360 && (stage != 0 && stage != 3))
					{
						skinTab.setSize(skinTab.getSizeX(), skinTab.getSizeY() + 1);
						skinTab.initDown();
						draw(1);
					}
					break;
				case sf::Keyboard::Escape:
				case sf::Keyboard::M:
					if (stage == 0)
						stage = 1;
					else
					{
						gameMenu.clearSelectedItem();
						gameMenu.clearMenuLevel();
						stage = 0;
					}	
					break;
				case sf::Keyboard::Enter:
					if (stage == 0 || stage == 3)
					{
						stageSwitch(gameMenu.MenuChoice(gameMenu.getSelectedItemIndex()));
					}
					break;
				}
			break;

			case sf::Event::MouseButtonPressed:
				if (stage == 0 || stage == 3)
					stageSwitch(gameMenu.handleMouseClick());
				else if (stage == 2)
 					std::cout << "click captured in game" << std::endl;

				skinTab.handleMouseClick();
				break;
		}
	}
}

int main() {
	skinTab.setSize(TABSIZE, TABSIZE);
	srand(static_cast<unsigned>(time(NULL)));
	sf::Clock clock;
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		updateInput();

		if (clock.getElapsedTime().asMilliseconds() > 10) {
			update();
			clock.restart();
		}
		window.clear(sf::Color::Black);

		draw(stage);

		window.display();
	}
	return 0;
}
