#include <SFML/Graphics.hpp>
#include "GameScene.h"

int main()
{
	// Create the game scene
	GameScene game_scene;

	// Bind the control keys
	game_scene.bind(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Space, sf::Keyboard::Q);

	// Initialize the game scene
	game_scene.start();

	// Create the render texture to which the game scene will be rendered
	sf::RenderTexture game_render;
	game_render.create(2560, 1440);

	// Create the window
	sf::RenderWindow window(sf::VideoMode(2560, 1440), "Purple", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);

	// Game loop
	while (window.isOpen())
	{
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

		// Update the game
		game_scene.update();

		// Render the game scene
		game_scene.render(game_render);

		// Draw the rendered scene
		sf::Sprite render_sprite(game_render.getTexture());
		window.draw(render_sprite);
	}

	return 0;
}