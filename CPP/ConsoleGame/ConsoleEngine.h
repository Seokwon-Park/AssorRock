#pragma once
#include "ConsoleWindow.h"

class ConsoleEngine
{
	// void Update(); // 움직인다.
	// void Move(); // 움직인다.
public:
	static void Start();

private:
	ConsoleEngine();

	UConsoleWindow Window;

	// 2번 실행되지 않습니다.
	void BeginPlay(); // 움직인다.

	void Tick(); // 움직인다.
	// void Collision(); // 유니티는 두고 언리얼은 두지 않는다.
	void Render(); // 그린다.
};

