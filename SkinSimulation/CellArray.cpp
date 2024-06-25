#include "CellArray.h"

CellArray::CellArray(sf::RenderWindow& window, Settings& settings)
    : m_window(window)
    , m_settings(settings)
{
    setSize(12, 12);
}


void CellArray::setSize(int x, int y)
{
    m_sizeX = x;
    m_sizeY = y;
    m_skinCellTab.resize(x, std::vector<SkinCell>(y));
    for (auto& innerTab : m_skinCellTab) {
        innerTab.resize(y);
    }
    resizeTab();
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
                sf::Vector2f(round(m_window.getSize().x * 1.0f / m_sizeX), round(m_window.getSize().y * 1.0f / m_sizeY)),
                sf::Vector2f(round(m_window.getSize().x * 1.0f / m_sizeX) * i, round(m_window.getSize().y * 1.0f / m_sizeY) * j),
                0,
                m_settings.getHealthyColor()
            );
        }
    }
    resizeTab();
}

void CellArray::initRight()
{
    for (int i = 0; i < m_sizeY; i++)
    {
        m_skinCellTab[m_sizeX - 1][i].init(
            sf::Vector2f(round(m_window.getSize().x * 1.0f / m_sizeX), round(m_window.getSize().y * 1.0f / m_sizeY)),
            sf::Vector2f(round(m_window.getSize().x * 1.0f / m_sizeX) * m_sizeX, round(m_window.getSize().y * 1.0f / m_sizeY) * i),
            0,
            m_settings.getHealthyColor()
        );
    }
    resizeTab();
}


void CellArray::initDown()
{
    for (int i = 0; i < m_sizeX; i++)
    {
        m_skinCellTab[i][m_sizeY - 1].init(
            sf::Vector2f(round(m_window.getSize().x * 1.0f / m_sizeX), round(m_window.getSize().y * 1.0f / (m_sizeY - 1))),
            sf::Vector2f(round(m_window.getSize().x * 1.0f / m_sizeX) * i, round(m_window.getSize().y * 1.0f / (m_sizeY - 1)) * i),
            0,
            m_settings.getHealthyColor()
        );
    }
    resizeTab();
}

void CellArray::resizeTab()
{

    if (!m_settings.getIfCellSymetricAspectRatio())
    {
        for (int i = 0; i < m_sizeX; i++)
        {
            for (int j = 0; j < m_sizeY; j++)
            {
                m_skinCellTab[i][j].updatePositon(
                    sf::Vector2f(round(m_window.getSize().x * 1.0f / m_sizeX * i), round(m_window.getSize().y * 1.0f / m_sizeY * j)));
                m_skinCellTab[i][j].updateSize(
                    sf::Vector2f(round(m_window.getSize().x * 1.0f / m_sizeX), round(m_window.getSize().y * 1.0f / m_sizeY)));
            }
        }
    }
    else
    {
        double offset = 0;
        if ((m_window.getSize().x * 1.0f / m_sizeX) > m_window.getSize().y * 1.0f / m_sizeY)
        {
            offset = ((m_window.getSize().y * 1.0f / m_sizeY) * (m_sizeY - m_sizeX) / 2) +
                ((m_window.getSize().x - ((m_window.getSize().y * 1.0f / m_sizeX)) * m_sizeX)) / 2;
            for (int i = 0; i < m_sizeX; i++)
            {
                for (int j = 0; j < m_sizeY; j++)
                {
                    m_skinCellTab[i][j].updatePositon(
                        sf::Vector2f(round(m_window.getSize().y * 1.0f / m_sizeY * i) + offset,
                            round(m_window.getSize().y * 1.0f / m_sizeY * j)));
                    m_skinCellTab[i][j].updateSize(
                        sf::Vector2f(round(m_window.getSize().y * 1.0f / m_sizeY),
                            round(m_window.getSize().y * 1.0f / m_sizeY)));
                }
            }
        }
        else
        {
            offset = (m_window.getSize().x * 1.0f / m_sizeX) * (m_sizeX - m_sizeY) / 2 +
                ((m_window.getSize().y - ((m_window.getSize().x * 1.0f / m_sizeY)) * m_sizeY)) / 2;;
            for (int i = 0; i < m_sizeX; i++)
            {
                for (int j = 0; j < m_sizeY; j++)
                {
                    m_skinCellTab[i][j].updatePositon(
                        sf::Vector2f(round(m_window.getSize().x * 1.0f / m_sizeX * i), round(m_window.getSize().x * 1.0f / m_sizeX * j) + offset));
                    m_skinCellTab[i][j].updateSize(
                        sf::Vector2f(round(m_window.getSize().x * 1.0f / m_sizeX), round(m_window.getSize().x * 1.0f / m_sizeX)));
                }
            }
        }

    }
}

void CellArray::update(int infectTime, int resistTime)
{
    for (int i = 0; i < m_sizeX; i++)
    {
        for (int j = 0; j < m_sizeY; j++)
        {
            if (m_skinCellTab[i][j].getTimeUnit() == infectTime && m_skinCellTab[i][j].getStateCell() == 1)
            {
                m_skinCellTab[i][j].setTargetColor(m_settings.getResistantColor());
                m_skinCellTab[i][j].setStateCell(2);
            }
            if (m_skinCellTab[i][j].getTimeUnit() > (infectTime + resistTime) && m_skinCellTab[i][j].getStateCell() == 2)
            {
                m_skinCellTab[i][j].setTargetColor(m_settings.getHealthyColor());
                m_skinCellTab[i][j].setTimeUnit(0);
                m_skinCellTab[i][j].setStateCell(0);
            }
            m_skinCellTab[i][j].update(infectTime, resistTime);
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
                el.setTargetColor(m_settings.getInfectedColor());
                el.setStateCell(1);
                el.setAbleToInfect(1);
            }
        }
    }
    return 0;
}

void CellArray::updateInfect()
{
    updateInfectMulti();
}

void CellArray::updateInfectMulti()
{
    for (int i = 0; i < m_sizeX; i++)
    {
        for (int j = 0; j < m_sizeY; j++)
        {
            if (m_skinCellTab[i][j].getStateCell())
            {
                m_skinCellTab[i][j].setAbleToInfect(1);
            }
            else
            {
                m_skinCellTab[i][j].setAbleToInfect(0);
            }
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
            if (m_skinCellTab[i][j].getStateCell() == 1 && m_skinCellTab[i][j].getAbleToInfect())
            {
                if (i == 0 && j == 0)
                {
                    m_skinCellTab[1][0].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[0][1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[1][1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                }
                if (i == m_sizeX - 1 && j == m_sizeY - 1)
                {
                    m_skinCellTab[m_sizeX - 2][m_sizeY - 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[m_sizeX - 1][m_sizeY - 2].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[m_sizeX - 2][m_sizeY - 2].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                }
                if (i == m_sizeX - 1 && j == 0)
                {
                    m_skinCellTab[m_sizeX - 2][0].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[m_sizeX - 1][1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[m_sizeX - 2][1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                }
                if (i == 0 && j == m_sizeY - 1)
                {
                    m_skinCellTab[0][m_sizeY - 2].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[1][m_sizeY - 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[1][m_sizeY - 2].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                }

                if (i == 0 && j != 0 && j != m_sizeY - 1)
                {
                    m_skinCellTab[0][j - 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[0][j + 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[1][j].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[1][j + 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[1][j - 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                }
                if (i == m_sizeX - 1 && j != 0 && j != m_sizeY - 1)
                {
                    m_skinCellTab[i][j - 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i][j + 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i - 1][j].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i - 1][j - 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i - 1][j + 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                }
                if (j == 0 && i != 0 && i != m_sizeX - 1)
                {
                    m_skinCellTab[i - 1][0].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i + 1][0].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i][1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i - 1][1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i + 1][1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                }
                if (j == m_sizeY - 1 && i != 0 && i != m_sizeX - 1)
                {
                    m_skinCellTab[i - 1][j].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i + 1][j].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i][j - 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i - 1][j - 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i + 1][j - 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                }
                if (j != 0 && j != m_sizeY - 1 && i != 0 && i != m_sizeX - 1)
                {
                    m_skinCellTab[i - 1][j].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i + 1][j].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i][j - 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i][j + 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());

                    m_skinCellTab[i + 1][j - 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i - 1][j - 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i - 1][j + 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
                    m_skinCellTab[i + 1][j + 1].randInfect(m_settings.getInfectionProbability(), m_settings.getInfectedColor());
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