#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu 
{
    int m_menuLevel = 0;
    static const int m_MENU_ITEMS = 4;
    static const int m_SETTINGS_ITEMS = 4;
    sf::Text m_title;
    sf::Text m_menu[m_MENU_ITEMS];
    sf::Text m_menu2[m_SETTINGS_ITEMS];
    sf::Font m_font;
    int m_selectedItemIndex;
    int m_selectedItemSettingsIndex;
    sf::RenderWindow& m_window;
    std::string m_options[m_MENU_ITEMS] = { "Kontynuuj","Nowa symulacja", "Ustawienia", "Wyjscie" };
    std::string m_options2[m_SETTINGS_ITEMS] = { "Powrot","Zarazliwosc", "Tryb zarazania", "Zapisz"};
public:

    Menu(sf::RenderWindow& window);

    void draw();
    void drawSettings();
    void moveUp();
    void moveDown();
    int getSelectedItemIndex() const;
    int handleMouseClick();
    int MenuChoice(int elementId);
    void clearSelectedItem();
    void clearMenuLevel();
};

#endif
