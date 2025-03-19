#pragma once
class BaseState;
#include "GameObject.h"

class StateMachine
{

public:
	StateMachine();
	virtual ~StateMachine();
	virtual void StateMachine_Update() = 0;
	virtual void StateMachine_Render() = 0;
	virtual void InitStates(World *world) = 0;
	virtual void SwitchState(const Enum_GameStates gameState) = 0;

	BaseState* m_currentState;
};

