#pragma once
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "constants.h"

// Represents a player
class Player: public sf::Sprite
{
private:
	// Texture used for the player
	sf::Texture player_texture;

	sf::Vector2i size = { 2, 2 };
	sf::Vector2f velocity = { 0, 0 };
	sf::Vector2f acceleration = { 0, 0 };

	// Horizontal acceleration when speeding up
	float horizontalAccelerationUp = 0.003;
	
	// Horizontal acceleration when slowing down
	float horizontalAccelerationDown = 0.006;
	
	// Maximum horizontal speed
	float horizontalSpeedCap = 0.4;

	// Minimum horizontal velocity (player stops completely if slower)
	float horizontalSpeedMin = 0.02;

	// Height in tex_sizes
	float jump_height = 10;

	// Time to reach maximum trajectory height
	sf::Time jump_time = sf::Time(sf::milliseconds(900));

	// Gravitational acceleration
	float gravity = 2 * jump_height * tex_size / jump_time.asMilliseconds() / jump_time.asMilliseconds();

	// Initial jump velocity
	float jump_velocity = 2 * jump_height*tex_size / jump_time.asMilliseconds();

	// Is the player standing on ground
	bool grounded = true;

	// Checks for collisions with objects and updates position
	void collide(std::vector<Entity> entities, sf::Vector2f vel);

	// Jumps if grounded
	void jmp();

	// Key Bindings
	sf::Keyboard::Key left_key;
	sf::Keyboard::Key right_key;
	sf::Keyboard::Key jump_key;

public:
	// Default constructor
	Player();

	Player(std::string texture_file);

	// Binds the key for left, right, and jump
	void bind(sf::Keyboard::Key m_left_key, sf::Keyboard::Key m_right_key, sf::Keyboard::Key m_jump_key);

	// Set player position in tex_sizes
	void setPos(sf::Vector2f pos);
	
	// Updates player position
	void update(std::vector<Entity> platforms, int elapsed_time);

	// Is the player alive
	bool alive = true;
};

