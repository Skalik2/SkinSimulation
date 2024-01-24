#include "SkinCell.h"

SkinCell::SkinCell() 
{

}
SkinCell::~SkinCell() 
{

}

void SkinCell::init(const sf::Vector2f& size,const sf::Vector2f& position, int state, sf::Color basicHealthyColor)
{
	m_shape.setSize(size);
	m_shape.setPosition(position);
	m_shape.setFillColor(basicHealthyColor);
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(1);
	setStateCell(state);
	setAbleToInfect(0);
	setTimeUnit(0);
	m_targetColor = basicHealthyColor;
}


void SkinCell::updatePositon(sf::Vector2f position)
{
	m_shape.setPosition(position);
}

void SkinCell::updateSize(sf::Vector2f size)
{
	m_shape.setSize(size);
}

void SkinCell::update(int infectTime, int resistTime)
{
	if (getTargetColor().r == m_shape.getFillColor().r &&
		getTargetColor().g == m_shape.getFillColor().g &&
		getTargetColor().b == m_shape.getFillColor().b)
	{

	}
	else
	{
		if (m_stateOfCell == 0)
		{
			m_shape.setFillColor(sf::Color(
				m_shape.getFillColor().r + std::floor(((m_targetColor.r - m_shape.getFillColor().r) / 2)),
				m_shape.getFillColor().g + std::floor(((m_targetColor.g - m_shape.getFillColor().g) / 2)),
				m_shape.getFillColor().b + std::floor(((m_targetColor.b - m_shape.getFillColor().b) / 2)),
				255));
		}
		else if (m_timeUnit <= infectTime && m_stateOfCell == 1)
		{
			m_shape.setFillColor(sf::Color(
				m_shape.getFillColor().r + std::floor(((m_targetColor.r - m_shape.getFillColor().r) / infectTime)),
				m_shape.getFillColor().g + std::floor(((m_targetColor.g - m_shape.getFillColor().g) / infectTime)),
				m_shape.getFillColor().b + std::floor(((m_targetColor.b - m_shape.getFillColor().b) / infectTime)),
				255));
			if (m_timeUnit == infectTime)
			{
				m_shape.setFillColor(sf::Color(
					m_targetColor.r,
					m_targetColor.g,
					m_targetColor.b,
					255));
				m_stateOfCell = 1;
			}
		}																																											
		else if (m_timeUnit -1 > infectTime && m_timeUnit <= (infectTime + resistTime))
		{
			m_shape.setFillColor(sf::Color(
				m_shape.getFillColor().r + std::floor(((m_targetColor.r - m_shape.getFillColor().r) / resistTime)),
				m_shape.getFillColor().g + std::floor(((m_targetColor.g - m_shape.getFillColor().g) / resistTime)),
				m_shape.getFillColor().b + std::floor(((m_targetColor.b - m_shape.getFillColor().b) / resistTime)),
				255));
			if (m_timeUnit == (infectTime + resistTime))
			{ 
				m_shape.setFillColor(sf::Color(
					m_targetColor.r,
					m_targetColor.g,
					m_targetColor.b,
					255));
				m_stateOfCell = 2;
			}
		}
	}
}

void SkinCell::randInfect(const int chance, sf::Color color)
{
	if (m_stateOfCell == 0)
	{
		int randNum = 0;
		randNum = rand() % 100;
		if (randNum < chance) {
			m_targetColor = color;
			m_stateOfCell = 1;
		}
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

void SkinCell::setTargetColor(const sf::Color color) 
{
	m_targetColor = color;
}

void SkinCell::setTimeUnit(const int tUnit)
{
	m_timeUnit = tUnit;
}

void SkinCell::addTimeUnit(const int tUnit)
{
	m_timeUnit += tUnit;
}

int SkinCell::getTimeUnit() const
{
	return m_timeUnit;
}

bool SkinCell::getAbleToInfect() const
{
	return m_ableToInfect;
}

void SkinCell::setAbleToInfect(const bool val)
{
	m_ableToInfect = val;
}
