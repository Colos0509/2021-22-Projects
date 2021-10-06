#pragma once

#include "GameObjects.h"
#include "Sprites.h"
#include "Music.h"

class Win : public GameObjects
{

public:

	Win(Screen& screen);

	void Applause();

	virtual void Render(Screen& screen);
	virtual void Update(Input& input);

private:

	Music m_applause;
	Sprites m_image;

};

