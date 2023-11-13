#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu 
{
    static const int MENU_ITEMS = 4;
    static const int SETTINGS_ITEMS = 3;
    sf::Text m_title;
    sf::Text m_menu[MENU_ITEMS];
    sf::Text m_menu2[SETTINGS_ITEMS];
    sf::Font m_font;
    int m_selectedItemIndex;
    int m_selectedItemSettingsIndex;
    sf::RenderWindow& m_window;
    std::string m_options[MENU_ITEMS] = { "Kontynuuj","Nowa symulacja", "Ustawienia", "Wyjscie" };
    std::string m_options2[SETTINGS_ITEMS] = { "Zarazliwosc", "Szybkosc", "Zapisz" };
public:

    Menu(sf::RenderWindow& window);

    void draw();
    void drawSettings();
    void moveUp();
    void moveDown();
    int getSelectedItemIndex() const;
    int handleMouseClick();
    int MenuChoice(int elementId);
};

#endif
