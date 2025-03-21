#include "stdafx.h"
#include "MenuState.h"

MenuState::MenuState(StateMachine* stateMachine, World *world) : BaseState(stateMachine, world) {}

void MenuState::Init() 
{
	std::cout << "MenuState Init" << std::endl;
}

void MenuState::Update() 
{
	ReadInput();
}
void MenuState::Render() 
{
	const char* startString = "PRESS ENTER TO START";
	DrawText(startString, HORIZONTAL_RESOLUTION/2 - strlen(startString), VERTICAL_RESOLUTION / 2, 20, GREEN);
}
void MenuState::Cleanup() 
{

}

void MenuState::ReadInput() 
{
	if (IsKeyPressed(KEY_ENTER))
		m_stateMachine->SwitchState(PLAYING_STATE);
}