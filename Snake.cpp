#include "stdafx.h"
#include "Snake.h"
#define SNAKE_DIMENSIONS 20

Snake::Snake(StateMachine* stateMachine, World *world, BaseAgent* playerAgent)
{
	m_name = "Snake";
	m_world = world;
	m_stateMachine = stateMachine;
	m_playerAgent = playerAgent;
	m_snakeSegments.reserve(100);
	m_snakeSegments.push_back(Segment({ HORIZONTAL_RESOLUTION/ 2, VERTICAL_RESOLUTION / 2 }));
	m_headSegment = &m_snakeSegments[0];
	m_movementVector = { 1, 0 };
	world->AddGameObject(this);
}

void Snake::Update()
{
	ReadInput();

	Vector2D oldPositionOfPredecessorSegment = m_headSegment->position;
	Vector2D tempPos;

	m_headSegment->position = m_headSegment->position + m_movementVector * m_speedModifier * m_world->DeltaTime();

	CheckForScreenWrapping();

	for (int i = 1; i < m_snakeSize; i++)
	{
		tempPos = m_snakeSegments[i].position;
		m_snakeSegments[i].position = oldPositionOfPredecessorSegment;
		oldPositionOfPredecessorSegment = tempPos;
	}

	CheckIfHeadBitBody();
}

Vector2D Snake::GetPosition()
{
	return m_headSegment->position;
}

void Snake::CheckForScreenWrapping()
{
	if (m_headSegment->position.x > HORIZONTAL_RESOLUTION)
		m_headSegment->position.x = 0;
	else if (m_headSegment->position.x < 0)
		m_headSegment->position.x = HORIZONTAL_RESOLUTION;
	else if (m_headSegment->position.y > VERTICAL_RESOLUTION)
		m_headSegment->position.y = 0;
	else if (m_headSegment->position.y < 0)
		m_headSegment->position.y = VERTICAL_RESOLUTION;
}

void Snake::CheckIfHeadBitBody()
{
	for (int i = 1; i < m_snakeSize; i++)
	{
		if (m_snakeSegments[i].position == m_headSegment->position)
			m_stateMachine->SwitchState(OUTRO_STATE);
	}
}

void Snake::GrowSnake()
{
	m_snakeSegments.push_back(Segment(Vector2D(HORIZONTAL_RESOLUTION+1, VERTICAL_RESOLUTION+1)));
	m_snakeSize++;
}

void Snake::Render() 
{
	for(int i = 0; i < m_snakeSize; i++)
		DrawRectangle(m_snakeSegments[i].position.x, m_snakeSegments[i].position.y, 
			SNAKE_DIMENSIONS, SNAKE_DIMENSIONS, GREEN);
}

void Snake::OnCollision(GameObject* other)
{
	std::cout << "Snake Collision! " << std::endl;
}

void Snake::Destroy()
{
	m_snakeSegments.clear();
	m_world = nullptr;
	m_isDestroyed = true;
}

void Snake::ReadInput()
{
	m_playerAgent->KeyDown(GetKeyPressed());
	m_movementVector = m_playerAgent->GetNextDirection();
}
