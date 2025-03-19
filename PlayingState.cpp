#include "stdafx.h"
#include "PlayingState.h"

PlayingState::PlayingState(StateMachine* stateMachine, World *world) : BaseState(stateMachine, world), m_world(world)
{
}

void PlayingState::Init() 
{
	CreateGameObjects();
	m_gameObjects = &(m_world->GetGameObjects());
}

void PlayingState::CreateGameObjects()
{
	m_snake = new Snake(m_world);
}

void PlayingState::Update() 
{
	for (GameObject* gameObject : *m_gameObjects)
		gameObject->Update();
}

void PlayingState::Render() 
{
	for (GameObject* gameObject : *m_gameObjects)
		gameObject->Render();
}
void PlayingState::Cleanup() 
{
}
void PlayingState::ReadInput() {}