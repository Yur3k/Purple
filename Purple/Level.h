#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "constants.h"

class Level
{
private:
	void update();

	sf::Texture block_tex; // Texture used for regular blocks
	std::vector<std::vector<std::vector<char>>> maps; // Level layouts
	int map_num;
	int cur_map = 0;

public:
	Level(sf::Texture &m_block_tex);

	// Loads the level layouts from a text file
	void loadFromText(std::string filename); 

	// Loads the level layouts from an image
	void loadFromImage(std::string filename);

	// Changes the level map
	void flip(int to);

	// Size of the level
	sf::Vector2u size;
	std::vector<sf::Sprite> entities;
};