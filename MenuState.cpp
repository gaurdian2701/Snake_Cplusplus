#include "MenuState.h"
#include "stdafx.h"
#define ENTER_KEY 13

MenuState::MenuState(StateMachine* stateMachine, SnakeGraphics* snakeGraphics) : BaseState(stateMachine, snakeGraphics) {}

void MenuState::Init() 
{
	std::cout << "MenuState Init" << std::endl;
}

void MenuState::Update() 
{
}
void MenuState::Render() 
{
	m_snakeGraphics->PlotText(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, Color(0, 0, 0), L"Start Game", Color(0, 255, 0), 
		SnakeGraphics::Alignment::Center);
	m_snakeGraphics->Render();
}
void MenuState::Cleanup() 
{
	m_snakeGraphics->ClearScreen();
}

void MenuState::KeyDown(const int key)const 
{
	std::cout << "Key Pressed " << key << std::endl;
	if (key == ENTER_KEY)
		m_stateMachine->SwitchState(PLAYING_STATE);
}