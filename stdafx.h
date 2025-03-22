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

class SnakeGameStateMachine;
class GameObject;

struct Vector2D
{
	int x;
	int y;
	Vector2D(int xval, int yval) { x = xval; y = yval; }
	Vector2D() { x = 0; y = 0; }
	Vector2D operator+(Vector2D other) const
	{
		return Vector2D(x + other.x, y + other.y);
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

