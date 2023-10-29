#include "CellArray.h"

void CellArray::setSize(int x, int y)
{
    m_sizeX = x;
    m_sizeY = y;
    m_skinCellTab.resize(x, std::vector<SkinCell>(y));
    for (auto& innerTab : m_skinCellTab) {
        innerTab.resize(y);
    }
    
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
            m_skinCellTab[i][j].init(
                sf::Vector2f(round(720 / m_sizeX), 
                             round(720 / m_sizeY)), 
                sf::Vector2f(round(720/ m_sizeX) * i, 
                             round(720 / m_sizeY) * j), 0
            );
        }
    }
}

void CellArray::initRight()
{
    for (int i = 0; i < m_sizeY; i++)
    {
        m_skinCellTab[m_sizeX - 1][i].init(
            sf::Vector2f(round(720.0f / m_sizeX), round(720.0f / m_sizeY)),
            sf::Vector2f(round(720.0f / m_sizeX) * m_sizeX, round(720.0f / m_sizeY) * i), 0
        );
    }
    resizeTab();
}


void CellArray::initDown()
{
    for (int i = 0; i < m_sizeX; i++)
    {
        m_skinCellTab[i][m_sizeY - 1].init(
            sf::Vector2f(round(720.0f / m_sizeX), round(720.0f / (m_sizeY - 1) )),
            sf::Vector2f(round(720.0f / m_sizeX) * i, round(720.0f / (m_sizeY - 1)) * i), 0
        );
    }
    resizeTab();
}

void CellArray::resizeTab()
{
    for (int i = 0; i < m_sizeX; i++)
    {
        for (int j = 0; j < m_sizeY; j++)
        {
            m_skinCellTab[i][j].updatePositon(
                sf::Vector2f(round(720 / m_sizeX) * i,
                    round(720 / m_sizeY) * j));
            m_skinCellTab[i][j].updateSize(
                sf::Vector2f(round(720 / m_sizeX),
                             round(720 / m_sizeY)));
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