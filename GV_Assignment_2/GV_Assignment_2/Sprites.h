#pragma once
#include "Screen.h"
#include <string>
#include <SDL.h>

class Sprites
{
public:

	Sprites();
	~Sprites() {}

	void IsAnimationLooping(bool flag);
	void IsAnimated(bool flag);

	void Unload();
	bool Load(const std::string& filename, Screen& screen);

	void SetAnimationVelocity(float velocity);
	void SetImageDimensions(int columns, int rows, int width, int height);   //in-folder(resolution)
	void SetSpriteDimension(int width, int height);   //on-screen
	void SetImageCel(int column, int row);

	void Update();   //because images are loaded one after another in animation
	void Render(int xPos, int yPos, double angle, Screen& screen);

private:

	bool m_isAnimationLooping;
	float m_animationVelocity;
	bool isAnimationDead;
	bool m_isAnimated;
	int m_imageCel;   //identifies a single image of a spritesheet

	SDL_Point m_spriteDimension;
	SDL_Point m_imageDimension;
	SDL_Point m_celDimension;    //a block of a sprite sheet (cel is an old name for frame)
	SDL_Texture* m_image;
};