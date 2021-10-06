#pragma once

#include "GameObjects.h"
#include "Screen.h"
#include "Sound.h"
#include "Sprites.h"
#include "Text.h"

class Death : public GameObjects
{

public:

	Death(Screen& screen);

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

	void SoundOfDeath();

private:

	Sound m_deathSound;
	Sprites m_image;
	Text m_text;

};

