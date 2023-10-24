#pragma once
#include <vector>
#include "SkinCell.h"

class CellArray
{
	std::vector<std::vector<SkinCell>> skinCellTab;
public:
	void size(int x, int y);
	void init();
	void update();
	sf::RectangleShape get(int x, int y);
};

