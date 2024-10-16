#pragma once
#include <EngineCore/Actor.h>

class Block : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	bool IsDownMovable(class Board* _board);
	void ChangeBlock(int _index);
	void Rotate();
private:
	int counter = 0;
	std::vector<class Renderer*> blockShapes;
};

