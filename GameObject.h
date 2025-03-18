#pragma once
class GameObject
{
public:
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
	bool IsDestroyed() { return m_isDestroyed; }

protected:
	bool m_isDestroyed = false;
};

