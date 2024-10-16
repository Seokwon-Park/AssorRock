#pragma once
#include "ConsoleImage.h"
#include "Actor.h"
#include "ActorVector.h"

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
class Player : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	static Player* GetPlayer()
	{
		return MainPlayer;
	}

	const ActorVector& GetBulletVector()
	{
		return BulletVector;
	}

private:
	static Player* MainPlayer;

	// �Ǵٸ� ����Ʈ�� ������ �Ѵ�.
	ActorVector BulletVector;
};

