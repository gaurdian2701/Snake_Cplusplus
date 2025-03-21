#include "stdafx.h"
#include "PlayerAgent.h"


PlayerAgent::~PlayerAgent()
{
	while (!m_inputQueue.empty())
		m_inputQueue.pop();
}

Vector2D PlayerAgent::GetNextDirection()
{
	if (m_inputQueue.empty())
		return m_latestInput;

	m_latestInput = m_inputQueue.front();
	m_inputQueue.pop();
	return m_latestInput;
}

void PlayerAgent::KeyDown(const int key)
{

	Vector2D m_movementVector;
	switch (key)
	{
	case KEY_RIGHT:
		if (m_currentDirection == MovementDirection::LEFT)
			return;

		m_currentDirection = MovementDirection::RIGHT;
		m_movementVector = { 1,0 };
		break;

	case KEY_LEFT:
		if (m_currentDirection == MovementDirection::RIGHT)
			return;

		m_currentDirection = MovementDirection::LEFT;
		m_movementVector = { -1, 0 };
		break;

	case KEY_UP:
		if (m_currentDirection == MovementDirection::DOWN)
			return;

		m_currentDirection = MovementDirection::UP;
		m_movementVector = { 0, -1 };
		break;

	case KEY_DOWN:
		if (m_currentDirection == MovementDirection::UP)
			return;

		m_currentDirection = MovementDirection::DOWN;
		m_movementVector = { 0, 1 };
		break;

	default:
		return;
	}

	if(m_inputQueue.size() <= 10)
		m_inputQueue.push(m_movementVector);
}
