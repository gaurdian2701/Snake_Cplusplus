#include "stdafx.h"
#include "World.h"


World::World(SnakeGraphics *snakeGraphics) 
{
	m_snakeGraphics = snakeGraphics;
	m_stateMachine = new SnakeGameStateMachine(m_snakeGraphics);
}

World::~World()
{
	delete m_stateMachine;
}

void World::Init() {}

void World::Render() 
{
	m_stateMachine->StateMachine_Render();
}
void World::Update() 
{
	m_stateMachine->StateMachine_Update();
}
void World::Cleanup() 
{
	for (GameObject* gameObject : m_gameObjects)
		gameObject->Destroy();
	for (GameObject* gameObject : m_gameObjects)
		delete gameObject;
	m_gameObjects.clear();
}

void World::KeyDown(const int key) const 
{
	m_stateMachine->StateMachine_KeyDownCallBack(key);
}