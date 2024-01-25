#include "windowHelp.h"

void OpenWindow(Settings& settings)
{
	sf::Vector2f viewSize2(450, 450);
	sf::VideoMode vm2(viewSize2.x, viewSize2.y);
	sf::RenderWindow window2(vm2, "Obsluga programu", sf::Style::Default);

	sf::Text text1;
	sf::Text text2;

	sf::Font font1;
	sf::Font font2;

	if (!font1.loadFromFile("font.otf"))
	{
		std::cerr << "Couldn't load font" << std::endl;
	}

	if (!font2.loadFromFile("Arial.ttf"))
	{
		std::cerr << "Couldn't load font" << std::endl;
	}


	text1.setFont(font1);
	text1.setString("Instrukcja");
	text1.setCharacterSize(80);
	text1.setFillColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(window2.getSize().x / 2 - text1.getGlobalBounds().width / 2, 15);

	text2.setFont(font2);
	text2.setString("Predkosc animacji\t<K L>\nSzansa zarazenia\t<O P>\nCzas infekcji\t<V B>\nCzas odpornosci\t<N M>\nZmiana proporcji\t<R>\nAktualne wartosci\t<I>\nMenu\t<Esc>\nZmiana wielkosci Planszy\n<strzalki/WASD>\n");
	text2.setCharacterSize(28);
	text2.setFillColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(window2.getSize().x / 2 - text2.getGlobalBounds().width / 2, 120);

	while (window2.isOpen() and settings.getIsWindowHelpOpen())
	{
		window2.clear(sf::Color::Black);
		sf::Event event;
		while (window2.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window2.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::H)
				window2.close();
		}
		window2.draw(text1);
		window2.draw(text2);
		window2.display();
	}
	if (settings.getIsWindowHelpOpen())
	{
		settings.toggleIsWindowHelpOpen();
	}
}


