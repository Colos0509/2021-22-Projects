#include "GameObjects.h"

GameObjects::GameObjects()
{
    m_angle = 0.0f;
    bool m_isActive = true;
    bool m_isAlive = true;
    bool m_isVisible = true;
}

float GameObjects::GetAngle() const
{
    return m_angle;
}

void GameObjects::SetAngle(float angle)
{
    m_angle = angle;
}

const Vector2D& GameObjects::GetSize() const
{
    return m_size;
}

void GameObjects::SetSize(const Vector2D& size)
{
    m_size = size;
}

void GameObjects::SetSize(int width, int height)
{
    m_size = { width, height };
}

const Vector2D& GameObjects::GetPosition() const
{
    return m_position;
}

void GameObjects::SetPosition(const Vector2D& position)
{
    m_position = position;
}

void GameObjects::SetPosition(int x, int y)
{
    m_position = { x, y };
}

void GameObjects::SetRandPos(int x, int y)
{
    m_position = { x = x + rand() % 1000, y };
}

bool GameObjects::IsActive() const
{
    return m_isActive;
}

bool GameObjects::IsAlive() const
{
    return m_isAlive;
}

bool GameObjects::IsVisible() const
{
    return m_isVisible;
}

void GameObjects::IsActive(bool flag)
{
    m_isActive = flag;
}

void GameObjects::IsAlive(bool flag)
{
    m_isAlive = flag;
}

void GameObjects::IsVisible(bool flag)
{
    m_isVisible = flag;
}