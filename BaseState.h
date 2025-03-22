#pragma once
#include "StateMachine.h"

class BaseState
{
public:
	BaseState(StateMachine* stateMachine, World *world);
	virtual ~BaseState();
	
protected:
	StateMachine *m_stateMachine;
	World* m_world;

public:
	virtual void Init() = 0;					
	virtual void Update();
	virtual void Render();
	virtual void Cleanup() = 0;
	virtual void ReadInput();
};

