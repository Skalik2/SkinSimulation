#include "SkinCell.h"

SkinCell::SkinCell() {

}
SkinCell::~SkinCell() {

}

sf::Color setStateColor(int state) {
	switch (state) {
	case 0:
		return sf::Color(255, 174, 0, 255);
		break;
	case 1:
		return sf::Color(255, 60, 0, 255);
		break;
	}
}

void SkinCell::init(sf::Vector2f size,sf::Vector2f position,
	int state) {
	m_shape.setSize(size);
	m_shape.setPosition(position);
	m_shape.setFillColor(setStateColor(state));
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(3);
}

void SkinCell::update(int state) {
	m_shape.setFillColor(setStateColor(state));	
}

sf::RectangleShape SkinCell::getShape() {
	return m_shape;
}