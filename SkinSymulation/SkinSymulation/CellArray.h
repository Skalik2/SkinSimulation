#pragma once
#include <vector>

#include "SkinCell.h"
#include "Settings.h"

class CellArray
{
	sf::RenderWindow& m_window;
	int m_sizeX, m_sizeY;
	Settings& m_settings;
	std::vector<std::vector<SkinCell>> m_skinCellTab;
public:
	CellArray(sf::RenderWindow& window, Settings& settings);
	int handleMouseClick();
	void setSize(int x, int y);
	void init();
	void initRight();
	void initDown();
	void resizeTab();
	void update(int infectTime, int resistTime);
	void updateInfect();
	void updateInfectMulti();
	sf::RectangleShape get(int x, int y);
	int getSizeX() const;
	int getSizeY() const;
};

