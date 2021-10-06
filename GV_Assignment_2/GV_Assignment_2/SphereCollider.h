#pragma once
#include "Vector2D.h"

class SphereCollider
{
public:

	SphereCollider();

	void SetPosition(int x, int y);
	void SetRadius(int radius);

	bool IsColliding(const SphereCollider& secondBox) const;

private:
	int m_radius;
	Vector2D m_position;

};

