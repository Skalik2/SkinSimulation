#include "menu.h"

GameMenu::GameMenu(sf::RenderWindow& window) 
    : m_window(window)  
    , m_selectedItemIndex(0)
{
    if (!m_font.loadFromFile("arial.ttf")) {
        std::cerr << "Nie uda³o siê wczytaæ czcionki." << std::endl;
    }

    m_title.setFont(m_font);
    m_title.setString("Problem liszaja");
    m_title.setCharacterSize(50);
    m_title.setFillColor(sf::Color::White);
    m_title.setStyle(sf::Text::Bold);
    m_title.setPosition(window.getSize().x / 2 - m_title.getGlobalBounds().width / 2, 140);

    for (int i = 0; i < MENU_ITEMS; ++i) {
        m_menu[i].setFont(m_font);
        m_menu[i].setCharacterSize(40);
        m_menu[i].setFillColor(sf::Color::White);
        m_menu[i].setString(m_options[i]);
        m_menu[i].setPosition(window.getSize().x / 2 - m_menu[i].getGlobalBounds().width / 2, 300 + i * 60);
    }
}

void GameMenu::draw() {
    m_window.draw(m_title);

    for (int i = 0; i < MENU_ITEMS; ++i) {
        m_window.draw(m_menu[i]);
    }
}

void GameMenu::moveUp() {
    if (m_selectedItemIndex - 1 >= 0) {
        m_menu[m_selectedItemIndex].setFillColor(sf::Color::White);
        m_selectedItemIndex--;
        m_menu[m_selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void GameMenu::moveDown() {
    if (m_selectedItemIndex + 1 < MENU_ITEMS) {
        m_menu[m_selectedItemIndex].setFillColor(sf::Color::White);
        m_selectedItemIndex++;
        m_menu[m_selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

int GameMenu::getSelectedItemIndex() const {
    return m_selectedItemIndex;
}
