#pragma once
#include <SFML/Graphics.hpp>  
#include <iostream>
#include <math.h>

class SkinCell
{
	sf::RectangleShape m_shape;
	sf::Color m_targetColor;
	int m_stateOfCell = 0;
	int m_timeUnit = 0;
public:
	SkinCell();
	~SkinCell();
	void init(const sf::Vector2f& size, const sf::Vector2f& position, int state);
	void updatePositon(sf::Vector2f position);
	void updateSize(sf::Vector2f size);
	void update();
	void randInfect();
	sf::RectangleShape getShape() const;
	sf::Color getTargetColor() const;
	void setTargetColor(const sf::Color&);
	int getStateCell() const;
	void setStateCell(const int state);
	void setTimeUnit(const int tUnit);
	void addTimeUnit(const int tUnit);
	int getTimeUnit() const;
	
};
