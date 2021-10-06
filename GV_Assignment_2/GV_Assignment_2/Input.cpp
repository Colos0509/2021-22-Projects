#include "Input.h"

Input::Input()
{
	m_isKeyPressed = false;
	m_isWindowClosed = false;
}

char Input::GetKeyUp()
{
	return m_keyUp;
}
char Input::GetKeyDown()
{
	return m_keyDown;
}

bool Input::IsKeyPressed()
{
	return m_isKeyPressed;
}

bool Input::IsWindowClosed()
{
	return m_isWindowClosed;
}


void Input::Update()
{
	SDL_Event events;

	while (SDL_PollEvent(&events))
	{
		if (events.type == SDL_QUIT)
		{
			m_isWindowClosed = true;
		}
		else if (events.type == SDL_KEYDOWN)
		{
			m_isKeyPressed = true;
			m_keyDown = events.key.keysym.sym;
		}
		else if (events.type == SDL_KEYUP)
		{
			m_isKeyPressed = false;
			m_keyDown = ' ';
			m_keyUp = events.key.keysym.sym;
		}
	}
}

