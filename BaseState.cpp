#include "BaseState.h"

BaseState::BaseState(StateMachine* stateMachine, SnakeGraphics* snakeGraphics)
{
	m_stateMachine = stateMachine;
	m_snakeGraphics = snakeGraphics;
}

BaseState::~BaseState()
{

}

void BaseState::Update() {}
void BaseState::Render() {}
void BaseState::KeyDown(const int key) const {}