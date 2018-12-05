#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Player.h"
#include "Level.h"


class GameScene
{
private:
	// Player in the scene
	Player player;

	// Level of the scene
	Level level;

	// The view showing the player
	sf::View view;

	// Status of the game : -1 - lose, 0 - normal, 1 - win
	int status = 0;

	// Current Level number
	int level_num = 1;

	// Clock that counts the time since last frame
	sf::Clock frame_clock;

public:
	// Default constructor
	GameScene();

	// Default destructor
	~GameScene();

	// Binds the keyboard keys for left, right, jump, and flip(level) keys
	void bind(sf::Keyboard::Key left_key, sf::Keyboard::Key right_key, sf::Keyboard::Key jump_key, sf::Keyboard::Key flip_key);

	// Starts the simulation of the level
	void start();

	// Stops the simulation of the level
	void pause();

	// Update the moving objects
	void update();

	// Change the passed sf::RenderTexture which will be drawn on the screen
	void render(sf::RenderTexture& screen);

	// Get the status
	int get_status();
};

