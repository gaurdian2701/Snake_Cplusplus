#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <vector>
#include <map>
#include <string>

class SnakeGraphics;
class SnakeGameStateMachine;

enum Enum_GameStates
{
	MENU_STATE,
	PLAYING_STATE,
	OUTRO_STATE
};

constexpr int SCREEN_WIDTH = 60;
constexpr int SCREEN_HEIGHT = 30;

