#include "GameScene.h"


GameScene::GameScene()
{
	// Create the level with the right map file
	level = Level("level" + std::to_string(level_num) + ".png");

	// Create the player at the level spawn
	player = Player("purple2.png");
}


GameScene::~GameScene()
{
}


void GameScene::start()
{
	// Restart the clock
	frame_clock.restart();

	// Move the player to spawn
	player.setPos(level.spawn);
}


void GameScene::update()
{
	level.update();

	player.update(level.entities, frame_clock.restart().asMilliseconds());
}


void GameScene::render(sf::RenderTexture& screen)
{
	screen.clear();

	for (int i = 0; i < level.entities.size(); i++)
		screen.draw(level.entities[i]);

	screen.draw(player);

	screen.display();
}


int GameScene::get_status()
{
	return status;
}