#include "CellArray.h"

void CellArray::setSize(int x, int y)
{
    m_sizeX = x;
    m_sizeY = y;
    m_skinCellTab.resize(x, std::vector<SkinCell>(y));
    
}

void CellArray::init()
{
    if (m_skinCellTab.empty())
    {
        std::cerr << "Tablica nie ma ustawionego rozmiaru." << std::endl;
        return;
    }

    for (int i = 0; i < m_sizeX; i++)
    {
        for (int j = 0; j < m_sizeY; j++)
        {
            m_skinCellTab[i][j].init(sf::Vector2f(round(800 / m_sizeX), round(800 / m_sizeY)), sf::Vector2f(round(800/ m_sizeX) * i, round(800 / m_sizeY) * j), 0);
        }
    }
}

void CellArray::update()
{
    for (int i = 0; i < m_sizeX; i++)
    {
        for (int j = 0; j < m_sizeY; j++)
        {
            m_skinCellTab[i][j].update(rand() % 3 + 1);
        }
    }
}

sf::RectangleShape CellArray::get(int x, int y)
{
    return m_skinCellTab[x][y].getShape();
}

int CellArray::getSizeX() const
{
    return m_sizeX;
}

int CellArray::getSizeY() const
{
    return m_sizeY;
}