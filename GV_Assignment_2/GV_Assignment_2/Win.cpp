#include "Win.h"

Win::Win(Screen& screen)
{
	m_image.Load("Assets/Images/winner.png", screen);
	m_image.SetImageDimensions(1, 1, 277, 182);
	m_image.SetSpriteDimension(554, 364);

	m_applause.Load("Assets/Audio/Applause.mp3");
	m_applause.SetVolume(100);
}

void Win::Applause()
{
	m_applause.Play(Music::PlayLoop::PLAY_ENDLESS);
}

void Win::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen);
}

void Win::Update(Input& input)
{
	m_applause.Play(Music::PlayLoop::PLAY_ENDLESS);

	m_image.Update();
}
