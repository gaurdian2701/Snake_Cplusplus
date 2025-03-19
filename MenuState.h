#pragma once
#include "BaseState.h"
class MenuState : public BaseState
{

public:
	MenuState(StateMachine *stateMachine, World *world);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Cleanup() override;
	void ReadInput() override;
};

