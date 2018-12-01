#include "Level.h"

Level::Level(std::string map_image_file, std::string block_texture_file, std::string hidden_texture_file)
{
	map.loadFromFile(map_image_file);
	block_texture.loadFromFile(block_texture_file);
	hidden_texture.loadFromFile(hidden_texture_file);
	size = map.getSize();
	update();	
}


void Level::update()
{
	entities.clear();

	for (int i = 0; i < size.x; i++)
		for (int j = 0; j < size.y; j++)
		{
			Entity block(false, true);
			block.setPosition(i * tex_size, j * tex_size);
			block.setTextureRect(sf::IntRect(0, 0, tex_size, tex_size));

			if (map.getPixel(i, j).r == 0 && map.getPixel(i, j).b == 0)
			{
				block.setTexture(block_texture);
				entities.push_back(block);
			}

			else if (map.getPixel(i, j).r == 0)
			{
				if (world == 0)
				{
					block.setTexture(block_texture);
				}
				else
				{
					block.setTexture(hidden_texture);
					block.solid = false;
				}

				entities.push_back(block);
			}

			else if (map.getPixel(i, j).b == 0)
			{
				if (world == 1)
				{
					block.setTexture(block_texture);
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