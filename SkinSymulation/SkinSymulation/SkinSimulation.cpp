﻿#include <SFML/Graphics.hpp>    

#include "CellArray.h"
#include "SkinCell.h"
#include "menu.h"
#include "Settings.h"
#include "EventCapture.h"
#include "windowHelp.h"


int WinMain() {
	sf::Vector2f viewSize(720, 720);
	sf::VideoMode vm(viewSize.x, viewSize.y);
	sf::RenderWindow window(vm, "Symulacja tkanki", sf::Style::Default);
	
	Settings settings(window);
	Menu gameMenu(window,settings);
	CellArray skinTab(window, settings);
	EventCapture eventCapture(window, settings, skinTab, gameMenu);

	srand(static_cast<unsigned>(time(NULL)));
	sf::Clock clock;
	window.setFramerateLimit(128);

	while (window.isOpen()) 
	{
		eventCapture.updateInput();
		if (clock.getElapsedTime().asMilliseconds() > settings.getTimeUnit())
		{
			skinTab.update(settings.getInfectionTime(), settings.getResistantTime());
			skinTab.updateInfect();
			clock.restart();
		}
		window.clear(sf::Color::Black);
		eventCapture.drawStage(settings.getStage());

		window.display();
	}
	if (eventCapture.isRunning)
	{
		if (settings.getIsWindowHelpOpen())
		{
			settings.toggleIsWindowHelpOpen();
		}
		eventCapture.isRunning = false;
		eventCapture.thread.join();
	}
	return 0;
}