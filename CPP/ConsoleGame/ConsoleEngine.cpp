#include "ConsoleEngine.h"
#include <Windows.h>
#include <conio.h>

UConsoleWindow ConsoleEngine::Window;

ConsoleEngine::ConsoleEngine()
{

}

void ConsoleEngine::Start()
{
	ConsoleEngine Engine;

	Engine.BeginPlay();

	while (true)
	{
		//int keyInput = _kbhit();
		//if (keyInput != 0)
		//{
		//	int escape = _getch();
		//	if (escape == 'o')
		//		break;

		//}
		Engine.Tick();
		Engine.Render();
		// ���α׷� 250
		// 1000�� 1���Դϴ�.
		Sleep(250);
	}

}

void ConsoleEngine::BeginPlay()
{
	Window.BeginPlay();
	Window.SetScreenSize({ 20, 10 });

	NewPlayer.BeginPlay();
}

void ConsoleEngine::Tick()
{
	NewPlayer.Tick();
}

void ConsoleEngine::Render()
{
	Window.Clear();

	NewPlayer.Render();

	Window.ScreenRender();
}