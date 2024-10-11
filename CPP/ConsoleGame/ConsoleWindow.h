#pragma once
#include "ConsoleImage.h"



class UConsoleWindow
{

public:
	UConsoleWindow();

	// �ʹ̴� ��ǻ�Ͱ� �ִٰ� ��������.

	// "****************"0
	// "****************"0
	// "****************"0
	// "****************"0
	// "****************"0
	// "****************"0
	// "****************"0

	void BeginPlay();

	void ScreenRender();

	void SetPixel(int _X, int _Y, char _Text);

	void Clear();

private:
	int FrameDelay = 250;

	// ���������� �츮 ���� ���� �̹���.
	// ���⿡�ٰ� �׸��� ������ ���� ������ �ʾƿ�.
	ConsoleImage BackBuffer;
};

