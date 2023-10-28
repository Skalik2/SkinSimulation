#include "SkinCell.h"

SkinCell::SkinCell() 
{

}
SkinCell::~SkinCell() 
{

}

sf::Color setStateColor(int state) 
{
	switch (state) {
	case 0:
		return sf::Color(255, 174, 0, 255);
		break;
	case 1:
		return sf::Color(255, 60, 0, 255);
		break;
	case 2:
		return sf::Color(34, 191, 76, 255);
		break;
	case 3:
		return sf::Color(204, 255, 0, 255);
		break;
	}
}

void SkinCell::init(const sf::Vector2f& size,const sf::Vector2f& position, int state) 
{
	m_shape.setSize(size);
	m_shape.setPosition(position);
	m_shape.setFillColor(setStateColor(0));
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(1);
}


void SkinCell::updatePositon(sf::Vector2f position)
{
	m_shape.setPosition(position);
}

void SkinCell::updateSize(sf::Vector2f size)
{
	m_shape.setSize(size);
}

int switchTickSpeed = 1;

void SkinCell::update(int state) 
{
	if (static_cast<int>(getTargetColor().r) == 0 &&
		static_cast<int>(getTargetColor().g) == 0 &&
		static_cast<int>(getTargetColor().b) == 0)
	{
		setTargetColor(setStateColor(state));
	}
	else
	{
		if (static_cast<int>(m_shape.getFillColor().r) < static_cast<int>(getTargetColor().r))
		{
			m_shape.setFillColor(sf::Color(
				static_cast<int>(std::min(255, m_shape.getFillColor().r + switchTickSpeed)),
				static_cast<int>(m_shape.getFillColor().g),
				static_cast<int>(m_shape.getFillColor().b),
				255));
		}
		else if (static_cast<int>(m_shape.getFillColor().r) > static_cast<int>(getTargetColor().r))
		{
			m_shape.setFillColor(sf::Color(
				static_cast<int>(std::max(0, m_shape.getFillColor().r - switchTickSpeed)),
				static_cast<int>(m_shape.getFillColor().g),
				static_cast<int>(m_shape.getFillColor().b),
				255));
		}
			
		if (static_cast<int>(m_shape.getFillColor().g) < static_cast<int>(getTargetColor().g))
		{
			m_shape.setFillColor(sf::Color(
				static_cast<int>(m_shape.getFillColor().r),
				static_cast<int>(std::min(255, m_shape.getFillColor().g + switchTickSpeed)),
				static_cast<int>(m_shape.getFillColor().b),
				255));
		}
		else if (static_cast<int>(m_shape.getFillColor().g) > static_cast<int>(getTargetColor().g))
		{
			m_shape.setFillColor(sf::Color(
				static_cast<int>(m_shape.getFillColor().r),
				static_cast<int>(std::max(0, m_shape.getFillColor().g - switchTickSpeed)),
				static_cast<int>(m_shape.getFillColor().b),
				255));
		}
			
		if (static_cast<int>(m_shape.getFillColor().b) < static_cast<int>(getTargetColor().b))
		{
			m_shape.setFillColor(sf::Color(
				static_cast<int>(m_shape.getFillColor().r),
				static_cast<int>(m_shape.getFillColor().g),
				static_cast<int>(std::min(255, m_shape.getFillColor().b + switchTickSpeed)),
				255));
		}
		else if (static_cast<int>(m_shape.getFillColor().b) > static_cast<int>(getTargetColor().b))
		{
			m_shape.setFillColor(sf::Color(
				static_cast<int>(m_shape.getFillColor().r),
				static_cast<int>(m_shape.getFillColor().g),
				static_cast<int>(std::max(0, m_shape.getFillColor().b - switchTickSpeed)),
				255));
		}
			
		if (static_cast<int>(m_shape.getFillColor().r) == static_cast<int>(getTargetColor().r) &&
			static_cast<int>(m_shape.getFillColor().g) == static_cast<int>(getTargetColor().g) &&
			static_cast<int>(m_shape.getFillColor().b) == static_cast<int>(getTargetColor().b))
		{
			setTargetColor(sf::Color(0, 0, 0, 0));
		}
	}
}

sf::RectangleShape SkinCell::getShape() const
{
	return m_shape;
}

sf::Color SkinCell::getTargetColor() const
{
	return m_targetColor;
}

void SkinCell::setTargetColor(const sf::Color& targetColor) 
{
	m_targetColor = targetColor;
}