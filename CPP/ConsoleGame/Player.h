#pragma once
#include "ConsoleImage.h"

//class AActor
//{
//	FIntPoint Location;
//};
//
//class Monster
//{
//	
//};

// 화면어딘가에 이녀석이 랜더링
// 일반적인 게임엔진
class Player
{
public:
	void BeginPlay();
	void Tick();
	void Render();

	void SetActorLocation(FIntPoint _Pos);

private:
	FIntPoint Pos;
	FIntPoint LeftTop;
	FIntPoint RightBottom;
	ConsoleImage PlayerImage;
};

