#include "CellArray.h"

void CellArray::setSize(int x, int y)
{
    m_skinCellTab.resize(x, std::vector<SkinCell>(y));
}

void CellArray::init()
{
    if (m_skinCellTab.empty())
    {
        std::cerr << "Tablica nie ma ustawionego rozmiaru." << std::endl;
        return;
    }

    for (int i = 0; i < m_skinCellTab.size(); i++)
    {
        for (int j = 0; j < m_skinCellTab[i].size(); j++)
        {
            m_skinCellTab[i][j].init(sf::Vector2f(60.f, 60.f), sf::Vector2f(60 * i, 60 * j), 0);
        }
    }
}

void CellArray::update()
{
    for (int i = 0; i < m_skinCellTab.size(); i++)
    {
        for (int j = 0; j < m_skinCellTab[i].size(); j++)
        {
            m_skinCellTab[i][j].update(rand() % 3 + 1);
        }
    }
}

sf::RectangleShape CellArray::get(int x, int y)
{
    return m_skinCellTab[x][y].getShape();
}