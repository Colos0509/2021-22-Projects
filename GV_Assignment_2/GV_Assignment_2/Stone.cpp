#include "Stone.h"

Stone::Stone(Screen& screen)
{
	m_velocity = 0;

	m_image.Load("Assets/Images/AsteroidBrown.png", screen);
	m_image.SetImageDimensions(1, 1, 160, 160);   //total amount of pictures on the spritesheet, resolution
	m_image.SetSpriteDimension(100, 100);  //I can set the size on-screen here

	m_collider.SetDimension(100, 100);
}

Stone::~Stone()
{
	m_image.Unload();
}

void Stone::SetAsteroidFall(int velocity, int direction)  //makes the asteroid "fall down"
{
	m_velocity = velocity;
	m_direction.y = direction;

	m_asteroidFall = velocity + direction;
}

void Stone::SetVelocity(float velocity)
{
	m_velocity = velocity;	
}

const BoxCollider& Stone::GetCollider() const
{
	return m_collider;
}

void Stone::Update(Input& input)
{
	m_direction = m_direction.Scale(m_velocity);
	m_position = m_position.Add(m_direction);

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();

	m_image.Update();
}

void Stone::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen);
}