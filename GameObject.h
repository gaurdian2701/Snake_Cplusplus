#pragma once
#include "World.h"
#include "StateMachine.h"
class GameObject
{
public:
	virtual void Update() {}
	virtual void Render() {}
	virtual void Destroy() {}
	virtual Vector2D GetPosition() { return m_position; }
	virtual void OnCollision(GameObject* other) {}
	bool IsDestroyed() { return m_isDestroyed; }
	std::string m_name;

protected:
	bool m_isDestroyed = false;
	World* m_world = nullptr;
	Vector2D m_position;
};

