#pragma once

#include "World.h"
class GameObject
{
public:
	virtual void Update() {}
	virtual void Render() {}
	virtual void Destroy() {}
	bool IsDestroyed() { return m_isDestroyed; }

protected:
	bool m_isDestroyed = false;
};

