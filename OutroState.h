#pragma once
#include "BaseState.h"
class OutroState : public BaseState
{
public:
	OutroState(StateMachine* stateMachine, SnakeGraphics* snakeGraphics);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Cleanup() override;
	void KeyDown(const int key) const override;
};

