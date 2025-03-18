#pragma once
#include "BaseState.h"
class PlayingState : public BaseState
{
public:
	PlayingState(StateMachine* stateMachine, SnakeGraphics* snakeGraphics);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Cleanup() override;
	void KeyDown(const int key) const override;
};

