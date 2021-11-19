#include "Level.h"


Level::Level()
{
}


Level::Level(std::string map_image_file)
{
	block_texture.loadFromFile("block.png");
	flip_block_texture.loadFromFile("flip_block.png");
	hidden_texture.loadFromFile("block_hidden.png");
	spike_texture.loadFromFile("spike.png");
	finish_texture.loadFromFile("finish.png");

	map.loadFromFile(map_image_file);
	size = map.getSize();

	update();	
}


void Level::update()
{
	entities.clear();

	for (float i = 0; i < size.x; i++)
		for (float j = 0; j < size.y; j++)
		{
			if (map.getPixel(i, j) == sf::Color(100, 0, 0, 255))
				spawn = { i, j };

			else if (map.getPixel(i, j) == sf::Color(0, 0, 100, 255))
			{
				Entity finish_entity(false, false, false);
				finish_entity.setTexture(finish_texture);
				finish_entity.setPosition(i * tex_size, j * tex_size);
				finish.push_back(finish_entity);
				entities.push_back(finish_entity);
			}
		}

	for (int i = 0; i < size.x; i++)
		for (int j = 0; j < size.y; j++)
		{
			sf::Color block_color = map.getPixel(i, j);
			Entity block(false, true, false);
			block.setPosition(i * tex_size, j * tex_size);
			block.setTextureRect(sf::IntRect(0, 0, tex_size, tex_size));
			
			if (block_color.g == 255)
			{
				block.deadly = true;
				block.solid = false;
				block.setTexture(spike_texture);
				entities.push_back(block);
			}

			else if (block_color.r == 255 && block_color.b == 255)
			{
				block.setTexture(block_texture);
				entities.push_back(block);
			}

			else if (block_color.r == 255)
			{
				if (world == 0)
				{
					block.setTexture(flip_block_texture);
				}
				else
				{
					block.setTexture(hidden_texture);
					block.solid = false;
				}

				entities.push_back(block);
			}

			else if (block_color.b == 255)
			{
				if (world == 1)
				{
					block.setTexture(flip_block_texture);
				}
				else
				{
					block.setTexture(hidden_texture);
					block.solid = false;
				}

				entities.push_back(block);
			}
		}
}


void Level::flip(int to)
{
	if (world != to)
	{
		world = to;
		update();
	}	
}