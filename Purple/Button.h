#pragma once
#include <SFML/Graphics.hpp>

class Button {
private:
		sf::Vector2f size; // Size relative to display
		sf::Vector2f center; // Position relative to display
		sf::Color color;
		std::string text;
		bool visible;

public:
	Button();
	Button(sf::Vector2f m_size, sf::Vector2f m_center, sf::Color m_color, std::string m_text);
	~Button();

	bool check_click(sf::Vector2i mouse_pos, sf::RenderWindow& window);
	virtual void on_click();

	void draw(sf::RenderWindow& window);
};