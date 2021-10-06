#pragma once

#include "GameObjects.h"
#include "Music.h"
#include "Sprites.h"

class Background : public GameObjects
{

public:

	Background(Screen& screen);
	~Background();

	void BackgroundNoise();

	virtual void Render(Screen& screen);
	virtual void Update(Input& input);

private:

	Music m_backgroundNoise;
	Sprites m_image;
};