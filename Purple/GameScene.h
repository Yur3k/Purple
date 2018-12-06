#pragma once
#include <string>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Player.h"
#include "Level.h"


class GameScene
{
private:
	// Player in the scene
	Player player;

	// View which shows the player
	sf::View player_view;

	// Center of the view which shows the player
	sf::Vector2f player_view_center;

	// Level of the scene
	Level level;

	// The view showing the player
	sf::View view;

	// Status of the game : -1 - lose, 0 - normal, 1 - win
	int status = 0;

	// Is the game on pause
	bool paused = false;

	// Current Level number
	int level_num = 1;

	// Clock that counts the time since last frame
	sf::Clock frame_clock;

	// Key for flipping the level
	sf::Keyboard::Key flip_key;

public:
	// Default constructor
	GameScene();

	// Default destructor
	~GameScene();

	// Binds the keyboard keys for left, right, jump, and flip(level) keys
	void bind(sf::Keyboard::Key left_key, sf::Keyboard::Key right_key, sf::Keyboard::Key jump_key, sf::Keyboard::Key flip_key);

	// Initializes the level
	void start();

	// Stops the simulation of the level
	void pause();

	// Starts/Resumes the simulation of the level
	void play();

	// Update the moving objects
	void update();

	// Change the passed sf::RenderTexture which will be drawn on the screen
	void render(sf::RenderTexture& screen);

	// Get the status
	int get_status();
};

