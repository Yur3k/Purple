#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "constants.h"

class Level
{
private:
	void update();

	// Texture used for regular blocks
	sf::Texture block_texture;

	// Texture used for hidden blocks
	sf::Texture hidden_texture;

	// Texture used for spikes
	sf::Texture spike_texture;

	// Layout of the level in image form
	sf::Image map; 

	// Current active world
	int world = 0; 

public:
	Level(std::string map_image_file, std::string block_texture_file, std::string hidden_texture_file, std::string spike_texture_file);

	// Changes the level map
	void flip(int to);

	// Size of the level
	sf::Vector2u size;

	// List of spirites
	std::vector<Entity> entities;
};