#pragma once

#include "World.h"
class GameObject
{
public:
	virtual void Update() {}
	virtual void Render() {}
	virtual void Destroy() {}
	bool IsDestroyed() { return m_isDestroyed; }

protected:
	bool m_isDestroyed = false;
	struct Vector2
	{
		int x;
		int y;
		Vector2(int xval, int yval) { x = xval; y = yval; }
		Vector2() { x = 0; y = 0; }
		Vector2 operator+(Vector2 other) const
		{
			return Vector2(x + other.x, y + other.y);
		}

		template <typename T>
		Vector2 operator*(T other) const
		{
			return Vector2(x * other, y * other);
		}
	};
};

