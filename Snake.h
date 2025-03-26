#pragma once
#include "GameObject.h"
#include "PlayerAgent.h"
#include "AI_Agent.h"
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

	std::vector<Segment> m_snakeSegments;
	Segment* m_headSegment;
	StateMachine* m_stateMachine;
	BaseAgent* m_playerAgent;
	Vector2D m_movementVector;
	int m_snakeSize = 1;
	const float m_speedModifier = 200.0f;
	void ReadInput();
	void OnCollision(GameObject* other) override;

public:
	Snake(StateMachine* stateMachine, World *world, BaseAgent *playerAgent);
	void GrowSnake();
	void CheckForScreenWrapping();
	void CheckIfHeadBitBody();
	Vector2D GetPosition() override;
	void Update() override;
	void Render() override;
	void Destroy() override;
};

