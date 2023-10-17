#pragma once
#include <SFML/Graphics.hpp>  

class SkinCell
{
private:
	sf::RectangleShape m_shape;
public:
	SkinCell();
	~SkinCell();
	void init(sf::Vector2f size, sf::Vector2f position, int
		state);
	void update(int state);
	sf::RectangleShape getShape();
};

