#pragma once
#include <vector>
#include "SkinCell.h"

class CellArray
{
	uint16_t m_sizeX, m_sizeY;
	std::vector<std::vector<SkinCell>> m_skinCellTab;
public:
	void setSize(int x, int y);
	void init();
	void update();
	sf::RectangleShape get(int x, int y);
	int getSizeX() const;
	int getSizeY() const;
};

