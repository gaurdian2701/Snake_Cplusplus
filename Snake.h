#pragma once
#include "GameObject.h"
class Snake : public GameObject
{
private:
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

	struct Segment
	{
	public:
		Vector2 position;

		Segment() {}
		Segment(Vector2 pos)
		{
			position = pos;
		}
	};

	enum MovementDirection
	{
		RIGHT,
		LEFT,
		UP,
		DOWN
	}m_currentMovementDirection;;

	World* m_world = nullptr;
	std::vector<Segment> m_snakeSegments;
	Segment* m_headSegment;
	Vector2 m_movementVector;
	int m_snakeSize = 1;
	const float m_speedModifier = 600.0f;
	
	void GrowSnake();
	void ReadInput();

public:
	Snake(World *world);
	void Update() override;
	void Render() override;
	void Destroy() override;
};

