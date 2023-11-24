#pragma once
#include <vector>

#include "SkinCell.h"


class CellArray
{
	sf::RenderWindow& m_window;
	int m_sizeX, m_sizeY;
	std::vector<std::vector<SkinCell>> m_skinCellTab;
public:
	CellArray(sf::RenderWindow& window);
	int handleMouseClick();
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

