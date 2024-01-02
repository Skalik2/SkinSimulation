#include <SFML/Graphics.hpp>    
#include <string.h>
#include <iostream>
#include <vector>

#include "CellArray.h"
#include "SkinCell.h"
#include "menu.h"
#include "Settings.h"

sf::Vector2f viewSize(720, 720);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Symulacja tkanki", sf::Style::Default);
sf::View view = window.getDefaultView();

Menu gameMenu(window);
Settings settings(window);
CellArray skinTab(window, settings);

bool gameActive = false;

void init() 
{
	skinTab.init();
}

void ResizeView()
{
	float aspectRatio = (float)window.getSize().x / (float)window.getSize().y;

	view.setSize((float)window.getSize().y * aspectRatio, window.getSize().y);
	window.setView(view);
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
	case -1:
		break;
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
		gameMenu.clearMenuLevel();
		draw(settings.getStage());
		break;
	case 3: // main menu 
		settings.setStage(0);
		gameMenu.clearSelectedItem();
		gameMenu.clearMenuLevel();
		gameMenu.setMenuLevel(0);
		draw(settings.getStage());
		break;
	case 4: // tab size 
		gameMenu.setMenuLevel(2);
		settings.setStage(4);
		draw(settings.getStage());
		break;
	case 5: //25x25
		skinTab.setSize(25, 25);
		init();
		gameMenu.clearMenuLevel();
		settings.setStage(3);
		gameMenu.setMenuLevel(1);
		draw(settings.getStage());
		break;
	case 6:	//75x75
		skinTab.setSize(75, 75);
		init();
		gameMenu.clearMenuLevel();
		settings.setStage(3);
		gameMenu.setMenuLevel(1);
		draw(settings.getStage());
		break;
	}
}

void update() 
{
	skinTab.update(settings.getInfectionTime(), settings.getResistantTime());
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

		if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			window.setView(sf::View(visibleArea));
			window.setSize(sf::Vector2u(event.size.width, event.size.height));
			skinTab.resizeTab();
			gameMenu.resize();
		}

		switch (event.type) {
			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::H:
					std::cout << "Stage: " << settings.getStage() << std::endl;
					std::cout << "menu_level: " << gameMenu.getMenuLevel() << std::endl;
					std::cout << "X: " << skinTab.getSizeX() << " Y: " << skinTab.getSizeY() << std::endl;
					break;
				case sf::Keyboard::W:
				case sf::Keyboard::Up:
					if (settings.getStage() == 0 || settings.getStage() == 3 || settings.getStage() == 4)
						gameMenu.moveUp();
					if (skinTab.getSizeY() != 1 && (settings.getStage() != 0 && settings.getStage() != 3 && settings.getStage() != 4))
					{
						skinTab.setSize(skinTab.getSizeX(), skinTab.getSizeY() - 1);
						skinTab.resizeTab();
						draw(1);
					}
					break;
				case sf::Keyboard::D:
				case sf::Keyboard::Right:
					if (skinTab.getSizeX() < 239 && (settings.getStage() != 0 && settings.getStage() != 3 && settings.getStage() != 4))
					{
						skinTab.setSize(skinTab.getSizeX() + 1, skinTab.getSizeY());
						skinTab.initRight();
						draw(1);
					}
					break;
				case sf::Keyboard::A:
				case sf::Keyboard::Left:
					if (skinTab.getSizeX() != 1 && (settings.getStage() != 0 && settings.getStage() != 3 && settings.getStage() != 4))
					{
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
						skinTab.setSize(skinTab.getSizeX(), skinTab.getSizeY() + 1);
						skinTab.initDown();
						draw(1);
					}
					break;
				case sf::Keyboard::Escape:
				case sf::Keyboard::M:
					if (settings.getStage() == 0 && gameActive == true)
						settings.setStage(1);
					else
					{
						gameMenu.clearSelectedItem();
						gameMenu.clearMenuLevel();
						gameMenu.setMenuLevel(0);
						settings.setStage(0);
					}	
					break;
				case sf::Keyboard::Enter:
					if (settings.getStage() == 0 || settings.getStage() == 3 || settings.getStage() == 4)
					{
						stageSwitch(gameMenu.MenuChoice(gameMenu.getSelectedItemIndex()));
					}
					break;
				case sf::Keyboard::O:
					settings.subProbability();
					break;
				case sf::Keyboard::P:
					settings.addProbability();
					break;
				case sf::Keyboard::L:
					if (settings.getFpsLimit() <= 64)
					{
						settings.setFpsLimit(settings.getFpsLimit() * 2);
						settings.setTimeUnit();
					}
					settings.drawFpsNumber();
					break;
				case sf::Keyboard::K:
					if (settings.getFpsLimit() >= 2)
					{
						settings.setFpsLimit(settings.getFpsLimit() / 2);
						settings.setTimeUnit();
					}
					settings.drawFpsNumber();
					break;
				}
				
			break;

			case sf::Event::MouseButtonPressed:
				if (settings.getStage() == 0 || settings.getStage() == 3 || settings.getStage() == 4)
				{
					stageSwitch(gameMenu.handleMouseClick());
				}
				else if (settings.getStage() == 2 || settings.getStage() == 1)
					skinTab.handleMouseClick();
					
				break;
		}
	}
}

int main() {
	settings.setTimeUnit(300);
	skinTab.setSize(12, 12);
	srand(static_cast<unsigned>(time(NULL)));
	sf::Clock clock;
	window.setFramerateLimit(128);
	while (window.isOpen()) 
	{
		updateInput();

		if (clock.getElapsedTime().asMilliseconds() > settings.getTimeUnit())
		{
			update();
			updateInfection();
			
			clock.restart();
		}
		window.clear(sf::Color::Black);

		draw(settings.getStage());

		window.display();
	}
	return 0;
}
