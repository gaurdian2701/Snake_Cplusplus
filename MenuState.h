#pragma once
#include "BaseState.h"
class MenuState : public BaseState
{

public:
	MenuState(StateMachine *stateMachine, SnakeGraphics* snakeGraphics);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Cleanup() override;
	void KeyDown(const int key) const override;
};

