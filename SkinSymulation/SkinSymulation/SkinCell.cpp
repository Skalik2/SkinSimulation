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
	case 0:  //resistant
		return sf::Color(255, 174, 0, 255);
		break;
	case 1:  //infected
		return sf::Color(255, 60, 0, 255);
		break;
	case 2:  //healthy
		return sf::Color(34, 191, 76, 255);
		break;
	}
}

void SkinCell::init(const sf::Vector2f& size,const sf::Vector2f& position, int state) 
{
	m_shape.setSize(size);
	m_shape.setPosition(position);
	m_shape.setFillColor(setStateColor(2));
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(1);
	setStateCell(0);
	setTargetColor(sf::Color(0, 0, 0, 255));
}


void SkinCell::updatePositon(sf::Vector2f position)
{
	m_shape.setPosition(position);
}

void SkinCell::updateSize(sf::Vector2f size)
{
	m_shape.setSize(size);
}

void SkinCell::update() 
{
	if (getTargetColor().r == 0 &&
		getTargetColor().g == 0 &&
		getTargetColor().b == 0)
	{
		//setTargetColor(setStateColor(0));
	}
	else
	{
		if (m_shape.getFillColor().r < getTargetColor().r)
		{
			m_shape.setFillColor(sf::Color(
				std::min(255, m_shape.getFillColor().r + 1),
							  m_shape.getFillColor().g,
							  m_shape.getFillColor().b,
							  255));
		}
		else if (m_shape.getFillColor().r > getTargetColor().r)
		{
			m_shape.setFillColor(sf::Color(
				std::max(0, m_shape.getFillColor().r - 1),
							m_shape.getFillColor().g,
							m_shape.getFillColor().b,
							255));
		}
			
		if (m_shape.getFillColor().g < getTargetColor().g)
		{
			m_shape.setFillColor(sf::Color(
							  m_shape.getFillColor().r,
				std::min(255, m_shape.getFillColor().g + 1),
							  m_shape.getFillColor().b,
							  255));
		}
		else if (m_shape.getFillColor().g > getTargetColor().g)
		{
			m_shape.setFillColor(sf::Color(
							m_shape.getFillColor().r,
				std::max(0, m_shape.getFillColor().g - 1),
							m_shape.getFillColor().b,
							255));
		}
			
		if (m_shape.getFillColor().b < getTargetColor().b)
		{
			m_shape.setFillColor(sf::Color(
						  	  m_shape.getFillColor().r,
							  m_shape.getFillColor().g,
				std::min(255, m_shape.getFillColor().b + 1),
				255));
		}
		else if (m_shape.getFillColor().b > getTargetColor().b)
		{
			m_shape.setFillColor(sf::Color(
							m_shape.getFillColor().r,
							m_shape.getFillColor().g,
				std::max(0, m_shape.getFillColor().b - 1),
				255));
		}
			
		if (m_shape.getFillColor().r == getTargetColor().r &&
			m_shape.getFillColor().g == getTargetColor().g &&
			m_shape.getFillColor().b == getTargetColor().b) 
		{
			//setTargetColor(sf::Color(0, 0, 0, 0));
			m_stateOfCell = 1;
		}
	}
}

void SkinCell::randInfect()
{
	int probability = 0;
	probability = rand() % 2;
	if (probability) {
		m_targetColor = sf::Color(255, 60, 0, 255);
	}
}

void SkinCell::setStateCell(int state)
{
	m_stateOfCell = state;
}

int SkinCell::getStateCell() const
{
	return m_stateOfCell;
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