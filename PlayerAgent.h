#pragma once
#include "BaseAgent.h"
class PlayerAgent : public BaseAgent
{
public:
	PlayerAgent(int keyBoardLayoutID) : m_keyBoardLayoutID(keyBoardLayoutID) 
	{
		m_currentDirection = MovementDirection::RIGHT;
		m_latestInput = { 1, 0 };
		m_inputQueue.push(m_latestInput);
	}
	~PlayerAgent();
public:
	Vector2D GetNextDirection() override;
	void KeyDown(const int key) override;
private:
	int m_keyBoardLayoutID;
	MovementDirection m_currentDirection;
	Vector2D m_latestInput;
};

