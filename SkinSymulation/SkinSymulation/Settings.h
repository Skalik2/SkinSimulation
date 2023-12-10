#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Settings
{
	sf::RenderWindow& m_window;
	int m_stage;
	int m_fpsLimit;
	sf::Text m_fpsNumber;
	sf::Font m_font;
public:
	Settings(sf::RenderWindow& window);
	void setStage(const int number);
	int getStage() const;
	void setFpsLimit(const int number);
	int getFpsLimit() const;
	void drawFpsNumber();
};

