#pragma once
#include <SFML/Graphics.hpp>    
#include <string.h>
#include <iostream>
#include <vector>
#include <thread>

#include "CellArray.h"
#include "menu.h"
#include "Settings.h"
#include "windowHelp.h"

class EventCapture
{
	bool m_gameActive;
	Menu& m_gameMenu;
	Settings& m_settings;
	CellArray& m_skinTab;
	sf::RenderWindow& m_window;
public:
	EventCapture(sf::RenderWindow& window, Settings& settings, CellArray& skinTab, Menu& gameMenu);
	void stageSwitch(int menuButton);
	void drawStage(const int stage);
	void updateInput();
	void changeColor(int numberOfRect, bool add);
};

