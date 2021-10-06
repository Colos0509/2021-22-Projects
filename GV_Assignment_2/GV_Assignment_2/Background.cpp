#include "Background.h"

Background::Background(Screen& screen)
{
	m_image.Load("Assets/Images/cyberpunk-street.png", screen);
	m_image.SetImageDimensions(1, 1, 1280, 720);
	m_image.SetSpriteDimension(1280, 720);   

	m_backgroundNoise.Load("Assets/Audio/Siren.mp3");
	m_backgroundNoise.SetVolume(10);
}

Background::~Background()
{
	m_image.Unload();
}

void Background::BackgroundNoise()
{
	m_backgroundNoise.Play(Music::PlayLoop::PLAY_ENDLESS);
}

void Background::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen);
}

void Background::Update(Input& input)
{

}
