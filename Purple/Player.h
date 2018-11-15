#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.h"

class Player: public sf::Sprite // represents a player
{
private:
	sf::Vector2i size;
	sf::Vector2f velocity = { 0, 0 };
	sf::Vector2f acceleration = { 0, 0 };

	float horizontalAccelerationUp = 0.001; // Horizontal when speeding up
	float horizontalAccelerationDown = 0.003; // Horizontal acceleration when slowing down
	float horizontalSpeedCap = 0.17; // Maximum horizontal speed

	float jump_height; // Height in tex_sizes
	float jump_time; // Time to reach maximum trajectory height in milliseconds

	float gravity = 0.0005; // Gravitational acceleration
	float jump_velocity = 0.36; // Initial jump velocity

	bool grounded = true; // Is the player standing on ground

	// checks for collisions with objects and updates position
	void collide(std::vector<sf::Sprite> entities, sf::Vector2f vel);

	// jumps if grounded
	void jump();

public:
	Player(sf::Vector2i m_size, sf::Vector2f m_position, sf::Texture &tex);
	
	// Updates player position
	void update(bool right, bool left, bool up, std::vector<sf::Sprite> platforms, int elapsed_time);
};

