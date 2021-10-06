#pragma once

#include "BoxCollider.h"
#include "GameObjects.h"
#include "Score.h"
#include "Sprites.h"

class Stone : public GameObjects
{

public:

	Stone(Screen& screen);
	~Stone();

	void SetAsteroidFall(int velocity, int direction);  //added this for the asteroids movement 
	void SetVelocity(float velocity);

	const BoxCollider& GetCollider() const;

	virtual void Update(Input& input);  
	virtual void Render(Screen& screen);

private:

	int m_velocity;

	Sprites m_image;

	Vector2D m_direction;
	Vector2D m_asteroidFall;

	BoxCollider m_collider;
};