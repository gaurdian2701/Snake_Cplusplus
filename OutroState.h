#pragma once
#include "BaseState.h"
class OutroState : public BaseState
{
public:
	OutroState(StateMachine* stateMachine, World *world);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Cleanup() override;
	void ReadInput() override;
	int m_score;
};

