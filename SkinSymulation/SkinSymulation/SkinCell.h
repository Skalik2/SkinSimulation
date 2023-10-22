#pragma once
#include <SFML/Graphics.hpp>  
#include <iostream>

class SkinCell
{
	sf::RectangleShape m_shape;
	sf::Color m_targetColor;
public:
	SkinCell();
	~SkinCell();
	void init(sf::Vector2f size, sf::Vector2f position, int
		state);
	void update(int state);
	sf::RectangleShape getShape();
	sf::Color getTargetColor();
	void setTargetColor(sf::Color);
	
};

