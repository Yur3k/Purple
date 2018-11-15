#include "Level.h"

Level::Level(sf::Texture &tex)
	: block_tex(tex)
{
}


void Level::loadFromText(std::string filename)
{
	std::ifstream map_file;
	map_file.open(filename);
	map_file >> size.x >> size.y >> map_num;

	/*for (int i = 0; i < map_num; i++)
	{
		maps.push_back(std::vector<std::string>(size.y));
		for (int j = 0; j < size.y; j++)
			map_file >> maps[i][j];
	}*/

	map_file.close();

	update();
}


void Level::loadFromImage(std::string filename)
{
	sf::Image map_image;
	map_image.loadFromFile(filename);
	size = map_image.getSize();

	maps.push_back(std::vector<std::vector<char>>());
	for (int i = 0; i < size.y; i++)
	{
		maps[0].push_back(std::vector<char>(size.x, '-'));

		for (int j = 0; j < size.x; j++)
		{
			if (map_image.getPixel(j, i).r == 0)
				maps[0][i][j] = '0';
		}	
	}

	update();
}


void Level::update()
{
	entities.clear();
	for (int i = 0; i < size.y; i++)
		for (int j = 0; j < size.x; j++)
			if (maps[cur_map][i][j] == '0')
			{
				sf::Sprite block(block_tex);
				block.setPosition(j * tex_size, i * tex_size);
				//block.setTextureRect(sf::IntRect(0, 0, tex_size, tex_size));
				entities.push_back(block);
			}
}

void Level::flip(int to)
{
	if (cur_map != to)
	{
		cur_map = to;
		update();
	}	

	//std::cout << cur_map;
}