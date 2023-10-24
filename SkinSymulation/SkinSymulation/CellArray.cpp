#include "CellArray.h"

void CellArray::size(int x, int y)
{
    skinCellTab.resize(x, std::vector<SkinCell>(y));
}

// Funkcja inicjalizuj¹ca komórki
void CellArray::init()
{
    if (skinCellTab.empty())
    {
        std::cerr << "Tablica nie ma ustawionego rozmiaru." << std::endl;
        return;
    }

    for (int i = 0; i < skinCellTab.size(); i++)
    {
        for (int j = 0; j < skinCellTab[i].size(); j++)
        {
            skinCellTab[i][j].init(sf::Vector2f(60.f, 60.f), sf::Vector2f(60 * i, 60 * j), 0);
        }
    }
}

void CellArray::update()
{
    for (int i = 0; i < skinCellTab.size(); i++)
    {
        for (int j = 0; j < skinCellTab[i].size(); j++)
        {
            skinCellTab[i][j].update(rand() % 3 + 1);
        }
    }
}

sf::RectangleShape CellArray::get(int x, int y)
{
    return skinCellTab[x][y].getShape();
}