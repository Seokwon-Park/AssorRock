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

// ȭ���򰡿� �̳༮�� ������
// �Ϲ����� ���ӿ���
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

