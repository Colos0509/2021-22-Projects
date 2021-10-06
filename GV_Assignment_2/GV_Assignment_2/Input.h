#pragma once

#include <SDL.h>

class Input
{
public:

	Input();

	void Update();

	char GetKeyUp();
	char GetKeyDown();
	bool IsKeyPressed();
	bool IsWindowClosed();


private:

	char m_keyUp;
	char m_keyDown;
	bool m_isKeyPressed;
	bool m_isWindowClosed;
};

