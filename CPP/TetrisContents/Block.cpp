#include "Block.h"
#include "Board.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleImage.h>
#include <conio.h>
#include <string>



void Block::BeginPlay()
{
	Super::BeginPlay();

	blockShapes.reserve(7);

	std::vector<std::string> OBlock =
	{
		"    ",
		" @@ ",
		" @@ ",
		"    ",
	};
	std::vector<std::string> IBlock =
	{
		"    ",
		"@@@@",
		"    ",
		"    ",
	};

	std::vector<std::string> SBlock =
	{
		"    ",
		"  @@",
		" @@ ",
		"    ",
	};
	std::vector<std::string> ZBlock =
	{
		"    ",
		" @@ ",
		"  @@",
		"    ",
	};
	std::vector<std::string> LBlock =
	{
		"    ",
		" @@@",
		" @  ",
		"    ",
	};
	std::vector<std::string> JBlock =
	{
		"    ",
		" @@@",
		"   @",
		"    ",
	};

	std::vector<std::string> TBlock =
	{
		"    ",
		" @@@",
		"  @ ",
		"    ",
	};

	for (int i = 0; i < 7; i++)
	{
		blockShapes.push_back(CreateDefaultSubObject());
	}

	blockShapes[0]->RenderImage.Create({4, 4}, OBlock);
	blockShapes[1]->RenderImage.Create({4, 4}, IBlock);
	blockShapes[2]->RenderImage.Create({4, 4}, SBlock);
	blockShapes[3]->RenderImage.Create({4, 4}, ZBlock);
	blockShapes[4]->RenderImage.Create({4, 4}, LBlock);
	blockShapes[5]->RenderImage.Create({4, 4}, JBlock);
	blockShapes[6]->RenderImage.Create({4, 4}, TBlock);
	
}

void Block::Tick()
{
	Super::Tick();

	// ㅇㅇ
	counter++;
	if (counter > 1)
	{
		AddActorLocation(FIntPoint::DOWN);
		counter = 0;
	}

	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			AddActorLocation(FIntPoint::LEFT);
			break;
		case 'D':
		case 'd':
			AddActorLocation(FIntPoint::RIGHT);
			break;
		case 'W':
		case 'w':
			Rotate();
			break;
		case 'S':
		case 's':
			AddActorLocation(FIntPoint::DOWN);
			break;
		default:
			break;
		}

	}
}

bool Block::IsDownMovable(Board* _board)
{
	ConsoleImage block = GetImageRenderer()->RenderImage;
	ConsoleImage boardImg = _board->GetImageRenderer()->RenderImage;
	FIntPoint ImageSize = block.GetImageSize();
	for (int i = 0; i < ImageSize.Y; i++)
	{
		for (int j = 0; j < ImageSize.X; j++)
		{
			if (block.GetPixel(j, i) == '@')
			{
				// 블록의 @부분일때 y +1을 한 부분이 경계밖이거나 다른 블럭이면 내려갈수없다.
				FIntPoint CurPos = GetActorLocation() + FIntPoint(j, i + 1);
				if (CurPos.Y >= boardImg.GetImageSize().Y || boardImg.GetPixel(CurPos) == '@')
					return false;
			}
		}
	}
	return true;
}

void Block::ChangeBlock(int _index)
{
	SetImageRenderer(blockShapes[_index]);
}

void Block::Rotate()
{
	GetImageRenderer()->RenderImage.Rotate();
}
