#pragma once
#include "StateMachine.h"
#include "MenuState.h"
#include "PlayingState.h"
#include "OutroState.h"

class World;

class SnakeGameStateMachine : public StateMachine
{
public:
	SnakeGameStateMachine(World *world);
	~SnakeGameStateMachine();

public:
	void InitStates(World * world) override;
	void SwitchState(const Enum_GameStates gameState) override;
	void StateMachine_Update() override;
	void StateMachine_Render() override;

private:
	MenuState* m_menuState;
	PlayingState* m_playingState;
	OutroState* m_outroState;
};

