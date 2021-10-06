#include "Score.h"

Score::Score()
{
	m_score = 0;

	m_text.Load("Assets/Fonts/AGENCYB.TTF", 1000);
	m_text.SetColor(255, 0, 0, 255);
	m_text.SetDimension(60, 90);
}

Score::~Score()
{
	m_text.Unload();
}

void Score::SetScore(int score)
{
	m_score = score;
	m_text.SetText(std::to_string(m_score));
}

void Score::ScoreAdd(int plus)
{
	m_score += plus;
	m_text.SetText(std::to_string(m_score));
}

int Score::GetScore()
{
	return m_score;
}

void Score::Render(Screen& screen)
{
	m_text.Render(10, 10, screen);
}