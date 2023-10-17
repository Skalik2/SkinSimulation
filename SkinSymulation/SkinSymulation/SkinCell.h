#pragma once
#include <SFML/Graphics.hpp>  

class SkinCell
{
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	int m_state;
public:
	SkinCell();
	~SkinCell();
	void init(std::string textureName, sf::Vector2f position, int
		state);
	void update(float dt);
	sf::Sprite getSprite();
};

