#include "ConsoleEngine.h"

ConsoleEngine::ConsoleEngine()
{

}

void ConsoleEngine::Start()
{
	ConsoleEngine Engine;

	Engine.BeginPlay();

	while (true)
	{
		Engine.Tick();
		Engine.Render();
	}
	
}

void ConsoleEngine::BeginPlay()
{
	Window.BeginPlay();
}

void ConsoleEngine::Tick()
{

}

void ConsoleEngine::Render()
{
	Window.Clear();


	Window.ScreenRender();
}