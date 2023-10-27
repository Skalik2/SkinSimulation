#pragma once
#include <vector>
#include "SkinCell.h"

class CellArray
{
	int m_sizeX, m_sizeY;
	std::vector<std::vector<SkinCell>> m_skinCellTab;
public:
	void setSize(int x, int y);
	void init();
	void initRight();
	void initDown();
	void resizeTab();
	void update();
	sf::RectangleShape get(int x, int y);
	int getSizeX() const;
	int getSizeY() const;
};

