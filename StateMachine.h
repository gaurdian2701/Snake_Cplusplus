#pragma once
#include "stdafx.h"
class BaseState;

class StateMachine
{

public:
	StateMachine();
	virtual ~StateMachine();
	virtual void StateMachine_Update() = 0;
	virtual void StateMachine_Render() = 0;
	virtual void StateMachine_KeyDownCallBack(const int key) const = 0;
	virtual void InitStates() = 0;
	virtual void SwitchState(const Enum_GameStates gameState) = 0;

	BaseState* m_currentState;
};

