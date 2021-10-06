#pragma once

#include "BoxCollider.h"
#include "GameObjects.h"
#include "Sound.h"
#include "Sprites.h"

class Player : public GameObjects   
{

public:

	enum State { IDLE, RUN, DIE, TOTAL_STATES };   //enum for player animation states

	Player(Screen& screen);
	~Player();

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

	void SetSpeed(int speed);
	void SetState(State state);

	void RunningSound();
	void DeathSound();

	const BoxCollider& GetCollider() const;

private:

	Sprites m_images[TOTAL_STATES];

	BoxCollider m_collider;

	Vector2D m_direction;

	Sound m_runningSound;
	Sound m_deathSound;

	State m_state;

	int m_speed;
};