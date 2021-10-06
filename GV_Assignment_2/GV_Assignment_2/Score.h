#pragma once

#include "GameObjects.h"
#include "Music.h"
#include "Text.h"

class Score : public GameObjects
{
public:

	Score();
	~Score();

	void SetScore(int score);
	void ScoreAdd(int plus);

	int GetScore();

	virtual void Update(Input& input) {}
	virtual void Render(Screen& screen);

private:

	int m_score;

	Text m_text;
};