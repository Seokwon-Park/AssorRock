#pragma once
#include <EngineCore/Actor.h>

class Board : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	void SetBlock(class Block* _block)
	{
		block = _block;
	}

	void CheckBoard();

private:
	//std::vector<Block*> BlockList;
	class Block* block;
};

