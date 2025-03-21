#pragma once
#include "stdafx.h"
class BaseAgent
{
public:
	virtual Vector2D GetNextDirection() = 0;
	virtual void KeyDown(const int key) {}

protected:
	std::queue<Vector2D> m_inputQueue;
};

