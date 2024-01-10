#include "menu.h"

void Menu::menuInit()
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

    for (int i = 0; i < m_SETTINGS_ITEMS2; ++i)
    {
        m_menu2[i].setFont(m_font);
        m_menu2[i].setCharacterSize(50);
        m_menu2[i].setFillColor(sf::Color::White);
        m_menu2[i].setString(m_options2[i]);
        m_menu2[i].setPosition(m_window.getSize().x / 2 - m_menu2[i].getGlobalBounds().width / 2, 300 + i * 80);
    }
    m_menu2[0].setFillColor(sf::Color::Red);

    if (!m_t1.loadFromFile("Assets/graphics/25.png"))
    {
        std::cerr << "Texture load error" << std::endl;
    }
    m_s1.setTexture(m_t1);
    m_s1.setPosition(m_window.getSize().x / 2 - 75 - 120, m_window.getSize().y / 2 + 50);

    if (!m_t2.loadFromFile("Assets/graphics/75.png"))
    {
        std::cerr << "Texture load error" << std::endl;
    }
    m_s2.setTexture(m_t2);
    m_s2.setPosition(m_window.getSize().x / 2 - 75 + 120, m_window.getSize().y / 2 + 50);


    for (int i = 0; i < m_SETTINGS_ITEMS3; i++)
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
            m_window.getSize().y / 3.0f
            :
            m_window.getSize().y / 2.0f
        );
    }
    m_menu3[0].setFillColor(sf::Color::Red);

    for (int i = 0; i < m_SETTINGS_ITEMS4; i++)
    {
        m_menu4[i].setFont(m_font);
        m_menu4[i].setCharacterSize(i == 0 ? 50 : 30);
        m_menu4[i].setFillColor(sf::Color::White);
        m_menu4[i].setString(m_options4[i]);
        m_menu4[i].setPosition(
            i == 0 ?
            m_window.getSize().x / 2 - m_menu4[i].getGlobalBounds().width / 2
            :
            (i == 1 ?
                m_window.getSize().x / 2 - m_menu4[i].getGlobalBounds().width / 2 - 150
                :
                (i == 2 ?
                    m_window.getSize().x / 2 - m_menu4[i].getGlobalBounds().width / 2 + 0
                    :
                    m_window.getSize().x / 2 - m_menu3[i].getGlobalBounds().width / 2 + 150)),
            i == 0 ?
            300
            :
            m_window.getSize().y / 1.8f
        );
    }
    m_menu4[0].setFillColor(sf::Color::Red);

    for (int i = 0; i < m_SETTINGS_ITEMS5; i++)
    {
        m_menu5[i].setFont(m_font);
        m_menu5[i].setCharacterSize(i == 0 ? 50 : 30);
        m_menu5[i].setFillColor(sf::Color::White);
        m_menu5[i].setString(m_options5[i]);
        m_menu5[i].setPosition(
            i == 0 ?
            m_window.getSize().x / 2 - m_menu5[i].getGlobalBounds().width / 2
            :
            (i == 1 ?
                m_window.getSize().x / 2 - m_menu5[i].getGlobalBounds().width / 2 - 150
                :
                (i == 2 ?
                    m_window.getSize().x / 2 - m_menu5[i].getGlobalBounds().width / 2 + 0
                    :
                    m_window.getSize().x / 2 - m_menu5[i].getGlobalBounds().width / 2 + 150)),
            i == 0 ?
            300
            :
            m_window.getSize().y / 1.8f
        );
    }
    m_menu5[0].setFillColor(sf::Color::Red);

    m_rec1.setSize(sf::Vector2f(50, 50));
    m_rec1.setPosition(m_window.getSize().x / 2 - m_rec1.getGlobalBounds().width / 2 - 150, m_window.getSize().y / 1.6f);
    m_rec1.setFillColor(m_settings.getHealthyColor());

    m_rec2.setSize(sf::Vector2f(50, 50));
    m_rec2.setPosition(m_window.getSize().x / 2 - m_rec1.getGlobalBounds().width / 2, m_window.getSize().y / 1.6f);
    m_rec2.setFillColor(m_settings.getInfectedColor());

    m_rec3.setSize(sf::Vector2f(50, 50));
    m_rec3.setPosition(m_window.getSize().x / 2 - m_rec1.getGlobalBounds().width / 2 + 150, m_window.getSize().y / 1.6f);
    m_rec3.setFillColor(m_settings.getResistantColor());

    for (int i = 0; i < m_SETTINGS_ITEMS6; i++)
    {
        m_menu6[i].setFont(m_font);
        m_menu6[i].setCharacterSize(50);
        m_menu6[i].setFillColor(sf::Color::White);
        m_menu6[i].setString(m_options6[i]);
        m_menu6[i].setPosition(m_window.getSize().x / 2 - m_menu6[i].getGlobalBounds().width / 2, 300 + i * 60);
    }
    m_menu6[0].setFillColor(sf::Color::Red);
}

Menu::Menu(sf::RenderWindow& window, Settings& settings)
    : m_window(window)  
    , m_selectedItemIndex(0)
    , m_settings(settings)
{
    menuInit();
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

    for (int i = 0; i < m_SETTINGS_ITEMS2; ++i) {
        m_window.draw(m_menu2[i]);
    }
}

void Menu::drawSettingsInfectType()
{
    m_window.draw(m_title);

    for (int i = 0; i < m_SETTINGS_ITEMS3; ++i) {
        m_window.draw(m_menu3[i]);
    }

    m_window.draw(m_s1);
    m_window.draw(m_s2);
}

void Menu::drawSettingsColorPicker()
{
    m_window.draw(m_title);
    for (int i = 0; i < m_SETTINGS_ITEMS4; ++i) {
        m_window.draw(m_menu4[i]);
    }
    m_window.draw(m_rec1);
    m_window.draw(m_rec2);
    m_window.draw(m_rec3);
}

void Menu::drawChooseSetingsColor(int number)
{
    m_window.draw(m_title);
    for (int i = 0; i < m_SETTINGS_ITEMS5; ++i) {
        m_window.draw(m_menu5[i]);
    }
    m_window.draw(number == 1 ? m_rec1 : number == 2 ? m_rec2 : m_rec3);
}

void Menu::drawAdvancedSettings()
{
    m_window.draw(m_title);
    for (int i = 0; i < m_SETTINGS_ITEMS6; ++i) {
        m_window.draw(m_menu6[i]);
    }
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
    case 3:
        if (m_selectedItemIndex - 1 >= 0) {
            m_menu4[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex--;
            m_menu4[m_selectedItemIndex].setFillColor(sf::Color::Red);
        }
        break;
    case 4:
        if (m_selectedItemIndex - 1 >= 0) {
            m_menu5[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex--;
            m_menu5[m_selectedItemIndex].setFillColor(sf::Color::Red);
        }
        break;
    case 5:
        if (m_selectedItemIndex - 1 >= 0) {
            m_menu6[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex--;
            m_menu6[m_selectedItemIndex].setFillColor(sf::Color::Red);
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
        if (m_selectedItemIndex + 1 < m_SETTINGS_ITEMS2) {
            m_menu2[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex++;
            m_menu2[m_selectedItemIndex].setFillColor(sf::Color::Red);
        }
    break;
    case 2:
        if (m_selectedItemIndex + 1 < m_SETTINGS_ITEMS3) {
            m_menu3[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex++;
            m_menu3[m_selectedItemIndex].setFillColor(sf::Color::Red);
        }
        break;
    case 3:
        if (m_selectedItemIndex + 1 < m_SETTINGS_ITEMS4) {
            m_menu4[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex++;
            m_menu4[m_selectedItemIndex].setFillColor(sf::Color::Red);
        }
        break;
    case 4:
        if (m_selectedItemIndex + 1 < m_SETTINGS_ITEMS5) {
            m_menu5[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex++;
            m_menu5[m_selectedItemIndex].setFillColor(sf::Color::Red);
        }
        break;
    case 5:
        if (m_selectedItemIndex + 1 < m_SETTINGS_ITEMS6) {
            m_menu6[m_selectedItemIndex].setFillColor(sf::Color::White);
            m_selectedItemIndex++;
            m_menu6[m_selectedItemIndex].setFillColor(sf::Color::Red);
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
        for (int i = 0; i < m_SETTINGS_ITEMS2; ++i) 
        {
            if (m_menu2[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) 
            {
                m_selectedItemIndex = i;
                for (int j = 0; j < m_SETTINGS_ITEMS2; ++j) 
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
        for (int i = 0; i < m_SETTINGS_ITEMS3; ++i) 
        {
            if (m_menu3[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) 
            {
                m_selectedItemIndex = i;
                for (int j = 0; j < m_SETTINGS_ITEMS3; ++j) 
                {
                    m_menu3[j].setFillColor(sf::Color::White);
                }
                m_menu3[m_selectedItemIndex].setFillColor(sf::Color::Red);
                return MenuChoice(m_selectedItemIndex);
                break;
           }
        }
        break;
    case 3:
        for (int i = 0; i < m_SETTINGS_ITEMS4; ++i)
        {
            if (m_menu4[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
            {
                m_selectedItemIndex = i;
                for (int j = 0; j < m_SETTINGS_ITEMS4; ++j)
                {
                    m_menu4[j].setFillColor(sf::Color::White);
                }
                m_menu4[m_selectedItemIndex].setFillColor(sf::Color::Red);
                return MenuChoice(m_selectedItemIndex);
                break;
            }
        }
        break;
    case 4:
        for (int i = 0; i < m_SETTINGS_ITEMS5; ++i)
        {
            if (m_menu5[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
            {
                m_selectedItemIndex = i;
                for (int j = 0; j < m_SETTINGS_ITEMS5; ++j)
                {
                    m_menu5[j].setFillColor(sf::Color::White);
                }
                m_menu5[m_selectedItemIndex].setFillColor(sf::Color::Red);
                if (m_selectedItemIndex == 0)
                    return MenuChoice(m_selectedItemIndex);
                break;
            }
        }
        break;
    case 5:
        for (int i = 0; i < m_SETTINGS_ITEMS6; ++i)
        {
            if (m_menu6[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
            {
                m_selectedItemIndex = i;
                for (int j = 0; j < m_SETTINGS_ITEMS6; ++j)
                {
                    m_menu6[j].setFillColor(sf::Color::White);
                }
                m_menu6[m_selectedItemIndex].setFillColor(sf::Color::Red);
                if (m_selectedItemIndex == 0)
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
    for (int i = 0; i < m_SETTINGS_ITEMS2; ++i)
    {
        m_menu2[i].setFillColor(sf::Color::White);
    }
    m_menu2[m_selectedItemIndex].setFillColor(sf::Color::Red);
    for (int i = 0; i < m_SETTINGS_ITEMS3; ++i)
    {
        m_menu3[i].setFillColor(sf::Color::White);
    }
    m_menu3[m_selectedItemIndex].setFillColor(sf::Color::Red);
    for (int i = 0; i < m_SETTINGS_ITEMS4; ++i)
    {
        m_menu4[i].setFillColor(sf::Color::White);
    }
    m_menu4[m_selectedItemIndex].setFillColor(sf::Color::Red);
    for (int i = 0; i < m_SETTINGS_ITEMS5; ++i)
    {
        m_menu5[i].setFillColor(sf::Color::White);
    }
    m_menu5[m_selectedItemIndex].setFillColor(sf::Color::Red);
    for (int i = 0; i < m_SETTINGS_ITEMS6; ++i)
    {
        m_menu6[i].setFillColor(sf::Color::White);
    }
    m_menu6[m_selectedItemIndex].setFillColor(sf::Color::Red);
}

int Menu::getMenuLevel() {
    return m_menuLevel;
}

void Menu::setMenuLevel(const int lvl)
{
    m_menuLevel = lvl;
}

void Menu::resize()
{
    m_title.setPosition(m_window.getSize().x / 2 - m_title.getGlobalBounds().width / 2, 120);


    for (int i = 0; i < m_MENU_ITEMS; ++i)
    {
        m_menu[i].setPosition(m_window.getSize().x / 2 - m_menu[i].getGlobalBounds().width / 2, 300 + i * 80);
    }

    for (int i = 0; i < m_SETTINGS_ITEMS2; ++i)
    {
        m_menu2[i].setPosition(m_window.getSize().x / 2 - m_menu2[i].getGlobalBounds().width / 2, 300 + i * 80);
    }

    m_s1.setPosition(m_window.getSize().x / 2 - 75 - 120, m_window.getSize().y / 2 + 50);
    m_s2.setPosition(m_window.getSize().x / 2 - 75 + 120, m_window.getSize().y / 2 + 50);

    for (int i = 0; i < m_SETTINGS_ITEMS3; i++)
    {
        m_menu3[i].setPosition(
            i == 0 ?
            m_window.getSize().x / 2 - m_menu3[i].getGlobalBounds().width / 2
            :
            (i == 1 ?
                m_window.getSize().x / 2 - m_menu3[i].getGlobalBounds().width / 2 - 120
                :
                m_window.getSize().x / 2 - m_menu3[i].getGlobalBounds().width / 2 + 120),
            i == 0 ?
            m_window.getSize().y / 3.0f
            :
            m_window.getSize().y / 2.0f
        );
    }
    for (int i = 0; i < m_SETTINGS_ITEMS4; i++)
    {
        m_menu4[i].setPosition(
            i == 0 ?
            m_window.getSize().x / 2 - m_menu4[i].getGlobalBounds().width / 2
            :
            (i == 1 ?
                m_window.getSize().x / 2 - m_menu4[i].getGlobalBounds().width / 2 - 150
                :
                (i == 2 ?
                    m_window.getSize().x / 2 - m_menu4[i].getGlobalBounds().width / 2 + 0
                    :
                    m_window.getSize().x / 2 - m_menu4[i].getGlobalBounds().width / 2 + 150)),
            i == 0 ?
            300
            :
            m_window.getSize().y / 1.8f
        );
    }
    for (int i = 0; i < m_SETTINGS_ITEMS5; i++)
    {
        m_menu5[i].setCharacterSize(i == 0 ? 50 : 30);
        m_menu5[i].setPosition(
            i == 0 ?
            m_window.getSize().x / 2 - m_menu5[i].getGlobalBounds().width / 2
            :
            (i == 1 ?
                m_window.getSize().x / 2 - m_menu5[i].getGlobalBounds().width / 2 - 150
                :
                (i == 2 ?
                    m_window.getSize().x / 2 - m_menu5[i].getGlobalBounds().width / 2 + 0
                    :
                    m_window.getSize().x / 2 - m_menu5[i].getGlobalBounds().width / 2 + 150)),
            i == 0 ?
            300
            :
            m_window.getSize().y / 1.8f
        );
    }

    m_rec1.setPosition(m_window.getSize().x / 2 - m_rec1.getGlobalBounds().width / 2 - 150, m_window.getSize().y / 1.6f);
    m_rec2.setPosition(m_window.getSize().x / 2 - m_rec1.getGlobalBounds().width / 2, m_window.getSize().y / 1.6f);
    m_rec3.setPosition(m_window.getSize().x / 2 - m_rec1.getGlobalBounds().width / 2 + 150, m_window.getSize().y / 1.6f);

    for (int i = 0; i < m_SETTINGS_ITEMS6; i++)
    {
        m_menu6[i].setPosition(m_window.getSize().x / 2 - m_menu6[i].getGlobalBounds().width / 2, 300 + i * 60);
    }
}

void Menu::updateColorNumbers()
{
    switch (m_colorPick)
    {
    case 1:
        m_menu5[1].setString("R: " + std::to_string(m_settings.getHealthyColor().r));
        m_menu5[2].setString("G: " + std::to_string(m_settings.getHealthyColor().g));
        m_menu5[3].setString("B: " + std::to_string(m_settings.getHealthyColor().b));
        m_rec1.setFillColor(m_settings.getHealthyColor());
        break;
    case 2:
        m_menu5[1].setString("R: " + std::to_string(m_settings.getInfectedColor().r));
        m_menu5[2].setString("G: " + std::to_string(m_settings.getInfectedColor().g));
        m_menu5[3].setString("B: " + std::to_string(m_settings.getInfectedColor().b));
        m_rec2.setFillColor(m_settings.getInfectedColor());
        break;
    case 3:
        m_menu5[1].setString("R: " + std::to_string(m_settings.getResistantColor().r));
        m_menu5[2].setString("G: " + std::to_string(m_settings.getResistantColor().g));
        m_menu5[3].setString("B: " + std::to_string(m_settings.getResistantColor().b));
        m_rec3.setFillColor(m_settings.getResistantColor());
        break;
    }
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
            return 7;
            break;
        case 3:
            m_selectedItemIndex = 0;
            return 8;
            break;
        } 
    break;
    case 2: // simulation size
        switch (elementId)
        {
        case 0: 
            m_menuLevel = 1;
            return 2;
            break;
        case 1:
            clearSelectedItem();
            return 5;
            break;
        case 2:
            clearSelectedItem();
            return 6;
            break;
        }
        break;
    case 3: // color settings
        switch (elementId)
        {
        case 0: 
            m_menuLevel = 1;
            return 2;
            break;
        case 1:
            resize();
            setColorPick(1);
            updateColorNumbers();
            return 9;
            break;
        case 2:
            resize();
            setColorPick(2);
            updateColorNumbers();
            return 9;
            break;
        case 3:
            resize();
            setColorPick(3);
            updateColorNumbers();
            return 9;
            break;
        }
        break;
    case 4: // color picker
        switch (elementId)
        {
        case 0:
            m_menuLevel = 3;
            return 8;
            break;
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        }
        break;
    case 5: // advanced settings
        switch (elementId)
        {
        case 0:
            m_menuLevel = 1;
            return 2;
            break;
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            break;
        }
        break;
    }
}


sf::RectangleShape Menu::getRect1()
{
    return m_rec1;
}

void Menu::SetRect1(const sf::RectangleShape shape)
{
    m_rec1 = shape;
}

sf::RectangleShape Menu::getRect2()
{
    return m_rec2;
}

void Menu::SetRect2(const sf::RectangleShape shape)
{
    m_rec1 = shape;
}

sf::RectangleShape Menu::getRect3()
{
    return m_rec3;
}

void Menu::SetRect3(const sf::RectangleShape shape)
{
    m_rec1 = shape;
}

int Menu::getColorPick() const
{
    return m_colorPick;
}

void Menu::setColorPick(int num)
{
    m_colorPick = num;
}