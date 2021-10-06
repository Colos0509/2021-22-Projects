#include "Explosion.h"

Explosion::Explosion(Screen& screen)
{
	m_image.Load("Assets/Images/Explosion.png", screen);
	m_image.SetImageDimensions(4, 4, 3628, 3628);
	m_image.SetSpriteDimension(300, 300);
	m_image.IsAnimated(true);
	m_image.SetAnimationVelocity(1.5f);

	m_explosionSound.Load("Assets/Audio/Explosion.mp3");
	m_explosionSound.SetVolume(50);
}

Explosion::~Explosion()
{
	m_image.Unload();
}

void Explosion::ExplosionSound()
{
	m_explosionSound.Play();
}

void Explosion::Update(Input& input)
{
	m_explosionSound.Play();

	m_image.Update();
}

void Explosion::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen);
}
