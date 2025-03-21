#include "stdafx.h"
#include "SnakeGameStateMachine.h"


SnakeGameStateMachine::SnakeGameStateMachine(World *world)
{
	std::cout << "Snake Game State Machine ctor" << std::endl;
	InitStates(world);
	m_currentState = m_menuState;
	m_currentState->Init();
}

SnakeGameStateMachine::~SnakeGameStateMachine()
{
	m_currentState = nullptr;
	delete m_menuState;
	delete m_playingState;
	delete m_outroState;
}

void SnakeGameStateMachine::InitStates(World *world)
{
	m_menuState = new MenuState(this, world);
	m_playingState = new PlayingState(this, world);
	m_outroState = new OutroState(this, world);
}

void SnakeGameStateMachine::SwitchState(const Enum_GameStates gameState)
{
	BaseState* newState = nullptr;

	switch (gameState)
	{
	case MENU_STATE:
		newState = m_menuState;
		break;
	case PLAYING_STATE:
		newState = m_playingState;
		break;
	case OUTRO_STATE:
		newState = m_outroState;
		break;
	}

	if (newState == nullptr)
		newState = m_currentState;

	if (newState == m_currentState)
		return;

	m_currentState->Cleanup();
	m_currentState = newState;
	m_currentState->Init();
}

void SnakeGameStateMachine::StateMachine_Update()
{
	m_currentState->Update();
}

void SnakeGameStateMachine::StateMachine_Render()
{
	m_currentState->Render();
}