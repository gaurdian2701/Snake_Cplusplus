#pragma once
#include "GameObject.h"
class Snake : public GameObject
{
private:
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

	enum class MovementDirection
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

