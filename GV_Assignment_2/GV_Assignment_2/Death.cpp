#include "Death.h"

Death::Death(Screen& screen)
{
	m_image.Load("Assets/Images/Death.png", screen);
	m_image.SetImageDimensions(1, 10, 5880, 600);
	m_image.SetSpriteDimension(100, 157);
	m_image.IsAnimated(true);   
	m_image.SetAnimationVelocity(3.5f);

	m_deathSound.Load("Assets/Audio/Fart.mp3");
	m_deathSound.SetVolume(50);
}

void Death::Update(Input& input)
{
	m_image.Update();

	m_deathSound.Play();
}

void Death::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen);
}

void Death::SoundOfDeath()
{
	m_deathSound.Play();
}