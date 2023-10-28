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
	void init(const sf::Vector2f& size, const sf::Vector2f& position, int state);
	void updatePositon(sf::Vector2f position);
	void updateSize(sf::Vector2f size);
	void update(int state);
	sf::RectangleShape getShape() const;
	sf::Color getTargetColor() const;
	void setTargetColor(const sf::Color&);
	
};
