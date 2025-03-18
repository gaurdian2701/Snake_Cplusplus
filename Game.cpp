#include "stdafx.h"
#include "Game.h"
#include "Tools/SnakeInput.h"
#include "Tools/SnakeGraphics.h"
#include "SnakeGameStateMachine.h"


bool Game::Init()
{
	m_snakeGraphics = new SnakeGraphics(1024, 720, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (!m_snakeGraphics->Init())
	{
		std::cerr << "UNABLE TO INITIALIZE SNAKE GRAPHICS!" << std::endl;
		return false;
	}

	if (!SnakeInput::Init(m_snakeGraphics))
	{
		std::cerr << "UNABLE TO INITIALIZE SNAKE INPUT!" << std::endl;
		return false;
	}
	SnakeInput::AddKeyDownCallback(std::bind(&Game::KeyDownCallBack, this, std::placeholders::_1));
	world = new World(m_snakeGraphics);
	world->Init();
	return true;
}

void Game::Update()
{
	world->Update();
}

void Game::Render()
{
	world->Render();
}

void Game::KeyDownCallBack(const int key) const
{
	world->KeyDown(key);
}

void Game::Cleanup()
{
	SnakeInput::CleanUp();
	world->Cleanup();
	delete world;
	delete m_snakeGraphics;
}

void Game::Run()
{
	if (!Init())
	{
		std::cerr << "INIT FAILED!" << std::endl;
		return;
	}

	std::chrono::system_clock::time_point timeAtStartOfFrame = std::chrono::system_clock::now();

	while (m_snakeGraphics->UpdateWindowMessages())
	{
		Update();
		Render();

		std::chrono::duration<double, std::milli> work_time = std::chrono::system_clock::now() - timeAtStartOfFrame;
		long timeLeftInFrame = (long)(1000 / FPS) - work_time.count();

		if (timeLeftInFrame > 0.0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(timeLeftInFrame));
		}

		m_deltaTime = (float)(std::chrono::system_clock::now() - timeAtStartOfFrame).count() / 1000.0f;
		timeAtStartOfFrame = std::chrono::system_clock::now();
	}
	Cleanup();
}