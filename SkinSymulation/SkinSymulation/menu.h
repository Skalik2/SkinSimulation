#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Settings.h"

class Menu 
{
    int m_menuLevel = 0;
    static const int m_MENU_ITEMS = 4;
    static const int m_SETTINGS_ITEMS = 4;
    static const int m_SETTINGS_ITEMS2 = 3;
    static const int m_SETTINGS_ITEMS3 = 4;
    static const int m_SETTINGS_ITEMS4 = 4;
    static const int m_SETTINGS_ITEMS5 = 5;
    sf::Text m_title;
    sf::Text m_menu[m_MENU_ITEMS];
    sf::Text m_menu2[m_SETTINGS_ITEMS];
    sf::Text m_menu3[m_SETTINGS_ITEMS2];
    sf::Text m_menu4[m_SETTINGS_ITEMS3];
    sf::Text m_menu5[m_SETTINGS_ITEMS4];
    sf::Text m_menu6[m_SETTINGS_ITEMS5];
    sf::Font m_font;
    int m_selectedItemIndex;
    sf::RenderWindow& m_window;
    Settings& m_settings;
    std::string m_options[m_MENU_ITEMS] = { "Kontynuuj","Nowa symulacja", "Ustawienia", "Wyjscie" };
    std::string m_options2[m_SETTINGS_ITEMS] = { "Powrot","Rozmiar planszy", "Dokladne wartosci", "Kolory" };
    std::string m_options3[m_SETTINGS_ITEMS2] = { "Powrot", "25x25", "75x75"};
    std::string m_options4[m_SETTINGS_ITEMS3] = { "Powrot", "Zdrowa", "Chora", "Odporna"};
    std::string m_options5[m_SETTINGS_ITEMS4] = { "Powrot", "R", "G", "B"};
    std::string m_options6[m_SETTINGS_ITEMS5] = { "Powrot", "Czas infekcji", "Czas odpornosci", "Klatki na sekunde", "Szansa zarazenia" };

    sf::Texture m_t1;
    sf::Sprite m_s1;
    sf::Texture m_t2;
    sf::Sprite m_s2;
    sf::RectangleShape m_rec1, m_rec2, m_rec3;
    int m_colorPick;
public:

    Menu(sf::RenderWindow& window, Settings& settings);

    void menuInit();
    void resize();
    void draw();
    void drawSettings();
    void drawAdvancedSettings();
    void moveUp();
    void moveDown();
    int getSelectedItemIndex() const;
    int handleMouseClick();
    int MenuChoice(int elementId);
    void clearSelectedItem();
    void clearMenuLevel();
    void drawSettingsInfectType();
    void drawSettingsColorPicker();
    int getMenuLevel();
    void setMenuLevel(const int lvl);
    sf::RectangleShape getRect1();
    void SetRect1(const sf::RectangleShape shape);
    sf::RectangleShape getRect2();
    void SetRect2(const sf::RectangleShape shape);
    sf::RectangleShape getRect3();
    void SetRect3(const sf::RectangleShape shape);
    void drawChooseSetingsColor(int number);
    int getColorPick() const;
    void setColorPick(int num);
    void updateColorNumbers();
};

#endif
