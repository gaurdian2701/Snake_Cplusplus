#pragma once
#include "StateMachine.h"
#include "Tools/SnakeGraphics.h"

class BaseState
{
public:
	BaseState(StateMachine* stateMachine, SnakeGraphics* snakeGraphics);
	virtual ~BaseState();
	
protected:
	StateMachine *m_stateMachine;
	SnakeGraphics *m_snakeGraphics;

public:
	virtual void Init() = 0;					
	virtual void Update();
	virtual void Render();
	virtual void Cleanup() = 0;
	virtual void KeyDown(const int key) const;
};

