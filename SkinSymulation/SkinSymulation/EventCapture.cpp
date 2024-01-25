#include "EventCapture.h"

EventCapture::EventCapture(sf::RenderWindow& window, Settings& settings, CellArray& skinTab, Menu& gameMenu)
	: m_gameMenu(gameMenu)
	, m_settings(settings)
	, m_skinTab(skinTab)
	, m_window(window)
	, m_gameActive(false)
{

}

void EventCapture::drawStage(int stage) {
	switch (m_settings.getStage())
	{
	case 0:
		m_gameMenu.draw();
		break;

	case 1:
	case 2:
		for (int x = 0; x < m_skinTab.getSizeX(); x++)
		{
			for (int y = 0; y < m_skinTab.getSizeY(); y++)
			{
				m_window.draw(m_skinTab.get(x, y));
			}
		}
		m_settings.drawFpsNumber();
		break;

	case 3:
		m_gameMenu.drawSettings();
		break;

	case 4:
		m_gameMenu.drawSettingsInfectType();
		break;
	case 5:
		m_gameMenu.drawSettingsColorPicker();
		break;
	case 6:
		m_gameMenu.drawChooseSetingsColor(m_gameMenu.getColorPick());
		break;
	}
}

void EventCapture::stageSwitch(int menuButton)
{
	switch (menuButton)
	{
	case -1:
		break;
	case 0: // continue
		if (!m_gameActive)
			break;
		m_settings.setStage(1);
		drawStage(m_settings.getStage());
		break;
	case 1: // new game
		m_gameActive = true;
		m_settings.setStage(2);
		m_skinTab.init();
		break;
	case 2: // settings
		m_settings.setStage(3);
		m_gameMenu.clearMenuLevel();
		m_gameMenu.setMenuLevel(1);
		drawStage(m_settings.getStage());
		break;
	case 3: // main menu 
		m_settings.setStage(0);
		m_gameMenu.clearSelectedItem();
		m_gameMenu.clearMenuLevel();
		m_gameMenu.setMenuLevel(0);
		drawStage(m_settings.getStage());
		break;
	case 4: // tab size 
		m_gameMenu.setMenuLevel(2);
		m_settings.setStage(4);
		drawStage(m_settings.getStage());
		break;
	case 5: //25x25
		m_skinTab.setSize(25, 25);
		m_skinTab.init();
		m_gameMenu.clearMenuLevel();
		m_settings.setStage(3);
		m_gameMenu.setMenuLevel(1);
		drawStage(m_settings.getStage());
		break;
	case 6:	//75x75
		m_skinTab.setSize(75, 75);
		m_skinTab.init();
		m_gameMenu.clearMenuLevel();
		m_settings.setStage(3);
		m_gameMenu.setMenuLevel(1);
		drawStage(m_settings.getStage());
		break;
	case 7: 
		m_gameMenu.clearMenuLevel();
		m_gameMenu.setMenuLevel(5);
		m_settings.setStage(7);
		break;
	case 8: // color menu
		m_skinTab.resizeTab();
		m_gameMenu.clearMenuLevel();
		m_gameMenu.setMenuLevel(3);
		m_settings.setStage(5);
		break;
	case 9: //color pick
		m_gameMenu.clearMenuLevel();
		m_gameMenu.setMenuLevel(4);
		m_settings.setStage(6);
		break;
	}
}

void EventCapture::changeColor(int numberOfRect, bool add)
{
	switch (numberOfRect)
	{
	case 1:
		if (add)
		{
			switch (m_gameMenu.getSelectedItemIndex()) 
			{
			case 1:
				m_settings.setHealthyColor(sf::Color(m_settings.getHealthyColor().r + 1, m_settings.getHealthyColor().g, m_settings.getHealthyColor().b));
				break;
			case 2:
				m_settings.setHealthyColor(sf::Color(m_settings.getHealthyColor().r, m_settings.getHealthyColor().g + 1, m_settings.getHealthyColor().b));
				break;
			case 3:
				m_settings.setHealthyColor(sf::Color(m_settings.getHealthyColor().r, m_settings.getHealthyColor().g, m_settings.getHealthyColor().b + 1));
				break;
			}
		}
		else
		{
			switch (m_gameMenu.getSelectedItemIndex())
			{
			case 1:
				m_settings.setHealthyColor(sf::Color(m_settings.getHealthyColor().r - 1, m_settings.getHealthyColor().g, m_settings.getHealthyColor().b));
				break;
			case 2:
				m_settings.setHealthyColor(sf::Color(m_settings.getHealthyColor().r, m_settings.getHealthyColor().g - 1, m_settings.getHealthyColor().b));
				break;
			case 3:
				m_settings.setHealthyColor(sf::Color(m_settings.getHealthyColor().r, m_settings.getHealthyColor().g, m_settings.getHealthyColor().b - 1));
				break;
			}
		}
		break;
	case 2:
		if (add)
		{
			switch (m_gameMenu.getSelectedItemIndex())
			{
			case 1:
				m_settings.setInfectedColor(sf::Color(m_settings.getInfectedColor().r + 1, m_settings.getInfectedColor().g, m_settings.getInfectedColor().b));
				break;
			case 2:
				m_settings.setInfectedColor(sf::Color(m_settings.getInfectedColor().r, m_settings.getInfectedColor().g + 1, m_settings.getInfectedColor().b));
				break;
			case 3:
				m_settings.setInfectedColor(sf::Color(m_settings.getInfectedColor().r, m_settings.getInfectedColor().g, m_settings.getInfectedColor().b + 1));
				break;
			}
		}
		else
		{
			switch (m_gameMenu.getSelectedItemIndex())
			{
			case 1:
				m_settings.setInfectedColor(sf::Color(m_settings.getInfectedColor().r - 1, m_settings.getInfectedColor().g, m_settings.getInfectedColor().b));
				break;
			case 2:
				m_settings.setInfectedColor(sf::Color(m_settings.getInfectedColor().r, m_settings.getInfectedColor().g - 1, m_settings.getInfectedColor().b));
				break;
			case 3:
				m_settings.setInfectedColor(sf::Color(m_settings.getInfectedColor().r, m_settings.getInfectedColor().g, m_settings.getInfectedColor().b - 1));
				break;
			}
		}
		break;
	case 3:
		if (add)
		{
			switch (m_gameMenu.getSelectedItemIndex())
			{
			case 1:
				m_settings.setResistantColor(sf::Color(m_settings.getResistantColor().r + 1, m_settings.getResistantColor().g, m_settings.getResistantColor().b));
				break;
			case 2:
				m_settings.setResistantColor(sf::Color(m_settings.getResistantColor().r, m_settings.getResistantColor().g + 1, m_settings.getResistantColor().b));
				break;
			case 3:
				m_settings.setResistantColor(sf::Color(m_settings.getResistantColor().r, m_settings.getResistantColor().g, m_settings.getResistantColor().b + 1));
				break;
			}
		}
		else
		{
			switch (m_gameMenu.getSelectedItemIndex())
			{
			case 1:
				m_settings.setResistantColor(sf::Color(m_settings.getResistantColor().r - 1, m_settings.getResistantColor().g, m_settings.getResistantColor().b));
				break;
			case 2:
				m_settings.setResistantColor(sf::Color(m_settings.getResistantColor().r, m_settings.getResistantColor().g - 1, m_settings.getResistantColor().b));
				break;
			case 3:
				m_settings.setResistantColor(sf::Color(m_settings.getResistantColor().r, m_settings.getResistantColor().g, m_settings.getResistantColor().b - 1));
				break;
			}
		}
		break;
	}
}


void EventCapture::updateInput() {
	sf::Event event;
	if (!m_settings.getIsWindowHelpOpen() and isRunning)
	{
		isRunning = false;
		thread.join();
	}
	while (m_window.pollEvent(event)) {

		if (event.type == sf::Event::Closed)
			m_window.close();

		if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			m_window.setView(sf::View(visibleArea));
			m_window.setSize(sf::Vector2u(event.size.width, event.size.height));
			m_gameMenu.resize();
			m_skinTab.resizeTab();
		}

		switch (event.type) {
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::H:
				if (!isRunning)
				{
					m_settings.toggleIsWindowHelpOpen();
					isRunning = true;
					thread = std::thread (OpenWindow, std::ref(m_settings));
				}
				else
				{
					if (m_settings.getIsWindowHelpOpen())
					{
						m_settings.toggleIsWindowHelpOpen();
					}
					isRunning = false;
					thread.join();
				}
				break;
			case sf::Keyboard::I:
				m_settings.toggleInfoVisibility();
				break;
			case sf::Keyboard::R:
				m_settings.toggleSymetricAspectRatio();
				m_skinTab.resizeTab();
				break;
			case sf::Keyboard::W:
			case sf::Keyboard::Up:
				if (m_settings.getStage() != 1 && m_settings.getStage() != 2)
					m_gameMenu.moveUp();
				if (m_skinTab.getSizeY() != 1 && (m_settings.getStage() == 2 || m_settings.getStage() == 1))
				{
					m_skinTab.setSize(m_skinTab.getSizeX(), m_skinTab.getSizeY() - 1);
					m_skinTab.resizeTab();
					drawStage(1);
				}
				break;
			case sf::Keyboard::D:
			case sf::Keyboard::Right:
				if (m_skinTab.getSizeX() < 239 && (m_settings.getStage() == 1 || m_settings.getStage() == 2))
				{
					m_skinTab.setSize(m_skinTab.getSizeX() + 1, m_skinTab.getSizeY());
					m_skinTab.initRight();
					drawStage(1);
				}
				if (m_settings.getStage() == 6)
				{
					changeColor(m_gameMenu.getColorPick(), true);
					m_gameMenu.updateColorNumbers();
				}
				break;
			case sf::Keyboard::A:
			case sf::Keyboard::Left:
				if (m_skinTab.getSizeX() != 1 && (m_settings.getStage() == 1 || m_settings.getStage() == 2))
				{
					m_skinTab.setSize(m_skinTab.getSizeX() - 1, m_skinTab.getSizeY());
					m_skinTab.resizeTab();
					drawStage(1);
				}
				if (m_settings.getStage() == 6)
				{
					changeColor(m_gameMenu.getColorPick(), false);
					m_gameMenu.updateColorNumbers();
				}
				break;
			case sf::Keyboard::S:
			case sf::Keyboard::Down:
				if (m_settings.getStage() != 1 && m_settings.getStage() != 2)
					m_gameMenu.moveDown();
				if (m_skinTab.getSizeY() < 239 && (m_settings.getStage() == 2 || m_settings.getStage() == 1))
				{
					m_skinTab.setSize(m_skinTab.getSizeX(), m_skinTab.getSizeY() + 1);
					m_skinTab.initDown();
					drawStage(1);
				}
				break;
			case sf::Keyboard::Escape:
				if (m_settings.getStage() == 0 && m_gameActive == true)
					m_settings.setStage(1);
				else
				{
					m_gameMenu.clearSelectedItem();
					m_gameMenu.clearMenuLevel();
					m_gameMenu.setMenuLevel(0);
					m_settings.setStage(0);
				}
				break;
			case sf::Keyboard::Enter:
				if (m_settings.getStage() != 1 && m_settings.getStage() != 2)
				{
					stageSwitch(m_gameMenu.MenuChoice(m_gameMenu.getSelectedItemIndex()));
				}
				break;
			case sf::Keyboard::N:
				m_settings.setResistantTime(m_settings.getResistantTime() - 1);
				break;
			case sf::Keyboard::M:
				m_settings.setResistantTime(m_settings.getResistantTime() + 1);
				break;
			case sf::Keyboard::V:
				m_settings.setInfetcionTime(m_settings.getInfectionTime() - 1);
				break;
			case sf::Keyboard::B:
				m_settings.setInfetcionTime(m_settings.getInfectionTime() + 1);
				break;
			case sf::Keyboard::O:
				m_settings.subProbability();
				break;
			case sf::Keyboard::P:
				m_settings.addProbability();
				break;
			case sf::Keyboard::L:
				if (m_settings.getFpsLimit() <= 64)
				{
					m_settings.setFpsLimit(m_settings.getFpsLimit() * 2);
					m_settings.setTimeUnit();
				}
				m_settings.drawFpsNumber();
				break;
			case sf::Keyboard::K:
				if (m_settings.getFpsLimit() >= 2)
				{
					m_settings.setFpsLimit(m_settings.getFpsLimit() / 2);
					m_settings.setTimeUnit();
				}
				m_settings.drawFpsNumber();
				break;
			}

			break;

		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left) {
				if (m_settings.getStage() != 1 && m_settings.getStage() != 2)
				{
					stageSwitch(m_gameMenu.handleMouseClick());
				}
				else if (m_settings.getStage() == 2 || m_settings.getStage() == 1)
					m_skinTab.handleMouseClick();
			}
			break;
		}
	}
}