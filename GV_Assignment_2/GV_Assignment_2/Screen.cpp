#include <iostream>
#include "Screen.h"

Screen::Screen()
{
    m_window = nullptr;
    m_renderer = nullptr;
}

bool Screen::Initialize(const std::string& windowTitle, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == -1)   //create SDL
    {
        std::cout << "Error initializing SDL" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return false;
    }

    m_window = SDL_CreateWindow(windowTitle.c_str(),        //window title, as declared in Screen.h
                                SDL_WINDOWPOS_CENTERED,    //screen pos x   
                                SDL_WINDOWPOS_CENTERED,   //screen pos y
                                width,                   //screen width, as in Screen.h
                                height,                 //screen height, as in Screen.h
                                0);                    //flags

    if (!m_window)
    {
        std::cout << "Error creating game window" << std::endl;
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);   //create renderer 

    if (!m_renderer)
    {
        std::cout << "Error creating renderer" << std::endl;
        return false;
    }

    return true;
}

void Screen::ClearScreen()
{
    SDL_RenderClear(m_renderer);   //clears the screen
}

void Screen::Present()
{
    SDL_RenderPresent(m_renderer);
}

void Screen::ShutDown()
{
    SDL_DestroyRenderer(m_renderer);    //erase renderer from memory
    SDL_DestroyWindow(m_window);       //erase window from memory
    SDL_Quit();                       //shut down SDL
}

SDL_Renderer* Screen::GetRenderer()
{
    return m_renderer;
}
