#include "stdafx.h"
#include "PlayingState.h"

PlayingState::PlayingState(StateMachine* stateMachine, SnakeGraphics* snakeGraphics) : BaseState(stateMachine, snakeGraphics) {}

void PlayingState::Init() 
{
	std::cout << "Playing State Init" << std::endl;
}
void PlayingState::Update() {}
void PlayingState::Render() 
{
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		m_snakeGraphics->PlotTile(x, 0, 0, Color(0, 255, 0), Color(0, 0, 0), 'S');
		m_snakeGraphics->PlotTile(x, SCREEN_HEIGHT - 1, 0, Color(0, 255, 0), Color(0, 0, 0), 'S');
	}

	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		m_snakeGraphics->PlotTile(0, y, 0, Color(0, 255, 0), Color(0, 0, 0), 'S');
		m_snakeGraphics->PlotTile(SCREEN_WIDTH - 1, y, 0, Color(0, 255, 0), Color(0, 0, 0), 'S');
	}

	m_snakeGraphics->Render();
}
void PlayingState::Cleanup() 
{
	m_snakeGraphics->ClearScreen();
}
void PlayingState::KeyDown(const int key)const {}