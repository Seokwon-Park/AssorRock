#include "TetrisInit.h"
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>

#include "Block.h"
#include "Board.h"

void TetrisInit::UserBeginPlay(ConsoleEngine* _MainEngine)
{
	// ������ �մϴ�.
	_MainEngine->GetWindow()->SetScreenSize({20, 20});
	Board* NewBoard =  _MainEngine->SpawnActor<Board>();
	Block* NewBlock = _MainEngine->SpawnActor<Block>();
	NewBoard->SetBlock(NewBlock);
}