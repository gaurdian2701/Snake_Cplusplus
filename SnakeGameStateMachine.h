#pragma once
#include "StateMachine.h"
#include "MenuState.h"
#include "PlayingState.h"
#include "OutroState.h"
class SnakeGameStateMachine : public StateMachine
{
public:
	SnakeGameStateMachine(SnakeGraphics* snakeGraphics);
	~SnakeGameStateMachine();

public:
	void InitStates() override;
	void SwitchState(const Enum_GameStates gameState) override;
	void StateMachine_Update() override;
	void StateMachine_Render() override;
	void StateMachine_KeyDownCallBack(const int key) const override;

private:
	MenuState* m_menuState;
	PlayingState* m_playingState;
	OutroState* m_outroState;
	SnakeGraphics* m_snakeGraphics;
};

