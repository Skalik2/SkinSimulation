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

			m_stateOfCell = checkState(m_shape.getFillColor());
		}
	}
}

void SkinCell::randInfect(bool val)
{
	if (m_stateOfCell == 0 && m_infectAttempt == false)
	{
		int probability = 0;
		probability = rand() % 2;
		if (probability) {
			m_targetColor = INFECTED_COLOR;
		}
		m_infectAttempt = true;
	}
}

void SkinCell::randInfect()
{
	if (m_stateOfCell == 0)
	{
		int probability = 0;
		probability = rand() % 2;
		if (probability) {
			m_targetColor = INFECTED_COLOR;
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

bool SkinCell::getinfectAttempt() const
{
	return m_infectAttempt;
}

void SkinCell::setinfectAttempt(const bool val)
{
	m_infectAttempt = val;
}
