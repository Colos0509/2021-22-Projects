#pragma once

#include <ctime>
#include <SDL.h>
#include <string>
#include "Input.h"
#include "Screen.h"
#include "Vector2D.h"

class GameObjects   //Abstract base class
{

public:
	
	GameObjects();

	void IsActive(bool flag);
	void IsAlive(bool flag);
	void IsVisible(bool flag);

	float GetAngle() const;   //game object angle
	void SetAngle(float angle);   

	const Vector2D& GetSize() const;   //game object size
	void SetSize(const Vector2D& size);
	void SetSize(int width, int height);
	
	const Vector2D& GetPosition() const;   //game object position
	void SetPosition(const Vector2D& position);
	void SetPosition(int x, int y);
	void SetRandPos(int x, int y);   //made to randomize asteroids

	bool IsActive() const;
	bool IsAlive() const;
	bool IsVisible() const;

	virtual void Update(Input& input) = 0;
	virtual void Render(Screen& screen) = 0;

protected:   //return variables

	float m_angle;  

	bool m_isActive;
	bool m_isAlive;
	bool m_isVisible;

	Vector2D m_size;
	Vector2D m_position;
};

