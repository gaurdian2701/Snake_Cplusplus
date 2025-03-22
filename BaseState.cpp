#include "stdafx.h"
#include "BaseState.h"

BaseState::BaseState(StateMachine* stateMachine, World *world)
{
	m_stateMachine = stateMachine;
	m_world = world;
}

BaseState::~BaseState()
{

}

void BaseState::Update() {}
void BaseState::Render() {}
void BaseState::ReadInput() {}