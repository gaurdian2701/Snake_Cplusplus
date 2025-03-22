#include "stdafx.h"
#include "OutroState.h"

OutroState::OutroState(StateMachine* stateMachine, World *world) : BaseState(stateMachine, world) {}

void OutroState::Init() 
{
	m_score = m_world->GetScore();
}
void OutroState::Update() {}
void OutroState::Render() 
{
	DrawText("GAME OVER", HORIZONTAL_RESOLUTION/2, VERTICAL_RESOLUTION/2, 20, GREEN);
	DrawText(TextFormat("SCORE: %08i", m_score), HORIZONTAL_RESOLUTION / 2, VERTICAL_RESOLUTION / 2 + 20, 20, GREEN);
}
void OutroState::Cleanup() {}
void OutroState::ReadInput() {}