#include <SDL_image.h>
#include "Sprites.h"
#include <iostream>

Sprites::Sprites()
{
    m_image = nullptr; 
    m_animationVelocity = 0.0f;

    m_isAnimationLooping = false;   //no animation by default
    isAnimationDead = false;
    m_isAnimated = false;         //not looping by default
    
    m_spriteDimension = { 0, 0 };   
    m_imageDimension = { 0, 0 };
    m_celDimension = { 0, 0 };
}

void Sprites::IsAnimationLooping(bool flag)
{
    m_isAnimationLooping = flag;
}

void Sprites::IsAnimated(bool flag)
{
    m_isAnimated = flag;
}

bool Sprites::Load(const std::string& filename, Screen& screen)
{
    SDL_Surface* rawImageData = IMG_Load(filename.c_str());

    if (!rawImageData)
    {
        std::cout << "Error loading image" << std::endl;
        return false;
    }

    m_image = SDL_CreateTextureFromSurface(screen.GetRenderer(), rawImageData);   

    return true;
}

void Sprites::Unload()
{
    SDL_DestroyTexture(m_image);
}

void Sprites::SetAnimationVelocity(float velocity)
{
    m_animationVelocity = velocity;
}

//resolution and column/row dimensions of the sprite image as it is stored in the Assets folder
void Sprites::SetImageDimensions(int columns, int rows, int width, int height)
{
    m_imageDimension.x = columns;
    m_imageDimension.y = rows;

    m_celDimension.x = width / columns;   //width resolution divided by number of columns
    m_celDimension.y = height / rows;    //height resolution divided by the number of rows
}

//resolution of the sprite image as it will appear on-screen
void Sprites::SetSpriteDimension(int width, int height)
{
    m_spriteDimension.x = width;
    m_spriteDimension.y = height;
}

void Sprites::SetImageCel(int column, int row)
{
    m_imageCel = ((row - 1) * m_imageDimension.x) + (column - 1);
}

void Sprites::Update()
{
    if (m_isAnimated)
    {
        static float total = 0.0f;
        total += 0.1f;

        m_imageCel = static_cast<int>(total * m_animationVelocity) % (m_imageDimension.x * m_imageDimension.y);
        if (!m_isAnimationLooping && m_imageCel == (m_imageDimension.x * m_imageDimension.y - 1))
        {
            isAnimationDead = true;
        }
    }
}

void Sprites::Render(int xPos, int yPos, double angle, Screen& screen)
{
    if (!isAnimationDead)
    {
        SDL_Rect sourceRect;
        SDL_Rect targetRect;

        sourceRect.x = (m_imageCel % m_imageDimension.x) * m_celDimension.x;
        sourceRect.y = (m_imageCel / m_imageDimension.x) * m_celDimension.y;
        sourceRect.w = m_celDimension.x;
        sourceRect.h = m_celDimension.y;

        targetRect.x = xPos;
        targetRect.y = yPos;
        targetRect.w = m_spriteDimension.x;
        targetRect.h = m_spriteDimension.y;

        SDL_Point centre{ m_spriteDimension.x * 0.5f, m_spriteDimension.y * 0.5f };

        SDL_RenderCopyEx(screen.GetRenderer(), m_image, &sourceRect, &targetRect, angle, &centre, SDL_FLIP_NONE);
    }
}