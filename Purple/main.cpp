#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Player.h"
#include "Level.h"
#include "constants.h"


int main()
{
	// Create Player and Level
	Level level1 = Level("level1.png", "tile2.png");
	Player player = Player({ 2, 2 }, { 1, 1 }, "purple2.png");

	sf::View view;
	view.setSize(tex_size * 16 * 2, tex_size * 9 * 2);

	sf::RenderWindow window(sf::VideoMode(2560, 1440), "Purple", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);

	// A clock used for calculating the time between frames
	sf::Clock frame_clock;

	// Game loop
	while (window.isOpen())
	{
		// Get time elapsed since last frame
		sf::Time frame_time = frame_clock.restart();

		// Event handling
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
						case sf::Keyboard::Escape:
							window.close();
							break;

						default:
							break;
					}
			}
		}

		// Flip the level to 1 if "Q" is pressed, else to 0
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			level1.flip(1);
		else
			level1.flip(0);

		// Update the player
		player.update(sf::Keyboard::isKeyPressed(sf::Keyboard::Left),
			sf::Keyboard::isKeyPressed(sf::Keyboard::Right),
			sf::Keyboard::isKeyPressed(sf::Keyboard::Space),
			level1.entities, frame_time.asMilliseconds());

		// Center the view around the player and check that it doesn't show anything outside the level
		sf::Vector2f view_center = player.getPosition();
		view_center += { player.getLocalBounds().width / 2, player.getLocalBounds().height / 2 };

		view_center.x = std::max(0.f, view_center.x - view.getSize().x / 2) + view.getSize().x / 2;
		view_center.x = std::min((float) level1.size.x * tex_size, view_center.x + view.getSize().x / 2) - view.getSize().x / 2;

		view_center.y = std::max(0.f, view_center.y - view.getSize().y / 2) + view.getSize().y / 2;
		view_center.y = std::min((float)level1.size.y * tex_size, view_center.y + view.getSize().y / 2) - view.getSize().y / 2;

		view.setCenter(view_center);
		window.setView(view);

		// Clear the window and draw all the entities
		window.clear();
		for (int i = 0; i < level1.entities.size(); i++)
			window.draw(level1.entities[i]);
		window.draw(player);
		window.display();
	}

	return 0;
}