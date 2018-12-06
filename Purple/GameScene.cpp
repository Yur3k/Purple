#include "GameScene.h"


GameScene::GameScene()
{
	// Create the level with the right map file
	level = Level("level" + std::to_string(level_num) + ".png");

	// Create the player at the level spawn
	player = Player("purple.png");
}


GameScene::~GameScene()
{
}


void GameScene::bind(sf::Keyboard::Key left_key, sf::Keyboard::Key right_key, sf::Keyboard::Key jump_key, sf::Keyboard::Key m_flip_key)
{
	player.bind(left_key, right_key, jump_key);

	flip_key = m_flip_key;
}


void GameScene::start()
{
	// Restart the clock
	frame_clock.restart();

	// Move the player to spawn
	player.setPos(level.spawn);

	// Set the size of the player view
	player_view.setSize(tex_size * 16 * 5, tex_size * 9 * 5);
}


void GameScene::pause()
{
	paused = true;
}


void GameScene::play()
{
	paused = false;
}


void GameScene::update()
{
	if (paused)
		return;

	// Flip the level to 1 if "Q" is pressed, else to 0
	if (sf::Keyboard::isKeyPressed(flip_key))
		level.flip(1);
	else
		level.flip(0);

	// Update the level
	level.update();

	// Update the player
	player.update(level.entities, frame_clock.restart().asMilliseconds());

	// Update the view center
	player_view_center = player.getPosition();
	player_view_center += { player.getLocalBounds().width / 2, player.getLocalBounds().height / 2 };

	player_view_center.x = std::max(0.f, player_view_center.x - view.getSize().x / 2) + player_view.getSize().x / 2;
	player_view_center.x = std::min((float)level.size.x * tex_size, player_view_center.x + player_view.getSize().x / 2) - player_view.getSize().x / 2;

	player_view_center.y = std::max(0.f, player_view_center.y - view.getSize().y / 2) + view.getSize().y / 2;
	player_view_center.y = std::min((float)level.size.y * tex_size, player_view_center.y + player_view.getSize().y / 2) - player_view.getSize().y / 2;

	// Update the player view
	player_view.setCenter(player_view_center);
}


void GameScene::render(sf::RenderTexture& screen)
{
	screen.setView(player_view);

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