#include "CellArray.h"

#define HEALTHY_COLOR sf::Color(0, 80, 0, 255)
#define INFECTED_COLOR sf::Color(255, 0, 0, 255)
#define RESISTANT_COLOR sf::Color(235, 177, 45, 255)

CellArray::CellArray(sf::RenderWindow& window)
    : m_window(window)
{

}


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
        std::cerr << "Array empty" << std::endl;
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
            m_skinCellTab[i][j].update();

            if (m_skinCellTab[i][j].getTimeUnit() == 6 && m_skinCellTab[i][j].getStateCell() == 1)
            {
                m_skinCellTab[i][j].setTargetColor(RESISTANT_COLOR);
                m_skinCellTab[i][j].setStateCell(2);
            }
            else if (m_skinCellTab[i][j].getTimeUnit() >= 10 && m_skinCellTab[i][j].getStateCell() == 2)
            {
                m_skinCellTab[i][j].setTargetColor(HEALTHY_COLOR);
                m_skinCellTab[i][j].setTimeUnit(0);
                m_skinCellTab[i][j].setStateCell(0);
            }
        }
    }
}

int CellArray::handleMouseClick() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

    for (auto& innerTab : m_skinCellTab) {
        for (auto& el : innerTab) {
            sf::RectangleShape currentCell = el.getShape();
            if (currentCell.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
            {
                el.setTargetColor(INFECTED_COLOR);
            }
        }
    }
    return 0;
}

void CellArray::updateInfect(bool isMultiInfect)
{
    for (int i = 0; i < m_sizeX; i++)
    {
        for (int j = 0; j < m_sizeY; j++)
        {
            m_skinCellTab[i][j].setinfectAttempt(false);
        }
    }
    for (int i = 0; i < m_sizeX; i++)
    {
        for (int j = 0; j < m_sizeY; j++)
        {
            if (m_skinCellTab[i][j].getStateCell() == 1 || m_skinCellTab[i][j].getStateCell() == 2)
            {
                m_skinCellTab[i][j].addTimeUnit(1);
            }
            if (m_skinCellTab[i][j].getStateCell() == 1)
            {
                if (i == 0 && j == 0)
                {
                    m_skinCellTab[1][0].randInfect();
                    m_skinCellTab[0][1].randInfect();
                }
                else if (i == m_sizeX - 1 && j == m_sizeY - 1)
                {
                    m_skinCellTab[m_sizeX - 2][m_sizeY - 1].randInfect();
                    m_skinCellTab[m_sizeX - 1][m_sizeY - 2].randInfect();
                }
                else if (i == m_sizeX - 1 && j == 0)
                {
                    m_skinCellTab[m_sizeX - 2][0].randInfect();
                    m_skinCellTab[m_sizeX - 1][1].randInfect();
                }
                else if (i == 0 && j == m_sizeY - 1)
                {
                    m_skinCellTab[0][m_sizeY - 2].randInfect();
                    m_skinCellTab[1][m_sizeY - 1].randInfect();
                }

                else if (i == 0 && j != 0 && j != m_sizeY - 1)
                {
                    m_skinCellTab[0][j - 1].randInfect();
                    m_skinCellTab[0][j + 1].randInfect();
                    m_skinCellTab[1][j].randInfect();
                }
                else if (i == m_sizeX -1 && j != 0 && j != m_sizeY - 1)
                {
                    m_skinCellTab[i][j - 1].randInfect();
                    m_skinCellTab[i][j + 1].randInfect();
                    m_skinCellTab[i - 1][j].randInfect();
                }
                else if (j == 0 && i != 0 && i != m_sizeX - 1)
                {
                    m_skinCellTab[i - 1][0].randInfect();
                    m_skinCellTab[i + 1][0].randInfect();
                    m_skinCellTab[i][1].randInfect();
                }
                else if (j == m_sizeY - 1 && i != 0 && i != m_sizeX - 1)
                {
                    m_skinCellTab[i - 1][j].randInfect();
                    m_skinCellTab[i + 1][j].randInfect();
                    m_skinCellTab[i][j - 1].randInfect();
                }
                else if (j != 0 && j != m_sizeY - 1 && i != 0 && i != m_sizeX - 1)
                {
                    m_skinCellTab[i - 1][j].randInfect();
                    m_skinCellTab[i + 1][j].randInfect();
                    m_skinCellTab[i][j - 1].randInfect();
                    m_skinCellTab[i][j + 1].randInfect();
                }
            }
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