#include "SkinCell.h"

#define HEALTHY_COLOR sf::Color(0, 80, 0, 255)
#define INFECTED_COLOR sf::Color(255, 0, 0, 255)
#define RESISTANT_COLOR sf::Color(235, 177, 45, 255)

SkinCell::SkinCell() 
{

}
SkinCell::~SkinCell() 
{

}

int checkState(sf::Color color)
{
	if (color == HEALTHY_COLOR)
		return 0;
	else if (color == INFECTED_COLOR)
		return 1;
	else if (color == RESISTANT_COLOR)
		return 2;
}

sf::Color setStateColor(int state) 
{
	switch (state) {
	case 0: 
		return HEALTHY_COLOR;
		break;
	case 1:
		return INFECTED_COLOR;
		break;
	case 2:
		return RESISTANT_COLOR;
		break;
	}
}

void SkinCell::init(const sf::Vector2f& size,const sf::Vector2f& position, int state)
{
	m_shape.setSize(size);
	m_shape.setPosition(position);
	m_shape.setFillColor(setStateColor(state));
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(1);
	setStateCell(state);
	setAbleToInfect(0);
	setTimeUnit(0);
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

void SkinCell::update(int infectTime, int resistTime)
{
	if (getTargetColor().r == 0 &&
		getTargetColor().g == 0 &&
		getTargetColor().b == 0)
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
		if (m_timeUnit <= infectTime && m_stateOfCell == 1)
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
		if (m_timeUnit > infectTime && m_timeUnit <= (infectTime + resistTime))
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

void SkinCell::randInfect(int chance)
{
	if (m_stateOfCell == 0)
	{
		int randNum = 0;
		randNum = rand() % 100;
		if (randNum < chance) {
			m_targetColor = INFECTED_COLOR;
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

void SkinCell::setTargetColor(const sf::Color& targetColor) 
{
	m_targetColor = targetColor;
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
