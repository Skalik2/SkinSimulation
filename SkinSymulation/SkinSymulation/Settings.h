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
	int m_timeInfectUnit;
	bool m_isMultiInfect = true;
public:
	Settings(sf::RenderWindow& window);
	void setStage(const int number);
	int getStage() const;
	void setFpsLimit(const int number);
	int getFpsLimit() const;
	void drawFpsNumber();
	int getTimeUnit() const;
	void setTimeUnit(const int t);
	void addTimeUnit();
	void subTimeUnit();
	bool getIsMultiInfect() const;
	void setIsMultiInfect(const bool val);
};

