#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"

class Entity: public sf::Sprite
{
private:
	sf::Vector2i size = { 1, 1 }; // in tex_sizes
	sf::Vector2f velocity = { 0, 0 };
	sf::Vector2f acceleration = { 0, 0 };

public:
	Entity(bool m_movable, bool m_solid);

	bool movable = false;
	bool solid = false;
};
