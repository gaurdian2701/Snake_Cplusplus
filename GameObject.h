#pragma once
#include "World.h"
#include "StateMachine.h"
class GameObject
{
public:
	virtual void Update() {}
	virtual void Render() {}
	virtual void Destroy() {}
	virtual Vector2D GetPosition() { return Vector2D(0, 0); }
	bool IsDestroyed() { return m_isDestroyed; }

protected:
	bool m_isDestroyed = false;
	World* m_world = nullptr;
	Vector2D m_position;
};

