#pragma once

#include "GameObjects.h"
#include "Sprites.h"
#include "Sound.h"
#include "Input.h"

class Explosion : public GameObjects
{

public:

	Explosion(Screen& screen);
	~Explosion();

	void ExplosionSound();

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

private:

	Sound m_explosionSound;
	Sprites m_image;

};

