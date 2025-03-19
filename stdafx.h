#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <vector>
#include <map>
#include <string>
#include "raylib.h"

class SnakeGameStateMachine;

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

	float DistanceFrom(Vector2D other)
	{
		float diffX = x - other.x;
		float diffY = y - other.y;
		return sqrt((diffX * diffX) + (diffY * diffY));
	}
};

enum Enum_GameStates
{
	MENU_STATE,
	PLAYING_STATE,
	OUTRO_STATE
};

constexpr int HORIZONTAL_RESOLUTION = 1024;
constexpr int VERTICAL_RESOLUTION = 720;

