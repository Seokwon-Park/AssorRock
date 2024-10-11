#include "Player.h"
#include <conio.h>
#include "Enums.h"
#include "ConsoleEngine.h"
#include <BaseSystem/EngineMath.h>


void Player::BeginPlay()
{
	PlayerImage.Create({2, 3}, '@');
	LeftTop = FIntPoint::ZERO;
	RightBottom = ConsoleEngine::GetWindow()->GetBackBufferPtr()->GetSize();
}

void Player::Tick()
{
	int Value = _kbhit();
	Enums::GAMEDIR Dir = Enums::GAMEDIR::NONE;
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			Dir = Enums::GAMEDIR::LEFT;
			break;
		case 'D':
		case 'd':
			Dir = Enums::GAMEDIR::RIGHT;
			break;
		case 'W':
		case 'w':
			Dir = Enums::GAMEDIR::UP;
			break;
		case 'S':
		case 's':
			Dir = Enums::GAMEDIR::DOWN;
			break;
		default:
			break;
		}

	}

	FIntPoint NextPos = Pos;
	switch (Dir)
	{
	case Enums::GAMEDIR::LEFT:
		NextPos = Pos + FIntPoint::LEFT;
		break;
	case Enums::GAMEDIR::RIGHT:
		NextPos = Pos + FIntPoint::RIGHT;
		break;
	case Enums::GAMEDIR::UP:
		NextPos = Pos + FIntPoint::UP;
		break;
	case Enums::GAMEDIR::DOWN:
		NextPos = Pos + FIntPoint::DOWN;
		break;
	default: //GAMEDIR::NONE;
		break;
	}

	int TargetX = NextPos.X;
	int TargetY = NextPos.Y;
	if (TargetX < 0 || TargetY < 0 || 
		TargetX + PlayerImage.GetImageSizeX() > RightBottom.X || 
		TargetY + PlayerImage.GetImageSizeY() > RightBottom.Y) return;

	Pos = NextPos;

	
	// Pos += FIntPoint::RIGHT;
}

void Player::Render()
{
	// delete _BackBuffer;
	ConsoleEngine::GetWindow()->GetBackBufferPtr()->Copy(Pos, PlayerImage);
}

void Player::SetActorLocation(FIntPoint _Pos)
{
	Pos = _Pos;
}

