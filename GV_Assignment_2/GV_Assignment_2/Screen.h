#pragma once
#include <SDL.h>
#include <string>

class Screen
{

public:

	Screen();
	bool Initialize(const std::string& windowTitle = "<Assignment 2 GV>", int width = 1280, int height = 720);
	void ClearScreen();
	void Present();
	void ShutDown();

	SDL_Renderer* GetRenderer();

private:

	SDL_Window* m_window;        //window pointer
	SDL_Renderer* m_renderer;   //renderer pointer

};

