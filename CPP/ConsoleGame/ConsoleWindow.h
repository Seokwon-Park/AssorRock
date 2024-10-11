#pragma once
#include "ConsoleImage.h"



class UConsoleWindow
{

public:
	UConsoleWindow();

	// 초미니 컴퓨터가 있다고 생각하자.

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

	// 최종적으로 우리 눈에 보일 이미지.
	// 여기에다가 그리지 않으면 눈에 보이지 않아요.
	ConsoleImage BackBuffer;
};

