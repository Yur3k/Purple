#include "Player.h"

Player::Player(sf::Vector2i m_size, sf::Vector2f position, std::string texture_file)
	: size(m_size)
{
	player_texture.loadFromFile(texture_file);
	setTexture(player_texture);

	setPosition(position.x * tex_size, position.y * tex_size);
	setScale(size.x, size.y);
}


void Player::collide(std::vector<Entity> platforms, sf::Vector2f vel)
{
	sf::Vector2f temp_pos = getPosition();

	for (int i = 0; i < platforms.size(); i++)
	{
		sf::FloatRect rect = platforms[i].getGlobalBounds();

		if (getGlobalBounds().intersects(rect) && platforms[i].solid)
		{
			if (vel.x > 0)
			{
				temp_pos.x = rect.left - size.x * tex_size;
				velocity.x = 0;
			}
			if (vel.x < 0)
			{
				temp_pos.x = rect.left + rect.width;
				velocity.x = 0;
			}

			if (vel.y > 0)
			{
				temp_pos.y = rect.top - size.y * tex_size;
				velocity.y = 0;
				grounded = true;
			}
			if (vel.y < 0)
			{
				temp_pos.y = rect.top + rect.height;
				velocity.y = 0;
			}
		}
	}

	setPosition(temp_pos);

	for (int i = 0; i < platforms.size(); i++)
		if (getGlobalBounds().intersects(platforms[i].getGlobalBounds()) && platforms[i].deadly)
		{
			alive = false;
		}
}


void Player::update(bool left, bool right, bool up, std::vector<Entity> platforms, int elapsed_time)
{
	if (!alive)
		return;

	if (!jerky)
	{
		if (left && !right)
		{
			if (velocity.x > 0)
				acceleration.x = -horizontalAccelerationDown;
			else
				acceleration.x = -horizontalAccelerationUp;

		}
		else if (right && !left)
		{
			if (velocity.x < 0)
				acceleration.x = horizontalAccelerationDown;
			else
				acceleration.x = horizontalAccelerationUp;
		}
		else
		{
			acceleration.x = 0;

			if (grounded)
				velocity.x *= 0.93;
		}
	}
	
	else
	{
		if (left && !right)
			velocity.x = -horizontalSpeedCap;
		else if (right && !left)
			velocity.x = horizontalSpeedCap;
		else
			velocity.x = 0;
	}
	
	if (grounded)
		acceleration.y = 0;
	else
		acceleration.y = gravity;

	velocity += {acceleration.x * elapsed_time, acceleration.y * elapsed_time};
	velocity.x = fmin(horizontalSpeedCap, velocity.x);
	velocity.x = fmax(-horizontalSpeedCap, velocity.x);

	grounded = false;
	move(velocity.x * elapsed_time, 0);
	collide(platforms, { velocity.x, 0 });
	move(0, velocity.y * elapsed_time);
	collide(platforms, { 0, velocity.y });

	if (up)
		jump();
}


void Player::jump()
{
	if (grounded)
	{
		grounded = false;
		velocity.y = -jump_velocity;
	}
}