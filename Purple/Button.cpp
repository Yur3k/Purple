#include "Button.h"


Button::Button()
{
}


Button::Button(sf::Vector2f m_size, sf::Vector2f m_center, sf::Color m_color, std::string m_text):
	size(m_size),
	center(m_center),
	color(m_color),
	text(m_text)
{
}


Button::~Button()
{
}


bool Button::check_click(sf::Vector2i mouse_pos, sf::RenderWindow& window)
{
	sf::Vector2u display = window.getSize();

	sf::RectangleShape btn_rect;
	btn_rect.setSize(sf::Vector2f(size.x * display.x, size.y * display.y));
	btn_rect.setOrigin(sf::Vector2f(btn_rect.getSize().x / 2, btn_rect.getSize().y / 2));
	btn_rect.setPosition(sf::Vector2f(center.x * display.x, center.y * display.y));
	btn_rect.setFillColor(color);

	if (btn_rect.getGlobalBounds().contains((sf::Vector2f)mouse_pos))
	{
		//onClick();
	}
}

void Button::on_click()
{
}


void Button::draw(sf::RenderWindow& window)
{
	sf::Vector2u display = window.getSize();

	sf::RectangleShape btn_rect;
	btn_rect.setSize(sf::Vector2f(size.x * display.x, size.y * display.y));
	btn_rect.setOrigin(sf::Vector2f(btn_rect.getSize().x / 2, btn_rect.getSize().y / 2));
	btn_rect.setPosition(sf::Vector2f(center.x * display.x, center.y * display.y));
	btn_rect.setFillColor(color);

	window.setView(window.getDefaultView());
	window.draw(btn_rect);
}