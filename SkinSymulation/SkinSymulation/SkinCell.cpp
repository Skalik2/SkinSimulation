#include "SkinCell.h"

SkinCell::SkinCell() {

}
SkinCell::~SkinCell() {

}
void SkinCell::init(std::string textureName, sf::Vector2f position,
	int state) {
	m_position = position;
	m_state = state;

	m_texture.loadFromFile(textureName.c_str());
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
}

//void SkinCell::update(float dt) {
//	if (m_state ... ) {
//
//	}
//}

sf::Sprite SkinCell::getSprite() {
	return m_sprite;
}