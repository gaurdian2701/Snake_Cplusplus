#include "stdafx.h"
#include "Snake.h"
#define SNAKE_DIMENSIONS 20

Snake::Snake(World *world)
{
	m_world = world;
	m_snakeSegments.reserve(100);
	m_snakeSegments.push_back(Segment({ SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2 }));
	m_headSegment = &m_snakeSegments[0];
	m_movementVector = { 1, 0 };
	m_currentMovementDirection = RIGHT;
	world->AddGameObject(this);
}

void Snake::Update()
{
	ReadInput();

	Vector2 oldPositionOfPredecessorSegment = m_headSegment->position;
	Vector2 tempPos;

	std::cout << "Pos: " << m_headSegment->position.x << " " << m_headSegment->position.y << std::endl;

	m_headSegment->position = m_headSegment->position + m_movementVector * m_speedModifier * m_world->DeltaTime();

	for (int i = 1; i < m_snakeSize; i++)
	{
		tempPos = m_snakeSegments[i].position;
		m_snakeSegments[i].position = oldPositionOfPredecessorSegment;
		oldPositionOfPredecessorSegment = tempPos;
	}
}

void Snake::GrowSnake()
{
	m_snakeSegments.push_back(Segment(Vector2(m_headSegment->position.x - SNAKE_DIMENSIONS, 
		m_headSegment->position.y - SNAKE_DIMENSIONS)));
	m_snakeSize++;
}

void Snake::Render() 
{
	for(int i = 0; i < m_snakeSize; i++)
		DrawRectangle(m_snakeSegments[i].position.x, m_snakeSegments[i].position.y, 
			SNAKE_DIMENSIONS, SNAKE_DIMENSIONS, GREEN);
}

void Snake::Destroy()
{
	m_snakeSegments.clear();
}

void Snake::ReadInput()
{
	switch (GetKeyPressed())
	{
	case KEY_RIGHT:
		if (m_currentMovementDirection == LEFT)
			return;

		m_currentMovementDirection = RIGHT;
		m_movementVector = { 1,0 };
		break;

	case KEY_LEFT:
		if (m_currentMovementDirection == RIGHT)
			return;

		m_currentMovementDirection = LEFT;
		m_movementVector = { -1, 0 };
		break;

	case KEY_UP:
		if (m_currentMovementDirection == DOWN)
			return;

		m_currentMovementDirection = UP;
		m_movementVector = { 0, -1 };
		break;

	case KEY_DOWN:
		if (m_currentMovementDirection == UP)
			return;

		m_currentMovementDirection = DOWN;
		m_movementVector = { 0, 1 };
		break;

	default:
		break;
	}
}
