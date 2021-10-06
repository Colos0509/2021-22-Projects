#include "Player.h"

Player::Player(Screen& screen)
{
	m_speed = 0;
	m_state = IDLE;

	m_images[IDLE].Load("Assets/Images/Idle.png", screen);
	m_images[RUN].Load("Assets/Images/RunBoy.png", screen);
	m_images[DIE].Load("Assets/Images/Death.png", screen);

	for (int i = 0; i < TOTAL_STATES; i++)
	{
		m_images[i].SetImageDimensions(10, 1, 5880, 600);
		m_images[i].SetSpriteDimension(100, 157);  //I can set the size on-screen here
		m_images[i].IsAnimated(true);

		if (i == DIE)
		{
			m_images[i].IsAnimationLooping(false);
			m_images[i].SetAnimationVelocity(0.8f);   //Needed different animation velocity for death
		}
		else
		{
			m_images[i].IsAnimationLooping(true);
			m_images[i].SetAnimationVelocity(2.0f);
		}

		if (i == RUN)
		{
			m_images[i].SetImageDimensions(10, 1, 4150, 507);
		}
		else
		{
			m_images[i].SetImageDimensions(10, 1, 5880, 600);
		}
	}

	m_collider.SetDimension(100, 157);  //collider size

	m_runningSound.Load("Assets/Audio/Running.mp3");   //audio for running. Weird for some reason, not what the original sound is like. 
	m_runningSound.SetVolume(20);

	m_deathSound.Load("Assets/Audio/Fart.mp3");   //audio for running. Weird for some reason, not what the original sound is like. 
	m_deathSound.SetVolume(20);
}

Player::~Player()
{
	m_images[m_state].Unload();
}

void Player::Update(Input& input) //sprite controls with arrow keys, running sounds, and collision
{
	if (input.GetKeyDown() == SDL_SCANCODE_LEFT)
	{
		m_direction.x = -1;
		m_direction.y = 0;
		m_state = RUN;

		m_runningSound.Play();
	}
	else if (input.GetKeyDown() == SDL_SCANCODE_RIGHT)
	{
		m_direction.x = 1;
		m_direction.y = 0;
		m_state = RUN;

		m_runningSound.Play();
	}
	else
	{
		m_direction.x = 0;
		m_direction.y = 0;
		m_state = IDLE;

		m_runningSound.Stop();   //Running sound stops when no keys are pressed
	}

	if (m_isAlive == false)   //if player is not alive, state switches to "DIE"
	{
		m_state = DIE; 
		m_deathSound.Play();
	}

	m_direction = m_direction.Scale(m_speed);
	m_position = m_position.Add(m_direction);

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();

	m_images[m_state].Update();
}

void Player::Render(Screen& screen)
{
	m_images[m_state].Render(m_position.x, m_position.y, m_angle, screen);
}

void Player::SetSpeed(int speed)
{
	m_speed = speed;
}

void Player::SetState(State state)
{
	m_state = state;
}

void Player::RunningSound()
{
	m_runningSound.Play();
}

void Player::DeathSound()
{
	m_deathSound.Play();
}

const BoxCollider& Player::GetCollider() const
{
	return m_collider;
}