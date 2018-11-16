#include "Level.h"

Level::Level(std::string map_image_file, std::string block_texture_file)
{
	map.loadFromFile(map_image_file);
	block_texture.loadFromFile(block_texture_file);
	size = map.getSize();
	update();	
}


void Level::update()
{
	entities.clear();

	for (int i = 0; i < size.x; i++)
		for (int j = 0; j < size.y; j++)
			if ((map.getPixel(i, j).r == 0) && (world == 0) || map.getPixel(i, j).b == 0 && world == 1)
			{
				sf::Sprite block(block_texture);
				block.setPosition(i * tex_size, j * tex_size);
				entities.push_back(block);
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