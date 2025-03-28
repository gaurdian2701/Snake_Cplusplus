#include "stdafx.h"
#include "Apple.h"
#define APPLE_DIMENSIONS 20

Apple::Apple(World* world, GameObject* snake)
{
	m_name = "Apple";
	m_world = world;
	m_snake = dynamic_cast<Snake*>(snake);
	RandomizePosition();
	world->AddGameObject(this);
}

void Apple::Update()
{
	if (m_position.DistanceFrom(m_snake->GetPosition()) < 20)
	{
		RandomizePosition();
		m_snake->GrowSnake();
		m_world->UpdateScore();
	}
}

void Apple::OnCollision(GameObject* other)
{
	std::cout << "Apple collision!" << std::endl;
}

void Apple::RandomizePosition()
{
	m_position = Vector2D(GetRandomValue(0, HORIZONTAL_RESOLUTION), GetRandomValue(0, VERTICAL_RESOLUTION));
}

void Apple::Render()
{
	DrawRectangle(m_position.x, m_position.y, APPLE_DIMENSIONS, APPLE_DIMENSIONS, { 255, 0, 0, 255 });
}

void Apple::Destroy()
{
	m_world = nullptr;
	m_snake = nullptr;
	m_isDestroyed = true;
}
