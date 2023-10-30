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
	if (getTargetColor().r == 0 &&
		getTargetColor().g == 0 &&
		getTargetColor().b == 0)
	{
		setTargetColor(setStateColor(state));
		setDividerRed(round(std::abs((m_shape.getFillColor().r - getTargetColor().r) / 2)));
		setDividerGreen(round(std::abs((m_shape.getFillColor().g - getTargetColor().g) / 2)));
		setDividerBlue(round(std::abs((m_shape.getFillColor().b - getTargetColor().b) / 2)));
	}
	else
	{
		if (m_shape.getFillColor().r < getTargetColor().r)
		{
			m_shape.setFillColor(sf::Color(
				std::min(255, m_shape.getFillColor().r + getDividerRed()),
							  m_shape.getFillColor().g,
							  m_shape.getFillColor().b,
							  255));
		}
		else if (m_shape.getFillColor().r > getTargetColor().r)
		{
			m_shape.setFillColor(sf::Color(
				std::max(0, m_shape.getFillColor().r - getDividerRed()),
							m_shape.getFillColor().g,
							m_shape.getFillColor().b,
							255));
		}
			
		if (m_shape.getFillColor().g < getTargetColor().g)
		{
			m_shape.setFillColor(sf::Color(
							  m_shape.getFillColor().r,
				std::min(255, m_shape.getFillColor().g + getDividerGreen()),
							  m_shape.getFillColor().b,
							  255));
		}
		else if (m_shape.getFillColor().g > getTargetColor().g)
		{
			m_shape.setFillColor(sf::Color(
							m_shape.getFillColor().r,
				std::max(0, m_shape.getFillColor().g - getDividerGreen()),
							m_shape.getFillColor().b,
							255));
		}
			
		if (m_shape.getFillColor().b < getTargetColor().b)
		{
			m_shape.setFillColor(sf::Color(
						  	  m_shape.getFillColor().r,
							  m_shape.getFillColor().g,
				std::min(255, m_shape.getFillColor().b + getDividerBlue()),
				255));
		}
		else if (m_shape.getFillColor().b > getTargetColor().b)
		{
			m_shape.setFillColor(sf::Color(
							m_shape.getFillColor().r,
							m_shape.getFillColor().g,
				std::max(0, m_shape.getFillColor().b - getDividerBlue()),
				255));
		}
			
		if ((m_shape.getFillColor().r + getDividerRed() >= getTargetColor().r || getTargetColor().r - getDividerRed() >= m_shape.getFillColor().r) &&
			(m_shape.getFillColor().g + getDividerGreen() >= getTargetColor().g || getTargetColor().g - getDividerGreen() >= m_shape.getFillColor().g) &&
			(m_shape.getFillColor().b + getDividerBlue() >= getTargetColor().b || getTargetColor().b - getDividerBlue() >= m_shape.getFillColor().b))
		{
			setTargetColor(sf::Color(0, 0, 0, 0));
		}
	}
}

void SkinCell::setDividerRed(int divider)
{
	m_dividerRed = divider;
}

void SkinCell::setDividerGreen(int divider)
{
	m_dividerGreen = divider;
}

void SkinCell::setDividerBlue(int divider)
{
	m_dividerBlue = divider;
}

int SkinCell::getDividerRed()
{
	return  m_dividerRed;
}
int SkinCell::getDividerGreen()
{
	return m_dividerGreen;
}
int SkinCell::getDividerBlue()
{
	return m_dividerBlue;
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