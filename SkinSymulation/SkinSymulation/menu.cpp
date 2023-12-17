#include "menu.h"

Menu::Menu(sf::RenderWindow& window) 
    : m_window(window)  
    , m_selectedItemIndex(0)
{
    if (!m_font.loadFromFile("font.otf")) 
    {
        std::cerr << "Couldn't load font" << std::endl;
    }

    m_title.setFont(m_font);
    m_title.setString("Problem liszaja");
    m_title.setCharacterSize(80);
    m_title.setFillColor(sf::Color::White);
    m_title.setStyle(sf::Text::Bold);
    m_title.setPosition(m_window.getSize().x / 2 - m_title.getGlobalBounds().width / 2, 120);
    

    for (int i = 0; i < m_MENU_ITEMS; ++i) 
    {
        m_menu[i].setFont(m_font);
        m_menu[i].setCharacterSize(50);
        m_menu[i].setFillColor(sf::Color::White);
        m_menu[i].setString(m_options[i]);
        m_menu[i].setPosition(m_window.getSize().x / 2 - m_menu[i].getGlobalBounds().width / 2, 300 + i * 80);
    }
    m_menu[0].setFillColor(sf::Color::Red);

    for (int i = 0; i < m_SETTINGS_ITEMS; ++i) 
    {
        m_menu2[i].setFont(m_font);
        m_menu2[i].setCharacterSize(50);
        m_menu2[i].setFillColor(sf::Color::White);
        m_menu2[i].setString(m_options2[i]);
        m_menu2[i].setPosition(m_window.getSize().x / 2 - m_menu2[i].getGlobalBounds().width / 2, 300 + i * 80);
    }
    m_menu2[0].setFillColor(sf::Color::Red);

    if (!m_t1.loadFromFile("Assets/graphics/multiple.png"))
    {
        std::cerr << "Texture load error" << std::endl;
    }
    m_s1.setTexture(m_t1);
    m_s1.setPosition(m_window.getSize().x / 2 - 75 - 120, m_window.getSize().y / 2 + 50);

    if (!m_t2.loadFromFile("Assets/graphics/single.png"))
    {
        std::cerr << "Texture load error" << std::endl;
    }
    m_s2.setTexture(m_t2);
    m_s2.setPosition(m_window.getSize().x / 2 - 75 + 120, m_window.getSize().y / 2 + 50);


    for (int i = 0; i < m_SETTINGS_ITEMS2; i++)
    {
        m_menu3[i].setFont(m_font);
        m_menu3[i].setCharacterSize(i == 0 ? 50 : 30);
        m_menu3[i].setFillColor(sf::Color::White);
        m_menu3[i].setString(m_options3[i]);
        m_menu3[i].setPosition(
            i == 0 ?
            m_window.getSize().x / 2 - m_menu3[i].getGlobalBounds().width / 2
            :
            (i == 1 ?
            m_window.getSize().x / 2 - m_menu3[i].getGlobalBounds().width / 2 - 120
            :
            m_window.getSize().x / 2 - m_menu3[i].getGlobalBounds().width / 2 + 120),
            i == 0 ? 
            300
            :
            600
        );
    }
    m_menu3[0].setFillColor(sf::Color::Red);

}

void Menu::draw() 
{
    m_window.draw(m_title);

    for (int i = 0; i < m_MENU_ITEMS; ++i) {
        m_window.draw(m_menu[i]);
    }
}

void Menu::drawSettings() 
{
    m_window.draw(m_title);

    for (int i = 0; i < m_SETTINGS_ITEMS; ++i) {
        m_window.draw(m_menu2[i]);
    }
}

void Menu::drawSettingsInfectType()
{
    m_window.draw(m_title);

    for (int i = 0; i < m_SETTINGS_ITEMS2; ++i) {
        m_window.draw(m_menu3[i]);
    }

    m_window.draw(m_s1);
    m_window.draw(m_s2);
}


void Menu::moveUp() 
{
    switch (m_menuLevel)
    {
    case 0:
        if (m_selectedItemIndex - 1 >= 0) {
            m_menu[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex--;
            m_menu[m_selectedItemIndex].setFillColor(sf::Color::Red);
        }
        break;
    case 1:
        if (m_selectedItemIndex - 1 >= 0) {
            m_menu2[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex--;
            m_menu2[m_selectedItemIndex].setFillColor(sf::Color::Red);
        }
        break;
    case 2:
        if (m_selectedItemIndex - 1 >= 0) {
            m_menu3[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex--;
            m_menu3[m_selectedItemIndex].setFillColor(sf::Color::Red);
        }
        break;
    }
      
}

void Menu::moveDown() {
    switch (m_menuLevel)
    {
    case 0:
        if (m_selectedItemIndex + 1 < m_MENU_ITEMS) {
            m_menu[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex++;
            m_menu[m_selectedItemIndex].setFillColor(sf::Color::Red);
        }
    break;
    case 1:
        if (m_selectedItemIndex + 1 < m_SETTINGS_ITEMS) {
            m_menu2[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex++;
            m_menu2[m_selectedItemIndex].setFillColor(sf::Color::Red);
        }
    break;
    case 2:
        if (m_selectedItemIndex + 1 < m_SETTINGS_ITEMS2) {
            m_menu3[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex++;
            m_menu3[m_selectedItemIndex].setFillColor(sf::Color::Red);
        }
        break;
    }
    
}

int Menu::getSelectedItemIndex() const {
    return m_selectedItemIndex;
}

int Menu::handleMouseClick() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

    switch (m_menuLevel)
    {
    case 0:
        for (int i = 0; i < m_MENU_ITEMS; ++i) 
        {
            if (m_menu[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) 
            {
                m_selectedItemIndex = i;
                for (int j = 0; j < m_MENU_ITEMS; ++j) 
                {
                    m_menu[j].setFillColor(sf::Color::White);
                }
                m_menu[m_selectedItemIndex].setFillColor(sf::Color::Red);
                return MenuChoice(m_selectedItemIndex);
                break;
            }
        }
        break;
    case 1:
        for (int i = 0; i < m_SETTINGS_ITEMS; ++i) 
        {
            if (m_menu2[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) 
            {
                m_selectedItemIndex = i;
                for (int j = 0; j < m_SETTINGS_ITEMS; ++j) 
                {
                    m_menu2[j].setFillColor(sf::Color::White);
                }
                m_menu2[m_selectedItemIndex].setFillColor(sf::Color::Red);
                return MenuChoice(m_selectedItemIndex);
                break;
            }
        }
        break;
    case 2:
        for (int i = 0; i < m_SETTINGS_ITEMS2; ++i) 
        {
            if (m_menu3[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) 
            {
                m_selectedItemIndex = i;
                for (int j = 0; j < m_SETTINGS_ITEMS2; ++j) 
                {
                    m_menu3[j].setFillColor(sf::Color::White);
                }
                m_menu3[m_selectedItemIndex].setFillColor(sf::Color::Red);
                return MenuChoice(m_selectedItemIndex);
                break;
           }
        }
        break;
    }
    return -1;
}

void Menu::clearSelectedItem()
{
    m_selectedItemIndex = 0;
}

void Menu::clearMenuLevel()
{
    m_selectedItemIndex = 0;
    for (int i = 0; i < m_MENU_ITEMS; ++i)
    {
        m_menu[i].setFillColor(sf::Color::White);
    }
    m_menu[m_selectedItemIndex].setFillColor(sf::Color::Red);
    for (int i = 0; i < m_SETTINGS_ITEMS; ++i)
    {
        m_menu2[i].setFillColor(sf::Color::White);
    }
    m_menu2[m_selectedItemIndex].setFillColor(sf::Color::Red);
    for (int i = 0; i < m_SETTINGS_ITEMS2; ++i)
    {
        m_menu3[i].setFillColor(sf::Color::White);
    }
    m_menu3[m_selectedItemIndex].setFillColor(sf::Color::Red);
}

int Menu::getMenuLevel() {
    return m_menuLevel;
}

void Menu::setMenuLevel(const int lvl)
{
    m_menuLevel = lvl;
}

int Menu::MenuChoice(int elementId) 
{
    switch (m_menuLevel)
    {
    case 0:
        switch (elementId)
        {
        case 0:
            return 0;
            break;
        case 1:
            return 1;
            break;
        case 2: 
            m_selectedItemIndex = 0;
            m_menuLevel = 1;
            return 2;
            break;
        case 3:
            m_window.close();
            return 3;
            break;
        }
    break;
    case 1:
        switch (elementId)
        {
        case 0:
            return 3;
            break;
        case 1:
            m_selectedItemIndex = 0;
            return 4;
            break;
        case 2:
            break;
        case 3:
            break;
        } 
        break;
    case 2:
        switch (elementId)
        {
        case 0: 
            m_menuLevel = 1;
            return 2;
            break;
        case 1:
            clearSelectedItem();
            clearMenuLevel();
            return 5;
            break;
        case 2:
            clearSelectedItem();
            clearMenuLevel();
            return 6;
            break;
        }
        break;
    }
}