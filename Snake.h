#pragma once
#include "GameObject.h"
class Snake : public GameObject
{
private:
	struct Segment
	{
	public:
		Vector2D position;

		Segment() {}
		Segment(Vector2D pos)
		{
			position = pos;
		}
	};

	enum class MovementDirection
	{
		RIGHT,
		LEFT,
		UP,
		DOWN
	}m_currentMovementDirection;;

	std::vector<Segment> m_snakeSegments;
	Segment* m_headSegment;
	Vector2D m_movementVector;
	int m_snakeSize = 1;
	const float m_speedModifier = 200.0f;

	void ReadInput();

public:
	Snake(World *world);
	void GrowSnake();
	Vector2D GetPosition() override;
	void Update() override;
	void Render() override;
	void Destroy() override;
};

