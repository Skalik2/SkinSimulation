#include <SFML/Graphics.hpp>    
#include <string.h>
#include <iostream>
#include <vector>

#include "CellArray.h"
#include "SkinCell.h"
#include "menu.h"
#include "Settings.h"

#define TABSIZE 12

sf::Vector2f viewSize(720, 720);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Symulacja tkanki", sf::Style::Default);

sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
sf::Vector2i centerPosition(desktop.width / 2 - viewSize.x / 2, desktop.height / 2 - viewSize.y / 2);
sf::Vector2u originalSize = window.getSize();

Menu gameMenu(window);
CellArray skinTab(window);
Settings settings(window);

bool gameActive = false;

void init() 
{
	skinTab.init();
}

void draw(int stage) {
	switch (settings.getStage())
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
			settings.drawFpsNumber();
			break;

		case 3:
			gameMenu.drawSettings();
			break;

		case 4:
			gameMenu.drawSettingsInfectType();
			break;
	}
}

void stageSwitch(int menuButton) 
{
	switch (menuButton)
	{
	case 0: // continue
		if (!gameActive)
			break;
		settings.setStage(1);
		draw(settings.getStage());
		break;
	case 1: // new game
		gameActive = true;
		settings.setStage(2);
		init();
		break;
	case 2: // settings
		settings.setStage(3);
		draw(settings.getStage());
		break;
	case 3: // main menu 
		settings.setStage(0);
		gameMenu.clearSelectedItem();
		gameMenu.clearMenuLevel();
		draw(settings.getStage());
		break;
	case 4: // infection model
		settings.setStage(4);
		draw(settings.getStage());
		break;
	}
	
}

void update() 
{
	skinTab.update();
}

void updateInfection()
{
	skinTab.updateInfect();
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
					if (settings.getStage() == 0 || settings.getStage() == 3 || settings.getStage() == 4)
						gameMenu.moveUp();
					if (skinTab.getSizeY() != 1 && (settings.getStage() != 0 && settings.getStage() != 3 && settings.getStage() != 4))
					{
						std::cout << "X: " << skinTab.getSizeX() << " Y: " << skinTab.getSizeY() << std::endl;
						skinTab.setSize(skinTab.getSizeX(), skinTab.getSizeY() - 1);
						skinTab.resizeTab();
						draw(1);
					}
					break;
				case sf::Keyboard::D:
				case sf::Keyboard::Right:
					if (skinTab.getSizeX() < 239 && (settings.getStage() != 0 && settings.getStage() != 3 && settings.getStage() != 4))
					{
						std::cout << "X: " << skinTab.getSizeX() << " Y: " << skinTab.getSizeY() << std::endl;
						skinTab.setSize(skinTab.getSizeX() + 1, skinTab.getSizeY());
						skinTab.initRight();
						draw(1);
					}
					break;
				case sf::Keyboard::A:
				case sf::Keyboard::Left:
					if (skinTab.getSizeX() != 1 && (settings.getStage() != 0 && settings.getStage() != 3 && settings.getStage() != 4))
					{
						std::cout << "X: " << skinTab.getSizeX() << " Y: " << skinTab.getSizeY() << std::endl;
						skinTab.setSize(skinTab.getSizeX() - 1, skinTab.getSizeY());
						skinTab.resizeTab();
						draw(1);
					}
					break;
				case sf::Keyboard::S:
				case sf::Keyboard::Down:
					if (settings.getStage() == 0 || settings.getStage() == 3 || settings.getStage() == 4)
						gameMenu.moveDown();
					if (skinTab.getSizeY() < 239 && (settings.getStage() != 0 && settings.getStage() != 3 && settings.getStage() != 4))
					{
						std::cout << "X: " << skinTab.getSizeX() << " Y: " << skinTab.getSizeY() << std::endl;
						skinTab.setSize(skinTab.getSizeX(), skinTab.getSizeY() + 1);
						skinTab.initDown();
						draw(1);
					}
					break;
				case sf::Keyboard::Escape:
				case sf::Keyboard::M:
					if (settings.getStage() == 0)
						settings.setStage(1);
					else
					{
						gameMenu.clearSelectedItem();
						gameMenu.clearMenuLevel();
						settings.setStage(0);
					}	
					break;
				case sf::Keyboard::Enter:
					if (settings.getStage() == 0 || settings.getStage() == 3 || settings.getStage() == 4)
					{
						stageSwitch(gameMenu.MenuChoice(gameMenu.getSelectedItemIndex()));
					}
					break;
				case sf::Keyboard::PageUp:
					if (settings.getFpsLimit() <= 80)
					{
						settings.setFpsLimit(settings.getFpsLimit() + 10);
						settings.subTimeUnit();
					}
					window.setFramerateLimit(settings.getFpsLimit());
					settings.drawFpsNumber();
					break;
				case sf::Keyboard::PageDown:
					if (settings.getFpsLimit() >= 20)
					{
						settings.setFpsLimit(settings.getFpsLimit() - 10);
						settings.addTimeUnit();
					}
					window.setFramerateLimit(settings.getFpsLimit());
					settings.drawFpsNumber();
					break;
				}
				
			break;

			case sf::Event::MouseButtonPressed:
				if (settings.getStage() == 0 || settings.getStage() == 3 || settings.getStage() == 4)
					stageSwitch(gameMenu.handleMouseClick());
				else if (settings.getStage() == 2)
					skinTab.handleMouseClick();
					
				break;
		}
	}
}

int main() {
	settings.setTimeUnit(2000);
	skinTab.setSize(TABSIZE, TABSIZE);
	srand(static_cast<unsigned>(time(NULL)));
	sf::Clock clock;
	sf::Clock clock2;
	window.setFramerateLimit(settings.getFpsLimit());
	while (window.isOpen()) 
	{
		updateInput();

		if (clock.getElapsedTime().asMilliseconds() > 10) 
		{
			update();
			clock.restart();
		}

		if (clock2.getElapsedTime().asMilliseconds() > settings.getTimeUnit())
		{
			updateInfection();
			clock2.restart();
		}
		window.clear(sf::Color::Black);

		draw(settings.getStage());

		window.display();
	}
	return 0;
}
