#pragma once
#include "ConsoleWindow.h"

class ConsoleEngine
{
	// void Update(); // �����δ�.
	// void Move(); // �����δ�.
public:
	static void Start();

private:
	ConsoleEngine();

	UConsoleWindow Window;

	// 2�� ������� �ʽ��ϴ�.
	void BeginPlay(); // �����δ�.

	void Tick(); // �����δ�.
	// void Collision(); // ����Ƽ�� �ΰ� �𸮾��� ���� �ʴ´�.
	void Render(); // �׸���.
};

