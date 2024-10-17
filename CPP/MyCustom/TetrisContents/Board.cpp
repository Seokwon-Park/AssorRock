#include "Board.h"
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>
#include <EngineCore/Renderer.h>
#include "Block.h"
#include <random>

void Board::BeginPlay()
{
	srand((unsigned int)time(0));
	Super::BeginPlay();

	//FIntPoint BackbufSize = ConsoleEngine::GetEngine().GetWindow()->GetBackBufferRef().GetImageSize();
	FIntPoint BackbufSize = { 10,20 };

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create(BackbufSize, '.');
}

void Board::Tick()
{
	Renderer* boardRenderer = GetImageRenderer();
	// 더 내려갈 수 있음?
	if (!block->IsDownMovable(this))
	{
		// ㄴㄴ
		boardRenderer->RenderImage.Copy(block->GetActorLocation(),block->GetImageRenderer()->RenderImage);
		block->SetActorLocation({ boardRenderer->RenderImage.GetImageSize().X / 2,0 });
		block->ChangeBlock(rand()%7);

		CheckBoard();
	}
}

void Board::CheckBoard()
{
	Renderer* boardRenderer = GetImageRenderer();
	std::vector<int> delLine;
	for (int i = boardRenderer->RenderImage.GetImageSize().Y - 1; i >= 0; i--)
	{
		auto& line = boardRenderer->RenderImage.GetLineRef(i);
		int cnt = count(line.begin(), line.end(), '@');
		if (cnt != 0)
		{
			if (cnt == boardRenderer->RenderImage.GetImageSize().X)
			{
				delLine.push_back(i);
			}
		}
		else
		{
			break;
		}
	}

	for (auto ix : delLine)
	{
		for (int i = ix; i >= 1; i--)
		{
			auto& line = boardRenderer->RenderImage.GetLineRef(i);
			line = boardRenderer->RenderImage.GetLine(i-1);
		}

	}
}
