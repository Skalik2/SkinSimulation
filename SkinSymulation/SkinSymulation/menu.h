#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GameMenu {
public:
    GameMenu(sf::RenderWindow& window);

    void draw();
    void moveUp();
    void moveDown();
    int getSelectedItemIndex() const;

private:
    static const int MENU_ITEMS = 3;
    sf::Text m_title;
    sf::Text m_menu[MENU_ITEMS];
    sf::Font m_font;
    int m_selectedItemIndex;
    sf::RenderWindow& m_window;
    std::string m_options[MENU_ITEMS] = { "Nowa symulacja", "Opcje", "Wyjscie" };
};

#endif // GAMEMENU_H
