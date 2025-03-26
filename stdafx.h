#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include "raylib.h"
#include <ostream>


class SnakeGameStateMachine;
class GameObject;

struct Vector2D
{
	int x;
	int y;
	double fVal;
	double gVal;
	double hVal;
	std::unique_ptr<Vector2D> parent = nullptr;
	Vector2D() { x = 0; y = 0; fVal = 0; gVal = 0; hVal = 0; parent = nullptr; }
	Vector2D(int xval, int yval) { x = xval; y = yval; }
	Vector2D(int xVal, int yVal, Vector2D startPos, Vector2D endPos)
	{
		x = xVal;
		y = yVal;
		gVal = startPos.gVal + this->DistanceFrom(startPos);
		hVal = this->DistanceFrom(endPos);
		fVal = gVal + hVal;
		parent = nullptr;
	}

	Vector2D(const Vector2D& other)
	{
		x = other.x;
		y = other.y;
		fVal = other.fVal;
		hVal = other.hVal;
		gVal = other.gVal;
		Deep_SetParent(other.parent.get());
	}

	Vector2D& operator=(const Vector2D& other)
	{
		if (this == &other)
			return *this;

		x = other.x;
		y = other.y;
		fVal = other.fVal;
		hVal = other.hVal;
		gVal = other.gVal;
		Deep_SetParent(other.parent.get());
		return *this;
	}

	void Deep_SetParent(const Vector2D* newParent)
	{
		if (newParent)
			parent = std::unique_ptr<Vector2D>(new Vector2D(*newParent));
		else
			parent = nullptr;
	}

	Vector2D operator+(Vector2D other) const
	{
		return Vector2D(x + other.x, y + other.y);
	}

	Vector2D operator-(Vector2D other) const
	{
		return Vector2D(x - other.x, y - other.y);
	}

	template <typename T>
	Vector2D operator*(T other) const
	{
		return Vector2D(x * other, y * other);
	}

	double DistanceFrom(Vector2D other)
	{
		double diffX = x - other.x;
		double diffY = y - other.y;
		return sqrt((diffX * diffX) + (diffY * diffY));
	}

	bool operator==(Vector2D other)
	{
		return x == other.x && y == other.y;
	}

	bool operator !=(Vector2D other)
	{
		return x != other.x || y != other.y;
	}

	bool operator <(const Vector2D &other) const
	{
		return x < other.x && y < other.y;
	}

	bool operator <=(const Vector2D other) const
	{
		return x <= other.x && y <= other.y;
	}

	friend std::ostream& operator<<(std::ostream& os, Vector2D const& vector) {
		return os << "Vector(" << vector.x << ", " << vector.y << ")" << std::endl;
	}
};

struct CollisionStruct
{
	int frameID;
	GameObject* gameObject;
};

enum Enum_GameStates
{
	MENU_STATE,
	PLAYING_STATE,
	OUTRO_STATE
};

enum class MovementDirection
{
	LEFT,
	UP,
	RIGHT,
	DOWN
};

constexpr int HORIZONTAL_RESOLUTION = 1024;
constexpr int VERTICAL_RESOLUTION = 720;

