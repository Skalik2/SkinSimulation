#include "Settings.h"

Settings::Settings(sf::RenderWindow& window)
	: m_window(window)
	, m_stage(0)
	, m_fpsLimit(60)
{
	if (!m_font.loadFromFile("arial.ttf")) {
		std::cerr << "Couldn't load font" << std::endl;
	}
	m_fpsNumber.setFont(m_font);
	m_fpsNumber.setString(std::to_string(m_fpsLimit));
	m_fpsNumber.setFillColor(sf::Color(0, 0, 0));
	m_fpsNumber.setOutlineColor(sf::Color(255, 255, 255));
	m_fpsNumber.setOutlineThickness(1);
	m_fpsNumber.setCharacterSize(20);
	m_fpsNumber.setPosition(sf::Vector2f(0, 0));
}

void Settings::drawFpsNumber()
{
	m_fpsNumber.setString(std::to_string(m_fpsLimit));
	m_window.draw(m_fpsNumber);
}

void Settings::setStage(const int number)
{
	m_stage = number;
}

int Settings::getStage() const
{
	return m_stage;
}

void Settings::setFpsLimit(const int number)
{
	m_fpsLimit = number;
}

int Settings::getFpsLimit() const
{
	return m_fpsLimit;
}

int Settings::getTimeUnit() const
{
	return m_timeInfectUnit;
}

void Settings::setTimeUnit(const int t)
{
	m_timeInfectUnit = t;
}

void Settings::addTimeUnit()
{
	m_timeInfectUnit += 333;
}

void Settings::subTimeUnit()
{
	m_timeInfectUnit -= 333;
}